#include "lcd_i2c.h"
#include "stm32f1xx_hal.h"
#include "string.h"

extern I2C_HandleTypeDef hi2c1;

static void lcd_send(uint8_t data, uint8_t rs) {
    uint8_t upper = data & 0xF0;
    uint8_t lower = (data << 4) & 0xF0;
    uint8_t data_arr[4];
		uint8_t backlight = 0x08; // d?m b?o dèn nen bat
	
		data_arr[0] = upper | backlight | (rs ? 0x01 : 0x00) | 0x04; // En=1
		data_arr[1] = upper | backlight | (rs ? 0x01 : 0x00);        // En=0
		data_arr[2] = lower | backlight | (rs ? 0x01 : 0x00) | 0x04;
		data_arr[3] = lower | backlight | (rs ? 0x01 : 0x00);

    HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDR, data_arr, 4, HAL_MAX_DELAY);
    HAL_Delay(1);
}

void LCD_Send_Cmd(uint8_t cmd) {
    lcd_send(cmd, 0);
}

void LCD_Send_Data(uint8_t data) {
    lcd_send(data, 1);
}

void LCD_Send_String(char *str) {
    while (*str) {
        LCD_Send_Data((uint8_t)(*str++));
    }
}

void LCD_Set_Cursor(uint8_t row, uint8_t col) {
    uint8_t addr[] = {0x80, 0xC0};
    if (row < 2 && col < 16) {
        LCD_Send_Cmd(addr[row] + col);
    }
}

void LCD_Clear(void) {
    LCD_Send_Cmd(0x01);
    HAL_Delay(2);
}

void LCD_CreateChar(uint8_t location, uint8_t charmap[]) {
    location &= 0x07;
    LCD_Send_Cmd(0x40 | (location << 3));
    for (int i = 0; i < 8; i++) {
        LCD_Send_Data(charmap[i]);
    }
}

void LCD_Init(void) {
    HAL_Delay(1000);
	    // N?u mu?n: reset PCF8574
    uint8_t zero = 0x00;
    HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDR, &zero, 1, 100);
    HAL_Delay(100);
    LCD_Send_Cmd(0x30);
	
	
    HAL_Delay(5);
    LCD_Send_Cmd(0x30);
    HAL_Delay(1);
    LCD_Send_Cmd(0x30);
    HAL_Delay(10);
    LCD_Send_Cmd(0x20); // 4-bit mode

    LCD_Send_Cmd(0x28); // 2 lines, 5x7
    LCD_Send_Cmd(0x08); // display off
    LCD_Send_Cmd(0x01); // clear
    HAL_Delay(2);
    LCD_Send_Cmd(0x06); // entry mode
    LCD_Send_Cmd(0x0C); // display on
}