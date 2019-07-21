
/*
 * delay_ms.c
 *
 *  Created on: Mar 12, 2019
 *      Author: AyetAllah
 */

#ifndef DELAY_MS_C_
#define DELAY_MS_C_


#include "STD_TYPES.h"

void  extern Delay_ms(u32 value)
{


u32 i=0,j=0;
for(;i<value;i++)
{
	for(j=0;j<208;j++)
	{
			asm("NOP");
			asm("NOP");
			asm("NOP");
			asm("NOP");
			//asm("NOP");
		    //asm("NOP");
		    //asm("NOP");
		    //asm("NOP");
	}

}
}



#endif /* DELAY_MS_C_ */
