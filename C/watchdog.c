/*
 * Hospital Central Militar
 * 
 * Archivo: watchdog.c
 * Autor  : Valentín Nájera Bello
 * Fecha  : 2024-jul-03
 *
 * Descripción:     
 *
 */

#include "driverlib.h"


void watchdog_configuration(void)
{
	WDT_A_hold(WDT_A_BASE); // Stop watchdog timer
}

