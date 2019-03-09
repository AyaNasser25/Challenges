/*
 * LCD_driver.c
 *
 * Created: 3/1/2019 10:41:31 AM
 * Author : AVE-LAP-023
 */ 


#include "../INCLUDES/app.h"

extern uint8 correct,wrong;
int main(void)
{
 
  APP_init();
	
	LCD_displayStringRowColumn("welcome ",2,2);
	smile_character(2,10);
	_delay_ms(2000);
	LCD_clear();
	LCD_displayStringRowColumn("let's start ",2,2);
	_delay_ms(2000);
	LCD_clear();
	questions("first question","are you eqyption");
	get_answer(but0);
	questions("second question","avelabs is 1st");
	get_answer(but1);
	questions("third question","sw is the best");
	get_answer(but0);
	questions("fourth question","arr are pointer");
	get_answer(but0);
	questions("fifth question","str like arr");
	get_answer(but0);
	LCD_clear();
	LCD_displayStringRowColumn("correct:",1,0);
	LCD_intgerToString(correct);
	LCD_displayStringRowColumn("wrong:",2,0);
	LCD_intgerToString(wrong);
	_delay_ms(2000);
	if(correct > wrong)
	{
		LCD_clear();
		LCD_displayStringRowColumn("congratulation",1,1);
		smile_character(2,6);
	}
	else
	{
		LCD_clear();
		LCD_displayStringRowColumn("hard luck",1,2);
		sad_character(2,6);
	}
	
    while (1) 
    {
    }
}

