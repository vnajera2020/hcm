/*
 * Hospital Central Militar
 * 
 * Archivo: msp430.h
 * Autor  : Valentín Nájera Bello
 * Fecha  : 2024-jul-03
 *
 * Descripción:     
 */

#ifndef BIBLIOTECAS_MSP_H_
#define BIBLIOTECAS_MSP_H_

#include <driverlib.h>

void mps430_configuration(void);
void spia_tx(uint8_t data);

#endif /* BIBLIOTECAS_MSP_H_ */
