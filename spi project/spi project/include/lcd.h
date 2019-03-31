/*
 * lcd.h
 *
 * Created: 3/1/2019 11:04:29 AM
 *  Author: AVE-LAP-023
 */ 


#ifndef LCD_H_
#define LCD_H_



#include "../include/DIO_driver.h"
#include <stdlib.h>
#include <util/delay.h>

/* defining control pins of lcd */
#define  RS 1
#define  RW 2
#define  E  3
/* declaring the desired port that lcd is connected */
#define DATA_PORT_OUT PORTA
#define  DATA_PORT_DIR DDRA

/* set desired mode which lcd is operated in */
#define FOUR_BIT_MODE
#define  UPPER_PINS 

/* defining all pins */
#define  PIN_0 0
#define  PIN_1 1
#define  PIN_2 2
#define  PIN_3 3

#define  PIN_4 4
#define  PIN_5 5
#define  PIN_6 6
#define  PIN_7 7


/* command section */
#define  CLEAR_SCREEN 0x01
#define  FOUR_BIT   0x28
#define  CURSOR_OFF 0x0c
#define  CURSOR_ON 0x0A
#define  FIRST_LINE 0x80
#define  SCOND_LINE 0xc0
#define  EGHIT_BIT_MODE 0x38



/***********************************************************************************************************/
/* Function name :- LCD_init                                                                               */
/* Function job :- initializing LCD                                                                        */
/* Function inputs :- N/A                                                                                  */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/


void LCD_init(void);

/***********************************************************************************************************/
/* Function name :- LCD_sendCommand                                                                        */
/* Function job :-sending a specific command to lcd                                                        */
/* Function inputs :-selected command                                                                      */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/
void LCD_sendCommand(uint8 command);

/***********************************************************************************************************/
/* Function name :- LCD_sendCommand                                                                        */
/* Function job :-sending a specific command to lcd                                                        */
/* Function inputs :-selected command                                                                      */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/
void LCD_displayChar(uint8 data);

/***********************************************************************************************************/
/* Function name :- LCD_displayString                                                                      */
/* Function job :- displaying string on                                                                    */
/* Function inputs :- pointer to desired string                                                            */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/

void LCD_displayString(const uint8 *str);

/***********************************************************************************************************/
/* Function name :- LCD_goToRowColumn                                                                      */
/* Function job :- force cursor to display in desired position                                             */
/* Function inputs :-row and column                                                                        */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/

void LCD_goToRowColumn(uint8 row, uint8 col);

/***********************************************************************************************************/
/* Function name :- LCD_clear                                                                              */
/* Function job :- clear lcd                                                                               */
/* Function inputs :- N/A                                                                                  */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/

void LCD_clear(void);

/***********************************************************************************************************/
/* Function name :- LCD_displayStringRowColumn                                                             */
/* Function job :- force cursor to display string in desired position                                      */
/* Function inputs :-string ,row and column                                                                */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/

void LCD_displayStringRowColumn(const uint8 *str,uint8 row, uint8 col);
/***********************************************************************************************************/
/* Function name :- LCD_intgerToString                                                                     */
/* Function job :- displaying any number                                                                   */
/* Function inputs :- desired number                                                                       */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/

void LCD_intgerToString(uint32 num);

/***********************************************************************************************************/
/* Function name :- LCD_customCharacter                                                                    */
/* Function job :- generate custom character                                                               */
/* Function inputs :- desired character , its location in cg ram and position of reading from cg rom       */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/
void LCD_customCharacter(uint8 *character,uint8 loc,uint8 val,uint8 row,uint8 col);

/***********************************************************************************************************/
/* Function name :- sad_character                                                                          */
/* Function job :- to draw sad face on lcd                                                                 */
/* Function inputs :- row and column  to be written                                                        */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/


void sad_character(uint8 row,uint8 col);

#endif /* LCD_H_ */