/*
 * DIO_prog.c
 *
 *  Created on: Feb 11, 2019
 *      Author: AyetAllah
 */
/**********************************************************************************************************************
 *created: 29 jan 2019                                                                                                *
 *Author: Aya Abdelmagied                                                                                             *
 *Description                                                                                                         *
 * ------------------                                                                                                 *                                                                                                                     *
 *  This Driver for MCAL layer ,this component is called Digital input output(DIO)                                    *                                                                                                                *
 ******************************************************************************************************************** */


#include"STD_TYPES.h"
#include"BIT_CALC.h"
//library

// lower  layer if exists

// owner drivers
#include"DIO_interface.h"
#include"DIO_private.h"
#include"DIO_config.h"

/* NAME       : DIO_VInit
 * DESCRIPTIVE:INITAL CopyValue  FOR SOME REGISTERS LIKE PORTX AND DDRX
 * AEGUMENTS  :N/A
 * RETURN     :N/A
 */


void DIO_VInit(void)
{

  DDRD=CONC_8BITS(DIO_PIN0_Dir,DIO_PIN1_Dir,DIO_PIN2_Dir,DIO_PIN3_Dir,DIO_PIN4_Dir,DIO_PIN5_Dir,DIO_PIN6_Dir,DIO_PIN7_Dir);
  DDRB=CONC_8BITS(DIO_PIN8_Dir,DIO_PIN9_Dir,DIO_PIN10_Dir,DIO_PIN11_Dir,DIO_PIN12_Dir,DIO_PIN13_Dir,DIO_PIN14_Dir,DIO_PIN15_Dir);
  DDRC=CONC_8BITS(DIO_PIN16_Dir,DIO_PIN17_Dir,DIO_PIN18_Dir,DIO_PIN19_Dir,DIO_PIN20_Dir,DIO_PIN21_Dir,DIO_PIN22_Dir,DIO_PIN23_Dir);
  DDRD=CONC_8BITS(DIO_PIN24_Dir,DIO_PIN25_Dir,DIO_PIN26_Dir,DIO_PIN27_Dir,DIO_PIN28_Dir,DIO_PIN29_Dir,DIO_PIN30_Dir,DIO_PIN31_Dir);

  PORTA=CONC_8BITS(DIO_PIN0_VALUE,,DIO_PIN2_VALUE,DIO_PIN3_VALUE,DIO_PIN4_VALUE,DIO_PIN5_VALUE,DIO_PIN6_VALUE,DIO_PIN7_VALUE);
  PORTB=CONC_8BITS(DIO_PIN8_VALUE,DIO_PIN9_VALUE,DIO_PIN10_VALUE,DIO_PIN11_VALUE,DIO_PIN12_VALUE,DIO_PIN13_VALUE,DIO_PIN14_VALUE,DIO_PIN15_VALUE);
  PORTC=CONC_8BITS(DIO_PIN16_VALUE,DIO_PIN17_VALUE,DIO_PIN18_VALUE,DIO_PIN19_VALUE,DIO_PIN20_VALUE,DIO_PIN21_VALUE,DIO_PIN22_VALUE,DIO_PIN23_VALUE);
  PORTD=CONC_8BITS(DIO_PIN24_VALUE,DIO_PIN25_VALUE,DIO_PIN26_VALUE,DIO_PIN27_VALUE,DIO_PIN28_VALUE,DIO_PIN29_VALUE,DIO_PIN30_VALUE,DIO_PIN31_VALUE);

}
/* NAME         :DIO_u8SetPinDirection
 *  DESCRIPTION :THIS fUNCTION ADD DIRECTION OUT OR IN IN DDRX THIS INDCATE WHICH REGISTER MICRO PROCESSOR WRITES(PINX) READS
 *  			       (PORTX)
 *  ARGUMENTS   :INDEX OF NUMBER PIN FROM (0->31),DIRECTION IS INPUT OR OUTPUT
 *  RETURN      : ERROR STATE INDCATES OR VERIFIES THE STATE OF FUNCTION
 *
 */

u8 DIO_u8SetPinDirection(u8 Copy_u8PinNb,u8 Copy_u8Direction)
{
	u8 Local_u8Error=ERROR_NO;
	u8 Local_u8PortNb ;
	u8 Local_u8PinNb;


	if((Copy_u8PinNb >=DIO_MAXPINNB)|| ((Copy_u8Direction != DIO_PIN_OUTPUT )&& (Copy_u8Direction != DIO_PIN_INPUT)))
	{/*condition of error */
		/*((u8PinNB >=DIO_MAXPINNB)||( Copy_u8Direction !=DIO_OUTPUT && Copy_u8Direction !=DIO_INPUT))*/
		//more readable
		Local_u8Error=ERROR_NOK;

	}
	else
	{      /*get the number of port and number of pin number*/
			//u8 Local_u8PortNb = u8PinNB /8;
			// not magic number
			 Local_u8PortNb = Copy_u8PinNb /NUMBER_PINS_IN_PORT;
			 Local_u8PinNb  = Copy_u8PinNb % NUMBER_PINS_IN_PORT;
			// put direction in
		switch(Local_u8PortNb)
		  {
			case DIO_PORTA:
			ASSIGN_BIT(DDRA,Local_u8PinNb,Copy_u8Direction);
//			SET_BIT(DDRA,Local_u8PinNb);
				break;
			case DIO_PORTB:
				ASSIGN_BIT(DDRB,Local_u8PinNb,Copy_u8Direction);
				break;
			case DIO_PORTC:
				ASSIGN_BIT(DDRC,Local_u8PinNb,Copy_u8Direction);
				break;
			case DIO_PORTD:
				ASSIGN_BIT(DDRD,Local_u8PinNb,Copy_u8Direction);
				break;
			//default:u8Error =ERROR_NOK;

			}
     }
	return Local_u8Error;


}

/* Name       : DIO_u8SetPinValue
 * Description: This function set a certain  value to  a specific value
 * OUTPUT     : return the state  of that function ERRor_NO if all thing is right or ERROR_NOK if something wrong
 * 				      its type
 * INPUT      : PinNb and this value
 */
u8 DIO_u8SetPinValue(u8 Copy_u8PinNb,u8 Copy_u8Value)
{
	u8 Local_u8Error=ERROR_NO;
	u8 Local_u8PortNb;
	u8 Local_u8PinNb;
  if((Copy_u8PinNb >=DIO_MAXPINNB)|| ((Copy_u8Value !=DIO_PIN_LOW) && (Copy_u8Value!=DIO_PIN_HIGH) ))
		{
			Local_u8Error=ERROR_NOK;

		}
		else
		{      /*get the number of port and number of pin number*/
				//u8 Local_u8PortNb = u8PinNB /8;
				// not magic number
				Local_u8PortNb = Copy_u8PinNb /	NUMBER_PINS_IN_PORT;
				Local_u8PinNb=Copy_u8PinNb % NUMBER_PINS_IN_PORT;
				// put direction in
			switch(Local_u8PortNb)
			  {
				case DIO_PORTA:
					ASSIGN_BIT(PORTA,Local_u8PinNb,Copy_u8Value);
//					SET_BIT(PORTA,Local_u8PinNb);
					break;
				case DIO_PORTB:
					ASSIGN_BIT(PORTB,Local_u8PinNb,Copy_u8Value);
					break;
				case DIO_PORTC:
					ASSIGN_BIT(PORTC,Local_u8PinNb,Copy_u8Value);
					break;
				case DIO_PORTD:
					ASSIGN_BIT(PORTD,Local_u8PinNb,Copy_u8Value);
					break;
				default:
					Local_u8Error =ERROR_NOK;

				}
	     }
		return Local_u8Error;


}


/* NAME          :DIO_u8GetPinValue
 * Description  : get a value from bin and put this in * pointer
                  is passed by
 * INPUT        :Copy_u8PinNb,u8PtrToValue
 * OUTPUT       : ERROR STATE
 */

u8 DIO_u8GetPinValue(u8 Copy_u8PinNb,u8* u8PtrToValue)
{
	u8 Local_u8Error=ERROR_NO;
	u8 Local_u8PortNb ;
	u8 Local_u8PinNb;
	if(Copy_u8PinNb < DIO_MAXPINNB && u8PtrToValue !=NULL )
		{
		               /*get the number of port and number of pin number*/
						//u8 Local_u8PortNb = u8PinNB /8;
						// not magic number
						Local_u8PortNb = Copy_u8PinNb /	NUMBER_PINS_IN_PORT;
						Local_u8PinNb=Copy_u8PinNb % NUMBER_PINS_IN_PORT;
						// put direction in
						switch(Local_u8PortNb)
								  {
									case DIO_PINA:
								    *(u8PtrToValue)=GET_BIT(PINA,Local_u8PinNb);
										break;
									case DIO_PINB:
										*(u8PtrToValue)=GET_BIT(PINB,Local_u8PinNb);
										break;
									case DIO_PINC:
										*(u8PtrToValue)=GET_BIT(PINC,Local_u8PinNb);
										break;
									case DIO_PIND:
										*(u8PtrToValue)=GET_BIT(PIND,Local_u8PinNb);
										break;
									default:
										Local_u8Error=ERROR_NOK;

									}





		}else
		{
			Local_u8Error=ERROR_NOK;
		}

return Local_u8Error;

}


/*
 * NAME         : DIO_u8SetPortDirection
 * DESCRIPTION  : THIS FUNCTION SET THE DIRECTION FOR DDRX AS AWHOLE BYTE
 * ARGUMENTS    : NNUMBER OF THE REGISTER FROM 0:3 AND DIRECTION IS INPUT OR OUTPUT
 * RETURN       :ERROR STATE
 */


u8 DIO_u8SetPortDirection(u8 Copy_u8PortNb, u8 Copy_u8Direction)
{
	u8 Local_u8Error=ERROR_NO;


		if(Copy_u8PortNb==DIO_DDRA)
			DDRA=Copy_u8Direction;
		else if(Copy_u8PortNb==DIO_DDRB)
			DDRB=Copy_u8Direction;
		else if(Copy_u8PortNb==DIO_DDRC)
			DDRC=Copy_u8Direction;
		else if(Copy_u8PortNb==DIO_DDRD)
			DDRD=Copy_u8Direction;
		else
			Local_u8Error=ERROR_NOK;

return Local_u8Error;
}



/*
 *  NAME        : DIO_u8SetPortValue
 * DESCRIPTION  : THIS FUNCTION SET THE Copy_u8Value FOR PORTX AS AWHOLE BYTE
 * ARGUMENTS    : NNUMBER OF THE REGISTER FROM 0:3 AND Copy_u8Value IS HEX NUMBER
 * RETURN       :ERROR STATE
 */

u8 DIO_u8SetPortValue(u8 Copy_u8PortNb,u8 Copy_u8Value)
{
	u8 Local_u8Error=ERROR_NO;
	switch(Copy_u8PortNb)
	{
	case DIO_PORTA:
		PORTA=Copy_u8Value;
		break;
	case DIO_PORTB:
		PORTA=Copy_u8Value;
		break;
	case DIO_PORTC:
			PORTC=Copy_u8Value;
			break;
	case DIO_PORTD:
			PORTD=Copy_u8Value;
			break;
	default:
		Local_u8Error=ERROR_NOK;
	}
return Local_u8Error;
}

/*Name       :DIO_u8GetPortValue
 *Description:get Copy_u8Value as whole byte from register PINx read by Micro-controller so it gets
 *Arguments  :number of pinA,B,C,D and the variable should Copy_u8Value returned in it
 *Return     :Error state is ok or no
 */
u8 DIO_u8GetPortValue(u8 u8PortNB,u8* u8PCopyValue)
{
	u8 Local_u8Error=ERROR_NO;

	switch(u8PortNB)
	{
	case DIO_PINA:
		*(u8PCopyValue)=PINA;
		break;
	case DIO_PINB:
		*(u8PCopyValue)=PINB;
		break;
	case DIO_PINC:
		*(u8PCopyValue)=PINC;
			break;
	case DIO_PIND:
		*(u8PCopyValue)=PIND;
			break;
	default:
		Local_u8Error=ERROR_NOK;


	}
	return Local_u8Error;
}






