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
			if( (TimerTickAcc >= buzz_delay) && (buzzCounter<=3) )
			{
				BUZZ_PORT ^= (1<<BUZZ_PIN);
				buzz_delay = setTimerSec((10^((buzzCounter+1)%2))*0.05);
				buzzCounter++;
			} else if (buzzCounter>3) {
				roundState = 2;	
				precount_delay = setTimerSec(1);
				precount_couter=10;
			}			
			break;
			
		case 2:
			// PRECOUNT
			if( (TimerTickAcc >= precount_delay) && (precount_couter>=0) )
			{	
				precount_delay = setTimerSec(1);
				display.print(precount_couter);
				precount_couter--;
				
			} else if(precount_couter<0)
			{
				roundState = 3;
				controlFlag = 0;
				count_delay = setTimerSec(0.8);
				counter_counter(240);
			}
			break;
		case 3:
			//COUNT
			if(controlFlag == 0)
			{
				GLED_PORT != (1<<GLED_PIN);
				BUZZ_PORT != (1<<BUZZ_PIN);
				display.print(counter_counter)
				if (TimerTickAcc>=count_delay)
				{
					controlFlag = 1;
					BUZZ_PORT &= ~(1<<BUZZ_PIN);
				}
				
			} else if(TimerTickAcc >= count_delay)
			{
				// controlFlag = 1;
				display.print(counter_counter)
			}
			
			
			break;
	}