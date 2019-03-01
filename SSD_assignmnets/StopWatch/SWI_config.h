/*
 * SWI_config.h
 *
 *  Created on: Feb 7, 2019
 *      Author: AyetAllah
 */

#ifndef SWI_CONFIG_H_
#define SWI_CONFIG_H_


#include "DIO_interface.h"



/*#define NUM_SW 2*/
/*choose  type-> pull up ,pull down*/
#define NUM_SW 1

u8 Au8SwiChannels[NUM_SW]={DIO_PIN30};
u8 Au8SwiTypes[NUM_SW]={PULLUP};
/*u8 Au8SwiTypes[NUM_SW]={PULLUP,PULLDOWN};*/


#endif /* SWI_CONFIG_H_ */
