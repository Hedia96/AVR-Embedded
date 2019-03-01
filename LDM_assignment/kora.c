#include"BIT_CALC.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"

#include "LDM_interface.h"
#include "util/delay.h"
int main()
{
u8 image1[]={156, 108, 96, 240, 96, 144, 144, 96 };
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
