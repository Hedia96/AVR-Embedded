/*snake*/
//#include<stdarg.h>
int main(void)
{
	while(1)
	{
		SSD_u8SetOn(3);
		SSD_u8SetOff(1);
		SSD_u8SetOff(2);
		SSD_u8SetOff(0);

		SSD_u8SetValue('b',3);
		_delay_ms(100);
		SSD_u8SetValue('a',3);
		_delay_ms(100);

		SSD_u8SetOff(3);
		SSD_u8SetOn(2);
		SSD_u8SetValue('a',2);
		_delay_ms(100);

		SSD_u8SetOff(2);
		SSD_u8SetOn(1);
		SSD_u8SetValue('a',1);
		_delay_ms(100);


		SSD_u8SetOff(1);
		SSD_u8SetOn(0);
		SSD_u8SetValue('a',0);
		_delay_ms(100);
		SSD_u8SetValue('f',0);
		_delay_ms(100);
		SSD_u8SetValue('e',0);
		_delay_ms(100);
		SSD_u8SetValue('d',0);
		_delay_ms(100);

		SSD_u8SetOff(0);
		SSD_u8SetOn(1);
		SSD_u8SetValue('d',1);
		_delay_ms(100);

		SSD_u8SetOff(1);
		SSD_u8SetOn(2);
		SSD_u8SetValue('d',2);
		_delay_ms(100);
		SSD_u8SetOff(2);
		SSD_u8SetOn(3);
		SSD_u8SetValue('d',3);
		_delay_ms(100);
		SSD_u8SetValue('c',3);
		_delay_ms(100);



	}

return 0;
}
