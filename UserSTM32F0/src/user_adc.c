#include "user_adc.h"

static uint16_t adc_value;

void ADC1_IRQHandler(void)
{
	GPIO_TogglePin(GPIOB, GPIO_Pin_13);
	if(ADC_GetITStatus(ADC1, ADC_FLAG_EOC) != RESET)
	{
		ADC_ClearITPendingBit(ADC1, ADC_FLAG_EOC);
		adc_value = ADC_GetConversionValue(ADC1);
	}
}

uint16_t ADC_GetConvertedValue(void)
{
	uint16_t tmpADC;
	
	tmpADC = adc_value;
	return tmpADC;
}

void ADC_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	ADC_InitTypeDef ADC_Initstructure;
//	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE); 
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);  
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
//	NVIC_InitStructure.NVIC_IRQChannel = ADC1_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
//	NVIC_Init(&NVIC_InitStructure);
	
	ADC_DeInit(ADC1);
	ADC_StructInit(&ADC_Initstructure);
	
	ADC_Initstructure.ADC_Resolution = ADC_Resolution_12b;
	ADC_Initstructure.ADC_ContinuousConvMode = ENABLE;
	ADC_Initstructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
	ADC_Initstructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_Initstructure.ADC_ScanDirection = ADC_ScanDirection_Upward;
	ADC_Init(ADC1, &ADC_Initstructure);
	
	ADC_ChannelConfig(ADC1, ADC_Channel_0, ADC_SampleTime_239_5Cycles);
	ADC_GetCalibrationFactor(ADC1);
//	ADC_ITConfig(ADC1, ADC_IT_EOC, ENABLE);						// IT Config

	ADC_DMARequestModeConfig(ADC1, ADC_DMAMode_Circular);		// DMA config
	ADC_DMACmd(ADC1, ENABLE);

	ADC_Cmd(ADC1, ENABLE);

	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_ADRDY));
	ADC_StartOfConversion(ADC1);
}

void ADC_SingerConfiguration(void)
{
	ADC_InitTypeDef ADC_Initstructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	ADC_StopOfConversion(ADC1);//
	ADC_Cmd(ADC1, DISABLE);//
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE); 
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);  
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	ADC_DeInit(ADC1);
	ADC_StructInit(&ADC_Initstructure);
	
	ADC_Initstructure.ADC_Resolution = ADC_Resolution_12b;
	ADC_Initstructure.ADC_ContinuousConvMode = DISABLE;
	ADC_Initstructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
	ADC_Initstructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_Initstructure.ADC_ScanDirection = ADC_ScanDirection_Upward;
	ADC_Init(ADC1, &ADC_Initstructure);
	
	ADC_ChannelConfig(ADC1, ADC_Channel_0, ADC_SampleTime_239_5Cycles);
	ADC_GetCalibrationFactor(ADC1);
	

	ADC_DMACmd(ADC1, DISABLE);
	DMA_Cmd(DMA1_Channel1, DISABLE);
	ADC_Cmd(ADC1, ENABLE);

	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_ADRDY));
	ADC_StartOfConversion(ADC1);
}	

