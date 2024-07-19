/*
 * Onik
 * 
 * Archivo: isr.c
 * Autor  : Valentín Nájera Bello
 * Fecha  : 2024-jul-04
 *
 * Descripción:     
 */

#include "driverlib.h"

extern int timer_ready;
extern int spia_tx_ready;

#pragma vector = TIMER0_A0_VECTOR
__interrupt void timer_a0_isr(void)
{
	timer_ready = 1;
}

#pragma vector = USCI_A2_VECTOR;
__interrupt void spia_isr(void)
{
	spia_tx_ready = 1;
	EUSCI_A_SPI_transmitData(EUSCI_A2_BASE, 0x00AA);
}

