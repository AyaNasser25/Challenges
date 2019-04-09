/*
 * Timer.h
 *
 * Created: 2/21/2019 1:32:01 PM
 *  Author: AVE-LAP-005
 */ 


#ifndef TIMER_H_
#define TIMER_H_


void PWM_Init();
void PWM_Generate(uint8 Copy_u8DutyCycle,uint32 Copy_u32freq);
/* Choose Mode */
#define F_PWM
#define INVERTING

#endif /* TIMER_H_ */