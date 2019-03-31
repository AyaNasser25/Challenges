/*
 * FSM.h
 *
 *  Created on: Mar 20, 2019
 *      Author: AVE-LAP-057
 */

#ifndef FSM_H_
#define FSM_H_


/******************************************************************************/
/* Common States Defination                                                   */
/******************************************************************************/
#define IGN_ON_OFF          0
#define MAINTAIN_SPEEED     1
#define INCREASE_SPEEED     2
#define DECREASE_SPEEED     3
#define BRAKES              4
#define FIRE_AIR_BAG        5


/******************************************************************************/
/* Common Used Distances                                                      */
/******************************************************************************/
#define MAINTAIN_SPEED_HIGH             22
#define MAINTAIN_SPEED_LOW              15
#define INCREASE_SPEED_HIGH             30
#define INCREASE_SPEED_LOW              22
#define DECREASE_SPEED_HIGH             15
#define DECREASE_SPEED_LOW              10
#define BRAKES_HIGH                     10
#define BRAKES_LOW                      3
#define FIRE_AIR_BAG_HIGH               3
#define FIRE_AIR_BAG_LOW                1


/******************************************************************************/
/* This task change State according to the Distance                           */
/******************************************************************************/
extern void FSM_Task(void *pvParameters);


extern void Manager_Task(void *pvParameters);


extern void SW_2_Task(void *pvParameters);

#endif /* FSM_H_ */
