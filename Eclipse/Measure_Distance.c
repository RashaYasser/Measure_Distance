/*
 ============================================================================
 Module      : Application
 Name        : Measure_Distance.c
 Layer       : APP
 Author      : RASHA_YASSER
 Description : APplication for Measure the distance using the Ultrasonic sensor HC-SR04.
 Date        : 3/10/2023
 ============================================================================
 */
#include"lcd.h"
#include"Ultrasonic.h"
#include"ICU_HW.h"
#include<avr/io.h> /* To use the SREG register */


int main(void)
{

    uint16 distance ;
    /* Initialize both the LCD and Ultrasonic driver */
	LCD_init();
	Ultrasonic_init();

	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);

	LCD_displayString("Distance=    cm");
	/* get the calculated distance */
	while(1)
	{
		distance = Ultrasonic_readDistance();
		if(distance <100)
		{
		LCD_moveCursor(0,10);
		/* display the distance on LCD screen */
		LCD_intgerToString(distance);
		LCD_displayCharacter(' ');
		}
		else
		{
			LCD_moveCursor(0,10);
			LCD_intgerToString(distance);
		}
	}
}
