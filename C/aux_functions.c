/*
 * Onik
 * 
 * Archivo: aux_functions.c
 * Autor  : Valentín Nájera Bello
 * Fecha  : 2024-jul-22
 *
 * Descripción:     
 */


#include "driverlib.h"

#define ONE_MICRO     1E-6
#define ONE_MILI      1E-3
#define TEN           10
#define ONE           1
#define ONE_THOUSAND  1E3
#define ONE_MILLION   1E6

#define PRECISION	  1

#define ZERO_ASCII_CODE 48


void clean_string(char * str, uint16_t length)
{
	uint16_t k;

	for (k = 0; k < length; k++) {
		str[k] = 0;
	}
}

/*
 * concatenate_strings añade la cadena str2 la cadena str1.
 * str1 debe tener suficiente espacio para almacenar a str2.
 */
void concatenate_strings(char *str1, char *str2)
{
	uint16_t k;
	uint16_t n;

	k = 0;
	while (str1[k] != 0) {
		k++;
	}

	n = 0;
	while(str2[n] != 0){
		str1[k] = str2[n];
		k++;
		n++;
	}
	str1[k] = 0;
}


/*
 * La función voltea el contenido del arreglo.
 * Ejemplo. Sea str = {d c b a}, después de llamar a
 * flip_string tenemos que str = {a b c d}.
 */
void flip_string(char * str, uint16_t length)
{
	uint16_t k;
	uint16_t n;
	uint16_t index;
	char temp;

	n = length / 2;
	for (k = 0; k < n; k++) {
		index = length - k - 1;
		temp = str[index];
		str[index] = str[k];
		str[k] = temp;
	}
}


/*
 * value debe ser positivo.
 */
void float_to_string(float value, char *str)
{
	const char *error_msg = "---.--";

	char integer_string[10] = {0};
	char fractional_string[10] ={0};
	uint16_t k;
	uint16_t digit;
	uint16_t integer_part;
	float fractional_part;


	if ((value < ONE_MICRO) || (value >= TEN)) {
		k = 0;
		while (error_msg[k] != 0) {
			str[k] = error_msg[k];
			k++;
		}
		return;
	}

	// Ajustar el value al rango correspondiente: micro, milis o unidades
	if ((value >= ONE_MICRO) && (value < ONE_MILI)) {
		value *= ONE_MILLION;
	}
	if ((value >= ONE_MILI) && (value < ONE)) {
		value *= ONE_THOUSAND;
	}

	integer_part = (uint16_t) (value);
	fractional_part = value - (float) (integer_part);

	// Extraer la cadena de la parte entera
	if (integer_part == 0) {
		integer_string[0] = '0';
	} else {
		k = 0;
		while (integer_part > 0) {
			integer_string[k] = (char) (ZERO_ASCII_CODE + (integer_part % 10));
			integer_part /= 10;
			k++;
		}
		flip_string(integer_string, k);
	}

	// Extraer la cadena de la parte fraccionaria
	for (k = 0; k < PRECISION; k++) {
		fractional_part = fractional_part * 10.0;
		digit = (uint16_t)(fractional_part);
		fractional_string[k] = (char)(ZERO_ASCII_CODE + digit);
		fractional_part -= (float)(digit);
	}

	concatenate_strings(str, integer_string);
	concatenate_strings(str, ".");
	concatenate_strings(str, fractional_string);
}



void string_copy(char * destiny, const char * origen)
{
	uint16_t k;
	k = 0;
	while (origen[k] != 0) {
		destiny[k] = origen[k];
		k++;
	}
}

/*
 * La función regresa el prefijo correspondiente en
 * notación de ingeniería.
 */
void get_prefix_string(float value, char *str)
{
	const char micro_sv[] = "uSv";
	const char mili_sv[]  = "mSV";
	const char sv[]       = "sV";

	if ((value < ONE_MICRO) || (value >= TEN)) {
		string_copy(str, sv);
	}
	else if ((value >= ONE_MICRO) && (value < ONE_MILI)) {
		string_copy(str, micro_sv);
	}
	else if ((value >= ONE_MILI) && (value < ONE)) {
		string_copy(str, mili_sv);
	}
	else{
		string_copy(str, sv);
	}
}


uint16_t string_length(char * str)
{
	uint16_t k;
	k = 0;
	while (str[k] != 0) {
		k++;
	}

	return k;
}
