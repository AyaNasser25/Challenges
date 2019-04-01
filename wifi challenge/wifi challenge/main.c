#include <stddef.h>
#include "../include/uart_driver.h"
#include "../include/ESP_Driver.h"
#include <avr/interrupt.h>
#include <avr/io.h>

#define SYSTEM_FREQ	16000000ULL
#define F_CPU 16000000UL

int main(void)

{
	
	int* DataReceived;
	

	Disable_Interrupts();
	UART_Init(9600,ESP_FillResponseBuffer);
	Enable_Interrupts();
	
	WIFI_Service_Start(Server, "4444", "aya", "1234567890", NULL, NULL, NULL, NULL);
	
	while(OK_Status!=ESP_SendData("Wifi Demo Started","17"));
	DDRB |= (1<<4);
	
	DataReceived=NO_Response;
	//while(NO_Response==DataReceived)
	//{
		while(1){
			/* receive data from wifi into datareceived pointer */
		DataReceived=ESP_ReceiveData();
		_delay_ms(1000);
	/* check on the recieveddata value if it equal character a */
		if (*DataReceived == 'a')
		{
			/* then led 0 on */
			PORTB |= (1<<4);
		}
		}
	
	//}
	
	return 0;
}
	