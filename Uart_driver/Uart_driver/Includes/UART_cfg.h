/*
 * UART_cfg.h
 *
 * Created: 2/27/2019 1:22:26 PM
 *  Author: AVE-LAP-023
 */ 


#ifndef UART_CFG_H_
#define UART_CFG_H_

/* this is the configurable values that determined by user */
#define BAUDRATE    9600 /* baud rate value */
#define NO_STOPBITS 1   /* number of stop bits */
#define PARITYMODE  FALSE   /* parity mode selection */
#define DATASIZE    eight_bit  /* data size that sent or received */
#define SPEEDMODE   ON  /* speed mode selection */


#define F_CPU 16000000 /* value of system frequancy */

/* uart registers mapping */

#define UCSRC (*((volatile uint8 *)(0x40)))
#define UBRRH (*((volatile uint8 *)(0x40)))
#define UDR (*((volatile uint8 *)(0x2C)))
#define UCSRA (*((volatile uint8 *)(0x2B)))
#define UCSRB (*((volatile uint8 *)(0x2A)))
#define UBRRL (*((volatile uint8 *)(0x29)))

/* uart pins mapping according to their positions in registers */
#define UCSZ0  1
#define UCSZ1 2
#define UCSZ2 2
#define URSEL 7
#define TXEN  3
#define RXEN 4
#define U2X 1
#define UDRE 5
#define TXC 6
#define RXC 7
#define USBS 3
#define UPM0 4
#define UPM1 5
#define even 1
#define  odd 2


/* number definitions */ 
#define six_bit 6
#define seven_bit 7
#define eight_bit 8
#define nine_bit 9





#endif /* UART_CFG_H_ */