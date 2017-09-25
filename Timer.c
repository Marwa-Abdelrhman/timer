/*
 * Timer.c
 *
 * Created: May04,2017 3:05:10 PM
 *  Author: Marwa
 */ 

#include "Timer.h"



void TIMER_OVF_Mode(void)
{
	/* initial value*/
	TCNT0=0;
	/*
	* F-micro=8MHz
	* Non PWM mode FOC0
	* prescaler=1024 CS00,CS02
	*/
	TCCR0|=(1<<FOC0)|(1<<CS00)|(1<<CS02);
	/**Timer Overflow Interrupt Enable*/
	TIMSK=(1<<TOIE0);
}


void TIMER_CTC_Mode(uint8 Ticks)

{
	/* initial value*/
	TCNT0=0;
	/*compare value*/
	OCR0=Ticks; 
	/*pin to generate clk*/
	DDRB|=(1<<PB3); 
	/* 
	* F-micro=8MHz
	* Non PWM mode FOC0
	* prescaler=1024 CS00,CS02
	* force output compare WGM01
	*/
	TCCR0|=(1<<FOC0)|(1<<WGM01)|(1<<CS00)|(1<<CS02);
	/*Output Compare Match Interrupt Enable*/
	TIMSK=(1<<OCIE0);
}
	



void TIMER_PWM_Mode(uint8 set_duty_cycle)

{
	/* initial value*/
	TCNT0=0;
	
	OCR0=set_duty_cycle;
	
	/* pin to generate clk*/
	DDRB|=(1<<PB3);
	
	/*
	* F-micro=8MHz
	* N prescaler=64 CS00,CS01
	* fast PWM mode WGM01
	* Non_inverting mode COM01
	*/
	TCCR0=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS01)|(1<<CS00);
	
}

