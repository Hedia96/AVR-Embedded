/*
 * UART_interface.h
 *
 *  Created on: May 5, 2019
 *      Author: AyetAllah
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

/*Registers */
#define UCSRA      *((u8 *)0x2B)
#define UCSRB      *((u8 *)0x2A)
#define UCSRC      *((u8 *)0x40)
#define UBRRL      *((u8 *)0x29)

#define UDR      *((u8 *)0x2C)
/*BITS IN UCSRA*/
#define RXC          7
#define TXC          6
#define UDRE         5
#define PE           2
#define U2X          1

/*BITS IN UCSRC*/
#define UPM0         4
#define UPM1         5
#define UCSZ0        1
#define UCSZ1        2
#define USBS         3
#define URSEL        7

/*BITS IN UCSRB*/
#define UCSZ2        2
#define TXEN 		 3
#define RXEN         4
#define UDRIE        5
#define TXCIE        6
#define RXCIE  		 7

void __vector_15(void)__attribute__((signal));/*transmiter complete */
void __vector_13(void)__attribute__((signal));/*reciever complete*/
void __vector_14(void)__attribute__((signal));/*isr for data empty*/

#endif /* UART_INTERFACE_H_ */
