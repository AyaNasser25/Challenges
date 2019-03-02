/*
 * interrupt.c
 *
 * Created: 3/2/2019 11:38:31 AM
 *  Author: AVE-LAP-023
 */ 

#include "../Includes/interrupt.h"

volatile uint8 g_flag_int2 ; /* global flag that indicate interrupt has occurred */

/*********************************************************************************************************/
/* Function name :- INT2_init                                                                           */
/* Function job :- initializing external interrupt 2                                                    */
/* Function inputs :- N/A                                                                               */
/* Function outputs :- N/A                                                                              */
/*********************************************************************************************************/
void INT2_init(void)
{
	/* declaring pb2 as input pin */
	DIO_SetPinDirection(10,LOW);
	DIO_WritePin(10,HIGH);
	/* enable module interrupt */
	Set_Bit(GICR,INT2);
	/* rising edge will activate interrupt */
	Set_Bit(MCUCSR,ISC2);
	//SREG |= (1<<7);
	sei();
}

/*********************************************************************************************************/
/* Function name :- ISR(INT2_vect)                                                                       */
/* Function job :- writing isr code for interrupt 2                                                      */
/* Function inputs :- N/A                                                                                */
/* Function outputs :- N/A                                                                               */
/*********************************************************************************************************/
ISR(INT2_vect)
{
	g_flag_int2 ++;
	
	
}