/*
 * LCD_private.h
 *
 *  Created on: Mar 12, 2019
 *      Author: AyetAllah
 */

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

/*****************************************************Commands***********************************************************/



#define  FUNCTIONSET_2LINES_SFONT                        0b00111000
#define  FUNCTIONSET_2LINES_BFONT                        0b00111100

#define  DISPLAY_ON_Cursor_off_Blink_off                 0b00001100
#define  DISPLAY_ON_Cursor_off_Blink_on                  0b00001111
#define  DISPLAY_CLEAR                                   0b00000001
#define  COMMAND_SET_ADDRESS_DDRAM                       0x80
#define  COMMAND_SET_ADDRESS_CGRAM                       0b01000000
#define  COMMAND_RETURN_HOME                             0X02
#define  COMMAND_DISPLAYSHIFT_RIGHT                      0b00011100
#define  COMMAND_DISPLAYSHIFT_LEFT						 0b00011000



#if LCD_BIT_MODE == FourBit
  #define   FUNCTIONSET_4MODE_2LINES_SFONT                  0x28
#endif

#define   ADDRESS_2ND_ROW                                0X40
#define   ADDRESS_1ST_ROW                                0x00




#define LCD_16_2_BOUNDRY_1STLINE_ADDRESS_DDRAM           0x90  /*1 001 0000*/
															   /* 1 for command (set to ddram )and the reset is the actual boundry address in ddram*/
#define LCD_16_2_BOUNDRY_2NDLINE_ADDRESS_DDRAM           0xD0 /* 1 101 0000*/















static u8 WriteCommand(u8 Copy_u8Command);
//static u8 WriteChar(u8 Copy_u8Char);
static void Write( u8 Copy_u8Data_or_Command);

#endif /* LCD_PRIVATE_H_ */
