/*
 * Onik
 * 
 * Archivo: dogm132.c
 * Autor  : Valentín Nájera Bello
 * Fecha  : 2024-jul-18
 *
 * Descripción:     
 */

#include "dogm132.h"
#include "font.h"

#define ALPHA 1
#define DIGIT 0

void float_to_string(float value, char *str);
void get_prefix_string(float value, char *str);
void clean_string(char * str, uint16_t length);
uint16_t string_length(char * str);


/*
 * cmd: 1) ON, 2) OFF.
 */
void lcd_display_state(uint8_t cmd)
{
	CS_low;
	A0_low;
	spia_tx(cmd);
	CS_high;
}


/*
 * line indica la dirección de la línea de inicio del LCD.
 */
void lcd_display_start_line_set(uint8_t line)
{
	uint8_t start_line;

	CS_low;
	A0_low;
	start_line = START_LINE_CMD | (MASK_6BITS & line);
	spia_tx(start_line);
	CS_high;
}


/*
 * page indica la página a usar.
 */
void lcd_page_address_set(uint8_t page)
{
	uint8_t page_address;

	CS_low;
	A0_low;
	page_address = PAGE_CMD | (MASK_4BITS & page);
	spia_tx(page_address);
	CS_high;
}


/*
 * column indica la columna a usar.
 */
void lcd_column_address_set(uint8_t column)
{
	uint8_t msca;
	uint8_t lsca;

	msca = UPPER_CMD | (MASK_4BITS & (column >> SHIFT_4BITS));
	lsca = LOWER_CMD | (MASK_4BITS & column);

	CS_low;
	A0_low;
	spia_tx(msca);
	spia_tx(lsca);
	CS_high;
}


/*
 * data representa el valor a escribir en la LCD.
 */
void lcd_display_data_write(uint8_t data)
{
	CS_low;
	A0_high;
	spia_tx(data);
	CS_high;
}


/*
 * cmd: 1) ADC_NORMAL, 2) ADC_REVERSE.
 */
void lcd_adc_select(uint8_t cmd)
{
	CS_low;
	A0_low;
	spia_tx(cmd);
	CS_high;
}


/*
 * cmd: 1) NORMAL_MODE, 2) REVERSE_MODE.
 */
void lcd_display_mode(uint8_t cmd)
{
	CS_low;
	A0_low;
	spia_tx(cmd);
	CS_high;
}


/*
 * cmd: 1) ALL_POINTS_ON, 2) ALL_POINTS_OFF
 */
void lcd_display_all_points(uint8_t cmd)
{
	CS_low;
	A0_low;
	spia_tx(cmd);
	CS_high;
}


/*
 * cmd: 1) RATIO_1_9_BIAS, 2) RATIO_1_7_BIAS.
 */
void lcd_bias_set(uint8_t cmd)
{
	CS_low;
	A0_low;
	spia_tx(cmd);
	CS_high;
}


/*
 *
 */
void ldc_reset(void)
{
	CS_low;
	A0_low;
	spia_tx(RESET);
	CS_high;
}


/*
 * mode: 1) COMMON_NORMAL_MODE, 2) COMMON_REVERSE_MODE.
 */
void lcd_common_output_mode_select(uint8_t mode)
{
	CS_low;
	A0_low;
	spia_tx(mode);
	CS_high;
}


/*
 * booster_mode:           1) BOOSTER_CIRCUIT_OFF,          2) BOOSTER_CIRCUIT_ON.
 * voltage_regulator_mode: 1) VOLTAGE_REG_CIRCUIT_OFF,      2) VOLTAGE_REG_CIRCUIT_ON.
 * voltage_follower_mode:  1) VOLTAGE_FOLLOWER_CIRCUIT_OFF, 2) VOLTAGE_FOLLOWER_CIRCUIT_ON.
 */
void lcd_power_control_set(uint8_t booster_mode, uint8_t voltage_regulator_mode, uint8_t voltage_follower_mode)
{
	uint8_t mode;

	CS_low;
	A0_low;
	mode = PWR_CONTROLLER_CMD | (booster_mode + voltage_regulator_mode + voltage_follower_mode);
	spia_tx(mode);
	CS_high;
}

/*
 * ratio indica la relación para la resistencia interna.
 */
void lcd_v0_voltage_reg_internal_resistor_ratio_set(uint8_t ratio)
{
	uint8_t resistor_ratio;

	CS_low;
	A0_low;
	resistor_ratio = RESISTOR_RATIO_CMD | (MASK_3BITS & ratio);
	spia_tx(resistor_ratio);
	CS_high;
}


/*
 * volume es el valor a escribir en el registro Electronic Volume.
 */
void lcd_electronic_volume(uint8_t volume)
{
	uint8_t volume_value;

	CS_low;
	A0_low;
	spia_tx(VOLUME_MODE_CMD);
	volume_value = VOLUME_REGISTER_CMD | (MASK_6BITS & volume);
	spia_tx(volume_value);
	CS_high;
}


/*
 * cmd: 1) BLINKING_ONE_SECOND, 2) BLINKING_HALF_SECOND, 3) CONSTANT_ON
 */
void lcd_static_indicator_on(uint8_t cmd)
{
	CS_low;
	A0_low;
	spia_tx(INDICATOR_ON);
	spia_tx(cmd);
	CS_high;
}


void lcd_static_indicator_off(void)
{
	CS_low;
	A0_low;
	spia_tx(INDICATOR_OFF);
	spia_tx(ZEROS);
	CS_high;
}


/*
 * ratio: 1) BOOSTER_2X_3X_4X, 2) BOOSTER_5X, 3)BOOSTER_6X.
 */
void lcd_booster_ratio_set(uint8_t ratio)
{
	CS_low;
	A0_low;
	spia_tx(BOOSTER_RATIO_MODE);
	spia_tx(ratio);
	CS_high;
}


void lcd_nop(void)
{
	CS_low;
	A0_low;
	spia_tx(NOP_CMD);
	CS_high;
}



/*
 * ch: caracter a escribie en el LCD.
 * page: 0,1,2,3 son los valores permisibles.
 * column: 0,1,...,131 solo valore permisibles.
 * font: apuntador a la estructura que contiene la información de la fuente a utilizar.
 * type: indica el tipo de cadena, alfanúmerica o digitos. Los valores de type son ALPHA o DIGIT
 */
void lcd_write_char(char ch, uint8_t page, uint8_t column, struct FONT * font, uint8_t type)
{
	uint16_t index;
	uint16_t ind;
	uint16_t row;
	uint16_t k;

	uint8_t data;
	uint16_t num_rows;
	uint16_t num_columns;

	char offset;

	num_rows = font->high / 8;
	num_columns = font->width;

	offset = ((type == ALPHA) ? ' ' : '-');
	index = (num_columns * num_rows) * (uint16_t)(ch - offset);

	lcd_column_address_set(column);
	for (row = 0; row < num_rows; row++){
		lcd_page_address_set(page + row);
		for (k = 0; k < num_columns; k++){
			ind = index + (num_rows * k + row);
			data = font->buf[ind];
			lcd_display_data_write(data);
		}
		lcd_column_address_set(column);
	}
}

/*
 * str: apuntador de la cadena a escribir en el LCD.
 * page: 0,1,2,3 son los valores permisibles.
 * column: 0,1,...,131 solo valore permisibles.
 */
void lcd_write_alphanumerics_string(char *str, uint8_t page, uint8_t column)
{
	uint8_t k;

	k = 0;
	while(str[k] != 0){
		lcd_write_char(str[k], page, column, &font_alphanumeric, ALPHA);
		column += font_alphanumeric.width;
		k++;
	}
}


/*
 * str: apuntador de la cadena a escribir en el LCD.
 * page: 0,1,2,3 son los valores permisibles.
 * column: 0,1,...,131 solo valore permisibles.
 */
void lcd_write_digits_string(char *str, uint8_t page, uint8_t column)
{
	uint8_t k;

	k = 0;
	while(str[k] != 0){
		lcd_write_char(str[k], page, column, &font_digits, DIGIT);
		column += font_digits.width;
		k++;
	}
}


void lcd_clean_display(void)
{
	uint8_t page;
	uint8_t column;

	for (page = 0; page < 4; page++){
		lcd_page_address_set(page);
		lcd_column_address_set(0);
		for (column = 0; column < 132; column++){
			lcd_display_data_write(ZEROS);
		}
	}
}


void lcd_configuration(void)
{
	lcd_display_start_line_set(0);
	lcd_adc_select(ADC_REVERSE);
	lcd_common_output_mode_select(COMMON_NORMAL_MODE);
	lcd_display_mode(NORMAL_MODE);
	lcd_bias_set(RATIO_1_9_BIAS);
	lcd_power_control_set(BOOSTER_CIRCUIT_ON, VOLTAGE_REG_CIRCUIT_ON, VOLTAGE_FOLLOWER_CIRCUIT_ON);
	lcd_booster_ratio_set(BOOSTER_2X_3X_4X);
	lcd_v0_voltage_reg_internal_resistor_ratio_set(0x03);
	lcd_electronic_volume(0x1F);
	lcd_static_indicator_off();
	lcd_display_state(ON);

	lcd_clean_display();
}



void lcd_write_measure(float x)
{
	char digits[20]={0};
	char prefix[20]={0};

	uint8_t length;
	uint8_t offset = 5;
	uint8_t width_font = 14;
	uint8_t start_col_digits;
	uint8_t start_col_alpha = 95;

	clean_string(digits, 20);
	clean_string(prefix, 20);

	float_to_string(x, digits);
	get_prefix_string(x, prefix);
	length = string_length(digits);
	start_col_digits = start_col_alpha - (length * width_font) - offset;

	lcd_clean_display();
	lcd_write_digits_string(digits, 1, start_col_digits);
	lcd_write_alphanumerics_string(prefix, 2, start_col_alpha);
}














