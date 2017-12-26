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



int main(void)
{
	RCC_HSI_Configuration();
	GPIO_Configuration();
	GPIO_WriteBit(LED_PORT, LED1, (BitAction)1);
	GPIO_WriteBit(LED_PORT, LED2, (BitAction)1);
	GPIO_WriteBit(PORTA, LCD_LED, (BitAction)0);
	delay_init(48);
	
	TIM3_TimeBaseInit();		// dang disable timer, disnable ngat
	
	ADC_Configuration();
	DMA_Configuration();
	DMA_P2M_ReadHalfWord(DMA1_Channel1, adcValue, (uint32_t)&ADC1->DR, 2*LENGHT_ACIS_X);
	
	Lcd_Init();
	LCD_LED_SET;

//	ADC_SingerConfiguration();
//	Lcd_Clear(BLACK);
	
//	displayAdvertisement();
//	delay_ms(1000);
//	delay_ms(1000);
//	delay_ms(1000);
	DisplayHomeOscillo();
	Lcd_ClearRigion(7, 7, 176, 146, BLACK);
	
	while(1)
	{
		__mainProcess();

//		adcValue1 = ADC_GetConversionValue(ADC1);
//		GPIO_TogglePin(LED_PORT, LED2);
//		sprintf(str1,"CH1: %.4u", adcValue1);
//		Gui_DrawFont_GBK16(5, 5, RED, BLACK, str1);
//		delay_ms(300);
	}
}

/*************************************** (C) COPYRIGHT MCA *****END OF FILE****/

