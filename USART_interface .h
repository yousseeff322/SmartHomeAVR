/* Include guard */
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H



void USART_VidInit();

/**
 * @brief A function to send a byte using USART.
 * @param Copy_u8Data The data to be sent.
 * @return u8 The status of the function.
 */

u8 USART_u8SendByte(u8 Copy_u8Data);

/**
 * @brief A function to send a string using USART in synchronous mode.
 * @param Copy_u8String The string to be sent.
 * @return u8 The status of the function.
 */
u8 USART_VidSendStringSynch(u8 *Copy_u8String);

/**
 * @brief A function to send a string using USART in asynchronous mode.
 * @param Copy_u8String The string to be sent.
 * @param Callback The function to be called when the transmission is done.
 * @return u8 The status of the function.
 */


u8 USART_VidSendStringAsynch(u8 *Copy_u8String, void (*Callback)(void));

/**
 * @brief A function to receive a byte using USART.
 * @param Copy_u8Byte The byte to be received.
 * @return u8 The status of the function.
 */


u8 USART_u8ReceiveByte(u8 *Copy_u8Byte);

/**
 * @brief A function to receive a string using USART in synchronous mode.
 * @param Copy_u8String The string to be received.
 * @return u8 The status of the function.
 */


u8 USART_VidReceiveStringSynch(u8 *Copy_u8String);

/**
 * @brief A function to receive a string using USART in asynchronous mode.
 * @param Copy_u8String The string to be received.
 * @param Callback The function to be called when the reception is done.
 * @return u8 The status of the function.
 */


u8 USART_VidReceiveStringAsynch(u8 *Copy_u8String, void (*Callback)(void));



#endif /* USART_INTERFACE_H */

/*** end of file ***/
