#include "roundstatemachine.h"
#include "timer.h"



#define RLED_PORT 	PORTB
#define RLED_PIN	7
#define GLED_PORT 	PORTB
#define GLED_PIN	7

#define BUZZ_PORT	PORTC
#define BUZZ_PIN	3


unsigned char roundState, startFlag, flashCounter, buzzCounter;
long rLed_delay, buzz_delay;

static void modeClub(void):
	switch(roundState)
	{
		case 0:
			//Aguarda flag START
			if(startFlag == HIGH)
			{
				buzz_delay = setTimerSec(0.5)
				roundState = 1;
				flashCounter = 0;
			}
			break;
			
		case 1:
			//BEEP BEEP
			if( (TimerTickAcc >= buzz_delay) && (buzzCounter<2) )
			{
				BUZZ_PORT ^= (1<<BUZZ_PIN);
				buzz_delay = setTimerSec(0.05)
			}
		
			rLedPeriod = setTimerSec(0.5);
			break;
			
		case 2:
			// PRECOUNT
			if( (TimerTickAcc >= RLED_period) && (flashCounter<10) )
			{
				flashCounter++;
				PORTLED ^= (1<<PINLED);
			} else if(flashCounter=>10)
			{
				gLedPeriod = 
			}
			break;
		case 3:
			//COUNT
			
			
			break;
	}