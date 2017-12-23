/**
  ******************************************************************************
  * @file    main.c
  * @author  MCA Team
  * @version V1.0
  * @date    14/9/2017
  * @brief   Main program
  *         
  ******************************************************************************
**/
#include "main.h"

uint16_t adcValue[2*LENGHT_ACIS_X];
uint16_t test, k;
int main(void)
{
	RCC_HSI_Configuration();
	GPIO_Configuration();
	GPIO_WriteBit(LED_PORT, LED1, (BitAction)1);
	GPIO_WriteBit(LED_PORT, LED2, (BitAction)1);
	GPIO_WriteBit(PORTA, LCD_LED, (BitAction)0);
	delay_init(48);
	
	ADC_Configuration();
	DMA_Configuration();
	
	Lcd_Init();
	LCD_LED_SET;

	DMA_P2M_ReadHalfWord(DMA1_Channel1, adcValue, (uint32_t)&ADC1->DR, 2*LENGHT_ACIS_X);
	
	DisplayHomeOscillo();
	while(1)
	{
		__mainProcess();

	}
}

/*************************************** (C) COPYRIGHT MCA *****END OF FILE****/

