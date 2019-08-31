/*
 * UART_interface.h
 *
 *  Created on: May 5, 2019
 *      Author: AyetAllah
 */
#include "STD_TYPES.h"

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_VInit(void);
void UART_VTransmitName(void);

void UART_EnableCommunication(void);
void UART_EnableInterrupt(void);
void UART_SetCallBackAsynchModeTX(void);

u8 UART_u8SendCharSynch(u8 Copy_u8char);

/* Name       : UART_u8SendStringSynch
 * Description: This function shall send the string (array of char) but how it transmits every char it send shall poll on it till certain time and
 * 				the flag will set which of them is closer or happen first if the flag isn't set within the time out which is configured in pre-build
 * 				configuration
 *
 *
 * Arguments: pointer to const char
 *
 * Return: error state is ok
 *
 */
void UART_SendStringSynch(const u8 * Copy_ptr_u8Data);

/*
 * Name       : UART_u8SendStringAsynch
 *
 * Description: This function transmits string after transmition a single character  if i enabled the interrupt TX Flag
 * 				transimts the rest of string in ISR Implemtation(the body of that ISR isn't changed ) and after it finished should
 * 				call another function to indicate the transmtion is completed
 * 				the concept of this function (Asynchronous function) unlike the synchronous one it is polling on transimted flag when it set
 * 				that means the transmition is completed then flag is cleared by writing on it (this in synch)but here ,we don't
 * 				clear it because it is automatically cleared when it entered to ISR
 *				((((INTERRUPT DRIVEN DATA TRANSMISSION)))
 *
 * Arguments  : Copy_ptr_u8Data(string pointer to char) , Copy_VFunction( pointer to function to be able to call back)
 * 				NOTE:
 * 				type of pointer is pointer to const char ,why because this function can't modify  in this arguments
 * 				irrespect of the type of the argument its self is const or isn't.
 * 				NOTE:
 * 				the pointer should be static  because the first time when function SendStringSynch enter to ISR
 * 				(change the context from frame of stack in function to another stack 's ISR)
 * 				if the variable doesn't exist or is a life  the pointer became a dangling pointer
 * 				pointer to a location (local varible )now its life time is out when  switch to another function
 *
 *
 * Return     :void
 */
void UART_SendStringAsynch(const  u8 * Copy_ptr_u8Data,Ptr_to_VFunction_t Copy_VFunction);

/*
 *  Name       :   UART_u8RecStringSynch
 *  Description: this function returns the string in the arguments is returned
 *  Arguments  :
 *  Return     :
 */
u8 UART_u8RecStringSynch(u8 * Copy_p_RecievedData,u8 Length);

u8 UART_u8RecCharSynch(u8 *Copy_Pu8RecievedData);

void UART_VRecStringAsynch(u8 *Copy_p_RecievedData,Ptr_to_VFunction_t Copy_VFunction);


#endif /* UART_INTERFACE_H_ */
