/*
 * lcd.c
 *
 * Created: 3/1/2019 11:04:13 AM
 *  Author: AVE-LAP-023
 */ 
#include "../INCLUDES/lcd.h"

/***********************************************************************************************************/
/* Function name :- LCD_init                                                                               */
/* Function job :- initializing LCD                                                                        */
/* Function inputs :- N/A                                                                                  */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/




void LCD_init(void)
{
	/* setting the lcd pins direction to be outputs */
	DIO_SetPinDirection(RS,HIGH);
	DIO_SetPinDirection(RW,HIGH);
	DIO_SetPinDirection(E,HIGH);
	/* choosing lcd operating mode to be 4 or 8 bit mode */
	/* if the selected mode is 4 bit mode select which 4 pins in the data direction */
	 #ifdef FOUR_BIT_MODE 
	#ifdef UPPER_PINS
	/* set direction of upper pins */
	DIO_SetPinDirection(PIN_4,HIGH);
	DIO_SetPinDirection(PIN_5,HIGH);
	DIO_SetPinDirection(PIN_6,HIGH);
	DIO_SetPinDirection(PIN_7,HIGH);

	#else 
	/* set direction of lower pins */
	DIO_SetPinDirection(PIN_0,HIGH);
	DIO_SetPinDirection(PIN_1,HIGH);
	DIO_SetPinDirection(PIN_2,HIGH);
	DIO_SetPinDirection(PIN_3,HIGH);
	#endif
	/* send 4 bit mode command */
	LCD_sendCommand(FOUR_BIT);
	/* or choosing 8 bit mode */
	#else
	/* set direction of eight pins */
	DIO_SetPinDirection(PIN_0,HIGH);
	DIO_SetPinDirection(PIN_1,HIGH);
	DIO_SetPinDirection(PIN_2,HIGH);
	DIO_SetPinDirection(PIN_3,HIGH);
	DIO_SetPinDirection(PIN_4,HIGH);
	DIO_SetPinDirection(PIN_5,HIGH);
	DIO_SetPinDirection(PIN_6,HIGH);
	DIO_SetPinDirection(PIN_7,HIGH);
	/* send command of eghit bit mode */
	LCD_sendCommand(EGHIT_BIT_MODE);
	
	#endif 
	       
		/* set cursor to be off then clear screen */
            LCD_sendCommand(CURSOR_OFF);
        	LCD_sendCommand(CLEAR_SCREEN);
	

}

	
/***********************************************************************************************************/
/* Function name :- LCD_sendCommand                                                                        */
/* Function job :-sending a specific command to lcd                                                        */
/* Function inputs :-selected command                                                                      */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/
void LCD_sendCommand(uint8 command)
{
	
 /* begin sequence of sending as data sheet 
   1- rs = 0 to write a command
   2- rw = 0 to write on lcd 
   3- wait for 1 mel second 
   4- e = 1 make enable pin high
   5- sending command in its desired mode
    */
   
	DIO_WritePin(RS,LOW);
	DIO_WritePin(RW,LOW);
	_delay_ms(ONE);
	DIO_WritePin(E,HIGH);
	_delay_ms(ONE);
	/* sending command to lcd choosing between 4 or 8 bit mode  */
	
	#ifdef FOUR_BIT_MODE
	/* send data on the desired pins upper or lower */
	#ifdef UPPER_PINS
	/* taking last 4 bits first then the other  */
	DIO_WritePin(PIN_4 ,(Get_Bit(command,PIN_4)>>PIN_4));
	DIO_WritePin(PIN_5,(Get_Bit(command,PIN_5)>>PIN_5));
	DIO_WritePin(PIN_6,(Get_Bit(command,PIN_6)>>PIN_6));
	DIO_WritePin(PIN_7,(Get_Bit(command,PIN_7)>>PIN_7));
	
	#else
	/* sending command to lower pins */
	DIO_WritePin(PIN_0 ,(Get_Bit(command,PIN_4)>>PIN_4));
	DIO_WritePin(PIN_1,(Get_Bit(command,PIN_5)>>PIN_5));
	DIO_WritePin(PIN_2,(Get_Bit(command,PIN_6)>>PIN_6));
	DIO_WritePin(PIN_3,(Get_Bit(command,PIN_7)>>PIN_7));
    #endif
	/* complete the sequence 
	6- wait for 1 mel second
	7- e = 0 set enable pin to low 
	*/
    _delay_ms(ONE);
    DIO_WritePin(E,LOW);
	_delay_ms(ONE);
	/* repeat the sequence again for the first 4 bit command */

       DIO_WritePin(E,HIGH);
       _delay_ms(ONE);
	   /* sending the rest of the command */
	#ifdef UPPER_PINS
	DIO_WritePin(PIN_4 ,(Get_Bit(command,PIN_0)>>PIN_0));
	DIO_WritePin(PIN_5,(Get_Bit(command,PIN_1)>>PIN_1));
	DIO_WritePin(PIN_6,(Get_Bit(command,PIN_2)>>PIN_2));
	DIO_WritePin(PIN_7,(Get_Bit(command,PIN_3)>>PIN_3));
	#else
	DIO_WritePin(PIN_0,(Get_Bit(command,PIN_0)>>PIN_0));
	DIO_WritePin(PIN_1,(Get_Bit(command,PIN_1)>>PIN_1));
	DIO_WritePin(PIN_2,(Get_Bit(command,PIN_2)>>PIN_2));
	DIO_WritePin(PIN_3,(Get_Bit(command,PIN_3)>>PIN_3));
	#endif
    _delay_ms(ONE);
	DIO_WritePin(E,LOW);
	_delay_ms(ONE);
	#else
	/* in 8 bit mode send command on one step and complete the sequence */
	DATA_PORT_OUT = command ;
	_delay_ms(ONE);
	DIO_WritePin(E,LOW);
	_delay_ms(ONE);
	#endif
	
}

/***********************************************************************************************************/
/* Function name :- LCD_sendCommand                                                                        */
/* Function job :-sending a specific command to lcd                                                        */
/* Function inputs :-selected command                                                                      */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/
void LCD_displayChar(uint8 data)
{
	/* begin sequence of sending as data sheet 
   1- rs = 1 to send data
   2- rw = 0 to write on lcd 
   3- wait for 1 mel second 
   4- e = 1 make enable pin high
   5- sending data in its desired mode
    */
	
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(RW,LOW);
	_delay_ms(ONE);
	
	DIO_WritePin(E,HIGH);
	_delay_ms(ONE);
	
	/* sending command to lcd choosing between 4 or 8 bit mode  */
	
	#ifdef FOUR_BIT_MODE
	#ifdef UPPER_PINS
	/* taking last 4 bits first then the other  */
    DIO_WritePin(PIN_4 ,(Get_Bit(data,PIN_4)>>PIN_4));
    DIO_WritePin(PIN_5,(Get_Bit(data,PIN_5)>>PIN_5));
    DIO_WritePin(PIN_6,(Get_Bit(data,PIN_6)>>PIN_6));
    DIO_WritePin(PIN_7,(Get_Bit(data,PIN_7)>>PIN_7));
	
	/* if lower pins is selected send first 4 bit on data in them */
	#else
	DIO_WritePin(PIN_0 ,(Get_Bit(data,PIN_4)>>PIN_4));
	DIO_WritePin(PIN_1,(Get_Bit(data,PIN_5)>>PIN_5));
	DIO_WritePin(PIN_2,(Get_Bit(data,PIN_6)>>PIN_6));
	DIO_WritePin(PIN_3,(Get_Bit(data,PIN_7)>>PIN_7));
    #endif
	
       /* complete the sequence 
	6- wait for 1 mel second
	7- e = 0 set enable pin to low 
	*/
	  _delay_ms(ONE);

    DIO_WritePin(E,LOW);
	_delay_ms(ONE);
	/* repeat the sequence again for the first 4 bit data to send the other 4 bit of data */
	DIO_WritePin(E,HIGH);
	_delay_ms(ONE);
	

	#ifdef UPPER_PINS
	DIO_WritePin(PIN_4,(Get_Bit(data,PIN_0)>>PIN_0));
	DIO_WritePin(PIN_5,(Get_Bit(data,PIN_1)>>PIN_1));
	DIO_WritePin(PIN_6,(Get_Bit(data,PIN_2)>>PIN_2));
	DIO_WritePin(PIN_7,(Get_Bit(data,PIN_3)>>PIN_3));
	#else
	DIO_WritePin(PIN_0,(Get_Bit(data,PIN_0)>>PIN_0));
	DIO_WritePin(PIN_1,(Get_Bit(data,PIN_1)>>PIN_1));
	DIO_WritePin(PIN_2,(Get_Bit(data,PIN_2)>>PIN_2));
	DIO_WritePin(PIN_3,(Get_Bit(data,PIN_3)>>PIN_3));
	#endif
    _delay_ms(ONE);
	DIO_WritePin(E,LOW);
	_delay_ms(ONE);
	/* if 8 bit mode is selected sned data in one time and complete the sequence */
	#else
	DATA_PORT_OUT = data ;
	_delay_ms(ONE);
	DIO_WritePin(E,LOW);
	_delay_ms(ONE);
	#endif
	
	
}

/***********************************************************************************************************/
/* Function name :- LCD_displayString                                                                      */
/* Function job :- displaying string on                                                                    */
/* Function inputs :- pointer to desired string                                                            */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/

void LCD_displayString(const uint8 *str)
{
	uint8 index = FALSE; /* index of every character */
	/* display character by character till null character */
	while(str[index] != '\0')
	{
		LCD_displayChar(str[index]);
		index ++;
	}
	
	
}

/***********************************************************************************************************/
/* Function name :- LCD_clear                                                                              */
/* Function job :- clear lcd                                                                               */
/* Function inputs :- N/A                                                                                  */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/

void LCD_clear(void)
{
	/* just send clear command to lcd */
	LCD_sendCommand(CLEAR_SCREEN);
}


/***********************************************************************************************************/
/* Function name :- LCD_goToRowColumn                                                                      */
/* Function job :- force cursor to display in desired position                                             */
/* Function inputs :-row and column                                                                        */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/

void LCD_goToRowColumn(uint8 row, uint8 col)
{
	uint8 adress ; /* to store specific adress */
	/* cases on row number */
	switch (row)
	{
		/* add col to first line command to give exact command to lcd */
		case ONE :	adress = FIRST_LINE + col ;
		break; 
		case TWO :	adress = SCOND_LINE + col ;
		break;
		default: adress = FIRST_LINE ;
		
	}
	/* send adess as a command */
	LCD_sendCommand(adress);
}

/***********************************************************************************************************/
/* Function name :- LCD_displayStringRowColumn                                                             */
/* Function job :- force cursor to display string in desired position                                      */
/* Function inputs :-string ,row and column                                                                */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/

void LCD_displayStringRowColumn(const uint8 *str,uint8 row, uint8 col)
{
	/* call function of go to row column then call function of display string */
	LCD_goToRowColumn(row,col);
	LCD_displayString(str);
}

