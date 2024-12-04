// adc.c

#include "adc.h"
#include "Timer.h"
#include <stdint.h>
#include <stdbool.h>
#include "lcd.h"
#include <inc/tm4c123gh6pm.h>
#include "driverlib/interrupt.h"

void adc_init(void)
{

    SYSCTL_RCGCGPIO_R |= 0x2; //portB
    SYSCTL_RCGCADC_R |= 0x1;      // enable clock ADC0 (page 340)
    GPIO_PORTB_DEN_R &= ~0x10;
    GPIO_PORTB_AFSEL_R |= 0x10;

    GPIO_PORTB_AMSEL_R |= 0x10;

    ADC0_ACTSS_R &= ~0x1;
    ADC0_EMUX_R = 0x0;
    ADC0_SSMUX0_R |= 0xA;
    ADC0_SSCTL0_R |= 0x6;
    ADC0_SAC_R = 0x4;
    ADC0_PSSI_R |= 0x1;

    ADC0_ACTSS_R |= 0x01; //SS0

}




