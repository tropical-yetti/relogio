#include "timer.h"
#include "roundstatemachine.h"

void setup()
{
	timer_init();
}



void loop() {
	
}



ISR(TIMER1_COMPA_vect) 
{
	timerHandler();
}