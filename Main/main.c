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
int d;


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

	displayAdvertisement();
	for(d=10;d<=210;d++)
	{
		Lcd_SetRegion(d, 140, d, 160);
		Gui_DrawLine(d, 140, d, 160, BLUE);
		delay_ms(20);
	}
	 	
	DisplayHomeOscillo();
	Lcd_ClearRigion(7, 7, 176, 146, BLACK);
	
	while(1)
	{
		__mainProcess();
	}
}

/*************************************** (C) COPYRIGHT MCA *****END OF FILE****/

