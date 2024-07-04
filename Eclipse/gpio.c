/*
 ============================================================================
 Module      : GPIO
 Name        : gpio.c
 Layer       : MCAL
 Author      : RASHA_YASSER
 Description : source file for interface the AVR GPIO driver
 Date        : 1/9/2023
 ============================================================================
 */
#include"gpio.h"
#include<avr/io.h>
#include"Common_Macros.h"

/*
 * check if n.of pin or n.of port are true if not true The function will not handle the request
 * Setup the direction of the required pin input/output
 *
 */

void GPIO_setupPinDirection(uint8 port_num,uint8 pin_num,GPIO_pinDirection direction){

	if((port_num>PORT_NUM)||(pin_num>PIN_NUM_PER_PORT)){
		/* Do Nothing */
	}
	else{
		switch(port_num){
		case PORTA_ID:
		if(direction==LOGIC_HIGH){
			SET_BIT(DDRA,pin_num);
		}
		else{
			CLEAR_BIT(DDRA,pin_num);
		}
		break;

		case PORTB_ID:
			if(direction==LOGIC_HIGH){
				SET_BIT(DDRB,pin_num);
	}
			else{
				CLEAR_BIT(DDRB,pin_num);
			}break;
		case PORTC_ID:
			if(direction==LOGIC_HIGH){
				SET_BIT(DDRC,pin_num);
			}
			else{
				CLEAR_BIT(DDRC,pin_num);
			}break;

			case PORTD_ID:
				if(direction==LOGIC_HIGH){
				SET_BIT(DDRD,pin_num);
		}
		  else{
				CLEAR_BIT(DDRD,pin_num);
				}break;
	}
}
}

/*write logic high or low on required pin
 * if the input port number  or pin not correct , the function will not handle the request
 */
void GPIO_writePin(uint8 port_num,uint8 pin_num ,uint8 value){
if((port_num>PORT_NUM)||(pin_num>PIN_NUM_PER_PORT)){
	/*do nothing*/
}
else{
	switch(port_num){
	case PORTA_ID:
		if(value==LOGIC_HIGH){
			SET_BIT(PORTA,pin_num);  //PORTA|=(1<<pin_num)
		}
		else{
			CLEAR_BIT(PORTA,pin_num);  //PORTA&=~(1<<pin_num)
		}break;
	case PORTB_ID:
			if(value==LOGIC_HIGH){
				SET_BIT(PORTB,pin_num);  //PORTA|=(1<<pin_num)
			}
			else{
				CLEAR_BIT(PORTB,pin_num);  //PORTA&=~(1<<pin_num)
			}break;
	case PORTC_ID:
			if(value==LOGIC_HIGH){
				SET_BIT(PORTC,pin_num);  //PORTA|=(1<<pin_num)
			}
			else{
				CLEAR_BIT(PORTC,pin_num);  //PORTA&=~(1<<pin_num)
			}break;
	case PORTD_ID:
			if(value==LOGIC_HIGH){
				SET_BIT(PORTD,pin_num);  //PORTA|=(1<<pin_num)
			}
			else{
				CLEAR_BIT(PORTD,pin_num);  //PORTA&=~(1<<pin_num)
			}break;
	}
}

}
/*
 * read and return the value for required pin ,it should be LOGIC_LOW or LOGIC_HIGH
 * if the input port number or pin number are not correct ,the function will return LOGIC_LOW
 */
uint8 GPIO_readPin(uint8 port_num,uint8 pin_num){
	if((port_num>PORT_NUM)||(pin_num>PIN_NUM_PER_PORT)){
		return LOGIC_LOW;
	}
	else {
		switch (port_num){
		case PORTA_ID:
			if(BIT_IS_SET(PINA,pin_num)){
				return LOGIC_HIGH;
			}
			else{
				return LOGIC_LOW;

			}
		case PORTB_ID:
					if(BIT_IS_SET(PINB,pin_num)){
						return LOGIC_HIGH;
					}
					else{
						return LOGIC_LOW;
					}
		case PORTC_ID:
					if(BIT_IS_SET(PINC,pin_num)){
						return LOGIC_HIGH;
					}
					else{
						return LOGIC_LOW;
					}
		case PORTD_ID:
					if(BIT_IS_SET(PIND,pin_num)){
						return LOGIC_HIGH;
					}
					else{
						return LOGIC_LOW;

					}
		}
	}
	return 0;

}

/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_setupPortDirection(uint8 port_num,GPIO_portDirection direction){
	if(port_num>PORT_NUM){
		/*do nothing*/
	}
	else
		switch (port_num){
		case PORTA_ID:
				DDRA=direction;
				break;
		case PORTB_ID:
			DDRB=direction;
			break;
		case PORTC_ID:
			DDRC=direction;
			break;
		case PORTD_ID:
			DDRD=direction;
			break;
			}
		}

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */

uint8 GPIO_readPort(uint8 port_num){
	if(port_num>PORT_NUM){
			/*do nothing*/
	}
	else{
	switch (port_num){
	case PORTA_ID:
		return PINA;
	case PORTB_ID:
		return PINB;
	case PORTC_ID:
		return PINC;
	case PORTD_ID:
		return PIND;

				}
         	}
	return 0 ;
	}
/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_writePort(uint8 port_num, uint8 value)
{
	if(port_num >= PORT_NUM)
		{
			/* Do Nothing */
		}
	else{
		switch(port_num)
		{
		case PORTA_ID:

			PORTA=value;
			break;
		case PORTB_ID:

				PORTB=value;

			break;
		case PORTC_ID:

				PORTC=value;
			break;
		case PORTD_ID:
		    PORTD=value;
		break;
	}
}
}
