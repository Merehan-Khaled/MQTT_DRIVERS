/*
 * Usart_cfg.h
 *
 *  Created on: Oct 14, 2022
 *      Author: ELSERAG FOR LAPTOP
 */

#ifndef INC_USART_CFG_H_
#define INC_USART_CFG_H_

/*******************************************************************
--> Options:
		RATE_2400
		RATE_4800
		RATE_9600
		RATE_14400
		RATE_19200
		RATE_28800
		RATE_38400
		RATE_57600
		RATE_76800
		RATE_115200
		RATE_230400
		RATE_250000
*/
#define USART_BAUD_RATE             RATE_9600
/*******************************************************************
--> Options:
        USART_ON
        USART_OFF
*/
#define USART_RECEIVER_ENABLE       USART_ON
#define USART_TRANSMITTER_ENABLE    USART_OFF
/*******************************************************************
--> Options:
        USART_CHAR_SIZE_5_BIT
        USART_CHAR_SIZE_6_BIT
        USART_CHAR_SIZE_7_BIT
        USART_CHAR_SIZE_8_BIT
        USART_CHAR_SIZE_9_BIT
*/
#define USART_CHAR_SIZE             USART_CHAR_SIZE_8_BIT
/*******************************************************************
--> Options:
        USART_SYNC
        USART_ASYNC
*/
#define USART_MODE                  USART_ASYNC
/*******************************************************************
--> Options:
        NORMAL_SPEED
		DOUBLE_SPEED
*/
#define TRANS_SPEED 				NORMAL_SPEED
/*******************************************************************
--> Options:
        USART_POLARITY_T_RISING_R_FALLING
        USART_POLARITY_T_FALLING_R_RISING
*/
#define USART_CLK_POLARITY          USART_POLARITY_T_RISING_R_FALLING
/******************************************************************
--> Options:
        USART_PARITY_DISABLED
        USART_PARITY_EVEN
        USART_PARITY_ODD
*/
#define USART_PARITY                USART_PARITY_DISABLED
/*******************************************************************
--> Options:
        USART_1_STOP_BIT
        USART_2_STOP_BIT
*/
#define USART_STOP_BIT              USART_1_STOP_BIT
/*******************************************************************/


#endif /* INC_USART_CFG_H_ */
