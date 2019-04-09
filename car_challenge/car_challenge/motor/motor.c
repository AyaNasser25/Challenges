/*
 * motor.c
 *
 * Created: 3/2/2019 10:49:56 PM
 *  Author: AVE-LAP-023
 */ 
#include "../includes/motor.h"
#include "../includes/motor_cfg.h"
#include "../includes/CommonNumbers.h"

/********************************************************************************************************/
/* Function name :- MOTOR_turnOn                                                                        */
/* Function job :-turn otor on                                                                          */
/* Function inputs :-direction of rotation and motor number                                             */
/* Function outputs :- N/A                                                                              */
/********************************************************************************************************/

void MOTOR_turnOn(uint8 direction,uint8 motor_num)
{
	
	switch(motor_num){
		case NUM_1 :
		/* set direction pins of motors to be output */
		DIO_SetPinDirection(MOTORA_PIN1,OUT);
		DIO_SetPinDirection(MOTORA_PIN2,OUT);
		switch(direction)
		{
			case FORWARD :
			/* turn them off first */
			DIO_WritePin(MOTORA_PIN1,LOW);
			DIO_WritePin(MOTORA_PIN2,LOW);
			/* then set pin 1 to high and pin 2 to zero to be forward */
			DIO_WritePin(MOTORA_PIN1,HIGH);
			DIO_WritePin(MOTORA_PIN2,LOW);
			
			break ;
			case BACKWARD :
			/* turn motor off first */
			DIO_WritePin(MOTORA_PIN1,LOW);
			DIO_WritePin(MOTORA_PIN2,LOW);
			/* then set pin 2 to high and pin 1 to zero to be backword */
			
			DIO_WritePin(MOTORA_PIN1,LOW);
			DIO_WritePin(MOTORA_PIN2,HIGH);
			
			break ;
			
		}
		break;
		/* motor 2 */
		case  NUM_2 :
			/* set direction pins of motors to be output */
		DIO_SetPinDirection(MOTORB_PIN1,OUT);
		DIO_SetPinDirection(MOTORB_PIN2,OUT);
		
		switch(direction)
		{
			case FORWARD :
			/* turn them off first */
			DIO_WritePin(MOTORB_PIN1,LOW);
			DIO_WritePin(MOTORB_PIN2,LOW);
			/* then set pin 1 to high and pin 2 to zero to be forward */
			DIO_WritePin(MOTORB_PIN1,HIGH);
			DIO_WritePin(MOTORB_PIN2,LOW);
			break ;
			case BACKWARD :
			/* turn motor off first */
			DIO_WritePin(MOTORB_PIN1,LOW);
			DIO_WritePin(MOTORB_PIN2,LOW);
			
				/* then set pin 2 to high and pin 1 to zero to be backword */
			DIO_WritePin(MOTORB_PIN1,LOW);
			DIO_WritePin(MOTORB_PIN2,HIGH);
			break ;
			
		}

          break;
	}
}
	
/********************************************************************************************************/
/* Function name :- MOTOR_turnOff                                                                       */
/* Function job :-turn motor off                                                                        */
/* Function inputs :- motor number                                                                      */
/* Function outputs :- N/A                                                                              */
/********************************************************************************************************/

void MOTOR_turnOff(uint8 motor_num)
{
		/* write zero to all pins */
		switch (motor_num){
		case NUM_1 :
		DIO_WritePin(MOTORA_PIN1,LOW);
		DIO_WritePin(MOTORA_PIN2,LOW);
		break ;
		case NUM_2 :
		DIO_WritePin(MOTORB_PIN1,LOW);
		DIO_WritePin(MOTORB_PIN2,LOW);
		break ;
	    }
	
}