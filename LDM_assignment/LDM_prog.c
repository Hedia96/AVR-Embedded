/*
 * LMD_prog.c
 *
 *  Created on: Feb 12, 2019
 *      Author: AyetAllah
 */

#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "util/delay.h"

#include"DIO_interface.h"

#include "LDM_interface.h"
#include "LDM_private.h"



/*
 * NAME: LDM_u8DisplayFrame
 * DESCRIPTION: this function draw an image on led display matrix (array for col or image )\
 * according to its type is configured in LDM_config.h and choose the color
 * ARGUMENT: array for active leds () and  color(select which any pins is repeated col or row
 * OUTPUT: error state
 */

u8 LDM_u8DisplayFrame(u8 * Copy_Au8Image,u8 Copy_Color)

{
	u8 Local_u8Error=ERROR_NO;
	u8 Local_i=0;

	DIO_VInit();
	DIO_u8SetPortDirection(LDM_PORT_IMAGE_RED ,DIO_PORT_HIGH);
	DIO_u8SetPortDirection(LDM_PORT_IMAGE_GREEN,DIO_PORT_HIGH);
	DIO_u8SetPortDirection(LDM_PORT_ACTIVE,DIO_PORT_HIGH);

	switch(Copy_Color)
	{
	case LDM_RED:

		for(;Local_i<LDM_SIZE;Local_i++)
			{

			DIO_u8SetPortValue(LDM_PORT_ACTIVE,LDM_ActiveVector[Local_i]);
			if(LDM_HARDWARE_TYPE_COMMON == LDM_COMMON_ROW)/*Volt of image COL connected to high*/
			{
		    	DIO_u8SetPortValue(LDM_PORT_IMAGE_RED,Copy_Au8Image[Local_i]);
		    	//my case active high as number given by user
			}
			_delay_ms(2);
			}

		break;
	case LDM_GREEN:

		for(;Local_i<LDM_SIZE;Local_i++)
			{
			DIO_u8SetPortValue(LDM_PORT_ACTIVE,LDM_ActiveVector[Local_i]);
			DIO_u8SetPortValue(LDM_PORT_IMAGE_GREEN,Copy_Au8Image[Local_i]);
			_delay_ms(2);

			}

		break;
	default:
		Local_u8Error=ERROR_NOK;
	}
	return Local_u8Error;

}



