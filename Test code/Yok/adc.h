
#ifndef ADC_H_
#define ADC_H_

#include "Timer.h"
#include <stdint.h>
#include <stdbool.h>
#include "lcd.h"
#include <inc/tm4c123gh6pm.h>
#include "driverlib/interrupt.h"

extern volatile  char uart_data;  // Your UART interupt code can place read data here
extern volatile  char flag;       // Your UART interupt can update this flag
                           // to indicate that it has placed new data
                           // in uart_data

volatile int uart_event;
volatile char uart_typed;



void adc_init(void);

#endif /* ADC_H_ */
