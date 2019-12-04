/*
 * uart.h
 *
 *  Created on: Nov 20, 2019
 *      Author: Pjotr
 */

#ifndef INC_UART_H_
#define INC_UART_H_
void uart(void);

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *UartHandle);

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle);

void debugPrint(UART_HandleTypeDef *huart, char _out[]);

void debugPrintln(UART_HandleTypeDef *huart, char _out[]);

void errorHandler(void);


#endif /* INC_UART_H_ */
