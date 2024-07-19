/*
 * Hospital Central Militar
 * 
 * Archivo: msp430_config.c
 * Autor  : Valentín Nájera Bello
 * Fecha  : 2024-jul-03
 *
 * Descripción:     
 */


#include "watchdog.h"
#include "clock_system.h"
#include "dio.h"
#include "timer.h"
#include "spi.h"

void lcd_configuration(void);


void mps430_configuration(void)
{
	watchdog_configuration();
	clock_system_configuration();
	dio_configuration();

	timer_configuration();
	spia_gpio();
	spia_configuration();

	lcd_configuration();
}
