/*
 * interrupt.h
 *
 * Created: 3/2/2019 11:47:47 AM
 *  Author: AVE-LAP-023
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../Includes/BiteWiseOperation.h"
#include "../Includes/DIO_driver.h"
#include "../Includes/Types.h"
#include <avr/interrupt.h>

/*********************************************************************************************************/
/* Function name :- INT2_init                                                                           */
/* Function job :- initializing external interrupt 2                                                    */
/* Function inputs :- N/A                                                                               */
/* Function outputs :- N/A                                                                              */
/*********************************************************************************************************/
void INT2_init(void);



#endif /* INTERRUPT_H_ */