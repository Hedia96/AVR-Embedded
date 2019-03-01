/*
 * LMD_interface.h
 *
 *  Created on: Feb 12, 2019
 *      Author: AyetAllah
 */

#ifndef LDM_INTERFACE_H_
#define LDM_INTERFACE_H_


#include "LDM_config.h"

/*
 * NAME: LDM_u8DisplayFrame
 * DESCRIPTION: this function draw an image on led display matrix (array for col or image )\
 * according to its type is configured in LDM_config.h and choose the color
 * ARGUMENT: array for active leds () and  color(select which any pins is repeated col or row
 * OUTPUT: error state
 */
/************************COLOR***************************/
/*
 * TO WRITE COLOR -> LDM_RED OR LDM_GREEN
 * in configuration file or passed in function
 */
#define LDM_COLOR   LDM_RED

/************************ HARDWARE ARCHITECTURE CONNECTION **************************************/

/*
 * RANGES FOR  TYPE OF ARCHITECTURE AS HARDWARE CONNECTION OF LED DISPLAY MATRIX
 *                    LDM_COMMON_ROW
                      LDM_COMMON_COL
 */
#define LDM_HARDWARE_TYPE_COMMON   LDM_COMMON_ROW

/****************************TYPE VOLTAGE**************************************/
/*
 * RANGES FOR THE TYPE OF VOLTAGE
 *                           LDM_ACTIVE_LOW
                             LDM_ACTIVE_HIGH
 */

#define LDM_ACTIVE_VOLT   LDM_ACTIVE_LOW
/************************************ APIs *************************************************/
u8 LDM_u8DisplayFrame(u8 * Copy_Au8Image,u8 Copy_Color);
#endif /* LDM_INTERFACE_H_ */
