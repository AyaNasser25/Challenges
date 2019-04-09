/*
 * DIO_Registers.h
 *
 * Created: 2/13/2019 2:44:08 PM
 *  Author: AVE-LAP-005
 */ 


#ifndef DIO_REGISTERS_H_
#define DIO_REGISTERS_H_

volatile typedef struct{
	uint8 PIN;
	uint8 DDR;
	uint8 PORT;
	
}GPIO;


#define GPIOA_DIO   ((GPIO*)0x39)
#define GPIOB_DIO   ((GPIO*)0x36)
#define GPIOC_DIO   ((GPIO*)0x33)
#define GPIOD_DIO   ((GPIO*)0x30)




#endif /* DIO_REGISTERS_H_ */