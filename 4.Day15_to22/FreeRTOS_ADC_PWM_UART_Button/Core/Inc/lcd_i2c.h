#ifndef __LCD_I2C_H__
#define __LCD_I2C_H__

#include "stm32f1xx_hal.h"

// Địa chỉ I2C của LCD (thường là 0x4E hoặc 0x27 << 1)
#define LCD_ADDR 0x27 << 1

void LCD_Init(void);
void LCD_Clear(void);
void LCD_Set_Cursor(uint8_t row, uint8_t col);
void LCD_Send_String(char *str);
void LCD_Send_Data(uint8_t data);
void LCD_Send_Cmd(uint8_t cmd);
void LCD_CreateChar(uint8_t location, uint8_t charmap[]);

#endif