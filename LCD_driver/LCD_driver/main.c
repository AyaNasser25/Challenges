/*
 * LCD_driver.c
 *
 * Created: 3/1/2019 10:41:31 AM
 * Author : AVE-LAP-023
 */ 

#include "../INCLUDES/lcd.h"
#include <util/delay.h>


int main(void)
{
    LCD_init();
	LCD_displayStringRowColumn("aya me",1,5);
	
    while (1) 
    {
    }
}

