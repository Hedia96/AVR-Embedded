/*

 * main.c
 *
 *  Created on: Feb 14, 2019
 *      Author: AyetAllah
 */
#include"BIT_CALC.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"

#include "LDM_interface.h"
#include "util/delay.h"
/*GYM*/
/*
int main(void)
{//60, 90, 66, 60, 90, 24, 24, 36)
u8 image1[8]={36, 24, 24, 90, 60, 66,90, 60};
u8 image2[8]={36, 24, 24, 24, 189, 66,90, 60};
u8 image3[8]={36, 24, 60, 24, 60, 66, 90, 60};
// u8 images[3][8]={{36, 24, 24, 90, 60, 66, 90, 60},{36, 24, 24, 24, 189, 66, 90, 60},{36, 24, 60, 24, 60, 66, 90, 60}}
int i;
while(1)
	 { 		for(i=0;i<50;i++)
			 {
					  LDM_u8DisplayFrame(image3,LDM_RED);
			 }
			 for(i=0;i<50;i++)
			 {
				LDM_u8DisplayFrame(image1,LDM_RED);
			 }
		 for(i=0;i<50;i++)
			 {
				LDM_u8DisplayFrame(image2,LDM_RED);
			 }

	 }
return 0;
}
*/
int main()
{
u8 image1[]={156, 108, 96, 240, 96, 144, 144, 96};
u8 image2[]={144, 96, 99, 243, 96, 144, 144, 96};
int i;
while(1)
	 { 		for(i=0;i<50;i++)
			 {
					  LDM_u8DisplayFrame(image1,LDM_RED);
			 }
			 for(i=0;i<50;i++)
			 {
				LDM_u8DisplayFrame(image2,LDM_RED);
			 }

	 }
return 0;
}
