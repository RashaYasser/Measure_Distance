/*
 ============================================================================
 Module      : ICU_HW
 Name        : ICU_HW.c
 Layer       : MCAL
 Author      : RASHA_YASSER
 Description : source file for interface the AVR ICU_HW driver
 Date        : 21/9/2023
 ============================================================================
 */
#include "ICU_HW.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include <avr/io.h>        /* To use ICU/Timer1 Registers */
#include <avr/interrupt.h> /* For ICU ISR */

static volatile void (*g_callBackPtr)(void) = NULL_PTR;

ISR(TIMER1_CAPT_vect)
{
	if(g_callBackPtr!=NULL_PTR)
	{
	(*g_callBackPtr)();
	}
}
void ICU_HW_init(const ICU_ConfigType *ptr_confg)
{
	DDRD &= ~(1<<PD6);

		/* Timer1 always operates in Normal Mode */
		TCCR1A = (1<<FOC1A) | (1<<FOC1B);

		/*
		 * insert the required clock value in the first three bits (CS10, CS11 and CS12)
		 * of TCCR1B Register
		 */
		TCCR1B = (TCCR1B & 0xF8) | (ptr_confg->clock);
		/*
	     * insert the required edge type in ICES1 bit in TCCR1B Register
		 */
		TCCR1B = (TCCR1B & 0xBF) | ((ptr_confg->edge)<<6);

		/* Initial Value for Timer1 */
		TCNT1 = 0;

		/* Initial Value for the input capture register */
		ICR1 = 0;

		/* Enable the Input Capture interrupt to generate an interrupt when edge is detected on ICP1/PD6 pin */
		TIMSK |= (1<<TICIE1);
	}

void ICU_GetCallBack(void(*ptr)(void))
{
	g_callBackPtr= ptr;

}


void ICU_setEdgeDetectionType(const ICU_EdgeType edge)
{

		/*
		 * insert the required edge type in ICES1 bit in TCCR1B Register
		 */
	TCCR1B = (TCCR1B & 0xBF) | (edge<<6);

}

uint16 ICU_getInputCaptureValue(void)
{
	return ICR1;
}


void ICU_clearTimerValue(void)
{
		TCNT1=0;
}


void ICU_deInit(void)
{
	/* Clear All Timer1/ICU Registers */
		TCCR1A = 0;
		TCCR1B = 0;
		TCNT1 = 0;
		ICR1 = 0;

		/* Disable the Input Capture interrupt */
		TIMSK &= ~(1<<TICIE1);

		/* Reset the global pointer value */
		g_callBackPtr = NULL_PTR;
}




