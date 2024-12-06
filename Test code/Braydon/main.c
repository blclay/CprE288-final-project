

/**
 * main.c
 */

#include "open_interface.h"
#include "Timer.h"
#include <stdio.h>
#include <math.h>
#include "movement.h"
//#include "uart_extra_help.h"
#include <stdlib.h>
#include <inc/tm4c123gh6pm.h>


int main(void)
{

    oi_t *sensor_data = oi_alloc();
    oi_init(sensor_data);

    move_forward_go_around(sensor_data, 10000);

    oi_free(sensor_data);
    return 0;
}
