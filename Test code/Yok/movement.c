/**
 * lcd.c: Functions for displaying content on the 4x16 Character LCD Screen.
 * Updated on 8/22/18 for compatibility with Isaac Rex's timer fixes.  
 *
 *  @author Noah Bergman, Eric Middleton
 *  @date 02/29/2016
 *
 *
 */
// phjones: Note typo??, above was updated on 9/22/2019 not 2018, correct???

#include "open_interface.h"
#include "movement.h"

double move_forward(oi_t *sensor, int cm)
{
    double sum = 0;
    oi_setWheels(150, 150);
    while (sum < cm * 10){
        if(sensor->bumpLeft || sensor->bumpRight)
        {
            return sum;
        }
        oi_update(sensor);
        sum += sensor->distance;
    }
    oi_setWheels(0, 0);  //stop
    return sum;
}

double move_backward(oi_t *sensor, int cm)
{
    double sum = cm * 10;
    oi_setWheels(-150, -150);
    while(sum > 0)
    {
        oi_update(sensor);
        sum += sensor->distance;
    }
    oi_setWheels(0,0);
    return sum;
}

void turn_clockwise(oi_t *sensor, int degree)
{
    double ang = 0;
    //double sens_ang = sensor->angle;
    oi_setWheels(-150, 150);
    while(ang > -degree)
    {
        oi_update(sensor);
        ang += sensor->angle;
    }
    oi_setWheels(0, 0);  //stop


//    oi_setWheels(-300, 300);
//    turn_clockwise(sensor, -67);
//    oi_setWheels(0,0);
}

void turn_counterclockwise(oi_t *sensor, int degree)
{
    double ang = 0;
    //double sens_ang = sensor->angle;
    oi_setWheels(150, -150);
    while(ang < degree)
    {
        oi_update(sensor);
        ang += sensor->angle;
    }
    oi_setWheels(0, 0);  //stop


//    oi_setWheels(-300, 300);
//    turn_clockwise(sensor, -67);
//    oi_setWheels(0,0);
}


//void collisionBumpRight(oi_t *sensor)
//{
//    //Move Backward
//    oi_setWheels(-500,-500);
//    oi_moveBack(sensor, 15);
//    oi_setWheels(0,0);
//
//    //Turn CounterClockwise 90 deg
//    oi_setWheels(300,-300);
//    oi_turncounterClockwise(sensor, 71.5);
//    oi_setWheels(0,0);
//
//    //Move Forward
//    oi_setWheels(500,500);
//    move_forward(sensor, 25);
//    oi_setWheels(0,0);
//
//    //Turn Clockwise 90 deg
//      oi_setWheels(-300,300);
//      oi_turncounterClockwise(sensor, -71.5);
//      oi_setWheels(0,0);
//}



/*void collisionBumpLeft(oi_t *sensor)
{
    //Move Backward
    oi_setWheels(-500,-500);
    oi_moveBack(sensor, 15);
    oi_setWheels(0,0);

    //Turn CounterClockwise 90 deg
    oi_setWheels(300,-300);
    oi_turncounterClockwise(sensor, 71.5);
    oi_setWheels(0,0);

    //Move Forward
    oi_setWheels(500,500);
    move_forward(sensor, 25);
    oi_setWheels(0,0);

    //Turn Clockwise 90 deg
      oi_setWheels(-300,300);
      oi_turncounterClockwise(sensor, -71.5);
      oi_setWheels(0,0);
}*/
