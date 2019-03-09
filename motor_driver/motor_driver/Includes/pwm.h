/*
 * pwm.h
 *
 * Created: 3/2/2019 10:39:27 PM
 *  Author: AVE-LAP-023
 */ 


#ifndef PWM_H_
#define PWM_H_
#include "../Includes/BiteWiseOperation.h"
#include "../Includes/DIO_driver.h"
#include "../Includes/Types.h"

#define PRE_SCALER 1024
#define OCA 28
#define OCB 29
#define num_100 100



/********************************************************************************************************/
/* Function name :- PWM_init                                                                            */
/* Function job :- initializing pwm module in timer 1                                                   */
/* Function inputs :- duty_cycle_value                                                                  */
/* Function outputs :- N/A                                                                              */
/********************************************************************************************************/
void PWM_init(uint16 duty_cycle,uint16 freq);




#endif /* PWM_H_ */