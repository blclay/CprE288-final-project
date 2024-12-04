#ifndef SERVO_H_
#define SERVO_H_


volatile signed pulse_width;


void servo_init(void);

void servo_move(float);



#endif /* SERVO_H_ */
