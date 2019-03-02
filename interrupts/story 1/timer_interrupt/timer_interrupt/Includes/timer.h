/*
 * timer.h
 *
 * Created: 2/13/2019 5:51:10 PM
 *  Author: AVE-LAP-023
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../Includes/BiteWiseOperation.h"
#include "../Includes/Types.h"
#include "../Includes/DIO_driver.h"
#include <avr/interrupt.h>
#include <avr/io.h>

#include <stdlib.h>

#define sec_3 3000
#define sec_2 2000
#define sec_4 4000
#define OCR_1ms 250




void timer_init(uint8 OCR_val);


#endif /* TIMER_H_ */