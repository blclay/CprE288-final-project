

/**
 * main.c
 */

#include "open_interface.h"
#include "Timer.h"
#include <stdio.h>
#include <math.h>
#include "movement.h"
#include "uart_extra_help.h"
#include <stdlib.h>
#include <inc/tm4c123gh6pm.h>


int main(void)
{

    oi_t *sensor_data = oi_alloc;



     move_forward_go_around(oi_t *sensor, 100);

     move_forward(oi_t *sensor, 100);

     move_backwards(oi_t *sensor, 100);

     turn_clockwise(oi_t *sensor, 90);

     turn_cclockwise(oi_t *sensor, 90);

    return 0;
}
