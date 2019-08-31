
#ifndef UART_CONFG_H_
#define UART_CONFG_H_


#define PARTIY_TYPE_ODD      1
#define PARTIY_TYPE_EVEN     2
#define PARTIY_TYPE_NONE     3
#define ENABLE               1
#define DISABLE              0
#define DATA_BITS_5          5
#define DATA_BITS_6          6
#define DATA_BITS_7          7
#define DATA_BITS_8          8
#define DATA_BITS_9          9
/*
 * THIS BAUD RATE FOR THE FREQUENCY 8MHZ
 *
 */
#define UART_BAUDRATE  9600
/*
 * Even
 * Odd
 * No
 */
#define UART_PARITY_TYPE  PARTIY_TYPE_NONE
/*
 * 5,6,7,8,9
 */
#define UART_NO_BITS_DATA  DATA_BITS_8
/*
 * THIS NUMBER MEANS THE FUNCTIONS CAN POLL TILL 20000 OF CLOCK CYCLE IN SYNCHRONOUS FUNCTION
 */
#define UART_TIMEOUT_SYNCH_FUNCTION   (u16)50000
/*
 * THERE ARE TWO OPTIONS 1 BIT OR 2BITS
 */
#define UART_NO_BITS_STOP  1

/*types of interrupt */
#define RX_COMPLETE_INTERRUPT   ENABLE
#define TX_COMPLETE_INTERRUPT   ENABLE
#endif /* UART_CONFG_H_ */
