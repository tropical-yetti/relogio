#ifndef TIMER_H_DEFINED
#difine	TIMER_H_DEFINED

volatile long timerTickAcc;
volatile const float timerTick_baseSec = 0.01; // 10ms.


void timer_init()
{	
	TCCR1A = 0;
	TCCR1B |= (1 << WGM12)|(1 << CS11)|(1 << CS10);	// set up timer with prescaler = 64 and CTC mode
	TIMSK1 |= (1 << OCIE1A);		// enable compare interrupt
	OCR1A = 2499;	// initialize compare value: (16MHZ/64)*0.01seg
	TCNT1 = 0;	// initialize counter

	sei();

	timerTickAcc = 0;
}

long setTimerSec (long duration)
{
	ticks = (long) ((float)(duration / timerTick_baseSec)) + timerTickAcc;
}

void isTimer (long dTick)
{
	timerFlag = FALSE;
	if (timerTickAcc >= dTick)
	{
		timerFlag = TRUE;
	}
	return(timerFlag);
}

timerHandler()
{
	timer_tick++;
}

#endif