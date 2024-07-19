/*
 * Onik
 * 
 * Archivo: timer.c
 * Autor  : Valentín Nájera Bello
 * Fecha  : 2024-jul-04
 *
 * Descripción:     
 */

#include "driverlib.h"

// For all periods, assumed that SMCL = 2 MHz
#define PERIOD_1S    50000
#define PERIOD_500MS 25000
#define PERIOD_100MS  5000
#define PERIOD_50MS   2500
#define PERIOD_10MS    500
#define PERIOD_1MS      50


void timer_configuration(void)
{
	Timer_A_initUpModeParam param = {0};

	param.clockSource = TIMER_A_CLOCKSOURCE_SMCLK;
	param.clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_40;
	param.timerPeriod = PERIOD_100MS - 1;
	param.timerInterruptEnable_TAIE = TIMER_A_TAIE_INTERRUPT_DISABLE;
	param.captureCompareInterruptEnable_CCR0_CCIE = TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE;
	param.timerClear = TIMER_A_DO_CLEAR;
	param.startTimer = false;

	Timer_A_stop(TIMER_A0_BASE);
	Timer_A_initUpMode(TIMER_A0_BASE, &param);
	Timer_A_clearTimerInterrupt(TIMER_A0_BASE);
	Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0);
}




