/*
 * LMD_config.h
 *
 *  Created on: Feb 12, 2019
 *      Author: AyetAllah
 */


/***************************PUBLIC CONFIGURATION********************************/
#ifdef LDM_INTERFACE_H_
#ifndef LDM_CONFIG_PUB_H_
#define LDM_CONFIG_PUB_H_
	/*SIZE OF LED DISPLAY MATRIX ,THE CONVENTION IS A SQUARE  */
	#define LDM_SIZE  8
	/*CHOOSE COLOR WHICH IS SELECTED*/
	#define LDM_RED                     (u8)10
	#define LDM_GREEN                   (u8)11

	#define LDM_ACTIVE_LOW              0
	#define LDM_ACTIVE_HIGH             1
	/*TYPE OF ARCHITECTURE AS HARWARE CONNECTION FOR LED DISPLLAY MATRIX */
	#define LDM_COMMON_ROW              2
  #define LDM_COMMON_COL              3
#endif/*LMD_CONFIG_PUB_H_*/
#endif /*LDM_INTERFACE_H_*/

/**************************PRIVATE CONFIGURATION****************************************/



#ifdef LDM_PRIVATE_H_
#ifndef LDM_CONFIG_PRI_H_
#define LDM_CONFIG_PRI_H_

   #define LDM_PORT_IMAGE_RED                         DIO_PORTD
   #define LDM_PORT_IMAGE_GREEN                       DIO_PORTB
   #define LDM_PORT_ACTIVE                            DIO_PORTA


#endif  /*LDM_CONFIG_PRI_H_*/
#endif /*LDM_PRIVATE_H_*/
