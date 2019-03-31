/*
 * Tasks.c
 *
 *  Created on: Mar 18, 2019
 *      Author: AVE-LAP-057
 */




#include <stdbool.h>
#include <stdint.h>

#include "tasks.h"
#include "../include/FreeRTOS.h"
#include "../include/task.h"

#include "../include/semphr.h"
#include "../include/CommonNumbers.h"
/*
#include "../include/Switch.h"
#include "Drivers/LEDs/inc/LEDs.h"
#include "tasks.h"
#include "Drivers/LCD/inc/LCD.h"
#include "Drivers/KeyPad/inc/Keypad.h"
*/
#include "../include/uart.h"

#define BIT_0   ( 1 << 0 )
#define BIT_1   ( 1 << 1 )
#define BIT_2   ( 1 << 2 )
#define BIT_3   ( 1 << 3 )
#define BIT_4   ( 1 << 4 )
#define BIT_5   ( 1 << 5 )
/******************************************************************************/
/* Switch flag to check if the button is pressed or not.                      */
/******************************************************************************/
volatile uint8_t WS_Flag = 0;

/********************************************************************************/
/* Default LED toggle delay value. LED toggling frequency is twice this number. */
/****************************************************************************** */
#define LED_TOGGLE_DELAY        10

/********************************************************************************/
/* Default LED toggle delay value. LED toggling frequency is twice this number. */
/****************************************************************************** */
#define SW_DELAY        10


/******************************************************************************/
/* buffer to hold the values entered from keypad.                             */
/******************************************************************************/
volatile uint8_t K_Data[16] = {0};

volatile uint8_t Key_ret;

QueueHandle_t QueueYassin;

/* Declare a variable to hold the created event group. */

EventGroupHandle_t xCreatedEventGroup_Flags;



/******************************************************************************/
/* This task toggles LED1 if the switch is pressed                            */
/******************************************************************************/

void LED1Task(void *pvParameters)
{
    while(1)
    {
        EventBits_t uxBits;
      /* Wait a maximum of 100ms for either bit 0 or bit 4 to be set within
      the event group.  Clear the bits before exiting. */
      uxBits = xEventGroupWaitBits(
                xCreatedEventGroup_Flags,   /* The event group being tested. */
                BIT_1,         /* The bits within the event group to wait for. */
                pdTRUE,        /* BIT_0 & BIT_4 should be cleared before returning. */
                pdFALSE,       /* Don't wait for both bits, either bit will do. */
                100 );         /* Wait a maximum of 100ms for either bit to be set. */

        if(( uxBits & ( BIT_1) ) == ( BIT_1 ))
        {
           LED1();
        }
        else
        {
            //LED1_OFF();/* The bits being set. */
        }
        vTaskDelay(LED_TOGGLE_DELAY);
    }
}

/******************************************************************************/
/* This task Check if the button is pressed or not                            */
/******************************************************************************/
void SW_1_Task(void *pvParameters)
{
    while(1)
    {

        if(SW_1_Status())
        {
            while(SW_1_Status())
            {
                xEventGroupSetBits( xCreatedEventGroup_Flags, BIT_1 );/* The bits being set. */
            }
        }
        vTaskDelay(SW_DELAY);
    }
}


/******************************************************************************/
/* This task Check if the button is pressed or not                            */
/******************************************************************************/
void SW_2_Task(void *pvParameters)
{

    while(1)
    {
        if(SW_2_Status())
        {


        }
        vTaskDelay(SW_DELAY);
    }
}




/******************************************************************************/
/* This task Check if the button is pressed or not                            */
/******************************************************************************/
void UART_TR_Task(void *pvParameters)
{
    while(1)
    {
        EventBits_t uxBits;
              /* Wait a maximum of 100ms for either bit 0 or bit 4 to be set within
              the event group.  Clear the bits before exiting. */
              uxBits = xEventGroupWaitBits(
                        xCreatedEventGroup_Flags,   /* The event group being tested. */
                        BIT_4,         /* The bits within the event group to wait for. */
                        pdTRUE,        /* BIT_0 & BIT_4 should be cleared before returning. */
                        pdFALSE,       /* Don't wait for both bits, either bit will do. */
                        100 );         /* Wait a maximum of 100ms for either bit to be set. */

                if(( uxBits & ( BIT_4) ) == ( BIT_4 ))
                {
                   UART0_Transmit(Key_ret);
                }
                else if(( uxBits & ( BIT_5) ) == ( BIT_5 ))
                {
                    uint8 index;
                    for(index = 0; index <16; index++)
                    {
                        K_Data[index] = UART0_receive();
                    }
                }
                else
                {

                }
        vTaskDelay(SW_DELAY);
    }
}


/******************************************************************************/
/* This task Init the leds and Switches                                       */
/******************************************************************************/
void MainTaskInit(void *pvParameters)
{
    while(1)
    {
      //  LEDs_Init();
      //  Switch_Init();
     //   Keypad_Init();
      //  UART0_init();
        LCD_init();
      LCD_goToRowColumn(NUM_2,NUM_1);
        LCD_displayString("Welcome TO HELL ");
        vTaskSuspend( NULL );
    }
}



void LCDTask(void *pvParameters)
{

    while(1)
    {
        EventBits_t uxBits;
           /* Wait a maximum of 100ms for either bit 0 or bit 4 to be set within
              the event group.  Clear the bits before exiting. */
         uxBits = xEventGroupWaitBits(
                  xCreatedEventGroup_Flags,   /* The event group being tested. */
                  BIT_4,         /* The bits within the event group to wait for. */
                  pdTRUE,        /* BIT_0 & BIT_4 should be cleared before returning. */
                  pdFALSE,       /* Don't wait for both bits, either bit will do. */
                  100 );         /* Wait a maximum of 100ms for either bit to be set. */

         if(( uxBits & ( BIT_4) ) == ( BIT_4 ))
         {
             UART0_Transmit(Key_ret);
         }
         else if(( uxBits & ( BIT_5) ) == ( BIT_5 ))
          {

          }
          else
          {

          }
        if(Key_ret)
        {
            LCD_displayChar(Key_ret);
            Key_ret =0;
        }
        else
        {

        }
        vTaskDelay(100);
    }
}



void LCD_Welcome_Task(void *pvParameters)
{
    while(1)
    {

    }
}




/******************************************************************************/
/* Keypad                                                                      */
/******************************************************************************/


void Keypad_Task(void*pvParameters)
{
    while(1)
    {
            if(Keypad_func() != 0 )
            {
                while(Keypad_func())
                {
                    Key_ret = Keypad_func();
                    //LED1();
                }
            }
            vTaskDelay(20);
    }
}




