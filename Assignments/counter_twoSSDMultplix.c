#include"STD_TYPES.h"



#define MAX 9
int main()
{
u8 index;

while(1)
{
	for(index=0;index>=MAX;index)
	{

		SSD_u8SetOff(1);
		SSD_u8SetOn(0);
		SSD_u8SetValue(index);
		_delay_ms(50);
		SSD_u8SetOff(0);
		SSD_u8SetOn(1);
		SSD_u8SetValue(MAX-index);
		_delay_ms(50);


	}

}
return 0;

}
