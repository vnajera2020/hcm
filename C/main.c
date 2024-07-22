/*
 * Hospital Central Militar
 * 
 * Archivo: main.c
 * Autor  : Valentín Nájera Bello
 * Fecha  : 2024-jul-03
 *
 * Descripción:     
 */

#include "msp.h"
#include "watchdog.h"
#include "lcd.h"

int timer_ready = 0;

int main(void)
{
	uint8_t flag = 1;
	mps430_configuration();

	Timer_A_startCounter(TIMER_A0_BASE, TIMER_A_UP_MODE);
	__bis_SR_register(GIE);

	while (1) {
		if (timer_ready) {
			timer_ready = 0;

			if(flag){
				flag = 0;
				lcd_clean_display();
				lcd_write_alphanumerics_string("HCM-Sedena", 0, 0);
				lcd_write_alphanumerics_string(" ID:DSD0001",     1, 0);
				lcd_write_alphanumerics_string("MTA:VNB2345678", 2, 0);
			}
			else{
				flag = 1;
				lcd_clean_display();
				lcd_write_alphanumerics_string("mSv", 2, 100);
				lcd_write_digits_string("123.01", 1, 10);
			}
		}
	}
}
