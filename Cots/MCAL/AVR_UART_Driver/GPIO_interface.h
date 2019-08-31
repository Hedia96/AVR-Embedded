/***********************************************************
 * LED_interface.h                                         *
 * Created on: Jan 31, 2019                                *
 * Author: AyetAllah                                       *
 ***********************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/*
 * layer MCAL DIO module
 */
#include "STD_TYPES.h"

/*max number for port in private.h*/

//without casting
/*DIRECTION */
#define DIO_PIN_INIT_OUTPUT        1
#define DIO_PIN_INIT_INPUT         0


/*VALUES*/

#define DIO_PIN_INIT_VALUE_DEFAULT 0
#define DIO_PIN_INIT_VALUE_LOW     0
#define DIO_PIN_INIT_VALUE_HIGH    1


#define GPIO_PIN_OUTPUT                (u8)DIO_PIN_INIT_OUTPUT
#define GPIO_PIN_INPUT                    (u8)DIO_PIN_INIT_INPUT
#define GPIO_PIN_HIGH                      (u8)DIO_PIN_INIT_VALUE_HIGH
#define GPIO_PIN_LOW                       (u8)DIO_PIN_INIT_VALUE_LOW
#define GPIO_HIGH_NIBBLE                 (u8)0xF0
#define GPIO_LOW_NIBBLE                  (u8)0x0F
#define GPIO_PORT_HIGH                     (u8)0xFF
#define GPIO_PORT_LOW                     (u8)0x00
#define GPIO_PORT_OUTPUT               (u8)0xFF
#define GPIO_PORT_INPUT                   (u8)0x00



/*order of all ports in AVR */
#define GPIO_PORTA (u8)0
#define GPIO_PORTB (u8)1
#define GPIO_PORTC (u8)2
#define GPIO_PORTD (u8)3

#define GPIO_PINB (u8)1
#define GPIO_PINA (u8)0
#define GPIO_PINC (u8)2
#define GPIO_PIND (u8)3


#define GPIO_DDRA (u8)0
#define GPIO_DDRB (u8)1
#define GPIO_DDRC (u8)2
#define GPIO_DDRD (u8)3


#define PORTA_PIN0   (u8)0
#define PORTA_PIN1   (u8)1
#define PORTA_PIN2   (u8)2
#define PORTA_PIN3   (u8)3
#define PORTA_PIN4   (u8)4
#define PORTA_PIN5   (u8)5
#define PORTA_PIN6   (u8)6
#define PORTA_PIN7   (u8)7

#define  PORTB_PIN0  (u8)8
#define  PORTB_PIN1   (u8)9
#define  PORTB_PIN2  (u8)10
#define  PORTB_PIN3  (u8)11
#define  PORTB_PIN4  (u8)12
#define  PORTB_PIN5  (u8)13
#define  PORTB_PIN6  (u8)14
#define  PORTB_PIN7  (u8)15

#define PORTC_PIN0  (u8)16
#define PORTC_PIN1  (u8)17
#define PORTC_PIN2  (u8)18
#define PORTC_PIN3  (u8)19
#define PORTC_PIN4   (u8)20
#define PORTC_PIN5  (u8)21
#define PORTC_PIN6  (u8)22
#define PORTC_PIN7  (u8)23

#define PORTD_PIN0  (u8)24
#define PORTD_PIN1  (u8)25
#define PORTD_PIN2  (u8)26
#define PORTD_PIN3  (u8)27
#define PORTD_PIN4  (u8)28
#define PORTD_PIN5  (u8)29
#define PORTD_PIN6  (u8)30
#define PORTD_PIN7  (u8)31
/*
 * DESCRIPTION  : SOME CONFIGURATIONS FOR ALL REGISTERS
 * PARAMETERS   : VOID
 * ARGUMENTS    : VOID
 */
/*void DIO_u8Init(void);*/
void GPIO_VInit(void);




/*
 *  NAME        :GPIO_u8SetPinDirectionType
 *  DESCRIPTION :THIS fUNCTION ADD DIRECTION OUT OR IN IN DDRX THIS INDCATE WHICH REGISTER MICRO PROCESSOR WRITES(PINX) READS
 *  			       (PORTX)
 *  ARGUMENTS   :INDEX OF NUMBER PIN FROM (0->31),DIRECTION IS INPUT OR OUTPUT
 *  RETURN      : ERROR STATE INDCATES OR VERIFIES THE STATE OF FUNCTION
 *
 */

u8 GPIO_u8SetPinDirectionType(u8 Copy_u8PinNB, u8 Copy_u8Direction);


/* Name       : GPIO_u8SetPinValue
 * Description: This function set a certain  value to  a specific value
 * OUTPUT     : return the state  of that function ERRor_NO if all thing is right or ERROR_NOK if something wrong
 * 				      its type
 * INPUT      : PinNb and this value
 */
u8 GPIO_u8SetPinValue(u8 Copy_u8PinNb,u8 Copy_u8Value);


/* NAME          :GPIO_u8GetPinValue
 * Description  : get a value from bin and put this in * pointer
                  is passed by
 * INPUT        :Copy_u8PinNb,u8PtrToValue
 * OUTPUT     : ERROR STATE
 */
u8 GPIO_u8GetPinValue(u8 Copy_u8PinNb,u8* u8PtrToValue);


/*
 * NAME         : GPIO_u8SetPortDirection
 * DESCRIPTION  : THIS FUNCTION SET THE DIRECTION FOR DDRX AS AWHOLE BYTE
 * ARGUMENTS    : NNUMBER OF THE REGISTER FROM 0:3 AND DIRECTION IS INPUT OR OUTPUT
 * RETURN       :ERROR STATE
 */
u8 GPIO_u8SetPortDirection(u8 Copy_u8PortNb, u8 Copy_u8Direction);



/*
 *  NAME        : GPIO_u8SetPortValue
 * DESCRIPTION  : THIS FUNCTION SET THE VALUE FOR PORTX AS AWHOLE BYTE
 * ARGUMENTS    : NNUMBER OF THE REGISTER FROM 0:3 AND VALUE IS HEX NUMBER
 * RETURN       :ERROR STATE
 */
u8 GPIO_u8SetPortValue(u8 Copy_u8PortNb,u8 Copy_u8Value);



/*Name:GPIO_u8GetPortValue
 *Description: get value as whole byte from register PINx read by Micro-controller so it gets
 *Arguments: number of pinA,B,C,D and the variable should value returned in it
 *Return:
 */
u8 GPIO_u8GetPortValue(u8 Copy_u8PortNb,u8* Copy_u8PValue);



#endif /* GPIO_INTERFACE_H_ */
