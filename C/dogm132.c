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


void lcd_display_state(uint8_t cmd)
{
	CS_low;
	A0_low;
	spia_tx(cmd);
	CS_high;
}


void lcd_display_start_line_set(uint8_t line)
{
	uint8_t start_line;

	CS_low;
	A0_low;
	start_line = START_LINE_CMD | (MASK_6BITS & line);
	spia_tx(start_line);
	CS_high;
}


void lcd_page_address_set(uint8_t page)
{
	uint8_t page_address;

	CS_low;
	A0_low;
	page_address = PAGE_CMD | (MASK_4BITS & page);
	spia_tx(page_address);
	CS_high;
}


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


void lcd_display_data_write(uint8_t data)
{
	CS_low;
	A0_high;
	spia_tx(data);
	CS_high;
}


void lcd_adc_select(uint8_t cmd)
{
	CS_low;
	A0_low;
	spia_tx(cmd);
	CS_high;
}


void lcd_display_mode(uint8_t cmd)
{
	CS_low;
	A0_low;
	spia_tx(cmd);
	CS_high;
}


void lcd_display_all_points(uint8_t cmd)
{
	CS_low;
	A0_low;
	spia_tx(cmd);
	CS_high;
}


void lcd_bias_set(uint8_t cmd)
{
	CS_low;
	A0_low;
	spia_tx(cmd);
	CS_high;
}


void ldc_reset(void)
{
	CS_low;
	A0_low;
	spia_tx(RESET);
	CS_high;
}


void lcd_common_output_mode_select(uint8_t mode)
{
	CS_low;
	A0_low;
	spia_tx(mode);
	CS_high;
}


void lcd_power_control_set(uint8_t booster_mode, uint8_t voltage_regulator_mode, uint8_t voltage_follower_mode)
{
	uint8_t mode;

	CS_low;
	A0_low;
	mode = PWR_CONTROLLER_CMD | (booster_mode + voltage_regulator_mode + voltage_follower_mode);
	spia_tx(mode);
	CS_high;
}


void lcd_v0_voltage_reg_internal_resistor_ratio_set(uint8_t ratio)
{
	uint8_t resistor_ratio;

	CS_low;
	A0_low;
	resistor_ratio = RESISTOR_RATIO_CMD | (MASK_3BITS & ratio);
	spia_tx(resistor_ratio);
	CS_high;
}


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
}




















