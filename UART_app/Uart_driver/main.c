/*
 * Uart_driver.c
 *
 * Created: 3/11/2019 3:31:34 PM
 * Author : AVE-LAP-023
 */ 

#include "../Includes/UART.h"
#include "../Includes/led.h"
#include "../Includes/led_cfg.h"
#include "../Includes/DIO_driver.h"

int main(void)
{
	uint8 temp;
	UART_Init();
	/* initialize all leds */
     LedInit(led0);
	 LedInit(led1);
	 LedInit(led2);
	 LedInit(led3);
    while (1) 
    {
		/* receive value by uart and save it in temp variable */ 
		temp = UART_receive();
		/* switch on temp value */
		switch (temp)
		{
			case  0 :
			/* case zero all leds off */
			LedState(led0,OFF);
			LedState(led1,OFF);
			LedState(led2,OFF);
			LedState(led3,OFF);
			break;
			case 1 :
			LedState(led0,ON);
			break ;
			case  2 :
			LedState(led1,ON);
			break;
			case 3 :
			LedState(led2,ON);
			break ;
			case  4 :
			LedState(led3,ON);
			break;
		}
		
			
    }
}

