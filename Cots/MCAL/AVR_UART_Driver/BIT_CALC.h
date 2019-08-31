
/*
 * BIT_CALC.h
 *
 *  Created on: Feb 11, 2019
 *      Author: AyetAllah
 */

#ifndef BIT_CALC_H_
#define BIT_CALC_H_
#define  SET_BIT(var,bit_index)                   var|=(1<<bit_index)
#define  CLR_BIT(var,bit_index)                  (var&=~(1<<bit_index))
#define  ASSIGN_BIT(var,bit_index,value)         ((value==1)?SET_BIT(var,bit_index):CLR_BIT(var,bit_index))
#define  GET_BIT(var,bit_index)		               ((var&(1<<bit_index))>>bit_index)
/*
Here if directive has both function like macro and obj like macro so funlike has more prority than object
so we do this ,because the problem is aroused when fun-lke concatenate before replace the value should obj-like do
so we make two stages by CONC_HELP
*/
//#define  CONC_8BITS(b7,b6,b5,b4,b3,b2,b1,b0)     (CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0))
#define  CONC_8BITS(b0,b1,b2,b3,b4,b5,b6,b7)     (CONC_HELP(b0,b1,b2,b3,b4,b5,b6,b7))
#define  CONC_HELP(b0,b1,b2,b3,b4,b5,b6,b7)       0b##b7##b6##b5##b4##b3##b2##b1##b0



#endif /* BIT_CALC_H_ */
