/*
 * display.c
 *
 *  Created on: Dec 4, 2019
 *      Author: Pjotr
 */

#include "display.h"

void displayInit(void){
  Set_cs(1);
  HAL_Delay(10);
  Set_cs(0);

  HAL_GPIO_WritePin(Disp_Green_GPIO_Port, Disp_Green_Pin, 1);

  WriteIns(0x3A); //8-Bit data length extension Bit RE=1; REV=0
  WriteIns(0x09); //4 line display
  WriteIns(0x06); //Bottom view
  WriteIns(0x1E); //Bias setting BS1=1
  WriteIns(0x39); //8-Bit data length extension Bit RE=0; IS=1
  WriteIns(0x1B); //BS0=1 -> Bias=1/6
  WriteIns(0x6E); //Devider on and set value
  WriteIns(0x56); //Booster on and set contrast (BB1=C5, DB0=C4)
  WriteIns(0x7A); //Set contrast (DB3-DB0=C3-C0)
  WriteIns(0x38); //8-Bit data length extension Bit RE=0; IS=0

  //DisplayOnOff(DISPLAY_ON | CURSOR_ON | BLINK_ON);'
  WriteIns(0x0F);
}

void DisplayOnOff(uint8_t data) {
  WriteIns(0x08+data);
}

void WriteIns(uint8_t ins) {

  SET_CS;
  HAL_Delay(10);
  RESET_CS;
  uint8_t outputBuffer[3] = {0x1F, 0x00, 0x00};
  outputBuffer[2] = ins & 0x0F;                 // mask 4 lsb:s
  outputBuffer[3] = (ins>>4) & 0x0F;            // mask 4 msb:s

  setCS(0);
  HAL_Delay(10);
  HAL_SPI_Transmit(&hspi2, outputBuffer, 3, 10);
  HAL_Delay(10);
  setCS(1);
}

void setCS(uint8_t set){
  HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, set);
}


