/*
 * DIO_private.h
 *
 *  Created on: feb 2, 2019
 *      Author: AyetAllah
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_
/*MAX NUMBERS*/
#define DIO_MAXPINNB             32
#define NUMBER_PINS_IN_PORT      8

//without casting
/*DIRECTION */
//#define DIO_PIN_INIT_OUTPUT        1
//#define DIO_PIN_INIT_INPUT         0


/*VALUES*/

//#define DIO_PIN_INIT_VALUE_DEFAULT 0
//#define DIO_PIN_INIT_VALUE_LOW     0
//#define DIO_PIN_INIT_VALUE_HIGH    1
/*
 * IO /MEMORY HAVE TWO ADDRESSE ONE FOR IO REGISTER OR (SPECIFIC FUNCTION REGISTERS), ANOTHER ADDRESS FOR MEMORY MAPPED
 * THESE FOLLWING ADDRESS FROM LATER TYPES
 */
#define DDRA_ADDRESS  0x3A
#define DDRB_ADDRESS  0x37
#define DDRC_ADDRESS  0x34
#define DDRD_ADDRESS  0x31


#define PORTA_ADDRESS 0x3B
#define PORTB_ADDRESS 0x38
#define PORTC_ADDRESS 0x35
#define PORTD_ADDRESS 0x32


#define PINA_ADDRESS  0x39
#define PINB_ADDRESS  0x36
#define PINC_ADDRESS  0x33
#define PIND_ADDRESS  0x30

/*
 * TYPEDEF FOR UNION STRUCTURE HAS A STRUCTURE MEMBER TO IMPLEMETS THE REGISTERS
 * TO HAVE THE ABILITY TO ACCESS AS WHOLE BYTE OR EVERY BIT THROUGH BIT FIELD
 * FROM ((STD_TYPES.h))
 */



/*
 * NAMES OF IO REGISTERS IN AVR
 */
#define   DDRA ((Register_8bit*) DDRA_ADDRESS)->ByteAccess
#define   DDRB ((Register_8bit*) DDRB_ADDRESS)->ByteAccess
#define   DDRC ((Register_8bit*) DDRC_ADDRESS)->ByteAccess
#define   DDRD ((Register_8bit*) DDRD_ADDRESS)->ByteAccess


#define   PORTA ((Register_8bit*) PORTA_ADDRESS) ->ByteAccess
#define   PORTB ((Register_8bit*) PORTB_ADDRESS) ->ByteAccess
#define   PORTC ((Register_8bit*) PORTC_ADDRESS)->ByteAccess
#define   PORTD ((Register_8bit*) PORTD_ADDRESS)->ByteAccess



#define   PINA ((Register_8bit*) PINA_ADDRESS) ->ByteAccess
#define   PINB ((Register_8bit*) PINB_ADDRESS) ->ByteAccess
#define   PINC ((Register_8bit*) PINC_ADDRESS) ->ByteAccess
#define   PIND ((Register_8bit*) PIND_ADDRESS) ->ByteAccess



#endif /* GPIO_PRIVATE_H_ */
