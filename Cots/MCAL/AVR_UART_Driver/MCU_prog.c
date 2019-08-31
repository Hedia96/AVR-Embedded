/*
 * MCU_prog.c
 *
 *  Created on: Apr 7, 2019
 *      Author: AyetAllah
 */

#include "MCU_config.h"
#include "MCU_private.h"
#include "MCU_interface.h"


void MCU_VEnableGlobalInt(void)
{
	SREG|=(1<<7);/*enable the global interrupt enable  Ibit is 7thbit in this register  */


}


