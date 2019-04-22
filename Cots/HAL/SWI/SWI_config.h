/*
 * SWI_config.h
 *
 *  Created on: Feb 7, 2019
 *      Author: AyetAllah
 */

#ifndef SWI_CONFIG_H_
#define SWI_CONFIG_H_


#include "DIO_interface.h"



#define NUM_SW 2
/*choose  type-> sspullup,pulldown*/


u8 Au8SwiChannels[NUM_SW]={DIO_PIN1,DIO_PIN2};
u8 Au8SwiTypes[NUM_SW]={PULLUP,PULLDOWN};


#endif /* SWI_CONFIG_H_ */
