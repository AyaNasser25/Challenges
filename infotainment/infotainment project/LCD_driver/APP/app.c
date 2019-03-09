/*
 * app.c
 *
 * Created: 3/9/2019 10:41:38 AM
 *  Author: AVE-LAP-023
 */ 

#include "../INCLUDES/app.h"

uint8 correct,wrong;  /* 2 variable to calculate correct and wrong answers */


/***********************************************************************************************************/
/* Function name :- APP_init                                                                               */
/* Function job :-initialize all peripheral needed                                                         */
/* Function inputs :- N/A                                                                                  */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/

void APP_init(void)
{
	LCD_init(); /* initialize lcd */
	
	/* set buttons direction to be input pins */
	DIO_SetPinDirection(but0,IN);
	DIO_SetPinDirection(but1,IN);
	
}

/***********************************************************************************************************/
/* Function name :- smile_character                                                                        */
/* Function job :- to draw smile face on lcd                                                               */
/* Function inputs :- row and column  to be written                                                        */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/


void smile_character(uint8 row,uint8 col)
{
	uint8 smile_arr[8]={0, 10, 0, 0, 17, 14, 0}; /* array of values that draw the shape */
	LCD_customCharacter(smile_arr,0,0,row,col); /* call function that generate custom character */
}

/***********************************************************************************************************/
/* Function name :- sad_character                                                                          */
/* Function job :- to draw sad face on lcd                                                                 */
/* Function inputs :- row and column  to be written                                                        */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/


void sad_character(uint8 row,uint8 col)
{
	uint8 sad_arr[8]={0, 10, 0, 0, 14, 17, 0};/* values of sad character */
	LCD_customCharacter(sad_arr,1,1,row,col);
}

/***********************************************************************************************************/
/* Function name :-like_character                                                                          */
/* Function job :- to draw like emoji on lcd                                                               */
/* Function inputs :- row and column  to be written                                                        */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/

void like_character(uint8 row,uint8 col)
{
	uint8 like_arr[8]={0, 24, 24, 24, 31, 31, 31};
		LCD_customCharacter(like_arr,2,2,row,col);
}

/***********************************************************************************************************/
/* Function name :-question_mark                                                                           */
/* Function job :- to draw  question mark on lcd                                                           */
/* Function inputs :- row and column  to be written                                                        */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/

void question_mark(uint8 row,uint8 col)
{
	uint8 question_arr[8]={0, 0, 3, 3, 31, 31, 31};
	LCD_customCharacter(question_arr,3,3,row,col);
}

/***********************************************************************************************************/
/* Function name :-questions                                                                               */
/* Function job :- to display questions                                                                    */
/* Function inputs :-strings of question number and type                                                   */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/
void questions(uint8 *ques_num,uint8 *ques_type)
{
	LCD_displayStringRowColumn(ques_num,2,1);
	_delay_ms(2000);
	LCD_clear();
	LCD_displayStringRowColumn(ques_type,1,0);
	LCD_displayStringRowColumn("0-yes",2,0);
	LCD_displayStringRowColumn("1-no",2,9);
}

/***********************************************************************************************************/
/* Function name :-get_answer                                                                              */
/* Function job :- determine correct answer                                                                */
/* Function inputs :-correct button                                                                        */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/
void get_answer(uint8 correct_but)
{
	/* loop until any button pressed */
	while(( !(DIO_ReadPin(but0)) && !(DIO_ReadPin(but1)) ) );
	/* determine answer type */
	if(DIO_ReadPin(correct_but))
	{
		LCD_clear();
		LCD_displayStringRowColumn("correct ",2,2);
		smile_character(2,12);
		_delay_ms(1000);
		correct ++;
	}
	else
	{
		LCD_clear();
		LCD_displayStringRowColumn("wrong ",2,2);
		sad_character(2,12);
		_delay_ms(1000);
		wrong++;
	}
}