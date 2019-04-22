/*
 * LED_interface.h
 *
 *  Created on: Jan 31, 2019
 *      Author: AyetAllah
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_
#include "STD_TYPES.h"

void LED_u8LedInit(u8 Copy_u8LedNb);



/*
NAME			 :LED_u8LedOn
DESCRIPTION: turn on the led according to type 
ARGUMENTS  :
RETURN     :
*/
u8 LED_u8LedOn(u8 Copy_u8LedNb);

/*
NAME			 :LED_u8LedOff
DESCRIPTION: off the led according to type
ARGUMENTS  :
RETURN     :
*/
u8 LED_u8LedOff(u8 Copy_u8LedNb);


#endif /* LED_INTERFACE_H_ */
