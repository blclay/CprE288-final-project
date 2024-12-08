

/**
 * main.c
 */

#include "open_interface.h"
#include "Timer.h"
#include <stdio.h>
#include <math.h>
#include "movement.h"
#include "uart_extra_help.h"
#include "lcd.h"
#include <stdlib.h>
#include <inc/tm4c123gh6pm.h>
#include "lcd.h"
#include "movement.h"
#include <stdint.h>
#include <stdbool.h>
#include <inc/tm4c123gh6pm.h>
#include "driverlib/interrupt.h"



int main(void)
{

    uart_init();
    timer_init();
    lcd_init();
    oi_t *sensor_data = oi_alloc();
      oi_init(sensor_data);
      oi_setWheels(200, 200);
//    int IR_FL = 0;
//        int IR_FR = 0;
//        int IR_L = 0;
//        int IR_R = 0;
//    int data[100];

        // lcd_printf("%d", data);

  /*  while (1)
    {
        oi_update(sensor_data);
        IR_FL = sensor_data->cliffFrontLeftSignal;
        IR_FR = sensor_data->cliffFrontRightSignal;
        IR_L = sensor_data->cliffLeftSignal;
        IR_R = sensor_data->cliffRightSignal;
        lcd_printf("%d", IR_FL);
        timer_waitMillis(500);
    } */
    move_forward_go_around(sensor_data, 100);


    oi_free(sensor_data);
    return 0;
}
