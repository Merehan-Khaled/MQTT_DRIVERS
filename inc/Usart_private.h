/*
 * Usart_private.h
 *
 *  Created on: Oct 14, 2022
 *      Author: ELSERAG FOR LAPTOP
 */

#ifndef INC_USART_PRIVATE_H_
#define INC_USART_PRIVATE_H_

/******************************************************************
 * Configurations
 *****************************************************************/

#define USART_ON                1
#define USART_OFF               0

#define USART_CHAR_SIZE_5_BIT   1
#define USART_CHAR_SIZE_6_BIT   2
#define USART_CHAR_SIZE_7_BIT   3
#define USART_CHAR_SIZE_8_BIT   4
#define USART_CHAR_SIZE_9_BIT	7

#define USART_SYNC              1
#define USART_ASYNC             2

/*Baud rate*/
#define RATE_2400			2400
#define RATE_4800       	4800
#define RATE_9600       	9600
#define RATE_14400      	14400
#define RATE_19200      	19200
#define RATE_28800      	28800
#define RATE_38400      	38400
#define RATE_57600      	57600
#define RATE_76800      	76800
#define RATE_115200     	115200
#define RATE_230400     	230400
#define RATE_250000     	250000

#define USART_TIMEOUT		50000
#define USART_IDLE              1
#define USART_BUSY              2

#define USART_PARITY_DISABLED   0
#define USART_PARITY_EVEN       1
#define USART_PARITY_ODD        2

#define USART_1_STOP_BIT        1
#define USART_2_STOP_BIT        2

#define USART_POLARITY_T_RISING_R_FALLING   1
#define USART_POLARITY_T_FALLING_R_RISING   2

/******************************************************************
 * Registers Bits
 *****************************************************************/

#define UCSRA_MPCM      0
#define UCSRA_U2X       1
#define UCSRA_PE        2
#define UCSRA_DOR       3
#define UCSRA_FE        4
#define UCSRA_UDRE      5
#define UCSRA_TXC       6
#define UCSRA_RXC       7

#define UCSRB_TXB8      0
#define UCSRB_RXB8      1
#define UCSRB_UCSZ2     2
#define UCSRB_TXEN      3
#define UCSRB_RXEN      4
#define UCSRB_UDRIE     5
#define UCSRB_TXCIE     6
#define UCSRB_RXCIE     7

#define UCSRC_UCPOL     0
#define UCSRC_UCSZ0     1
#define UCSRC_UCSZ1     2
#define UCSRC_USBS      3
#define UCSRC_UPM0      4
#define UCSRC_UPM1      5
#define UCSRC_UMSEL     6
#define UCSRC_URSEL     7

#endif /* INC_USART_PRIVATE_H_ */
