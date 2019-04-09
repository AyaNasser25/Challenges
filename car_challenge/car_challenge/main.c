#include <stddef.h>
#include "../includes/uart_driver.h"
#include "../includes/ESP_Driver.h"
#include "../includes/motor.h"
#include "../includes/Timer.h"
#include <avr/interrupt.h>
#include <avr/io.h>

#define SYSTEM_FREQ	16000000ULL

int main(void)

{
	PWM_Init();
	PWM_Generate(50,200);
	
	
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
		/* check on the recieveddata value if it equal character F */
		switch (*DataReceived)
		{
			case 'W' :
			/* move car in the forward direction */
			MOTOR_turnOn(FORWARD,1);
			MOTOR_turnOn(FORWARD,2);
			break ;
		   
		case 'S' :
		
			/* if recieved data is r move car in the back direction */
			MOTOR_turnOn(BACKWARD,1);
			MOTOR_turnOn(BACKWARD,2);
			break;
		
	case 'X' :
		/* if recieved data is x then stop car */
			MOTOR_turnOff(1);
			MOTOR_turnOff(2);
			break;
     case  'D' :
	 /* if recieved data is d then move right */
 				MOTOR_turnOn(FORWARD,1);
				MOTOR_turnOn(BACKWARD,2);
				break;
		case 'A' :
		/* if recieved data is x then move left */
					MOTOR_turnOn(BACKWARD,1);
					MOTOR_turnOn(FORWARD,2);
			break;
		}
	}
	
	//}
	
	
	
	
	return 0;
}
