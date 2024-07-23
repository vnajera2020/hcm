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

void lcd_write_measure(float x);

int main(void)
{
	mps430_configuration();
	float x = 0.000;

	Timer_A_startCounter(TIMER_A0_BASE, TIMER_A_UP_MODE);
	__bis_SR_register(GIE);

	while (1) {
		if (timer_ready) {
			timer_ready = 0;
		}

		lcd_write_measure(x);
		x = x + 0.0001;
	}
}
