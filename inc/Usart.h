#ifndef INC_USART_H_
#define INC_USART_H_

typedef enum {
    USART_NOT_COMPLETE,
    USART_COMPLETE
} Usart_StateType;

typedef enum {
    USART_INT_SOURCE_RX,
    USART_INT_SOURCE_TX,
    USART_INT_SOURCE_EMPTY
} Usart_InterruptSourceType;

void Usart_Init (void);
void Usart_Transmit (u8 data);
void Usart_TransmitASync (u8 data);
u8 Usart_Receive (void);
Usart_StateType Usart_ReceiveAsync (u8 *data);
void Usart_EnableNotification (Usart_InterruptSourceType source);
void Usart_DisableNotification (Usart_InterruptSourceType source);
void Usart_SetCallbackReceive(void (*callback) (u8 data));
void Usart_SetCallbackTransmit(void (*callback) (void));
void Usart_SetCallbackEmpty(void (*callback) (void));
void Usart_SendString(const u8 *str);
void Usart_SendNumber(s64 num);
void Usart_Print(const u8 *str, ...);

u8 USART_SendCharSynch(u16 Copy_u16Data);
u8 USART_u8SendBytesSynch(const char* Copy_pcharBuffer, u8 Copy_u8Len);

#endif
