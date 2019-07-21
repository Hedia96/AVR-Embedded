/*
 * LCD_config.h
 *
 *  Created on: Mar 12, 2019
 *      Author: AyetAllah
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


//#include "../include/MCAL/GPIO_interface.h"

#define LCD_D0           PORTA_PIN0
#define LCD_D1           PORTA_PIN1
#define LCD_D2           PORTA_PIN2
#define LCD_D3           PORTA_PIN3
#define LCD_D4           PORTA_PIN4
#define LCD_D5           PORTA_PIN5
#define LCD_D6           PORTA_PIN6
#define LCD_D7           PORTA_PIN7

/*
#define LCD_RS            PORTD_PIN0
#define LCD_R_W_BAR       PORTD_PIN1
#define LCD_ENABLE        PORTD_PIN2
*/
#define LCD_RS            PORTC_PIN7
#define LCD_R_W_BAR       PORTC_PIN6
#define LCD_ENABLE        PORTC_PIN5
/********************Modes******************/
/*choose the bit mode
 *  1-4bit or 8bit*/
#define EightBit    8
#define FourBit     4

#define LCD_BIT_MODE   EightBit


/*******************************Size LCD Width x Height********************************/
enum LCD_Types{LCD_16_2,LCD_20_2,LCD_40_2,LCD_20_4};
#define  LCD_SIZE_WIDTH    (u8)16

#define  LCD_SIZE_HIGHT    (u8)2
/*LCD_W_H */
 enum LCD_Types LCD_W_H=LCD_16_2 ;
/****************************************************************/

#endif /* LCD_CONFIG_H_ */
