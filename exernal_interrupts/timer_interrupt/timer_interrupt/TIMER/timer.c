/*
 * CFile1.c
 *
 * Created: 2/13/2019 3:57:20 PM
 *  Author: AVE-LAP-023
 */ 

#include "../Includes/timer.h"

volatile uint8 g_flag;

/*********************************************************************************************************/
/* Function name :- Timer_init                                                                           */
/* Function job :- initializing the timer module                                                         */
/* Function inputs :- OCR value                                                                          */
/* Function outputs :- N/A                                                                               */
/*********************************************************************************************************/

void timer_init(uint8 OCR_value)
{
	/* FRC0 = 1 & CTC MODE IS ON & PRECSACLE 64 & interrupt enable*/
	Set_Bit(TIMSK,OCIE0);
	TCCR0 |= (TRUE<<FOC0) | (TRUE<<WGM01) |(TRUE<<CS00) | (TRUE<<CS01);
	TCNT0 = FALSE;
	OCR0 = OCR_value;
	sei();
}



ISR(TIMER0_COMP_vect)
{
	g_flag ++ ;
}

