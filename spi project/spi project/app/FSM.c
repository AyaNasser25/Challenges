/*
 * FSM.c
 *
 *  Created on: Mar 20, 2019
 *      Author: AVE-LAP-057
 */
#if 0


#include <stdbool.h>
#include <stdint.h>
/*
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"
#include "utils/uartstdio.h"

*/
#include "../include/FreeRTOS.h"
#include "../include/task.h"

#include "../include/semphr.h"
#include "../include/Types.h"
/*
#include "Drivers/Switch/inc/Switch.h"
#include "Drivers/LEDs/inc/LEDs.h"
#include "tasks.h"

#include "Drivers/LCD/inc/LCD.h"
#include "Drivers/KeyPad/inc/Keypad.h"
*/
#include "../include/uart.h"
#include "../include/CommonNumbers.h"
#include "../include/FSM.h"
#include "../include/task.h"



/******************************************************************************/
/* Get Distance Defination function                                           */
/******************************************************************************/
#define ULTRASONIC_FACTOR   0.3
#define FIVE_SHIFT          5
#define DATA_MASK           0x1F

/******************************************************************************/
/* Event Flags Bits to check if state changed                                 */
/******************************************************************************/
#define STATE_BIT               ( 1 << 0 )
#define UART_BIT                ( 1 << 1 )
#define MANAGER_DISTANCE_BIT    ( 1 << 2 )
#define SW_BIT                  ( 1 << 4 )
/******************************************************************************/
/* FSM Task Periodicity                                                       */
/******************************************************************************/
#define FSM_PERIODICITY                 10

/******************************************************************************/
/* Manager Task Periodicity                                                   */
/******************************************************************************/
#define MANAGER_PERIODICITY             10


#define T_DELAY_1000                      1000
#define T_DELAY_10                        10
#define T_DELAY_100                       100
#define T_DELAY_50                        50
/************************************************************************/
/* Function: AlignData                                                  */
/* @param: command, distance                                            */
/* return: concatenated data                                            */
/* Description: function takes the distance and the command             */
/*              and concatenate them together in data and return it     */
/************************************************************************/
uint8_t AlignData(uint8_t command, uint8_t distance)
{
    uint8_t data = (command << FIVE_SHIFT) | distance;
    return data;
}

/************************************************************************/
/* Function: LCD get_distance                                           */
/* @param: Duty Cycle                                                   */
/* return: Distance                                                     */
/* Description: function takes the duty cycle and calculate             */
/*              the distance based on the ultrasonic equation           */
/************************************************************************/
uint8_t get_distance(uint8_t duty)
{
    uint8_t distance = ULTRASONIC_FACTOR * duty;
    return distance;
}

/******************************************************************************/
/* This task change State according to the Distance                              */
/******************************************************************************/
void FSM_Task(void *pvParameters)
{
    vTaskDelay(T_DELAY_100); /* delay till all modules intialized */
    uint8_t Distance; /* Store the distance received from the manager */
    uint8_t Command;
    uint16_t Prev_Distance = NUM_0; /* Store the previous distance */
    uint8_t SW_Flag = NUM_0;
    while (NUM_1)
    {

        /***********************************************************************************/
        /* check for the SW pressed or not                                                  */
        /***********************************************************************************/
        EventBits_t uxBits_SW;
        /* Wait a maximum of 100ms for either bit 0 or bit 4 to be set within
         the event group.  Clear the bits before exiting. */
        uxBits_SW = xEventGroupWaitBits(xCreatedEventGroup_Flags, /* The event group being tested. */
                                        SW_BIT, /* The bits within the event group to wait for. */
                                        pdTRUE, /* BIT_0 & BIT_4 should be cleared before returning. */
                                        pdFALSE, /* Don't wait for both bits, either bit will do. */
                                        100); /* Wait a maximum of 100ms for either bit to be set. */
        if ((uxBits_SW & ( SW_BIT)) == ( SW_BIT))
        {
            Prev_Distance = NUM_300;
            SW_Flag = NUM_1;
            SPI_Send(IGN_ON_OFF);
        }

        /* check if bit is set then the state is changed */
        EventBits_t uxBits_Dis;
        /* Wait a maximum of 100ms for either bit 0 or bit 4 to be set within
         the event group.  Clear the bits before exiting. */
        uxBits_Dis = xEventGroupWaitBits(xCreatedEventGroup_Flags, /* The event group being tested. */
                                         MANAGER_DISTANCE_BIT, /* The bits within the event group to wait for. */
                                         pdTRUE, /* BIT_0 & BIT_4 should be cleared before returning. */
                                         pdFALSE, /* Don't wait for both bits, either bit will do. */
                                         100); /* Wait a maximum of 100ms for either bit to be set. */
        if ((uxBits_Dis & ( MANAGER_DISTANCE_BIT)) == ( MANAGER_DISTANCE_BIT))
        {
            xQueueReceive(QueueManager, &Distance, NUM_10);
        }

        /***********************************************************************************************/
        /* check if the distance changed then new state or new distance                                */
        /***********************************************************************************************/
        if (Prev_Distance != Distance)
        {
            Prev_Distance = Distance; /* Store current distance  */
            xEventGroupSetBits(xCreatedEventGroup_Flags, STATE_BIT);/* Set the bit to notify that the state changed. */
        }
        if (SW_Flag == NUM_1)
        {
            if (Prev_Distance == ING_ON)
            {

            }
            else if ((Distance >= MAINTAIN_SPEED_LOW)
                    && (Distance < MAINTAIN_SPEED_HIGH))
            {
                /***********************************************************************************************/
                /* check if the distance changed then new state or new distance set bit to send via SPI to slave*/
                /***********************************************************************************************/
                EventBits_t uxBits;
                /* Wait a maximum of 100ms for either bit 0 or bit 4 to be set within
                 the event group.  Clear the bits before exiting. */
                uxBits = xEventGroupWaitBits(xCreatedEventGroup_Flags, /* The event group being tested. */
                                             STATE_BIT, /* The bits within the event group to wait for. */
                                             pdTRUE, /* BIT_0 & BIT_4 should be cleared before returning. */
                                             pdFALSE, /* Don't wait for both bits, either bit will do. */
                                             100); /* Wait a maximum of 100ms for either bit to be set. */
                Command = MAINTAIN_SPEEED; /* maintain speed */
                if ((uxBits & ( STATE_BIT)) == ( STATE_BIT))
                {
                    uint16_t Aligned_data;
                    Aligned_data = AlignData(Command, Distance);
                    SPI_Send(Aligned_data);

                }

            }
            else if ((Distance >= INCREASE_SPEED_LOW)
                    && (Distance <= INCREASE_SPEED_HIGH))
            {
                /***********************************************************************************************/
                /* check if the distance changed then new state or new distance set bit to send via SPI to slave*/
                /***********************************************************************************************/
                EventBits_t uxBits;
                /* Wait a maximum of 100ms for either bit 0 or bit 4 to be set within
                 the event group.  Clear the bits before exiting. */
                uxBits = xEventGroupWaitBits(xCreatedEventGroup_Flags, /* The event group being tested. */
                                             STATE_BIT, /* The bits within the event group to wait for. */
                                             pdTRUE, /* BIT_0 & BIT_4 should be cleared before returning. */
                                             pdFALSE, /* Don't wait for both bits, either bit will do. */
                                             100); /* Wait a maximum of 100ms for either bit to be set. */
                Command = INCREASE_SPEEED; /* increase speed */
                if ((uxBits & ( STATE_BIT)) == ( STATE_BIT))
                {
                    uint16_t Aligned_data;
                    Aligned_data = AlignData(Command, Distance);
                    /* send aligned data */
                    SPI_Send(Aligned_data);
                }
            }
            else if ((Distance >= DECREASE_SPEED_LOW)
                    && (Distance < DECREASE_SPEED_HIGH))
            {
                /***********************************************************************************************/
                /* check if the distance changed then new state or new distance set bit to send via SPI to slave*/
                /***********************************************************************************************/
                EventBits_t uxBits;
                /* Wait a maximum of 100ms for either bit 0 or bit 4 to be set within
                 the event group.  Clear the bits before exiting. */
                uxBits = xEventGroupWaitBits(xCreatedEventGroup_Flags, /* The event group being tested. */
                                             STATE_BIT, /* The bits within the event group to wait for. */
                                             pdTRUE, /* BIT_0 & BIT_4 should be cleared before returning. */
                                             pdFALSE, /* Don't wait for both bits, either bit will do. */
                                             100); /* Wait a maximum of 100ms for either bit to be set. */
                Command = DECREASE_SPEEED;/* decrease speed */
                if ((uxBits & ( STATE_BIT)) == ( STATE_BIT))
                {
                    uint16_t Aligned_data;
                    Aligned_data = AlignData(Command, Distance);
                    /* send aligned data */
                    SPI_Send(Aligned_data);
                }
            }
            else if ((Distance >= BRAKES_LOW) && (Distance < BRAKES_HIGH))
            {
                /***********************************************************************************************/
                /* check if the distance changed then new state or new distance set bit to send via SPI to slave*/
                /***********************************************************************************************/
                EventBits_t uxBits;
                /* Wait a maximum of 100ms for either bit 0 or bit 4 to be set within
                 the event group.  Clear the bits before exiting. */
                uxBits = xEventGroupWaitBits(xCreatedEventGroup_Flags, /* The event group being tested. */
                                             STATE_BIT, /* The bits within the event group to wait for. */
                                             pdTRUE, /* BIT_0 & BIT_4 should be cleared before returning. */
                                             pdFALSE, /* Don't wait for both bits, either bit will do. */
                                             100); /* Wait a maximum of 100ms for either bit to be set. */
                Command = BRAKES; /* brakes */
                if ((uxBits & ( STATE_BIT)) == ( STATE_BIT))
                {
                    uint16_t Aligned_data;
                    Aligned_data = AlignData(Command, Distance);
                    /* send aligned data */
                    SPI_Send(Aligned_data);
                }
            }
            else if ((Distance >= FIRE_AIR_BAG_LOW)
                    && (Distance < FIRE_AIR_BAG_HIGH))
            {
                /***********************************************************************************************/
                /* check if the distance changed then new state or new distance set bit to send via SPI to slave*/
                /***********************************************************************************************/
                EventBits_t uxBits;
                /* Wait a maximum of 100ms for either bit 0 or bit 4 to be set within
                 the event group.  Clear the bits before exiting. */
                uxBits = xEventGroupWaitBits(xCreatedEventGroup_Flags, /* The event group being tested. */
                                             STATE_BIT, /* The bits within the event group to wait for. */
                                             pdTRUE, /* BIT_0 & BIT_4 should be cleared before returning. */
                                             pdFALSE, /* Don't wait for both bits, either bit will do. */
                                             100); /* Wait a maximum of 100ms for either bit to be set. */
                Command = FIRE_AIR_BAG; /* Fire Air bag */

                if ((uxBits & ( STATE_BIT)) == ( STATE_BIT))
                {
                    uint16_t Aligned_data;
                    Aligned_data = AlignData(Command, Distance);
                    /* send aligned data */
                    SPI_Send(Aligned_data);

                }
            }
            else
            {
                LED2();
                /* handle the case there is error occured */
            }
        }
        else
        {
            LED3();
        }
        vTaskDelay(FSM_PERIODICITY);
    }
}

/******************************************************************************/
/* This task manages the communication between the UART and FSM               */
/******************************************************************************/
void Manager_Task(void *pvParameters)
{
    vTaskDelay(T_DELAY_100); /* delay till all modules intialized */
    while (NUM_1)
    {
        /***********************************************************************************************/
        /* check if there is data available at UART set bit                                            */
        /***********************************************************************************************/
        if (UARTCharsAvail(UART0_BASE))
        {
            xEventGroupSetBits(xCreatedEventGroup_Flags, UART_BIT);/* Set the bit to notify that there is data in UART. */
        }
        /***********************************************************************************************/
        /* check if UART bit set get data                                                              */
        /***********************************************************************************************/
        EventBits_t uxBits;
        /* Wait a maximum of 100ms for either bit 0 or bit 4 to be set within
         the event group.  Clear the bits before exiting. */
        uxBits = xEventGroupWaitBits(xCreatedEventGroup_Flags, /* The event group being tested. */
                                     UART_BIT, /* The bits within the event group to wait for. */
                                     pdTRUE, /* BIT_0 & BIT_4 should be cleared before returning. */
                                     pdFALSE, /* Don't wait for both bits, either bit will do. */
                                     100); /* Wait a maximum of 100ms for either bit to be set. */

        if ((uxBits & ( UART_BIT)) == ( UART_BIT))
        {
            xEventGroupSetBits(xCreatedEventGroup_Flags, MANAGER_DISTANCE_BIT);/* Set the bit to notify that Manager received data. */
            uint8_t duty = UART0_receive();
            uint8_t Distance = get_distance(duty);
            xQueueOverwrite(QueueManager, &Distance); /* Send to Queue */
        }
        vTaskDelay(MANAGER_PERIODICITY);
    }
}

/******************************************************************************/
/* This task detect if the SW is pressed then the system is ON                */
/******************************************************************************/
void SW_2_Task(void *pvParameters)
{
    while(1)
    {

        if(SW_1_Status())
        {
            vTaskDelay(1000);
            xEventGroupSetBits(xCreatedEventGroup_Flags, SW_BIT);
            LED1();
        }
        else
        {

        }
        vTaskDelay(10);
    }
}


void LCDTask(void *pvParameters)
{
    uint8_t V;
    while(1)
    {
            EventBits_t uxBits;
            /* Wait a maximum of 100ms for either bit 0 or bit 4 to be set within
             the event group.  Clear the bits before exiting. */
            uxBits = xEventGroupWaitBits(xCreatedEventGroup_Flags, /* The event group being tested. */
                                         MANAGER_DISTANCE_BIT, /* The bits within the event group to wait for. */
                                         pdTRUE, /* BIT_0 & BIT_4 should be cleared before returning. */
                                         pdFALSE, /* Don't wait for both bits, either bit will do. */
                                         100); /* Wait a maximum of 100ms for either bit to be set. */
            if ((uxBits & ( MANAGER_DISTANCE_BIT)) == ( MANAGER_DISTANCE_BIT))
            {
                if (xQueueReceive(QueueManager, &V, NUM_10))
                {
                    LCD_Clear();
                    LCD_Display_NUM(V);
                }
            }
        else
        {

        }
        vTaskDelay(10);
    }
}

#endif