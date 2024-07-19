/*
 * Hospital Central Militar
 * 
 * Archivo: clock_system.c
 * Autor  : Valentín Nájera Bello
 * Fecha  : 2024-jul-03
 *
 * Descripción:     
 */

#include "driverlib.h"

#define XT1CLK_FREQUENCY_HZ 32768
#define XT2CLK_FREQUENCY_HZ 0

uint32_t aclk_freq   = 0;
uint32_t smclk_freq  = 0;
uint32_t mclk_freq   = 0;

void clock_system_configuration(void)
{
	//CS_setExternalClockSource(XT1CLK_FREQUENCY_HZ, XT2CLK_FREQUENCY_HZ); // No se usan en este momento.

	CS_setDCOFreq(CS_DCORSEL_1, CS_DCOFSEL_4); 							 // DCOCLK = 16 MHz
	CS_initClockSignal(CS_MCLK , CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1);	 // MCLK   = 16 MHz
	CS_initClockSignal(CS_SMCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_8);  // SMCLK  =  2 MHz
	CS_initClockSignal(CS_ACLK , CS_VLOCLK_SELECT, CS_CLOCK_DIVIDER_1);  // ACLK   = 10 KHz

	mclk_freq  = CS_getMCLK();
	smclk_freq = CS_getSMCLK();
	aclk_freq  = CS_getACLK();
}


