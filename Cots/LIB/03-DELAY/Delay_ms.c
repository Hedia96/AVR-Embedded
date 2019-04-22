

void Delay_ms(u32 value)
{
u32 i=0,j=0;
for(;i<value;i++)
{
	for(j=0;j<208;j++)
	{
			asm("NOP");
			asm("NOP");
			asm("NOP");
			asm("NOP");
			//asm("NOP");
		    //asm("NOP");
		    //asm("NOP");
		    //asm("NOP");
	}

}
}