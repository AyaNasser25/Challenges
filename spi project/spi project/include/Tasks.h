/*
 * Tasks.h
 *
 *  Created on: Mar 18, 2019
 *      Author: AVE-LAP-057
 */

#ifndef TASKS_H_
#define TASKS_H_

#include "../include/FreeRTOS.h"
#include "../include/event_groups.h"
#include "../include/queue.h"
/*****************************************************************************/
/* Prototypes for the tasks.                                                 */
/*****************************************************************************/
extern void MainTaskInit(void *pvParameters);
extern void LED1Task(void *pvParameters);
extern void LCDTask(void *pvParameters);
extern void SW_1_Task(void *pvParameters);
extern void SW_2_Task(void *pvParameters);
extern void LCD_Welcome_Task(void *pvParameters);
extern  EventGroupHandle_t xCreatedEventGroup_Flags;
extern QueueHandle_t QueueYassin;
extern void Keypad_Task(void*pvParameters);
extern volatile uint8_t Key_ret;

/* Define an enumerated type used to identify the source of the data. */
typedef enum
{
 SW1,
 SW2
} DataSource_SW;
/* Define the structure type that will be passed on the queue. */
typedef struct
{
 uint8_t Counter_SW1_Value;
 uint8_t Counter_SW2_Value;
 DataSource_SW DataSource;
} Data_Value;



#endif /* TASKS_H_ */
