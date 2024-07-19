/*
 * Onik
 * 
 * Archivo: dogm132.h
 * Autor  : Valentín Nájera Bello
 * Fecha  : 2024-jul-18
 *
 * Descripción:     
 */

#ifndef BIBLIOTECAS_DOGM132_H_
#define BIBLIOTECAS_DOGM132_H_

#include "driverlib.h"

#define OFF				             0xAE
#define ON				             0xAF
#define START_LINE_CMD               0x40
#define PAGE_CMD		             0xB0
#define UPPER_CMD 		             0x10
#define LOWER_CMD 		             0x00
#define ADC_NORMAL                   0xA0
#define ADC_REVERSE		             0xA1
#define NORMAL_MODE                  0xA6
#define REVERSE_MODE                 0xA7
#define ALL_POINTS_ON                0xA4
#define ALL_POINTS_OFF               0xA5
#define RATIO_1_9_BIAS               0xA2
#define RATIO_1_7_BIAS               0xA3
#define RESET			             0xE2
#define COMMON_NORMAL_MODE  		 0xC0
#define COMMON_REVERSE_MODE 		 0xC8
#define BOOSTER_CIRCUIT_OFF        	 0x00
#define BOOSTER_CIRCUIT_ON           0x04
#define VOLTAGE_REG_CIRCUIT_OFF      0x00
#define VOLTAGE_REG_CIRCUIT_ON       0x02
#define VOLTAGE_FOLLOWER_CIRCUIT_OFF 0x00
#define VOLTAGE_FOLLOWER_CIRCUIT_ON  0x01
#define PWR_CONTROLLER_CMD		     0x28
#define RESISTOR_RATIO_CMD			 0x20
#define VOLUME_MODE_CMD				 0x81
#define VOLUME_REGISTER_CMD          0x00
#define BLINKING_ONE_SECOND          0x01
#define BLINKING_HALF_SECOND         0x02
#define CONSTANT_ON                  0x03
#define INDICATOR_OFF			     0xAC
#define INDICATOR_ON			     0xAD
#define BOOSTER_RATIO_MODE           0xF8
#define BOOSTER_2X_3X_4X			 0x00
#define BOOSTER_5X			 	     0x01
#define BOOSTER_6X			 	     0x03
#define NOP_CMD					     0xE3
#define ZEROS						 0x00

#define A0_high	GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN3)
#define A0_low	GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN3)
#define CS_high	GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN7)
#define CS_low	GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN7)
#define RST_high GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN4)
#define RST_low GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN4)

#define SHIFT_4BITS 4

#define MASK_3BITS	0x0007
#define MASK_4BITS	0x000F
#define MASK_6BITS	0x003F

void spia_tx(uint8_t data);

#endif /* BIBLIOTECAS_DOGM132_H_ */


