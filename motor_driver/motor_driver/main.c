/*
 * motor_driver.c
 *
 * Created: 3/2/2019 7:11:43 PM
 * Author : AVE-LAP-023
 */ 

#include <avr/io.h>
#include "../Includes/motor.h"
#include "../Includes/motor_cfg.h"

int main(void)
{
	PWM_init(40,9000);
	
	MOTOR_turnOn(FORWARD,1);
    while (1) 
    {
    }
}

