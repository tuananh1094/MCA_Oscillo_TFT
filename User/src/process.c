#include "process.h"
//#include "picture.h"

char str[20];
extern uint16_t adcValue[];

//void displayAdvertisement(void)
//{
//	Lcd_Clear(WHITE);
//	Gui_DrawFont_GBK16(85, 110, BLACK, WHITE, "Mr.Anh");
//	Gui_DrawFont_GBK16(55, 130, BLUE, WHITE, "0167.913.2684");
//	Gui_DisplayImage(105,40,92,67, MHG92x67);
//	Gui_DisplayImage(35,40,70,67, MCA70x67);
//}

void DisplayHomeOscillo(void)
{
	Lcd_Clear(BLACK);
	Gui_DrawLine(5, 5, 5, 155, WHITE);  
	Gui_DrawLine(5, 5, 185, 5, WHITE); 
	Gui_DrawLine(5, 155, 185, 155, WHITE); 
	Gui_DrawLine(185, 5, 185, 155, WHITE); 
	
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
	
	Gui_DrawFont_GBK16(5, 156, RED, BLACK, "CH1:ON");
	Gui_DrawFont_GBK16(105, 156, GREEN, BLACK, "CH2:OFF");
}

void __mainProcess(void)
{	
	uint16_t i;
//	sprintf(str,"%.4u", adcValue[0]);
//	Gui_DrawFont_GBK16(40, 156, RED, BLACK, str);
	
	for(i=0; i< LENGHT_ACIS_X; i++)
	{
		//Gui_DrawPoint(5+i, LENGHT_ACIS_Y- 70- adcValue[i]/68, RED);
		Gui_DrawLine(5+i, LENGHT_ACIS_Y- 70- adcValue[i]/68, 5+i, LENGHT_ACIS_Y- 70- adcValue[i+1]/68,RED);
		//delay_ms(20);
	}
	Lcd_ClearRigion(5, 5, 180, 150, BLACK);
}


