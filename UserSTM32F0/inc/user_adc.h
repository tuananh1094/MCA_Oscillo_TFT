#ifndef _USER_ADC_H_
#define _USER_ADC_H_

#include "main.h"

void ADC_Configuration(void);
void ADC_SingerConfiguration(void);
uint16_t ADC_GetConvertedValue(void);
void ADC1_IRQHandler(void);


#endif

