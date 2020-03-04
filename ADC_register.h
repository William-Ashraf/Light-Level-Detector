/*
 * ADC_register.h

 *
 *  Created on: Sep 7, 2019
 *      Author: William
 */

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_
#define ADCL_Register   * ((volatile u8 *) 0x24)
#define ACSR_Register   * ((volatile u8 *) 0x28)
#define ADMUX_Register  * ((volatile u8 *) 0x27)
#define ADCSRA_Register * ((volatile u8 *) 0x26)
#define ADCH_Register   * ((volatile u8 *) 0x25)
#define DDRA_Register   * ((volatile u8 * )0x3A)



#endif /* ADC_REGISTER_H_ */
