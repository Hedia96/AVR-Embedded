/*
 * main.c
 *
 *  Created on: Feb 11, 2019
 *      Author: AyetAllah
 */



#include"STD_TYPES.h"
#include "BIT_CALC.h"
#include "util/delay.h"
#include"DIO_private.h"
#include"DIO_interface.h"

#include"SSD_interface.h"

//#include"SSD_config.h"
//#include "SSD_private.h"

/*
 *first assignment
 */
/*
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
		SSD_u8SetOff(2);
		SSD_u8SetOff(3);
		SSD_u8SetOn(0);
		SSD_u8SetValue(9-i,0);
		_delay_ms(1);

        SSD_u8SetOff(0);
        SSD_u8SetOff(2);
        SSD_u8SetOff(3);
		SSD_u8SetOn(1);
		SSD_u8SetValue(9-i,1);
	   _delay_ms(1);
	   SSD_u8SetOff(0);
      SSD_u8SetOff(1);
      SSD_u8SetOff(3);
	  SSD_u8SetOn(2);
	  SSD_u8SetValue(i,2);
	  	_delay_ms(1);
	    SSD_u8SetOff(0);
	       SSD_u8SetOff(1);
	       SSD_u8SetOff(2);
	 	  SSD_u8SetOn(3);
	 	  SSD_u8SetValue(i,3);
	   	   _delay_ms(1);
		}


	}
}
return 0;
}

*/

/*global variables for stop watch*/

/*
    u8 u8_count_ms=0;
	u8 u8_count_s=0;
	u8 u8_count_ms_1digit=0;
	u8 u8_count_ms_2digit=0;
	u8 u8_count_s_1digit=0;
	u8 u8_count_s_2digit=0;
*/

/*stop watch*/
	/*
int main()
{

	//int j=0;

	//for(j=0;j<50;j++)
		//	{
	//DIO_u8SetPinDirection(DIO_PIN8,DIO_PIN_OUTPUT);
    //((Register_8bit*)DDRB_ADDRESS) ->ByteAccess=0xFF;


	while(1)
	{
		if(u8_count_ms_1digit <=9)
			{

			}
		else{
			u8_count_ms_1digit=0;
			u8_count_ms_2digit++;

		   }
		if(u8_count_ms_2digit<=9)
		{

		}else
		{
			u8_count_ms_2digit=0;
			u8_count_s_1digit++;
		}
		if(u8_count_s_1digit<=9)
		{

		}else
		{
			u8_count_s_1digit=0;
			u8_count_s_2digit++;
		}
		if(u8_count_s_2digit==9)
		{
			     u8_count_ms_1digit=0;
				 u8_count_ms_2digit=0;
				 u8_count_s_1digit=0;
				 u8_count_s_2digit=0;

		}
//DIO_u8SetPinValue(DIO_PIN8,DIO_PIN_HIGH);
		//((Register_8bit*)PORTB_ADDRESS) ->ByteAccess=0x01;


			SSD_u8SetOff(0);
			SSD_u8SetOff(1);
			SSD_u8SetOff(2);
			SSD_u8SetOn(3);
			SSD_u8SetValue(u8_count_ms_1digit,3);
			//_delay_ms(10);
			_delay_ms(3);
		    u8_count_ms_1digit++;

			SSD_u8SetOff(3);
			SSD_u8SetOn(2);
			SSD_u8SetValue(u8_count_ms_2digit,2);
			_delay_ms(3);
			SSD_u8SetOff(2);
			SSD_u8SetOn(1);
			SSD_u8SetValue(u8_count_s_1digit,1);
			_delay_ms(3);
		    SSD_u8SetOff(1);
		    SSD_u8SetOn(0);
		    SSD_u8SetValue(u8_count_s_2digit,0);
      	    _delay_ms(3);

		}

		//DIO_u8SetPinValue(DIO_PIN8,DIO_PIN_LOW);
		//((Register_8bit*)PORTB_ADDRESS) ->ByteAccess=0x00;
return 0;
}


*/

/*snake*/
//#include<stdarg.h>
int main(void)
{
	while(1)
	{
		SSD_u8SetOn(3);
		SSD_u8SetOff(1);
		SSD_u8SetOff(2);
		SSD_u8SetOff(0);

		SSD_u8SetValue('b',3);
		_delay_ms(100);
		SSD_u8SetValue('a',3);
		_delay_ms(100);

		SSD_u8SetOff(3);
		SSD_u8SetOn(2);
		SSD_u8SetValue('a',2);
		_delay_ms(100);

		SSD_u8SetOff(2);
		SSD_u8SetOn(1);
		SSD_u8SetValue('a',1);
		_delay_ms(100);


		SSD_u8SetOff(1);
		SSD_u8SetOn(0);
		SSD_u8SetValue('a',0);
		_delay_ms(100);
		SSD_u8SetValue('f',0);
		_delay_ms(100);
		SSD_u8SetValue('e',0);
		_delay_ms(100);
		SSD_u8SetValue('d',0);
		_delay_ms(100);

		SSD_u8SetOff(0);
		SSD_u8SetOn(1);
		SSD_u8SetValue('d',1);
		_delay_ms(100);

		SSD_u8SetOff(1);
		SSD_u8SetOn(2);
		SSD_u8SetValue('d',2);
		_delay_ms(100);
		SSD_u8SetOff(2);
		SSD_u8SetOn(3);
		SSD_u8SetValue('d',3);
		_delay_ms(100);
		SSD_u8SetValue('c',3);
		_delay_ms(100);



	}

return 0;
}
