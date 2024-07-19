/*
 * Onik
 * 
 * Archivo: spi.c
 * Autor  : Valentín Nájera Bello
 * Fecha  : 2024-jul-09
 *
 * Descripción:     
 */


#include "driverlib.h"

#define SPI_CLK_FREQUENCY  1000000

int spia_tx_ready = 1;


void spia_configuration(void)
{
	EUSCI_A_SPI_initMasterParam param = {0};

	param.selectClockSource    = EUSCI_A_SPI_CLOCKSOURCE_SMCLK;
	param.clockSourceFrequency = CS_getSMCLK();
	param.desiredSpiClock	   = SPI_CLK_FREQUENCY;
	param.msbFirst			   = EUSCI_A_SPI_MSB_FIRST;
	param.clockPhase           = EUSCI_A_SPI_PHASE_DATA_CHANGED_ONFIRST_CAPTURED_ON_NEXT;
	param.clockPolarity        = EUSCI_A_SPI_CLOCKPOLARITY_INACTIVITY_HIGH;
	param.spiMode              = EUSCI_A_SPI_3PIN;

	EUSCI_A_SPI_disable(EUSCI_A2_BASE);
	EUSCI_A_SPI_initMaster(EUSCI_A2_BASE, &param);
	EUSCI_A_SPI_enable(EUSCI_A2_BASE);
//	EUSCI_A_SPI_clearInterrupt(EUSCI_A2_BASE, EUSCI_A_SPI_TRANSMIT_INTERRUPT);
//	EUSCI_A_SPI_enableInterrupt(EUSCI_A2_BASE, EUSCI_A_SPI_TRANSMIT_INTERRUPT);
}


void spia_gpio(void)
{
	// The LCD's terminals connected to SPIA
	GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN7); // CS  (Chip Select: active low)
	GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN4); // RST (Reset:active low)
	GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN3); // A0  (A0: Display data [1] or Command [0])
	GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P5, GPIO_PIN2, GPIO_SECONDARY_MODULE_FUNCTION); // SCL
	GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P5, GPIO_PIN0, GPIO_SECONDARY_MODULE_FUNCTION); // SIMO

	GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN7); // CS
	GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN4); // RST
	GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN3); // A0
}


void spia_tx(uint8_t data)
{
	while(1){
		if (EUSCI_A_SPI_getInterruptStatus(EUSCI_A2_BASE ,EUSCI_A_SPI_TRANSMIT_INTERRUPT))
			break;
	}
	EUSCI_A_SPI_transmitData(EUSCI_A2_BASE, data);
}

