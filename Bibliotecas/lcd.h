/*
 * Onik
 * 
 * Archivo: lcd.h
 * Autor  : Valent�n N�jera Bello
 * Fecha  : 2024-jul-20
 *
 * Descripci�n:     
 */

#ifndef BIBLIOTECAS_LCD_H_
#define BIBLIOTECAS_LCD_H_

#include "driverlib.h"

void lcd_write_alphanumerics_string(char *str, uint8_t page, uint8_t column);
void lcd_write_digits_string(char *str, uint8_t page, uint8_t column);
void lcd_clean_display(void);

#endif /* BIBLIOTECAS_LCD_H_ */
