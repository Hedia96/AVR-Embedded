/*
 * LCD_prog.c
 *
 *  Created on: Mar 12, 2019
 *      Author: AyetAllah
 */

#ifndef LCD_PROG_C_
#define LCD_PROG_C_


#include "STD_TYPES.h"
#include "BIT_CALC.h"

#include "GPIO_interface.h"
#include "LCD_interface.h"

#include "LCD_config.h"
#include"LCD_private.h"

#include "avr/delay.h"

/*commands are decleard in private file*/


/*******************************************************APIS***********************************************************/






/* NAME         :LCD_VInitialize
 *
 * DESCRIPPTION : this function  does some steps in lcd
 *                1-function set
 *                2-display on/off
 *                3-clear
 *                4-Entry Mode
 *                for both modes in 8 bit mode  and 4 bit mode
 *
 * ARGUMENTS    : void
 * RETURN       : void
 */

void LCD_VInitialize(void)
{

#if LCD_BIT_MODE == EightBit
	//LCD_BIT_MODE   EightBit
	WriteCommand(FUNCTIONSET_2LINES_SFONT);
	_delay_ms(100);
	WriteCommand(DISPLAY_ON_Cursor_off_Blink_off);
	_delay_ms(100);
	WriteCommand(DISPLAY_CLEAR);
	_delay_ms(100);

#elif LCD_BIT_MODE == FourBit
	_delay_ms(100);
	WriteCommand(FUNCTIONSET_4MODE_2LINES_SFONT);
	_delay_ms(20);
	WriteCommand(DISPLAY_ON_Cursor_off_Blink_off);
	_delay_ms(100);
	WriteCommand(DISPLAY_CLEAR);
	_delay_ms(100);



#endif

}



/* NAME         : LCD_WriteStringInPosition
 *
 * DESCRIPPTION : this function takes the string and writes in certain position according to size of lcd  WxH  and
 * 			   it takes into its consideration  the boundries of lcd which are reflected to memories in DDRAM
 * 			   for all types lcd 16x2,20x2,40x2.....etc
 *
 * ARGUMENTS    : string you want write and certain position  according to size of lcd ,which is configured in a configuration file
 * RETURN       : error state level
 */
 u8 LCD_WriteStringInPosition(u8 *Copy_u8PString,u8 Copy_Xpos,u8 Copy_Ypos)
{

	 /*hight is y axis
	 width is x axis*/
	  u8 Local_u8ErrorState=ERROR_NOK;
     u8 Local_u8_AddressDDRAM=0x00;
	  /*********************INPUT VALIDATION**************************/

	  if (Copy_u8PString == NULL ||Copy_Xpos >LCD_SIZE_WIDTH ||Copy_Ypos >LCD_SIZE_HIGHT)
	  {
		return Local_u8ErrorState;
	  }

	  switch(LCD_W_H)
	  {
	  case LCD_16_2:
		  	  	  	  Local_u8_AddressDDRAM=(Copy_Ypos*ADDRESS_2ND_ROW)+Copy_Xpos;
		  	  	  	  Local_u8_AddressDDRAM|=COMMAND_SET_ADDRESS_DDRAM;    /* 1 xxx xxxx  where x's are bits indicate to address in DDRAM */
		  	  	  	  WriteCommand(Local_u8_AddressDDRAM); /*this command goes to DDRAM */

		  	  	  	  while(*Copy_u8PString !='\0')
		  	  	  	  {

		  	  	  		  if(Local_u8_AddressDDRAM == LCD_16_2_BOUNDRY_1STLINE_ADDRESS_DDRAM)
		  	  	  		  /*boundry first line in lcd 16x2 from 0x00 to 0x0f so after that willbe  10
		  	  	  		  and  if we add 1 before that address cause the command to get location in DDRAM (1 xxx xxxx)  */
		  	  	  		  {
		  	  	  			  Local_u8_AddressDDRAM=ADDRESS_2ND_ROW;
		  	  	  			  Local_u8_AddressDDRAM|=COMMAND_SET_ADDRESS_DDRAM;
		  	  	  			  WriteCommand(Local_u8_AddressDDRAM);



		  	  	  		  }else if (Local_u8_AddressDDRAM == LCD_16_2_BOUNDRY_2NDLINE_ADDRESS_DDRAM)
		  	  	  		  {
		  	  	  			  Local_u8_AddressDDRAM=ADDRESS_1ST_ROW;
		  	  	  			  Local_u8_AddressDDRAM|=COMMAND_SET_ADDRESS_DDRAM;
		  	  	  		      WriteCommand(Local_u8_AddressDDRAM);
		  	  	  		  }
		  	  	  	      WriteChar(*Copy_u8PString);
		  	  	  	      Copy_u8PString++;
		  	  	  	      Local_u8_AddressDDRAM++;
		  	  	  	  }
		  	  	  	  Local_u8ErrorState=ERROR_NO;

		              break;
	  case LCD_40_2:
		  break;
	  case LCD_20_2:
		  break;
	  case LCD_20_4:
	 		  break;
	  default:
		  Local_u8ErrorState=ERROR_NOK;


	  }




return Local_u8ErrorState;

}





 /* NAME         :LCD_ClearDisplay
  * DESCRIPPTION : this function  clears the screen  totally
  * ARGUMENTS    : void
  * RETURN       : void
  */
 void LCD_ClearDisplay(void)
 {
	 WriteCommand(DISPLAY_CLEAR);
 }

 u8 LCD_u8SymbolDisplay( u8 Copy_u8CharCodeCGROM, u8 Copy_u8Xpos,u8 Copy_u8Ypos)
 {
	 /*Local Variable holding the error state*/
	 	u8 Local_u8Error = ERROR_NO;
	 	u8 Local_u8Address;
	 	if ((Copy_u8Xpos >= LCD_SIZE_WIDTH) || (Copy_u8Ypos >= LCD_SIZE_HIGHT))
	 	{
	 		Local_u8Error = ERROR_NOK;
	 	}
	 	else
	 	{
	 		Local_u8Address = Copy_u8Xpos+(Copy_u8Ypos*ADDRESS_2ND_ROW);
	 		Local_u8Address |= COMMAND_SET_ADDRESS_DDRAM;
	 		WriteCommand(Local_u8Address);
	 		WriteChar(Copy_u8CharCodeCGROM);
	 	}
	 	/*Function return*/
	 	return Local_u8Error;

 }


 /* NAME         :LCD_u8CustomPattern
  *
  * DESCRIPPTION : This function
  * 				1. makes the address counter points to CGRAM firstly then
  *
  * 			    2.Fill what you want as the required pattern  which is send as an arrgument
  * 			    and there is  remarkable somthing that address is incremet /decrement automatically
  * 			    not need to adjust(increment /decrement) during filling Data in CGRAM
  *
  *					3.return Address counter to DDRAM  to be able to display  afterthat
  *
  *
  * ARGUMENTS    : Array pattern and its size and the index of this pattern which is matching to its code in DDRAM
  *
  * RETURN       : void
  */
 u8 LCD_u8CustomPattern(u8 *Copy_u8APattern, u8 Copy_u8size,u8 Copy_u8CodeinDDRAM)
 {
	 u8 Local_u8ErrorState=ERROR_NO;
	 u8 Local_u8AddressCGRAM=Copy_u8size*Copy_u8CodeinDDRAM;      /*0,1,....7 depends on fonts or 0,1,...3*/
	 u8 Local_u8indexloop;
/***************************INPUT VERIFCARTION*******************************/
	if (Copy_u8APattern == NULL)
	{
		Local_u8ErrorState=ERROR_NOK;
	}

	else
	{
		Local_u8AddressCGRAM|=COMMAND_SET_ADDRESS_CGRAM;
		 WriteCommand(Local_u8AddressCGRAM);

		 for(Local_u8indexloop=0;Local_u8indexloop<Copy_u8size;Local_u8indexloop++)
		 {
			 WriteChar(Copy_u8APattern[Local_u8indexloop]);
			 Local_u8AddressCGRAM++;

		 }
		 WriteCommand(COMMAND_SET_ADDRESS_DDRAM);
	}



	return Local_u8ErrorState;

 }

 /* NAME         :LCD_u8DisplayUnsignedNumber
  *
  * DESCRIPPTION : This function display a number from many digits
  *
  *
  *
  * ARGUMENTS    :u32 unsigned integer number
  *
  * RETURN       : ErrorState
  */

 u8 LCD_u8DisplayUnsignedNumber(u32 Copy_u32Number)
 {
	 u8 Error_State=ERROR_NO;
	 // print each digit and automatically in LCD the address will be increased
	 //write('6');
	 //write('3');
	 //print 6 3 in lcd
u32 num[10];
int rem;
int i=0;
while(Copy_u32Number)
{
	rem=Copy_u32Number%10;
	num[i]=rem;
	Copy_u32Number/=10;
	i++;
}
i--;
while(i>=0)
{
	WriteChar(num[i]+'0');
	i--;
}


	 return Error_State;
 }

 void LCD_ReturnHome(void)
 {
	 WriteCommand(COMMAND_RETURN_HOME);
 }
 void LCD_ShiftLeft(void)
 {
	 WriteCommand(COMMAND_DISPLAYSHIFT_LEFT);
 }
 void LCD_ShiftRight(void)
 {
	 WriteCommand(COMMAND_DISPLAYSHIFT_RIGHT);
 }































/**************************************************************************************************************************************/

/* NAME         : WriteCommand
 * DESCRIPPTION : THIS FUNCTION SET ENABLE PIN  AND RESET R/S PIN TO
 * 					SELECT THE INSTRUCTION REGISTER
 * ARGUMENTS    :
 * RETURN       :
 */
static u8 WriteCommand(u8 Copy_u8Command)
{
	u8 Local_u8ErrorState=ERROR_NO;

	GPIO_u8SetPinValue(LCD_RS,GPIO_PIN_LOW);

	Write(Copy_u8Command);


return Local_u8ErrorState;
}

/*****************************************************************************************************************************************/
/* NAME       :  Write
 * DESCRIPTION: This function make
 * 				1-reset the pin; write is active low
 * 		        2- to write should be in falling edge
 * 		        3- write data  on falling edge
 * ARGUMENTS  : values on D7:D0 whatever it is command or data
 * RETURN	  : void
 */
static void Write( u8 Copy_u8Data_or_Command)
{
	GPIO_u8SetPinValue(LCD_R_W_BAR,GPIO_PIN_LOW);

	GPIO_u8SetPinValue(LCD_ENABLE,GPIO_PIN_LOW);
	/*get bit */
	// ((var&(1<<bit_index))>>bit_index)
#if LCD_BIT_MODE == EightBit

	GPIO_u8SetPinValue(LCD_D0,GET_BIT(Copy_u8Data_or_Command,0));
	GPIO_u8SetPinValue(LCD_D1,GET_BIT(Copy_u8Data_or_Command,1));
	GPIO_u8SetPinValue(LCD_D2,GET_BIT(Copy_u8Data_or_Command,2));
	GPIO_u8SetPinValue(LCD_D3,GET_BIT(Copy_u8Data_or_Command,3));
	GPIO_u8SetPinValue(LCD_D4,GET_BIT(Copy_u8Data_or_Command,4));
	GPIO_u8SetPinValue(LCD_D5,GET_BIT(Copy_u8Data_or_Command,5));
	GPIO_u8SetPinValue(LCD_D6,GET_BIT(Copy_u8Data_or_Command,6));
	GPIO_u8SetPinValue(LCD_D7,GET_BIT(Copy_u8Data_or_Command,7));

	GPIO_u8SetPinValue(LCD_ENABLE,GPIO_PIN_HIGH);
	_delay_ms(100);
	GPIO_u8SetPinValue(LCD_ENABLE,GPIO_PIN_LOW);


#elif LCD_BIT_MODE ==FourBit
	// first instruction
	    GPIO_u8SetPinValue(LCD_D4,GET_BIT(Copy_u8Data_or_Command,4));
		GPIO_u8SetPinValue(LCD_D5,GET_BIT(Copy_u8Data_or_Command,5));
		GPIO_u8SetPinValue(LCD_D6,GET_BIT(Copy_u8Data_or_Command,6));
		GPIO_u8SetPinValue(LCD_D7,GET_BIT(Copy_u8Data_or_Command,7));

		GPIO_u8SetPinValue(LCD_ENABLE,GPIO_PIN_HIGH);
		_delay_ms(40);
		GPIO_u8SetPinValue(LCD_ENABLE,GPIO_PIN_LOW);

		_delay_ms(40);
		//seccond instraction
		    GPIO_u8SetPinValue(LCD_D4,GET_BIT(Copy_u8Data_or_Command,0));
			GPIO_u8SetPinValue(LCD_D5,GET_BIT(Copy_u8Data_or_Command,1));
			GPIO_u8SetPinValue(LCD_D6,GET_BIT(Copy_u8Data_or_Command,2));
			GPIO_u8SetPinValue(LCD_D7,GET_BIT(Copy_u8Data_or_Command,3));

			GPIO_u8SetPinValue(LCD_ENABLE,GPIO_PIN_HIGH);
			_delay_ms(40);
			GPIO_u8SetPinValue(LCD_ENABLE,GPIO_PIN_LOW);


#endif


}
/*********************************************************************************************************************************************/


 u8 WriteChar(u8 Copy_u8Char)

{
	 u8 Local_u8ErrorState=ERROR_NOK;

	 GPIO_u8SetPinValue(LCD_RS,GPIO_PIN_HIGH);

	 Write(Copy_u8Char);



	return Local_u8ErrorState;

}






























#endif /* LCD_PROG_C_ */
