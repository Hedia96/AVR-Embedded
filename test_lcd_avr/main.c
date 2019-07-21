
#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "GPIO_interface.h"
#include "LCD_interface.h"
#include "avr/delay.h"

int main(void)
{
GPIO_VInit();

GPIO_u8SetPortDirection(GPIO_PORTA,GPIO_PORT_OUTPUT);
//GPIO_u8SetPortDirection(GPIO_PORTD,GPIO_PORT_OUTPUT);
 GPIO_u8SetPortDirection(GPIO_PORTC,GPIO_PORT_OUTPUT);
/*
GPIO_u8SetPinValue(PORTD_PIN7,GPIO_PIN_HIGH);
_delay_ms(100);
GPIO_u8SetPinValue(PORTD_PIN7,GPIO_PIN_LOW);
*/
LCD_VInitialize();

//LCD_u8SymbolDisplay(0b01000001,0,0);
LCD_WriteStringInPosition("aya", 0, 0);


	while(1)
	{
//GPIO_u8SetPortValue(GPIO_PORTC,5);
		//GPIO_u8SetPortValue(GPIO_PORTA,0xFF);
		//GPIO_u8SetPortValue(GPIO_PORTD,0xFF);
		//GPIO_u8SetPortValue(GPIO_PORTC,0xFF);

	}

return 0;

}
