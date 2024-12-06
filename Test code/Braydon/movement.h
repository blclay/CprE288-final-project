
#include "open_interface.h"
#include "Timer.h"
#include <stdio.h>
#include "uart_extra_help.h"

void move_forward(oi_t *sensor, int millimeters);
void move_backwards(oi_t *sensor, int millimeters);
void turn_clockwise(oi_t *sensor, int degrees);
void turn_cclockwise(oi_t *sensor, int degrees);
void move_forward_go_around(oi_t *sensor, int millimeters);


/*double move_until_bump(oi_t *sensor, int max_cm)
{
    double dist_travelled = 0;
    oi_setWheels(150, 150); // move forward; full speed

    while(!sensor->bumpLeft && !sensor->bumpRight && abs(dist_travelled) < max_cm)
    {
        oi_update(sensor);
        dist_travelled += sensor->distance/10.0;

        if(flag)
        {
            flag = 0;
            if((char)uart_data == 't')
            {
                break;
            }
        }

        if(sensor->bumpLeft)
            uart_sendChar('L');

        if(sensor->bumpRight)
            uart_sendChar('R');



    }
    oi_setWheels(0, 0);
    return dist_travelled;
} */

bool hasBumpedLeft(oi_t *sensor);


bool hasBumpedRight(oi_t *sensor);

