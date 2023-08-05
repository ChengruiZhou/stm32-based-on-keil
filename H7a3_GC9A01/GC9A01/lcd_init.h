#ifndef __LCD_INIT_H
#define __LCD_INIT_H

#include "main.h"

#define LCD_W 240
#define LCD_H 240
void OLED_SendByte(uint8_t data);
void OLED_SendCMD(uint8_t cmd);
void OLED_SetBackLight(uint8_t value);
void OLED_Reset(uint8_t value);
void OLED_ChipSelect(uint8_t value);
void OLED_SetDataOrCommand(uint8_t value);
void OLED_WriteData_DMA(uint8_t* _data, uint32_t _len);
void OLED_WriteData(uint16_t dat);
void OLED_Init(void);
void OLED_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);

#endif
