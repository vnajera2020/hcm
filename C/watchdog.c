/*
 * Hospital Central Militar
 * 
 * Archivo: watchdog.c
 * Autor  : Valent�n N�jera Bello
 * Fecha  : 2024-jul-03
 *
 * Descripci�n:     
 *
 */

#include "driverlib.h"


void watchdog_configuration(void)
{
	WDT_A_hold(WDT_A_BASE); // Stop watchdog timer
}

