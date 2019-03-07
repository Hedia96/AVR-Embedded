/*
 * main.c
 *
 *  Created on: Mar 4, 2019
 *      Author: AyetAllah
 */



#include "STD_TYPES.h"
#include "BIT_CALC.h"


#include "DIO_interface.h"


#include "LCD_interface.h"
int main()
{
DIO_VInit();

LCD_VInit();
//	while (1)
	//{

    //LCD_u8WriteCommand(0b11000101); // secondline after some location 0x45
    //LCD_u8WriteData(0xF3);// write acharacter from its location
    //11011011
    /*
    LCD_u8WriteData(0XDB);
	LCD_u8WriteData('Y');
    LCD_u8WriteData('O');
    LCD_u8WriteData('Y');
    LCD_u8WriteData('O');
    LCD_u8WriteData(0XDB);
    */
   // LCD_u8WriteData(0xF3);


    /************************************************ write in arabic*******************************************/
// go to cgram

		LCD_u8WriteCommand(0b01000000);

		//pattern 1
           LCD_u8WriteData(3);
    		LCD_u8WriteData(2);
    		LCD_u8WriteData(14);
    		LCD_u8WriteData(4);
    		LCD_u8WriteData(4);
    		LCD_u8WriteData(4);
    		LCD_u8WriteData(4);
    		LCD_u8WriteData(4);
    		//pattern 2
               LCD_u8WriteData(0);
        		LCD_u8WriteData(0);
        		LCD_u8WriteData(2);
        		LCD_u8WriteData(2);
        		LCD_u8WriteData(30);
        		LCD_u8WriteData(0);
        		LCD_u8WriteData(10);
        		LCD_u8WriteData(0);
    //patern3
        		 LCD_u8WriteData(20);
        		 LCD_u8WriteData(0);
        		 LCD_u8WriteData(24);
        		 LCD_u8WriteData(24);
        		 LCD_u8WriteData(15);
        		 LCD_u8WriteData(0);
        		 LCD_u8WriteData(0);
		        LCD_u8WriteData(0);


		//go to ddram
		LCD_u8WriteCommand(0b10000101); //firstline in center
		//write data by send address of customising characters in data function
		//three patterns from cgram we get them by reverse becauseof the cursor write
		//from left to right not  right  to left
		LCD_u8WriteData(2);
		LCD_u8WriteData(1);
		LCD_u8WriteData(0);

	//}
return 0;
}
