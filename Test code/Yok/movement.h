/*
 * lcd.h
 *
 *  Created on: Mar 1, 2016
 *      Author: nbergman
 */
#include "open_interface.h"

double move_forward(oi_t *sensor, int cm);

double move_backward(oi_t *sensor, int cm);

void turn_clockwise(oi_t *sensor, int degree);

void turn_counterclockwise(oi_t *sensor, int degree);

//void collisionBumpRight(oi_t *sensor);
//
//void collisionBumpLeft(oi_t *sensor);
