/**
  ******************************************************************************
  * @file    user_timer.c
  * @author  MCA Team
  * @version V1.0
  * @date    15/9/2017
  * @brief   Timer Driver
  *         
  ******************************************************************************
**/

#include "user_timer.h"

/*
______________________________TIMER 1_______________________________
																	*/
void TIM1_InputCaptureConfig(void)
{
	TIM_TimeBaseInitTypeDef 	TIM_BaseStruct;
	TIM_ICInitTypeDef			TIM_ICInitStruct;
	NVIC_InitTypeDef			NVIC_InitStruct; 
	
	//TIM_DeInit(TIM1);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	
	TIM_BaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_BaseStruct.TIM_Prescaler = 0;
	TIM_BaseStruct.TIM_ClockDivision = 0;
	TIM_BaseStruct.TIM_Period = 0xFFFF;
	TIM_TimeBaseInit(TIM1, &TIM_BaseStruct);						// Configure Time Base
	
	TIM_ICInitStruct.TIM_Channel = TIM_Channel_1;		
	TIM_ICInitStruct.TIM_ICFilter = 0x0;
	TIM_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	TIM_ICInitStruct.TIM_ICPolarity = TIM_ICPolarity_Rising;
	TIM_ICInitStruct.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM_ICInit(TIM1, &TIM_ICInitStruct);							// Configure main input capture
	
//	TIM_ICInitStruct.TIM_Channel = TIM_Channel_2;
//	TIM_ICInitStruct.TIM_ICFilter = 0;
//	TIM_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;
//	TIM_ICInitStruct.TIM_ICPolarity = TIM_ICPolarity_Falling;
//	TIM_ICInitStruct.TIM_ICSelection = TIM_ICSelection_IndirectTI;
//	TIM_ICInit(TIM1, &TIM_ICInitStruct);							// Configure input trigger
	
	NVIC_InitStruct.NVIC_IRQChannel = TIM1_CC_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPriority = 0;
	NVIC_Init(&NVIC_InitStruct);									// Configure NVIC for interrupt
	
	TIM_ITConfig(TIM1, TIM_IT_CC1, ENABLE);
	
	TIM_Cmd(TIM1, ENABLE);
}

void TIM1_OutputCompareConfig(uint16_t Period)
{
	TIM_TimeBaseInitTypeDef 	TIM_BaseStruct;
	TIM_OCInitTypeDef			TIM_OCInitStruct;
	
	TIM_DeInit(TIM1);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	
	TIM_BaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_BaseStruct.TIM_Prescaler = 0;
	TIM_BaseStruct.TIM_ClockDivision = 0;
	TIM_BaseStruct.TIM_Period = Period;
	TIM_TimeBaseInit(TIM1, &TIM_BaseStruct);						// Configure Time Base
	
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM2;
	TIM_OCInitStruct.TIM_OCIdleState = TIM_OCIdleState_Set;
	TIM_OCInitStruct.TIM_OCNIdleState = TIM_OCNIdleState_Reset;
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OCInitStruct.TIM_OCNPolarity = TIM_OCNPolarity_High;
	TIM_OCInitStruct.TIM_OutputNState = TIM_OutputNState_Enable;
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_Pulse = Period/2;
	TIM_OC1Init(TIM1, &TIM_OCInitStruct);
	
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
	
	TIM_Cmd(TIM1, ENABLE);
	TIM_CtrlPWMOutputs(TIM1, ENABLE);
}
/*
______________________________TIMER 3_______________________________
																	*/
void TIM3_TimeBaseInit(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	NVIC_InitTypeDef 		NVIC_User;
	
	TIM_DeInit(TIM3);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	NVIC_User.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_User.NVIC_IRQChannelPriority = 0;
	NVIC_User.NVIC_IRQChannelCmd = ENABLE;	
	NVIC_Init(&NVIC_User);												// Enable NVIC
	
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Prescaler = 48;							// Base count = 1us
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_Period = 5000;							// after 10ms counter will be overflow
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStruct);					// Set up timer
										
	TIM_ITConfig(TIM3, TIM_IT_Update, DISABLE);							// Enable Interrupts TIM1
	
	TIM_Cmd(TIM3, DISABLE);
}


/*
______________________________TIMER 14_______________________________
																	*/
void TIM14_TimeBaseInit(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	NVIC_InitTypeDef 		NVIC_User;
	
	TIM_DeInit(TIM14);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14, ENABLE);
	
	NVIC_User.NVIC_IRQChannel = TIM14_IRQn;
	NVIC_User.NVIC_IRQChannelPriority = 0;
	NVIC_User.NVIC_IRQChannelCmd = ENABLE;	
	NVIC_Init(&NVIC_User);												// Enable NVIC
	
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Prescaler = 48;							// Base count = 1us
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_Period = 1;							// after 10ms counter will be overflow
	//TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;					// Time 1s
	TIM_TimeBaseInit(TIM14, &TIM_TimeBaseInitStruct);					// Set up timer
										
	TIM_ITConfig(TIM14, TIM_IT_Update, ENABLE);							// Enable Interrupts TIM14
	
	TIM_Cmd(TIM14, ENABLE);
}


////////////////////////////////////////////////////////////////////////
void TIM17_InputCaptureConfig(void)
{
	TIM_TimeBaseInitTypeDef 	TIM_BaseStruct;
	TIM_ICInitTypeDef			TIM_ICInitStruct;
	NVIC_InitTypeDef			NVIC_InitStruct; 
	
	//TIM_DeInit(TIM1);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM17, ENABLE);
	
	TIM_BaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_BaseStruct.TIM_Prescaler = 0;
	TIM_BaseStruct.TIM_ClockDivision = 0;
	TIM_BaseStruct.TIM_Period = 0xFFFF;
	TIM_TimeBaseInit(TIM17, &TIM_BaseStruct);						// Configure Time Base
	
	TIM_ICInitStruct.TIM_Channel = TIM_Channel_1;		
	TIM_ICInitStruct.TIM_ICFilter = 0x0;
	TIM_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	TIM_ICInitStruct.TIM_ICPolarity = TIM_ICPolarity_Rising;
	TIM_ICInitStruct.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM_ICInit(TIM17, &TIM_ICInitStruct);							// Configure main input capture
	
	NVIC_InitStruct.NVIC_IRQChannel = TIM17_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPriority = 2;
	NVIC_Init(&NVIC_InitStruct);									// Configure NVIC for interrupt
	
	TIM_ITConfig(TIM17, TIM_IT_CC1, ENABLE);
	
	TIM_Cmd(TIM17, ENABLE);
}
