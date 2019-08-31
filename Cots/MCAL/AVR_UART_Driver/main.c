/*lec41 uart /avr*/
#include "BIT_CALC.h"
#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "UART_interface.h"
#include "MCU_interface.h"
#include "avr/delay.h"


void TurnLedOn(void)
{
GPIO_u8SetPinValue(PORTB_PIN0,(u8)1);

}


int main(void)
{u8 Local_u8RecievedChar=0;
	GPIO_VInit();

GPIO_u8SetPinDirectionType(PORTD_PIN0,GPIO_PIN_INPUT);/*rx*/
GPIO_u8SetPinDirectionType(PORTD_PIN1,GPIO_PIN_OUTPUT);/*tx*/

GPIO_u8SetPortDirection(GPIO_PORTB,GPIO_PORT_OUTPUT);

GPIO_u8SetPortDirection(GPIO_PORTA,GPIO_PORT_OUTPUT);
GPIO_u8SetPinDirectionType(PORTA_PIN0,GPIO_PIN_OUTPUT);
/*enable global interrupt*/
MCU_VEnableGlobalInt();
UART_VInit();
//UART_SendStringSynch("ramdan");

//UART_u8SendCharSynch('z'); //okaay

//UART_VTransmitName();      //okay


//UART_SendStringAsynch("Ramdan",TurnLedOn);


while(1)
{

//TurnLedOn();
//UART_VTransmitName();
/*
UART_u8RecCharSynch(&Local_u8RecievedChar);
//_delay_ms(200);

UART_u8SendCharSynch(Local_u8RecievedChar);
_delay_ms(200);

GPIO_u8SetPortValue(GPIO_PORTB,0xff);
*/
/*
if(Local_u8RecievedChar=='s')
{
   GPIO_u8SetPortValue(GPIO_PORTB,0xff);
   _delay_ms(500);
	UART_SendStringAsynch("ramdan",TurnLedOn);
	GPIO_u8SetPortValue(GPIO_PORTB,0x00);
	_delay_ms(200);
	//_delay_ms(500);
}
*/
//UART_u8SendCharSynch('2');
UART_SendStringAsynch("Kareem",TurnLedOn);

_delay_ms(500);
//GPIO_u8SetPinValue(PORTB_PIN0,(u8)1);
	//UART_SendStringAsynch("koluyhgh",TurnLedOn);//okay
	//UART_SendStringSynch("word");
//_delay_ms(200);
}
	return 0;		
		
}





