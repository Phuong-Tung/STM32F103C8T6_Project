#ifndef __LCD_I2C_H__
#define __LCD_I2C_H__

#include "stm32f1xx_hal.h"

#define LCD_ADDR (0x27 << 1)  // Địa chỉ LCD I2C (có thể là 0x3F << 1)

extern I2C_HandleTypeDef hi2c1;

void LCD_Init(void);
void LCD_Clear(void);
void LCD_Set_Cursor(uint8_t row, uint8_t col);
void LCD_Send_Cmd(uint8_t cmd);
void LCD_Send_Data(uint8_t data);
void LCD_Send_String(char *str);
void LCD_CreateChar(uint8_t location, uint8_t charmap[]);

#endif