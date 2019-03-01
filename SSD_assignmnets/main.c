/*
 * main.c
 *
 *  Created on: Feb 11, 2019
 *      Author: AyetAllah
 */



#include"STD_TYPES.h"
#include "BIT_CALC.h"
#include "util/delay.h"

#include"DIO_interface.h"

#include"SSD_interface.h"
//#include"SSD_config.h"
//#include "SSD_private.h"

/*
 *first assignment
 */
int main()
{
	int i,j;

while(1)
{
	for(i=0;i<=9;i++)
	{
		for(j=0;j<50;j++)
		{
		SSD_u8SetOff(1);
		SSD_u8SetOn(0);
		SSD_u8SetValue(i,0);
		_delay_ms(10);
		//}
		//for(j=0;j<50;j++)
		//{
		        SSD_u8SetOff(0);
				SSD_u8SetOn(1);
				SSD_u8SetValue(9-i,1);
			   _delay_ms(10);
		}


	}
}
return 0;
}

