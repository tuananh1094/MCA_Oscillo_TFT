/**
  ******************************************************************************
  * @file    user_timer.h
  * @author  MCA Team
  * @version V1.0
  * @date    15/9/2017
  * @brief   Timer Driver
  *         
  ******************************************************************************
**/

#ifndef _USER_TIMER_H_
#define _USER_TIMER_H_

#include "main.h"

void TIM3_TimeBaseInit(void);
void TIM14_TimeBaseInit(void);
void TIM1_InputCaptureConfig(void);
void TIM1_OutputCompareConfig(uint16_t Period);

#endif
