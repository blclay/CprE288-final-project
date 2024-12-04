// adc.c

#include "adc.h"
#include "Timer.h"
#include <stdint.h>
#include <stdbool.h>
#include "lcd.h"
#include <inc/tm4c123gh6pm.h>
#include "driverlib/interrupt.h"
#include "ping.h"

volatile enum {LOW,HIGH,DONE} state;
volatile unsigned int rise_time;
volatile unsigned int fall_time;

void ping_init(void)
{
    SYSCTL_RCGCGPIO_R |= 0x2;
    GPIO_PORTB_DEN_R |= 0x8;
    GPIO_PORTB_AFSEL_R |= 0x08;
    GPIO_PORTB_PCTL_R |= 0x00007000;

    SYSCTL_RCGCTIMER_R |= 0x8;
    TIMER3_CTL_R &= ~0x100;
    TIMER3_CFG_R |= 0x4;
    TIMER3_TBMR_R |= 0x7;
    TIMER3_TBILR_R = 0xFFFF;
    TIMER3_TBPR_R = 0xFF;
    TIMER3_CTL_R |= 0x100;

    TIMER3_IMR_R = 0x400;
    NVIC_EN1_R |= 0x10;

    IntRegister(INT_TIMER3B, TIMER3B_Interrupt_Handler);
}

int ping_read(void)
{
    TIMER3_IMR_R = 0x0;
    TIMER3_CTL_R &= 0x0FF;
    send_Pulse();
    TIMER3_CTL_R |= 0xD00;

    while(state!=DONE);
    return (rise_time - fall_time);

}

void send_Pulse()
{

    GPIO_PORTB_AFSEL_R &= ~(0x08);
    GPIO_PORTB_DIR_R |= 0x08;
    GPIO_PORTB_DATA_R |= 0x08;
    timer_waitMicros(5);
    GPIO_PORTB_DATA_R &= 0xF7;
    GPIO_PORTB_DIR_R &= 0xF7;
    GPIO_PORTB_AFSEL_R |= 0x08;
    GPIO_PORTB_PCTL_R |= 0x00007000;

    TIMER3_ICR_R |= 0xFFFFF;
    TIMER3_IMR_R = 0x400;
    state = LOW;


}

void TIMER3B_Interrupt_Handler(void)
{
    if (state == LOW)
    {
        rise_time = TIMER3_TBR_R;
        state = HIGH;
    }
    else
    {
        fall_time = TIMER3_TBR_R;
        state = LOW;
        state = DONE;
    }
    TIMER3_ICR_R |= 0xFFFFF;
}



