/*
 * Types.h
 *
 * Created: 2/13/2019 10:50:42 AM
 *  Author: AVE-LAP-023
 */ 


#ifndef TYPES_H_
#define TYPES_H_

#define  TRUE 1
#define  FALSE 0

#define  OUT 1
#define  IN 0

#define  LOW 0
#define  HIGH 1

#define  ONE 1
#define  TWO 2

typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned char * uint8_ptr;
typedef signed char * sint8_ptr;

typedef unsigned short uint16;
typedef signed short sint16;
typedef signed short * sint16_ptr;
typedef unsigned short * uint16_ptr;

typedef unsigned long uint32;
typedef signed long sint32;
typedef unsigned long * uint32_ptr;
typedef signed long * sint32_ptr;



/*

#define PORTA (*((volatile uint8 *)(0x3B)))
#define DDRA (*(volatile uint8 *)(0x3A))
#define PINA (*(volatile uint8 *)(0x39))

#define PORTB (*(volatile uint8 *)(0x38))
#define DDRB (*(volatile uint8 *)(0x37))
#define PINB (*(volatile uint8 *)(0x36))

#define PORTC (*(volatile uint8 *)(0x35))
#define DDRC (*(volatile uint8 *)(0x34))
#define PINC (*(volatile uint8 *)(0x33))

#define PORTD (*(volatile uint8 *)(0x32))
#define DDRD (*(volatile uint8 *)(0x31))
#define PIND (*(volatile uint8 *)(0x30))
*/


/* timer registers 
#define  TIMSK (*(volatile uint8 *)(0x59))
#define  TIFR  (*(volatile uint8 *)(0x58))
#define  TCCR0  (*(volatile uint8 *)(0x53))
#define  TCNT0  (*(volatile uint8 *)(0x52))
#define  OCR0    (*(volatile uint8 *)(0x5C))
#define  SREG    (*(volatile uint8 *)(0x5F))


*/







#endif /* TYPES_H_ */