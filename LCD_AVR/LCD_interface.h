/*
 * LCD_interface.h
 *
 *  Created on: Mar 4, 2019
 *      Author: AyetAllah
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/* NAME       :
 * DESCRIPTION:
 * ARGUMENTS  :
 * RETURN     :
 *
 */
void LCD_VInit(void);

/* NAME       : LCD_u8WriteData
 * DESCRIPTION: this function
 * ARGUMENTS  :
 * RETURN     :
 *
 */
u8 LCD_u8WriteData(u8 Copy_u8_Data);

/* NAME       :
 * DESCRIPTION:
 * ARGUMENTS  :
 * RETURN     :
 *
 */
u8 LCD_u8WriteCommand(u8 Copy_u8_Command);

#endif /* LCD_INTERFACE_H_ */
