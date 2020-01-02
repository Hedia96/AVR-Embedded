/*
 * LCD_interface.h
 *
 *  Created on: Mar 12, 2019
 *      Author: AyetAllah
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
#include"STD_TYPES.h"

/* NAME         :LCD_VInitialize8BitMode
 *
 * DESCRIPPTION : this function  does some steps in lcd (8 bit mode)
 *                1-function set
 *                2-display on/off
 *                3-clear
 *                4-Entry Mode
 *                and  similar for 4 bit mode but on two stages
 *
 * ARGUMENTS    : void
 * RETURN       : void
 */



void LCD_VInitialize(void);

/* NAME         : LCD_WriteStringInPosition
 *
 * DESCRIPPTION : this function takes the string and writes in certain position according to size of lcd  WxH  and
 * 			   it takes into its consideration  the boundries of lcd which are reflected to memories in DDRAM
 * 			   for all types lcd 16x2,20x2,40x2.....etc
 *
 * ARGUMENTS    : string you want write and certain position  according to size of lcd ,which is configured in a configuration file
 * RETURN       : error state level
 */

u8 LCD_WriteStringInPosition(u8 *Copy_u8String,u8 Copy_Xpos,u8 Copy_Ypos);



/* NAME         :LCD_ClearDisplay
 * DESCRIPPTION : this function  clears the screen  totally
 * ARGUMENTS    : void
 * RETURN       : void
 */
void LCD_ClearDisplay(void);


/* Name       : LCD_u8SymbolDisplay
 * DESCRIPTION: this function get a symbol from those are stored in CGROM
 *				and there are stored in addresss like asci code for each symbols
 *
 * ARGUMENTS  : that symbol in asci code amd required position to display it
 *
 * RETURN     : error state
 *
 */

u8 LCD_u8SymbolDisplay( u8 Copy_u8CharCodeCGROM, u8 Copy_u8Xpos,u8 Copy_u8Ypos);





/* NAME         :LCD_u8CustomPattern
 *
 * DESCRIPPTION : This function
 * 				1. makes the address counter points to CGRAM firstly then
 *
 * 			    2.Fill what you want as the required pattern  which is send as an arrgument
 * 			    and there is  remarkable somthing that address is incremet /decrement automatically
 * 			    not need to adjust(increment /decrement) during filling Data in CGRAM
 *
 *					3.return Address counter to DDRAM  to be able to display  afterthat
 *
 *
 * ARGUMENTS    : Array pattern and its size and the index of this pattern which is matching to its code in DDRAM
 *
 * RETURN       : void
 */
u8 LCD_u8CustomPattern(u8 *Copy_u8APattern, u8 Copy_u8size,u8 Copy_u8CodeinDDRAM);


/* NAME         :LCD_u8DisplayUnsignedNumber
 *
 * DESCRIPPTION : This function display a number from many digits
 *
 *
 *
 * ARGUMENTS    :u32 unsigned integer number
 *
 * RETURN       : ErrorState
 */

u8 LCD_u8DisplayUnsignedNumber(u32 Copy_u32Number);


void LCD_ReturnHome(void);
void LCD_ShiftLeft(void);
void LCD_ShiftRight(void);


 u8 WriteChar(u8 Copy_u8Char);


















#endif /* LCD_INTERFACE_H_ */
