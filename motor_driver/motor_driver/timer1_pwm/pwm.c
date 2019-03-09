/*
 * pwm.c
 *
 * Created: 3/2/2019 7:12:25 PM
 *  Author: AVE-LAP-023
 */ 

#include "../Includes/pwm.h"
/********************************************************************************************************/
/* Function name :- PWM_init                                                                            */
/* Function job :- initializing pwm module in timer 1                                                   */
/* Function inputs :- duty_cycle_value                                                                  */
/* Function outputs :- N/A                                                                              */
/********************************************************************************************************/
void PWM_init(uint16 duty_cycle,uint16 freq)
{
	
	uint16 TOP = F_CPU/(TWO*freq);
	TCNT1 = FALSE;
	OCR1A = TOP-((duty_cycle*((TOP+HIGH))/num_100)) ;
	OCR1B = TOP-((duty_cycle*((TOP+HIGH))/num_100)) ;
	ICR1 = TOP;
	/* non inverting mode */
	Set_Bit(TCCR1A,COM1A1);
	Set_Bit(TCCR1A,COM1B1);
	/* phase correct mode */
	
	Set_Bit(TCCR1A,WGM11);
	Set_Bit(TCCR1B,WGM13);
	/* no prescaler */
	Set_Bit(TCCR1B,CS10);
	/* set direction of ocs pins */
	DIO_SetPinDirection(OCA,HIGH);
	DIO_SetPinDirection(OCB,HIGH);
	
}