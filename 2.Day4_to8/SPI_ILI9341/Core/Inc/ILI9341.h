#ifndef ILI9341_H
#define ILI9341_H

#include "stm32f1xx_hal.h"

#define ILI9341_CS_PORT   GPIOA
#define ILI9341_CS_PIN    GPIO_PIN_4

#define ILI9341_DC_PORT   GPIOA
#define ILI9341_DC_PIN    GPIO_PIN_2

#define ILI9341_RST_PORT  GPIOA
#define ILI9341_RST_PIN   GPIO_PIN_3

#define ILI9341_WIDTH     240
#define ILI9341_HEIGHT    320

void ILI9341_Init(SPI_HandleTypeDef *hspi);
void ILI9341_FillScreen(uint16_t color);
void ILI9341_SetAddressWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
void ILI9341_DrawPixel(uint16_t x, uint16_t y, uint16_t color);
void ILI9341_DrawChar(uint16_t x, uint16_t y, char ch, uint16_t color, uint16_t bg, uint8_t scale);
void ILI9341_DrawString(uint16_t x, uint16_t y, const char *str, uint16_t color, uint16_t bg, uint8_t scale);
void ILI9341_ClearRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
void ILI9341_SetRotation(uint8_t rotation);

#endif
