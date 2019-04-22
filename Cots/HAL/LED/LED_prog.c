/*
 * LED_prog.c
 *
 *  Created on: Jan 29, 2019
 *      Author: AyetAllah
 */
#include"STD_TYPES.h"
#include"BIT_CALC.h"

#include"DIO_interface.h"
#include"DIO_private.h"

#include"LED_interface.h"
#include"LED_private.h"
#include "LED_config.h"


void LED_u8LedInit(void)
{
	u8 i=0;
	for(;i<NUM_LEDS;i++)
	{
		DIO_u8SetPinDirection(LED_Au8LedNumPinCh[i],DIO_PIN_HIGH);

	}

}


/*
NAME			 :LED_u8LedOn
DESCRIPTION: turn on the led according to type
ARGUMENTS  :
RETURN     :
*/
u8 LED_u8LedOn(u8 Copy_u8LedNb)
{u8 Local_u8Error=ERROR_NO;

		if(LED_Au8LedNumType[Copy_u8LedNb]==FORWARD)
		{
			Local_u8Error=DIO_u8SetPinValue(LED_Au8LedNumPinCh[Copy_u8LedNb],DIO_PIN_HIGH);
		//	if(Local_u8Error==ERROR_NO)


		}else if(LED_Au8LedNumType[Copy_u8LedNb]==REVERSE)
		{
			Local_u8Error=DIO_u8SetPinValue(LED_Au8LedNumPinCh[Copy_u8LedNb],DIO_PIN_LOW);


		}



return Local_u8Error;
}

/*
NAME			 :LED_u8LedOff
DESCRIPTION: off the led according to type
ARGUMENTS  :
RETURN     :
*/

u8 LED_u8LedOff(u8 Copy_u8LedNb)
{
	u8 Local_u8Error=ERROR_NO;

			if(LED_Au8LedNumType[Copy_u8LedNb]==FORWARD)
			{
				Local_u8Error=DIO_u8SetPinValue(LED_Au8LedNumPinCh[Copy_u8LedNb],DIO_PIN_LOW);
			//	if(Local_u8Error==ERROR_NO)


			}else if(LED_Au8LedNumType[Copy_u8LedNb]==REVERSE)
			{
				Local_u8Error=DIO_u8SetPinValue(LED_Au8LedNumPinCh[Copy_u8LedNb],DIO_PIN_HIGH);


			}


return Local_u8Error;
}
