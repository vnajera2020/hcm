/*
 * Hospital Central Militar
 * 
 * Archivo: main.c
 * Autor  : Valent�n N�jera Bello
 * Fecha  : 2024-jul-03
 *
 * Descripci�n:     
 */

#include "msp.h"
#include "watchdog.h"

void lcd_display_data_write(uint8_t data);
void lcd_page_address_set(uint8_t page);
void lcd_column_address_set(uint8_t column);

int timer_ready = 0;

int main(void)
{
	uint8_t col, page, pattern;
	mps430_configuration();

	Timer_A_startCounter(TIMER_A0_BASE, TIMER_A_UP_MODE);
	__bis_SR_register(GIE);

	col = 0;
	page = 0;
	pattern = 0x0A;
	while (1) {

		if (timer_ready) {
			timer_ready = 0;
			lcd_display_data_write(pattern);
			col++;
			if (col >= 132){
				col = 0;
				lcd_column_address_set(0);
				page = 0x07 & (page + 1);
				lcd_page_address_set(page);
				pattern++;
			}
		}
	}
}

