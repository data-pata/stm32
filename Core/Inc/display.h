/*
 * display.h
 *
 *  Created on: Dec 4, 2019
 *      Author: Pjotr
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#include "stdint.h"
#include "gpio.h"
#include "stdio.h"
#include "stm32l4xx_hal.h"
#include "spi.h"

void displayInit(void);

void setCS(uint8_t setOrReset);
void writeIns(uint8_t inst);
void writeD(char d);
void writeIns(uint8_t ins);
void clrDisp(void); //writes instr 0x01
void setCS(uint8_t set);


#define DISPLAY_ON  0x04
#define DISPLAY_OFF 0x03
#define CURSOR_ON 0x02
#define CURSOR_OFF  0x05
#define BLINK_ON  0x01
#define BLINK_OFF 0x06

#define RESET_CS HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, 0)
#define SET_CS HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, 1)

#endif /* INC_DISPLAY_H_ */
