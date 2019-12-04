/*
 * uart.c
 *
 *  Created on: Nov 20, 2019
 *      Author: Pjotr
 */
#include "string.h"

#include "usart.h"
#include "gpio.h"

#include "uart.h"


#define BUFFERSIZE 11

static ITStatus uartReady = RESET;
static uint8_t buffer[] = "Hello world\n\r";
//uint8_t rxBuffer[11] ;

void uart(void) {

	for(;;) {
		// transmission
		if (HAL_UART_Transmit_IT(&huart5, buffer, BUFFERSIZE) != HAL_OK) {
		  errorHandler();
		}
		// wait for end of transmission (compiler optimization problem?)
		while(uartReady != SET) {

		}
		//reset flag
		uartReady = RESET;

		// receiving
		if (HAL_UART_Receive_IT(&huart5, buffer, BUFFERSIZE) != HAL_OK) {
		  errorHandler();
		}
		// wait for end of receivement (compiler optimization problem?)
		while(uartReady != SET) {

		}
		//reset flag
		uartReady = RESET;
	}

}

// uart transmission callback
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *UartHandle) {
	uartReady = SET;
}

// uart receiving callback
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle) {
	uartReady = SET;
}

//void debugPrint(UART_HandleTypeDef *huart, char _out[]){
// HAL_UART_Transmit(huart, (uint8_t *) _out, strlen(_out), 10);
//}

void errorHandler(void){
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	for(;;);
}
