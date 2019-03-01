/*
 * STD_TYPES.h
 *
 *  Created on: Feb 11, 2019
 *      Author: AyetAllah
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_


#define ERROR_NOK     1
#define ERROR_NO      0
#define NULL          ((void *)0)
#define MIN_U8        (u8) 0



typedef unsigned char          u8;
typedef unsigned short int     u16;
typedef unsigned long int      u32;
typedef unsigned long long int u64;

typedef signed char            s8;
typedef signed short int       s16;
typedef signed long int        s32;
typedef signed long long int   s64;

typedef float                  f32;
typedef double                 f64;


typedef union
{
	struct
	{
		u8 bit0 :1;
		u8 bit1 :1;
		u8 bit2 :1;
		u8 bit3 :1;
		u8 bit4 :1;
		u8 bit5 :1;
		u8 bit6 :1;
		u8 bit7 :1;

	}BitAccess;
	u8 ByteAccess;

}Register_8bit;



#endif /* STD_TYPES_H_ */
