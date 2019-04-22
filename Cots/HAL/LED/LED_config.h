/***********************************************************
 * LED_interface.h                                         *
 * Created on: Jan 31, 2019                                *
 * Author: AyetAllah                                       *
 ***********************************************************/


#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

#define NUM_LEDS                     2

#define LED_CONNECT_FORWARD_TYPE     FORWARD
#define LED_CONNECT_REVERSE_TYPE     REVERSE


/*

  THE VALUES FROM DIO_INTERFACE.H NAMES OF PINS

*/

u8 LED_Au8LedNumPinCh[NUM_LEDS]={DIO_PIN31,DIO_PIN10};
u8 LED_Au8LedNumType[NUM_LEDS]={LED_CONNECT_FORWARD_TYPE,LED_CONNECT_REVERSE_TYPE};




#endif /* LED_INTERFACE_H_ */
