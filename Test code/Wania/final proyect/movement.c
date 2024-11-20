#include "open_interface.h"
#include "Timer.h"
//#include "cyBot_Scan.h"
#include <stdio.h>
#include <math.h>
#include "movement.h"
#include "uart_extra_help.h"
//#include "adc.h"
//#include "servo.h"
//#include "ping.h"
#include <stdio.h>
#include <stdlib.h>
#include "Timer.h"
//#include "servo.h"
//#include "lcd.h"
//#include "button.h"
#include <inc/tm4c123gh6pm.h>

//volatile  char uart_data;  // Your UART interupt code can place read data here
//volatile  char flag;       // Your UART interupt can update this flag

typedef struct autostruct
{
    int minAngle;
    float objDist;
}autostruct_t;

typedef struct{
    float sound_dist;  // Distance from Ping Sensor (cyBOT_Scan returns -1.0 if PING is not enabled)
    int IR_raw_val;    // Raw ADC value from IR sensor (cyBOT_Scan return -1 if IR is not enabled)
} cyBOT_Scan_t;

void move_forward_go_around(oi_t *sensor, int millimeters){

     double sum = 0;
     oi_setWheels(250, 250); // move forward; full speed

     while (sum < millimeters) {
     oi_update(sensor);
     sum += sensor->distance;
     if(sensor->cliffLeft){
         move_backwards(sensor, 150);
         sum -= 10;
         turn_clockwise(sensor, 300);
         move_forward(sensor, 100);
         turn_cclockwise(sensor, 250);
         move_forward(sensor, 450);
         turn_cclockwise(sensor, 250);
         oi_setWheels(150, 150);
         }
     if(sensor->cliffFrontLeft){
             move_backwards(sensor, 150);
             sum -= 10;
             turn_clockwise(sensor, 300);
             move_forward(sensor, 100);
             turn_cclockwise(sensor, 250);
             move_forward(sensor, 450);
             turn_cclockwise(sensor, 250);
             oi_setWheels(150, 150);
             }
     if(sensor->cliffRight){
         move_backwards(sensor, 150);
         sum -= 10;
         turn_cclockwise(sensor, 300);
         move_forward(sensor,100);
         turn_clockwise(sensor, 250);
         move_forward(sensor, 450);
         turn_clockwise(sensor, 250);
         oi_setWheels(150, 150);
         }
     if(sensor->cliffFrontRight){
             move_backwards(sensor, 150);
             sum -= 10;
             turn_clockwise(sensor, 300);
             move_forward(sensor, 100);
             turn_cclockwise(sensor, 250);
             move_forward(sensor, 450);
             turn_cclockwise(sensor, 250);
             oi_setWheels(150, 150);
             }
     }
     oi_setWheels(0, 0); // stop
}

void move_forward(oi_t *sensor, int millimeters){

     double sum = 0;
     oi_setWheels(250, 250); // move forward; full speed

     while (sum < millimeters) {
     oi_update(sensor);
     sum += sensor->distance;
     if(sensor->bumpLeft){
         move_backwards(sensor, 150);
         sum -= 30;
         turn_clockwise(sensor, 250);
         move_forward(sensor, 250);
         turn_cclockwise(sensor, 250);
         oi_setWheels(250,250);
         }
     if(sensor->bumpRight){
         move_backwards(sensor, 150);
         sum -= 30;
         turn_cclockwise(sensor, 250);
         move_forward(sensor, 250);
         turn_clockwise(sensor, 250);
         oi_setWheels(250,250);
         }
     }
     oi_setWheels(0, 0); // stop
}
void move_backwards(oi_t *sensor, int millimeters){

     double sum = 0;
     oi_setWheels(-250, -250); // move back; full speed

     while (sum > -millimeters) {
     oi_update(sensor);
     sum += sensor->distance;
     }
     oi_setWheels(0, 0); // stop
}

void turn_clockwise(oi_t *sensor, int degrees){

    double angle = 0;
    oi_setWheels(-250, 250);
    while (angle > -degrees) {
    oi_update(sensor);
    angle += (sensor->angle / 0.324056);
    }
    oi_setWheels(0, 0); // stop
}
void turn_cclockwise(oi_t *sensor, int degrees){

    double angle = 0;
    oi_setWheels(250, -250);
    while (angle < degrees) {
    oi_update(sensor);
    angle += (sensor->angle / 0.324056);
    }
    oi_setWheels(0, 0); // stop
}


