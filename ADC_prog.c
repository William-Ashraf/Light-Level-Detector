/*
 * ADC_prog.c

 *
 *  Created on: Sep 7, 2019
 *      Author: William
 */

#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "ADC_register.h"
#include "ADC_interface.h"

void ADC_Init (void)
{
	//Set pin ADC0 PA0 input
	CLR_BIT(DDRA_Register,0);
	//turn on ADC Peripheral
	SET_BIT(ADCSRA_Register,7);
	//Conversion speed
	SET_BIT(ADCSRA_Register,2);
	SET_BIT(ADCSRA_Register,1);
	CLR_BIT(ADCSRA_Register,0);
	//Select voltage preference
	CLR_BIT(ADMUX_Register,7);
	SET_BIT(ADMUX_Register,6);
	//Select which pin ADC will convert
	CLR_BIT(ADMUX_Register,0);
	CLR_BIT(ADMUX_Register,1);
	CLR_BIT(ADMUX_Register,2);
	CLR_BIT(ADMUX_Register,3);
	CLR_BIT(ADMUX_Register,4);
	//adjust the data to the left
	SET_BIT(ADMUX_Register,5);
}

u8 ADC_get_value(void)
{
	//start conversion
	SET_BIT(ADCSRA_Register,6);
	//wait until flag of the conversion is up
	while (GET_BIT(ADCSRA_Register,4)==0);
	SET_BIT(ADCSRA_Register,4);
	return ADCH_Register ;
}



