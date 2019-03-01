int main()
{
	/*Set Direction output for counter SSD for both digits and they are multiplxed on the same port A*/

	/*enable digit1=pin7
	 *enable digit2=pin31
	 * these configuration in  ssd driver made
	 */

/*configuration for pin31 taktile switch pull up internally*/
	DIO_u8SetPinDirection(DIO_PIN30,DIO_PIN_INPUT);// make DDRX input
	DIO_u8SetPinValue(DIO_PIN30,DIO_PIN_HIGH);//write on portD=1//to activate pullup
	//u8 Local_u8Counter1=0;
	//u8 Local_u8Dec2=9;
	u8 Local_u8StateSW=0;
	int i=0,j;

	while(1)
{
		//SSD_u8SetOn(1);
		//SSD_u8SetValue(5,1);
	for(u8 i=0;i<9;i++)
	{

				for(j=0;j<50;j++)
								{

									SWI_u8GetSwiState(SWI_INDEX_SW0,&Local_u8StateSW);
									if(Local_u8StateSW == PRESSED)
									{
									SSD_u8SetOff(1);
									SSD_u8SetOn(0);
									SSD_u8SetValue(i,0);
									_delay_ms(10);

									SSD_u8SetOff(0);
									SSD_u8SetOn(1);
									SSD_u8SetValue(9-i,1);
								   _delay_ms(10);
									}
									else
									{
										while(Local_u8StateSW == RELEASED)
										{
										SSD_u8SetOff(1);
										SSD_u8SetOn(0);
										SSD_u8SetValue(i,0);
										_delay_ms(10);

										SSD_u8SetOff(0);
										SSD_u8SetOn(1);
										SSD_u8SetValue(9-i,1);
										_delay_ms(10);
										SWI_u8GetSwiState(SWI_INDEX_SW0,&Local_u8StateSW);
										}



									}
                                }
}


}

	return 0;
}
