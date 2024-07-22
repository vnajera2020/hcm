/*
 * Onik
 * 
 * Archivo: font.h
 * Autor  : Valentín Nájera Bello
 * Fecha  : 2024-jul-19
 *
 * Descripción:     
 */

#ifndef BIBLIOTECAS_FONT_H_
#define BIBLIOTECAS_FONT_H_

#include "driverlib.h"

//extern const uint8_t Courier_New7x11[];
//extern const uint8_t Consolas14x22[];

struct FONT{
	uint8_t width;
	uint8_t high;
	const uint8_t *buf;
};

extern struct FONT font_digits;
extern struct FONT font_alphanumeric;

#endif /* BIBLIOTECAS_FONT_H_ */
