#include "Timer.h"
#include "lcd.h"
#include "uart.h"
#include "movement.h"
#include "open_interface.h"
#include <stdint.h>
#include <stdbool.h>
#include <inc/tm4c123gh6pm.h>
#include "driverlib/interrupt.h"

/**
 * main.c
 */
void main(void)
{
    timer_init();
    lcd_init();
    uart_init();

    oi_t *sensor_data = oi_alloc();
    oi_init(sensor_data);

    char my_data;       // Variable to get bytes from Client
    char command[100];  // Buffer to store command from Client
    int index = 0;      // Index position within the command buffer
    int IR_FL = 2000;
    int IR_FR = 2000;
    int IR_L = 2000;
    int IR_R = 2000;


    while(1)
    {
        index = 0;
        my_data = uart_receive();


        while(my_data != '\n')
        {
            command[index] = my_data;
            index++;
            my_data = uart_receive();
        }

        command[index] = '\n';
        command[index + 1] = 0;

        if (command[0] == 'W')
        {
            oi_setWheels(100, 100);
            while(((IR_FL < 2600) && (IR_FL > 125)) && ((IR_FR < 2600) && (IR_FR > 125)) && ((IR_L < 2600) && (IR_L > 125)) && ((IR_R < 2600) && (IR_R > 125)))
            {
                oi_update(sensor_data);
                IR_FL = sensor_data->cliffFrontLeftSignal;
                IR_FR = sensor_data->cliffFrontRightSignal;
                IR_L = sensor_data->cliffLeftSignal;
                IR_R = sensor_data->cliffRightSignal;
                lcd_printf("%d", IR_FL);
                timer_waitMillis(200);
                if ((IR_FL > 2600) || (IR_FR > 2600) || (IR_L > 2600) || (IR_R > 2600))
                {
                    oi_setWheels(0,0);
                    IR_FL = 2000;//Back off and reset
                    IR_FR = 2000;
                    IR_L = 2000;
                    IR_R = 2000;
                    break;
                }
                else if ((IR_FL < 125) || (IR_FR < 125) || (IR_L < 125) || (IR_R < 125))
                {
                    oi_setWheels(0,0);
                    IR_FL = 2000;//Back off and reset
                    IR_FR = 2000;
                    IR_L = 2000;
                    IR_R = 2000;
                    break;
                }
            }
        }
        else if (command[0] == 'A')
        {
            oi_setWheels(100, -100);
            while(((IR_FL < 2600) && (IR_FL > 125)) && ((IR_FR < 2600) && (IR_FR > 125)) && ((IR_L < 2600) && (IR_L > 125)) && ((IR_R < 2600) && (IR_R > 125)))
            {
                oi_update(sensor_data);
                IR_FL = sensor_data->cliffFrontLeftSignal;
                IR_FR = sensor_data->cliffFrontRightSignal;
                IR_L = sensor_data->cliffLeftSignal;
                IR_R = sensor_data->cliffRightSignal;
                lcd_printf("%d", IR_FL);
                timer_waitMillis(200);
                if ((IR_FL > 2600) || (IR_FR > 2600) || (IR_L > 2600) || (IR_R > 2600))
                {
                    oi_setWheels(0,0);
                    IR_FL = 2000;//Back off and reset
                    IR_FR = 2000;
                    IR_L = 2000;
                    IR_R = 2000;
                    break;
                }
                else if ((IR_FL < 125) || (IR_FR < 125) || (IR_L < 125) || (IR_R < 125))
                {
                    oi_setWheels(0,0);
                    IR_FL = 2000;//Back off and reset
                    IR_FR = 2000;
                    IR_L = 2000;
                    IR_R = 2000;
                    break;
                }
            }
        }
        else if (command[0] == 'D')
        {
            oi_setWheels(-100, 100);
            while(((IR_FL < 2600) && (IR_FL > 125)) && ((IR_FR < 2600) && (IR_FR > 125)) && ((IR_L < 2600) && (IR_L > 125)) && ((IR_R < 2600) && (IR_R > 125)))
            {
                oi_update(sensor_data);
                IR_FL = sensor_data->cliffFrontLeftSignal;
                IR_FR = sensor_data->cliffFrontRightSignal;
                IR_L = sensor_data->cliffLeftSignal;
                IR_R = sensor_data->cliffRightSignal;
                lcd_printf("%d", IR_FL);
                timer_waitMillis(200);
                if ((IR_FL > 2600) || (IR_FR > 2600) || (IR_L > 2600) || (IR_R > 2600))
                {
                    oi_setWheels(0,0);
                    IR_FL = 2000;//Back off and reset
                    IR_FR = 2000;
                    IR_L = 2000;
                    IR_R = 2000;
                    break;
                }
                else if ((IR_FL < 125) || (IR_FR < 125) || (IR_L < 125) || (IR_R < 125))
                {
                    oi_setWheels(0,0);
                    IR_FL = 2000;//Back off and reset
                    IR_FR = 2000;
                    IR_L = 2000;
                    IR_R = 2000;
                    break;
                }
            }
        }
        uart_sendChar(command[0]);

        if(command[0] != '\n')
        {
            uart_sendChar('\n');
        }
    }
}
