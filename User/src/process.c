#include "process.h"
#include "picture.h"

char str[20];
extern uint16_t adcValue[];

void displayAdvertisement(void)
{
	Lcd_Clear(WHITE);
	Gui_DrawFont_GBK16(85, 110, BLACK, WHITE, "Mr.Anh");
	Gui_DrawFont_GBK16(55, 130, BLUE, WHITE, "0167.913.2684");
	Gui_DisplayImage(105,40,92,67, MHG92x67);
	Gui_DisplayImage(35,40,70,67, MCA70x67);
}
/////////////////////////////////////////////////////////////////////////
void DisplayHomeOscillo(void)
{
	Lcd_Clear(BLACK);
	Gui_DrawLine(5, 5, 5, 155, WHITE);  
	Gui_DrawLine(5, 5, 185, 5, WHITE); 
	Gui_DrawLine(5, 155, 185, 155, WHITE); 
	Gui_DrawLine(185, 5, 185, 155, WHITE); 
	
	Gui_DrawLine(5, 80, 185, 80, GREEN); 
	Gui_DrawLine(5, 60, 185, 60, GREEN);  
	Gui_DrawLine(5, 40, 185, 40, GREEN);  
	Gui_DrawLine(5, 20, 185, 20, GREEN); 
	Gui_DrawLine(5, 100, 185, 100, GREEN);  
	Gui_DrawLine(5, 120, 185, 120, GREEN); 
	Gui_DrawLine(5, 140, 185, 140, GREEN); 
	
	Gui_DrawLine(25, 5, 25, 155, GREEN);
	Gui_DrawLine(45, 5, 45, 155, GREEN);
	Gui_DrawLine(65, 5, 65, 155, GREEN);
	Gui_DrawLine(85, 5, 85, 155, GREEN);
	Gui_DrawLine(105, 5, 105, 155, GREEN);
	Gui_DrawLine(125, 5, 125, 155, GREEN);
	Gui_DrawLine(145, 5, 145, 155, GREEN);
	Gui_DrawLine(165, 5, 165, 155, GREEN);
	
	DisplayButtonUp(190, 5, 215, 35);
	Gui_DrawFont_GBK16(199, 12, WHITE, BLACK, "A");
	
	DisplayButtonUp(190, 45, 215, 75);
	Gui_DrawFont_GBK16(199, 52, WHITE, BLACK, "+");
	
	DisplayButtonUp(190, 85, 215, 115);
	Gui_DrawFont_GBK16(199, 92, WHITE, BLACK, "-");
	
	DisplayButtonUp(190, 125, 215, 155);
	Gui_DrawFont_GBK16(199, 132, WHITE, BLACK, "T");

	Gui_DrawFont_GBK16(5, 156, RED, BLACK, "CH1:2V");
	//	Gui_DrawFont_GBK16(105, 156, GREEN, BLACK, "CH2:2V");
}
/////////////////////////////////////////////////////////////////////////
void DisplayCaro(void)
{
	Gui_DrawLine(5, 80, 185, 80, GRAY2); 
	Gui_DrawLine(5, 60, 185, 60, GRAY2);  
	Gui_DrawLine(5, 40, 185, 40, GRAY2);  
	Gui_DrawLine(5, 20, 185, 20, GRAY2); 
	Gui_DrawLine(5, 100, 185, 100, GRAY2);  
	Gui_DrawLine(5, 120, 185, 120, GRAY2); 
	Gui_DrawLine(5, 140, 185, 140, GRAY2); 
	
	Gui_DrawLine(25, 5, 25, 155, GRAY2);
	Gui_DrawLine(45, 5, 45, 155, GRAY2);
	Gui_DrawLine(65, 5, 65, 155, GRAY2);
	Gui_DrawLine(85, 5, 85, 155, GRAY2);
	Gui_DrawLine(105, 5, 105, 155, GRAY2);
	Gui_DrawLine(125, 5, 125, 155, GRAY2);
	Gui_DrawLine(145, 5, 145, 155, GRAY2);
	Gui_DrawLine(165, 5, 165, 155, GRAY2);
}
/////////////////////////////////////////////////////////////////////////
void __mainProcess(void)
{	
	uint16_t i;
	uint8_t flagRun  = 0;
	static uint8_t count;

	_drawValue(adcValue);
	if(increase()== PRESS);
	if(reduced()== PRESS);
	if(enter() == PRESS);
	if(set() == PRESS);
	Lcd_ClearRigion(7, 15, 176, 70, BLACK);// clear 1 phan
	
}
/////////////////////////////////////////////////////////////////////////
uint8_t set(void)
{
	if(GPIO_ReadInputDataBit(BUTTON_PORT, BUTTON4)==0)
	{
		delay_ms(20);
		if(GPIO_ReadInputDataBit(BUTTON_PORT, BUTTON4)==0)
		{
			while(GPIO_ReadInputDataBit(BUTTON_PORT, BUTTON4)==0) 
			{
				Lcd_SetRegion(190, 5, 215, 35);
				DisplayButtonDown(190, 5, 215, 35);
				Gui_DrawFont_GBK16(199, 12, GREEN, BLACK, "A");
			}
			DisplayButtonUp(190, 5, 215, 35);
			Gui_DrawFont_GBK16(199, 12, WHITE, BLACK, "A");
			return PRESS;
		}
	}
	return NOT_PRESS;
}

uint8_t increase(void)
{
	if(GPIO_ReadInputDataBit(BUTTON_PORT, BUTTON2)==0)
	{
		delay_ms(20);
		if(GPIO_ReadInputDataBit(BUTTON_PORT, BUTTON2)==0)
		{
			while(GPIO_ReadInputDataBit(BUTTON_PORT, BUTTON2)==0)
			{
				Lcd_SetRegion(190, 45, 215, 75);
				DisplayButtonDown(190, 45, 215, 75);
				Gui_DrawFont_GBK16(199, 52, GREEN, BLACK, "+");
			}
			DisplayButtonUp(190, 45, 215, 75);
			Gui_DrawFont_GBK16(199, 52, WHITE, BLACK, "+");
			return PRESS;
		}
	}
	return NOT_PRESS;
}

uint8_t reduced(void)
{
	if(GPIO_ReadInputDataBit(BUTTON_PORT, BUTTON3)==0)
	{
		delay_ms(20);
		if(GPIO_ReadInputDataBit(BUTTON_PORT, BUTTON3)==0)
		{
			while(GPIO_ReadInputDataBit(BUTTON_PORT, BUTTON3)==0)
			{
				Lcd_SetRegion(190, 85, 215, 115);
				DisplayButtonDown(190, 85, 215, 115);
				Gui_DrawFont_GBK16(199, 92, GREEN, BLACK, "-");
			}
			DisplayButtonUp(190, 85, 215, 115);
			Gui_DrawFont_GBK16(199, 92, WHITE, BLACK, "-");
			return PRESS;
		}
	}
	return NOT_PRESS;
}
uint8_t enter(void)
{
	if(GPIO_ReadInputDataBit(BUTTON_PORT, BUTTON1)==0)
	{
		delay_ms(20);
		if(GPIO_ReadInputDataBit(BUTTON_PORT, BUTTON1)==0)
		{
			while(GPIO_ReadInputDataBit(BUTTON_PORT, BUTTON1)==0)
			{
				Lcd_SetRegion(190, 125, 215, 155);
				DisplayButtonDown(190, 125, 215, 155);
				Gui_DrawFont_GBK16(199, 132, GREEN, BLACK, "T");
			}
			DisplayButtonUp(190, 125, 215, 155);
			Gui_DrawFont_GBK16(199, 132, WHITE, BLACK, "T");
			return PRESS;
		}
	}
	return NOT_PRESS;
}
/////////////////////////////////////////////////////////////////////////
void buzz(uint8_t bip)
{
	while(bip)
	{
		GPIO_WriteBit(BUZZ_PORT, BUZZ, (BitAction)1);
		delay_ms(100);
		GPIO_WriteBit(BUZZ_PORT, BUZZ, (BitAction)0);
		delay_ms(100);
		bip--;
	}
}
/////////////////////////////////////////////////////////////////////////
void _drawValue(uint16_t *value)
{
	uint8_t i;
	for(i=0; i< LENGHT_ACIS_X; i++)
	{
		Gui_DrawLine(5+i, LENGHT_ACIS_Y- 70- value[i]/22, 5+i, LENGHT_ACIS_Y- 70- value[i+1]/22,RED);
	}
}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////



