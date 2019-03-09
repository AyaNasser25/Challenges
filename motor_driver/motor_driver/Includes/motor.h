/*
 * motor.h
 *
 * Created: 3/2/2019 11:01:27 PM
 *  Author: AVE-LAP-023
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#include "../Includes/pwm.h"


/********************************************************************************************************/
/* Function name :- MOTOR_turnOn                                                                        */
/* Function job :-turn motor on                                                                          */
/* Function inputs :-direction of rotation and motor number                                             */
/* Function outputs :- N/A                                                                              */
/********************************************************************************************************/

void MOTOR_turnOn(uint8 direction,uint8 motor_num);




/********************************************************************************************************/
/* Function name :- MOTOR_turnOff                                                                       */
/* Function job :-turn motor off                                                                        */
/* Function inputs :- motor number                                                                      */
/* Function outputs :- N/A                                                                              */
/********************************************************************************************************/

void MOTOR_turnOff(uint8 motor_num);

#endif /* MOTOR_H_ */