/**
  ******************************************************************************
  * @file    main.h
  * @author  MCA Team
  * @version V1.0
  * @date    14/9/2017
  * @brief   Main program
  *         
  ******************************************************************************
**/
#ifndef _MAIN_H_
#define _MAIN_H_

typedef unsigned char u8;
typedef unsigned int  u16;

#include "stm32f0xx.h"
#include "stm32f0xx_conf.h"

#include "stdio.h"
#include "string.h"

#include "user_delay.h"
#include "user_gpio.h"
#include "user_timer.h"
#include "user_uart.h"
#include "user_dma.h"
#include "user_adc.h"
#include "user_flash.h"
#include "user_rcc.h"

#include "tft_spi.h"
#include "GUI.h"
#include "process.h"



///////////////////////////////////////////
#define 	PORTB				GPIOB
#define 	LED_PORT			GPIOB
#define 	BUTTON_PORT			GPIOB

#define 	LED1				GPIO_Pin_5
#define 	LED2				GPIO_Pin_4

#define 	CAPTURE1			GPIO_Pin_9
#define 	CAPTURE2			GPIO_Pin_8

#define 	BUTTON1				GPIO_Pin_1
#define 	BUTTON2				GPIO_Pin_2
#define		BUTTON3				GPIO_Pin_10
#define 	BUTTON4				GPIO_Pin_11

#define 	SD_SS				GPIO_Pin_12
#define 	SD_SCK				GPIO_Pin_13
#define		SD_MISO				GPIO_Pin_14
#define		SD_MOSI				GPIO_Pin_15
////////////////////////////////////////////
#define 	PORTA				GPIOA
#define		ANALOG1				GPIO_Pin_0
#define 	ANALOG2				GPIO_Pin_1

#define 	TFT_RS				GPIO_Pin_2	
#define		TFT_RST				GPIO_Pin_3
#define 	TFT_LED				GPIO_Pin_6
#define		SPI1_CS				GPIO_Pin_4
#define		SPI1_SCK			GPIO_Pin_5
#define		SPI1_MOSI			GPIO_Pin_7

#define 	UART1_TX			GPIO_Pin_9
#define 	UART1_RX			GPIO_Pin_10
/////////////////////////////////////////////
#define 	PORTC				GPIOC
#define 	BUZZ_PORT			GPIOC
#define 	BUZZ				GPIO_Pin_13


#endif

/*************************************** (C) COPYRIGHT MCA *****END OF FILE****/





