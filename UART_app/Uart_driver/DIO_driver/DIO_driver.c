/*
 * DIO_driver.c
 *
 * Created: 2/13/2019 2:17:30 PM
 *  Author: AVE-LAP-023
 */ 

#include "../Includes/DIO_driver.h"


/********************************************************************************************************
* Function name :- DIO_WritePin                                                                         *
* function job :- write value in port if micro controller                                               *
* function arguments :- pin number and the value written to it                                          *
* function return :-            N/A                                                                     *
********************************************************************************************************/


void DIO_WritePin(uint8 PinNum,uint8 PinValue){
	/* according to pin number calculate the corresponding port to write in */
	if(PinNum >= PORTA_START && PinNum <=PORTA_END){
		switch(PinValue){
			case 1 : Set_Bit(PORTA,PinNum);
			break;
			case 0 : Clear_Bit(PORTA,PinNum);
			break;
			default :
			break ;
		}
	}
	else if(PinNum >= PORTB_START && PinNum <= PORTB_END){
		switch(PinValue){
			case 1 : Set_Bit(PORTB,(PinNum-PORTB_START));
			break;
			case 0 : Clear_Bit(PORTB,(PinNum-PORTB_START));
			break;
			default :
			break ;
		}
	}
	else if(PinNum >= PORTC_START && PinNum <= PORTC_END){
		switch(PinValue){
			case HIGH : Set_Bit(PORTC,(PinNum-PORTC_START));
			break;
			case LOW : Clear_Bit(PORTC,(PinNum-PORTC_START));
			break;
			default :
			break ;
		}
	}
	else if(PinNum >= PORTD_START && PinNum <= PORTD_END){
		switch(PinValue){
			case HIGH : Set_Bit(PORTD,(PinNum- PORTD_START));
			break;
			case LOW : Clear_Bit(PORTD,(PinNum-PORTD_START));
			break;
			default :
			break ;
		}
	}
}
/********************************************************************************************************
* Function name :- DIO_ReadPin                                                                          *
* function job :- Read value from pin of micro controller                                               *
* function arguments :- pin number                                                                      *
* function return :-            N/A                                                                     *
********************************************************************************************************/
uint8 DIO_ReadPin(uint8 PinNum){
	/* according to pin number calculate the corresponding port to read from */
	if(PinNum >=PORTA_START && PinNum <=PORTA_END){
		return (Get_Bit(PINA,PinNum));
	}
	else if(PinNum >=PORTB_START && PinNum <=PORTB_END){
		return (Get_Bit(PINB,(PinNum-PORTB_START)));
	}
	else if(PinNum >=PORTC_START && PinNum <=PORTC_END){
		return (Get_Bit(PINC,(PinNum-PORTC_START)));
	}
	else if(PinNum >=PORTD_START && PinNum <=PORTD_END){
		return (Get_Bit(PIND,(PinNum-PORTD_START)));
	}
	return FALSE;
}
/********************************************************************************************************
* Function name :- DIO_SetPinDirection                                                                  *
* function job :- determine direction of specified pin                                                  *
* function arguments :- pin number and desired direction (I/O)                                          *
* function return :-            N/A                                                                     *
*********************************************************************************************************/
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection){
	/* according to pin number calculate the corresponding port to set its direction */
	if(PinNum >=PORTA_START && PinNum <=PORTA_END){
		switch(PinDirection){
			case HIGH : Set_Bit(DDRA,PinNum);
			break;
			case LOW : Clear_Bit(DDRA,PinNum);
			break;
			default :
			break ;
		}
	}
	else if(PinNum >=PORTB_START && PinNum <=PORTB_END){
		switch(PinDirection){
			case HIGH : Set_Bit(DDRB,(PinNum-PORTB_START));
			break;
			case LOW : Clear_Bit(DDRB,(PinNum-PORTB_START));
			break;
			default :
			break ;
		}
	}
	else if(PinNum >=PORTC_START && PinNum <=PORTC_END){
		switch(PinDirection){
			case HIGH : Set_Bit(DDRC,(PinNum-PORTC_START));
			break;
			case LOW : Clear_Bit(DDRC,(PinNum-PORTC_START));
			break;
			default :
			break ;
		}
	}
	else if(PinNum >=PORTD_START && PinNum <=PORTD_END){
		switch(PinDirection){
			case HIGH : Set_Bit(DDRD,(PinNum-PORTD_START));
			break;
			case LOW : Clear_Bit(DDRD,(PinNum-PORTD_START));
			break;
			default :
			break ;
		}
	}
}
/********************************************************************************************************
* Function name :- DIO_togglePin                                                                        *
* function job :- toggle desired pin                                                                    *
* function arguments :- pin number and the value written to it                                          *
* function return :-            N/A                                                                     *
*********************************************************************************************************/
void DIO_togglePin(uint8 PinNum){
	/* according to pin number calculate the corresponding port to toggle  */
	if(PinNum >= PORTA_START && PinNum <= PORTA_END){
		Togle_Bit(PORTA,PinNum);
	}
	else if(PinNum >=PORTB_START && PinNum <=PORTB_END){
		Togle_Bit(PORTB,(PinNum-PORTB_START));
	}
	else if(PinNum >= PORTC_START && PinNum <=PORTC_END){
		Togle_Bit(PORTC,(PinNum-PORTC_START));
	}
	else if(PinNum >=PORTD_START && PinNum <=PORTD_END){
		Togle_Bit(PIND,(PinNum-PORTD_START));
	}
}
