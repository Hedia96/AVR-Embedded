/*
 * SSD_interface.h
 *
 *  Created on: Feb 11, 2019
 *      Author: AyetAllah
 */

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

/* ***************************************************************************************************************************                                                                                                                         *
 * Common Cathode:                                                                                                           *
 *   __a_                                                                                                                    *
 * f|   |b                                                                                                                   *
 *  |_g_|                                                                                                                    *
 * e|   |c                                                                                                                   *
 *  |_d_|   dot                                                                                                              *
 *                                                                                                                           *
 *  patter= g f e d c b a                                                                                                    *
 *                                                                                                                           *
 *  common cathode turn on by apply high volt on pins in seven segments so 1->HIGH                                           *
 *                                                                                                                           *
 * Common Anode:                                                                                                             *
 *                                                                                                                           *
 *  the same but low active by applying low voltage 0->LOW                                                                   *
 * Description:                                                                                                              *
 *  there will be an array to  show the number from 0 to nine                                                                *
 *                                                                                                                           *
 *****************************************************************************************************************************/



/*
NAME       : SSD_u8SetValue
DESCRIPTION: THIS SHOW THE REQUIRED PATTERN ACCORDING TO ITE TYPE COMMON ANOD OR CATHODE
             AND WHICH ONE
ARGUMENTS  : REQUIRED VALUE TO BE SHOWN ON SSD
RETURN     : ERROR STATE

*/

u8 SSD_u8SetValue(u8 Copy_u8ValuePattern,u8 Copy_u8IndexSsd);
/*
NAME       : SSD_u8SetOn
DESCRIPTION: THIS FUNCTION ENABLE REQUIRED SSD ACCORDING TO ITS TYPE
ARGUMENTS  : INDEX OF WHICH SSD IE ENABLED ACCORDING TO ITS TYPE.
RETURN     : ERROR STATE

*/
u8 SSD_u8SetOn(u8 Copy_IndexSsd);



/*
NAME       : SSD_u8SetOff
DESCRIPTION: THIS FUNCTION DISABLE REQUIRED SSD ACCORDING TO ITS TYPE
ARGUMENTS  : INDEX OF WHICH SSD IE ENABLED ACCORDING TO ITS TYPE
RETURN     : ERROR STATE

*/
u8 SSD_u8SetOff(u8 Copy_IndexSsd);

/*
 * NAME       :SSD_u8SetCustomPattern
 * DESCRIPTION: this function draws a certain pattern on a certain seven segment
 * ARGUMENTS  :number of total arguments then index and which segments u want
 * 				to draw your pattern
 * RETURN     : ERROR level
 */

u8 SSD_u8SetCustomPattern(u8 Copy_u8CountArg,...);








#endif /* SSD_INTERFACE_H_ */
