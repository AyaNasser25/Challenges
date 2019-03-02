/*
 * timer_interrupt.c
 *
 * Created: 3/1/2019 3:32:16 PM
 * Author : AVE-LAP-023
 */ 

#include "../Includes/timer.h"
#include "../Includes/interrupt.h"
#include <util/delay.h>


extern volatile uint8 g_flag_int2   ;
extern volatile uint8 g_flag ;

int main(void)
{
    DIO_SetPinDirection(led0,HIGH);
	DIO_SetPinDirection(led1,HIGH);
	DIO_SetPinDirection(led2,HIGH);
	timer_init(OCR_1ms);
	INT2_init();
	
	
	
    while (TRUE) 
    {
		DIO_WritePin(led0,HIGH);
		
		while(! (g_flag == FALSE) );
		g_flag = FALSE;		
		DIO_WritePin(led0,LOW);
		DIO_WritePin(led2,HIGH);
		while(! (g_flag == FALSE));
		g_flag = FALSE;
		
		DIO_WritePin(led2,LOW);
		DIO_WritePin(led1,HIGH);
		while( ! (g_flag == FALSE));
		g_flag = FALSE;
		
		DIO_WritePin(led1,LOW);
		/* this when bush button is pressed turn on stop led and wait a sec then return  */
		if(g_flag_int2 == TRUE){
			DIO_WritePin(led2,HIGH);
			DIO_WritePin(led1,LOW);
			DIO_WritePin(led0,LOW);
          while( ! (g_flag == FALSE));
           g_flag = FALSE;
			g_flag_int2 = FALSE;
		}
		
    }
}

