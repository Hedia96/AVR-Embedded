/*
 * SWI_prog.c
 *
 *  Created on: Feb 7, 2019
 *      Author: AyetAllah
 */
#include"STD_TYPES.h"
#include"BIT_CALC.h"

#include"DIO_interface.h"
#include "DIO_private.h"

#include "SWI_interface.h"
#include "SWI_private.h"
#include "SWI_config.h"

/* NAME       : SWI_u8GetSwiState
 * DESCRIPTION: this fun get state by passing pointer and choose the index of which switch
 * INPUT      :
 * OUTPUT     :
 *
 */
u8 SWI_u8GetSwiState(u8 Copy_u8_Swi_Index,u8 * P_StateSw)
{u8 Local_u8Error=ERROR_NO;
 u8 Local_u8ValuePin=0;
 /*validation for that pointer isn't null and index in range of number of switches*/
 if((*P_StateSw==NULL)||(Copy_u8_Swi_Index<=NUM_SW))
 {
	 Local_u8Error=ERROR_NOK;
 }
 else{
	 DIO_u8GetPinValue(Au8SwiChannels[Copy_u8_Swi_Index],&Local_u8ValuePin);
	if(Au8SwiTypes[Copy_u8_Swi_Index] == PULLUP &&( Local_u8ValuePin ==DIO_PIN_HIGH ))
	{
		*P_StateSw=RELEASED;

	}else if(Au8SwiTypes[Copy_u8_Swi_Index] == PULLUP &&( Local_u8ValuePin ==DIO_PIN_LOW ))
	{
		*P_StateSw=PRESSED;
	}
	else if(Au8SwiTypes[Copy_u8_Swi_Index] == PULLDOWN &&( Local_u8ValuePin ==DIO_PIN_HIGH ))
	{
		*P_StateSw=PRESSED;
	}
	else if(Au8SwiTypes[Copy_u8_Swi_Index] == PULLDOWN &&( Local_u8ValuePin ==DIO_PIN_HIGH ))
	{
		*P_StateSw=RELEASED;
	}
	else
	{
		Local_u8Error=ERROR_NOK;
	}




 }
return Local_u8Error;
}


