#include "music.h"
#include "open_interface.h"
#include "timer.h"
#include "lcd.h"


/**
 * main.c
 */


int main(void)
{

    oi_t* sensor = oi_alloc();
    oi_init(sensor);
    load_delivery_sound();
    timer_waitMillis(10000);
    load_warning_sound();


	return 0;
}
