/*
 * app.h
 *
 * Created: 3/9/2019 10:45:32 AM
 *  Author: AVE-LAP-023
 */ 


#ifndef APP_H_
#define APP_H_

#include "../INCLUDES/BiteWiseOperation.h"
#include "../INCLUDES/DIO_driver.h"
#include "../INCLUDES/lcd.h"
#include "../INCLUDES/Types.h"
#include <util/delay.h>

/***********************************************************************************************************/
/* Function name :- APP_init                                                                               */
/* Function job :-initialize all peripheral needed                                                         */
/* Function inputs :- N/A                                                                                  */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/

void APP_init(void);

/***********************************************************************************************************/
/* Function name :- smile_character                                                                        */
/* Function job :- to draw smile face on lcd                                                               */
/* Function inputs :- row and column  to be written                                                        */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/


void smile_character(uint8 row,uint8 col);

/***********************************************************************************************************/
/* Function name :-like_character                                                                          */
/* Function job :- to draw like emoji on lcd                                                               */
/* Function inputs :- row and column  to be written                                                        */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/

void like_character(uint8 row,uint8 col);

/***********************************************************************************************************/
/* Function name :-question_mark                                                                           */
/* Function job :- to draw  question mark on lcd                                                           */
/* Function inputs :- row and column  to be written                                                        */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/

void question_mark(uint8 row,uint8 col);

/***********************************************************************************************************/
/* Function name :-questions                                                                               */
/* Function job :- to display questions                                                                    */
/* Function inputs :-strings of question number and type                                                   */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/
void questions(uint8 *ques_num,uint8 *ques_type);

/***********************************************************************************************************/
/* Function name :-get_answer                                                                              */
/* Function job :- determine correct answer                                                                */
/* Function inputs :-correct button                                                                        */
/* Function outputs :- N/A                                                                                 */
/***********************************************************************************************************/
void get_answer(uint8 correct_but);

#endif /* APP_H_ */