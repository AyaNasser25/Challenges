/*
 * Uart_driver.c
 *
 * Created: 3/11/2019 3:31:34 PM
 * Author : AVE-LAP-023
 */ 

#include "../Includes/UART.h"
#include "../Includes/UART_cfg.h"


int main(void)
{
	UART_Init();
	if(UART_receive()){
		UART_Transmit('c');
	}
    while (1) 
    {
    }
}

