#ifndef PING_H_
#define PING_H_

void ping_init(void);

int ping_read(void);

void send_Pulse(void);

void TIMER3B_Interrupt_Handler(void);


#endif
