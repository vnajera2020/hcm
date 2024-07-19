/*
 * Onik
 * 
 * Archivo: gpio.c
 * Autor  : Valentín Nájera Bello
 * Fecha  : 2024-jul-04
 *
 * Descripción:     
 */

#include "driverlib.h"

void dio_configuration(void)
{
	/* P1: all inputs */
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P1, GPIO_PIN0);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P1, GPIO_PIN1);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P1, GPIO_PIN2);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P1, GPIO_PIN3);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P1, GPIO_PIN4);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P1, GPIO_PIN5);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P1, GPIO_PIN6);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P1, GPIO_PIN7);

	/* P2: all inputs */
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P2, GPIO_PIN0);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P2, GPIO_PIN1);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P2, GPIO_PIN2);

	/* P3: all inputs */
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P3, GPIO_PIN1);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P3, GPIO_PIN3);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P3, GPIO_PIN4);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P3, GPIO_PIN5);


	/* P4: all inputs */
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P4, GPIO_PIN0);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P4, GPIO_PIN1);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P4, GPIO_PIN2);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P4, GPIO_PIN3);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P4, GPIO_PIN4);


	/* P5: all inputs */
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P5, GPIO_PIN0);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P5, GPIO_PIN1);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P5, GPIO_PIN2);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P5, GPIO_PIN3);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P5, GPIO_PIN4);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P5, GPIO_PIN5);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P5, GPIO_PIN6);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P5, GPIO_PIN7);


	/* P6: all inputs */
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P6, GPIO_PIN0);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P6, GPIO_PIN2);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P6, GPIO_PIN4);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P6, GPIO_PIN5);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P6, GPIO_PIN6);


	/* P7: all inputs */
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P7, GPIO_PIN0);


	/* PJ: all inputs */
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_PJ, GPIO_PIN0);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_PJ, GPIO_PIN1);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_PJ, GPIO_PIN2);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_PJ, GPIO_PIN3);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_PJ, GPIO_PIN4);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_PJ, GPIO_PIN5);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_PJ, GPIO_PIN6);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_PJ, GPIO_PIN7);

	PMM_unlockLPM5();
}


