/*
 * main.c
 *
 *  Created on: Sep 7, 2019
 *      Author: William
 */
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#define GREEN_led  0
#define Yellow_led 1
#define Red_led    2
#define LED_Port  PORT_C

int main (void)
{
	u8 ADC_Value=0;
	u16 Analogue_Value =0;
	//Directions of the LEds
	DIO_voidSetPinDirection(LED_Port,GREEN_led,DIO_DIRECTION_OUTPUT);
	DIO_voidSetPinDirection(LED_Port,Yellow_led,DIO_DIRECTION_OUTPUT);
	DIO_voidSetPinDirection(LED_Port,Red_led,DIO_DIRECTION_OUTPUT);
     // turn off all LEDs
	DIO_SetPinValue(LED_Port,GREEN_led,LOW);
	DIO_SetPinValue(LED_Port,Yellow_led,LOW);
	DIO_SetPinValue(LED_Port,Red_led,LOW);
	// turn on ADC
	ADC_Init();
	while (1)
	{
		ADC_Value = ADC_get_value();
		// get the step size Vref/2^8 =13.4mV times the steps
		Analogue_Value=((ADC_Value*(5000UL))/256);
		if(0<=Analogue_Value && Analogue_Value<=1500)
		{
			    DIO_SetPinValue(LED_Port,GREEN_led,LOW);
				DIO_SetPinValue(LED_Port,Yellow_led,LOW);
				DIO_SetPinValue(LED_Port,Red_led,HIGH);
		}
		else if(1500<Analogue_Value && Analogue_Value<=3000)
				{
					    DIO_SetPinValue(LED_Port,GREEN_led,LOW);
						DIO_SetPinValue(LED_Port,Yellow_led,HIGH);
						DIO_SetPinValue(LED_Port,Red_led,LOW);
				}

		else if(3000<Analogue_Value && Analogue_Value<=5000)
				{
					    DIO_SetPinValue(LED_Port,GREEN_led,HIGH);
						DIO_SetPinValue(LED_Port,Yellow_led,LOW);
						DIO_SetPinValue(LED_Port,Red_led,LOW);
				}
		else
		{
//			DIO_SetPinValue(LED_Port,GREEN_led,LOW);
//			DIO_SetPinValue(LED_Port,Yellow_led,LOW);
//			DIO_SetPinValue(LED_Port,Red_led,LOW);
		}





	}

	return 0 ;
}
