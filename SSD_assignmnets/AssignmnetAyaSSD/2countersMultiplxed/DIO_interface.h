/***********************************************************
 * LED_interface.h                                         *
 * Created on: Jan 31, 2019                                *
 * Author: AyetAllah                                       *
 ***********************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*
 * layer MCAL DIO module
 */


/*max number for port in private.h*/

#define DIO_PIN_OUTPUT          (u8)DIO_PIN_INIT_OUTPUT
#define DIO_PIN_INPUT           (u8)DIO_PIN_INIT_INPUT
#define DIO_PIN_HIGH            (u8)DIO_PIN_INIT_VALUE_HIGH
#define DIO_PIN_LOW             (u8)DIO_PIN_INIT_VALUE_LOW
#define DIO_HIGH_NIBBLE         (u8)0xF0
#define DIO_LOW_NIBBLE          (u8)0x0F
#define DIO_PORT_HIGH           (u8)0xFF
#define DIO_PORT_LOW            (u8)0x00


/*order of all ports in AVR */
#define DIO_PORTA (u8)0
#define DIO_PORTB (u8)1
#define DIO_PORTC (u8)2
#define DIO_PORTD (u8)3

#define DIO_PINA (u8)0
#define DIO_PINB (u8)1
#define DIO_PINC (u8)2
#define DIO_PIND (u8)3


#define DIO_DDRA (u8)0
#define DIO_DDRB (u8)1
#define DIO_DDRC (u8)2
#define DIO_DDRD (u8)3


#define DIO_PIN0   (u8)0
#define DIO_PIN1   (u8)1
#define DIO_PIN2   (u8)2
#define DIO_PIN3   (u8)3
#define DIO_PIN4   (u8)4
#define DIO_PIN5   (u8)5
#define DIO_PIN6   (u8)6
#define DIO_PIN7   (u8)7
#define DIO_PIN8   (u8)8
#define DIO_PIN9   (u8)9
#define DIO_PIN10  (u8)10
#define DIO_PIN11  (u8)11
#define DIO_PIN12  (u8)12
#define DIO_PIN13  (u8)13
#define DIO_PIN14  (u8)14
#define DIO_PIN15  (u8)15
#define DIO_PIN16  (u8)16
#define DIO_PIN17  (u8)17
#define DIO_PIN18  (u8)18
#define DIO_PIN19  (u8)19
#define DIO_PIN20  (u8)20
#define DIO_PIN21  (u8)21
#define DIO_PIN22  (u8)22
#define DIO_PIN23  (u8)23
#define DIO_PIN24  (u8)24
#define DIO_PIN25  (u8)25
#define DIO_PIN26  (u8)26
#define DIO_PIN27  (u8)27
#define DIO_PIN28  (u8)28
#define DIO_PIN29  (u8)29
#define DIO_PIN30  (u8)30
#define DIO_PIN31  (u8)31
/*
 * DESCRIPTION  : SOME CONFIGURATIONS FOR ALL REGISTERS
 * PARAMETERS   : VOID
 * ARGUMENTS    : VOID
 */
/*void DIO_u8Init(void);*/
void DIO_VInit(void);




/*
 *  NAME        :DIO_u8SetPinDirection
 *  DESCRIPTION :THIS fUNCTION ADD DIRECTION OUT OR IN IN DDRX THIS INDCATE WHICH REGISTER MICRO PROCESSOR WRITES(PINX) READS
 *  			       (PORTX)
 *  ARGUMENTS   :INDEX OF NUMBER PIN FROM (0->31),DIRECTION IS INPUT OR OUTPUT
 *  RETURN      : ERROR STATE INDCATES OR VERIFIES THE STATE OF FUNCTION
 *
 */

u8 DIO_u8SetPinDirection(u8 Copy_u8PinNB, u8 Copy_u8Direction);


/* Name       : DIO_u8SetPinValue
 * Description: This function set a certain  value to  a specific value
 * OUTPUT     : return the state  of that function ERRor_NO if all thing is right or ERROR_NOK if something wrong
 * 				      its type
 * INPUT      : PinNb and this value
 */
u8 DIO_u8SetPinValue(u8 Copy_u8PinNb,u8 Copy_u8Value);


/* NAME          :DIO_u8GetPinValue
 * Description  : get a value from bin and put this in * pointer
                  is passed by
 * INPUT        :Copy_u8PinNb,u8PtrToValue
 * OUTPUT       : ERROR STATE
 */
u8 DIO_u8GetPinValue(u8 Copy_u8PinNb,u8* u8PtrToValue);


/*
 * NAME         : DIO_u8SetPortDirection
 * DESCRIPTION  : THIS FUNCTION SET THE DIRECTION FOR DDRX AS AWHOLE BYTE
 * ARGUMENTS    : NNUMBER OF THE REGISTER FROM 0:3 AND DIRECTION IS INPUT OR OUTPUT
 * RETURN       :ERROR STATE
 */
u8 DIO_u8SetPortDirection(u8 Copy_u8PortNb, u8 Copy_u8Direction);



/*
 *  NAME        : DIO_u8SetPortValue
 * DESCRIPTION  : THIS FUNCTION SET THE VALUE FOR PORTX AS AWHOLE BYTE
 * ARGUMENTS    : NNUMBER OF THE REGISTER FROM 0:3 AND VALUE IS HEX NUMBER
 * RETURN       :ERROR STATE
 */
u8 DIO_u8SetPortValue(u8 Copy_u8PortNb,u8 Copy_u8Value);



/*Name:DIO_u8GetPortValue
 *Description: get value as whole byte from register PINx read by Micro-controller so it gets
 *Arguments: number of pinA,B,C,D and the variable should value returned in it
 *Return:
 */
u8 DIO_u8GetPortValue(u8 Copy_u8PortNb,u8* Copy_u8PValue);



#endif /* DIO_INTERFACE_H_ */
