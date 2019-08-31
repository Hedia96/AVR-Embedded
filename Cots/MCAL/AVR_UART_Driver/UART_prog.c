/*
 * UART_prog.c
 *
 *  Created on: May 5, 2019
 *      Author: AyetAllah
 */
#include "STD_TYPES.h"
#include "BIT_CALC.h"

#include "UART_private.h"
#include "UART_confg.h"
#include "UART_interface.h"
#include "GPIO_interface.h"
/*APIs*/
	static  u8 * Datau8String;

	u16 static volatile  Global_u16_Index_String=0;
	/*to avoid  optimization because it is not modified in scope but in ISR*/

	static Ptr_to_VFunction_t P_TX_AsynchCallBack;

void UART_VInit(void)
{
	/*1-*/

	/*UCSRA=0b00000000;
	UCSRC=0b10000110;
	UBRRL=51;
	*/
	/*enable last step*/
	/*
	UCSRB=0b00111000;
	*/

	/*CHECK PARITY */
	if(UART_PARITY_TYPE != PARTIY_TYPE_NONE)
	{
		switch(UART_PARITY_TYPE)
		{
		case PARTIY_TYPE_EVEN:
			UCSRC|=(1<<UPM1);
			break;
		case PARTIY_TYPE_ODD:
			UCSRC|=(1<<UPM1)|(1<<UPM0)|(1<<URSEL);
			break;

		}
	}
	/*BAUD RATE FOR 8MHZ TILL NOW DOESN'T NEED UBRRH REGISTER SO THE WORK ON USCRC
 SO LAST BIT IN THE REGISTER USCRC SHOULD EQUAL ONE*/
	switch (UART_BAUDRATE) {
		case 9600:
					UBRRL=51;
			break;


	}

	/*SIZE OF DATA BITS*/
	switch(UART_NO_BITS_DATA)
	{
	case DATA_BITS_5:
		UCSRC&=~(1<<UCSZ0);
		UCSRC&=~(1<<UCSZ1);
		break;
	case DATA_BITS_6:
		UCSRC|=(1<<UCSZ0)|(1<<URSEL);
		UCSRC&=~(1<<UCSZ1);
		break;
	case DATA_BITS_7:
		UCSRC|=(1<<UCSZ1)|(1<<URSEL);
		UCSRC&=~(1<<UCSZ0);
			break;
	case DATA_BITS_8: //deafult in register
		UCSRC |= (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
			break;
	case DATA_BITS_9:
		UCSRC|=(1<<UCSZ0)|(1<<UCSZ1)|(1<<UCSZ2 );
				break;

	}
	/*stop bits*/
	switch(UART_NO_BITS_STOP)
	{case 1:
		UCSRC&=~(1<<USBS);
		break;
	case 2:
		UCSRC|=(1<<USBS);
		break;


	}

	/*******enable interrupt ******/
	/*
	if(RX_COMPLETE_INTERRUPT ==ENABLE)
			{
				UCSRB|=(1<<RXCIE);
			}
			if(TX_COMPLETE_INTERRUPT ==ENABLE)
			{
				UCSRB|=(1<<TXCIE);
			}
			*/
/****enable communication****/

		UCSRB|=(1<<TXEN)|(1<<RXEN);
			//UCSRB|=(1<<TXEN)|(1<<RXEN)|(1<<UDRIE);

}

void UART_SetCallBackAsynchModeTX(Ptr_to_VFunction_t Function)
{
	P_TX_AsynchCallBack=Function;
}

void UART_VTransmitName(void)
{
u8 Name[]="aya";
u8 i=0;
while(Name[i]!='\0')
{
	//UDR=Name[i];
	//while(!(UCSRA & (1<<TXC)));
	while(!(UCSRA & (1<<UDRE)));
	UDR=Name[i];
	i++;
    //UCSRA&=~(1<<TXC);/*clear the flag*/
}
}

u8 UART_u8SendCharSynch(u8 Copy_u8char)
{
	u8 Local_u8ErrorState=ERROR_NO;
     /*check before transmit if there is a transmit is ongoing before begin a new one*/

	/*UDRE is 1 so the buffer is ready to recieve new data to transmit
	 * 		        */
	//if((UCSRA & (1<<UDRE)))
	//{
		UDR=Copy_u8char;
	//}else
	//{
		/*there is ongoing transmition so we should wait on UDRE flag(uart data register empty) till  it set*/
		//Local_u8ErrorState=ERROR_NOK;

	//}

return Local_u8ErrorState;
}
u8 UART_u8RecCharSynch(u8 *Copy_Pu8RecievedData)
{

u8 Local_u8ErrorState=ERROR_NO;
/*input validation for pointer if it equalls Null or doesn't */
if(Copy_Pu8RecievedData!=NULL)
{
	//mointor the recieved flag if 1 that means in reciever buffer
	// is full of un read data is not empty (empty here means the data in buffer full of data readed before)
	while(!(UCSRA &(1<<RXC)));
    *Copy_Pu8RecievedData=UDR;


}
else
{
	Local_u8ErrorState=ERROR_NOK;
}

return Local_u8ErrorState;
}
u8 UART_u8RecStringSynch(u8 * Copy_p_RecievedData,u8 Length)
{
	u8 Local_u8ErrorState=ERROR_NO;
	int i=0;
	if(Copy_p_RecievedData!=NULL)
	{
		for(i=0;i<Length;i++)
		{

			while(!(UCSRA &(1<<RXC)));
			Copy_p_RecievedData[i]=UDR;

		}

	}
	else
	{
		Local_u8ErrorState=ERROR_NOK;
	}

}

void UART_EnableCommunication(void)
{/*enable transmit, reciever  ,enable then empty data interrupt*/
UCSRB|=(1<<TXEN)|(1<<RXEN)|(1<<UDRIE);
}
void UART_EnableInterrupt(void)
{
	if(RX_COMPLETE_INTERRUPT ==ENABLE)
	{
		UCSRB|=(1<<RXCIE);
	}
	if(TX_COMPLETE_INTERRUPT ==ENABLE)
	{
		UCSRB|=(1<<TXCIE);
	}
}
/* Name       : UART_u8SendStringSynch
 * Description: This function shall send the string (array of char) but how it transmits every char it send shall poll on it till certain time and
 * 				the flag will set which of them is closer or happen first if the flag isn't set within the time out which is configured in pre-build
 * 				configuration
 *
 *
 * Arguments: pointer to const char
 *
 * Return: error state is ok
 *
 */
void UART_SendStringSynch(const  u8 * Copy_ptr_u8Data)
{   u8 Local_ErrorState=ERROR_NO;

	//how i check the flow is right(send then clear ) and return somthing to indicate that are right
	u16 i=0;
	u16 timeout=0;
	if(Copy_ptr_u8Data!=NULL)
	{
		while(Copy_ptr_u8Data[i]!='\0')
		{
			//UART_u8SendCharSynch(Copy_ptr_u8Data[i]);//check the value is ok or it is coorupted because it leaves its scope
			UDR=Copy_ptr_u8Data[i];
			/*
			 * TXC is flag indicate the transmission is complete (there is no new data and shift register is done) -> set
			 * when it equals zero it means still the buffer transmits
			 *
			 */
//
			//while((!(UCSRA & (1<<TXC)))) make hastule and send half of word
			while((!(UCSRA & (1<<UDRE)))&& timeout<UART_TIMEOUT_SYNCH_FUNCTION)
			{
			// just wait (( polling )) and this loop wait  till the transmit complete flag  will be 1 then
			timeout++;
			}

//////check if is still true

			i++;

			/*clear flag  TxC write 0 due to we didn't enable the interrupt */
/*
			if(UCSRA & (1<<TXC))
			{
				UCSRA&=~(1<<TXC);
			}
*/
		}
		/*condition exit*/
			/*
			if(timeout==UART_TIMEOUT_SYNCH_FUNCTION &&(UCSRA & (1<<TXC)))
			{

			}
		*/

	}else
	{
		Local_ErrorState=ERROR_NOK;
	}
	//return Local_ErrorState

}

void UART_SendStringAsynch(const  u8 * Copy_ptr_u8Data,Ptr_to_VFunction_t Copy_VFunction)
{
	Datau8String=Copy_ptr_u8Data;
	//UART_SetCallBackAsynchModeTX(Copy_VFunction);
	P_TX_AsynchCallBack=Copy_VFunction;
	/*enable interrupt for tx*/

	Global_u16_Index_String=0;

	if(Datau8String[Global_u16_Index_String]!='\0')
	{
		UDR=Datau8String[Global_u16_Index_String];



	}
	/*enable interrupt empty register */
	UCSRB|=(1<<UDRIE);
	UCSRB|=(1<<TXCIE);
}


void __vector_14(void)/*isr for data empty register */
{
	Global_u16_Index_String++;

	if(Datau8String[Global_u16_Index_String]!='\0')
	{
		UDR=Datau8String[Global_u16_Index_String];

	}
	else
	{
		/*disable interrupt*/
		UCSRB&=~(1<<UDRIE);

		P_TX_AsynchCallBack();/*to know it is finished */
		Global_u16_Index_String=0;

	}
}

void __vector_13(void)/*reciver complete*/
{

}

void __vector_15(void)/*the transmiter complete */

{
	Global_u16_Index_String++;
	GPIO_u8SetPinValue(PORTB_PIN0,(u8)1);
	if(Datau8String[Global_u16_Index_String]!='\0')
	{
		UDR=Datau8String[Global_u16_Index_String];
	}
	else
	{

		/*disable interrupt*/
		UCSRB&=~(1<<TXCIE);
		P_TX_AsynchCallBack();
		/*to know it is finished */
		Global_u16_Index_String=0;


	}

}


