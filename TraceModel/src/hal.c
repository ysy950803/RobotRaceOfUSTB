/***************************************************
**HAL.c
**主要用于芯片硬件的内部外围和外部外围的初始化，两大INIT函数
**在MAIN中调用，使MAIN函数中尽量与硬件库无关
***************************************************/

#include "STM32Lib\\stm32f10x.h"
#include "hal.h"
#include "follow.h"

//各个内部硬件模块的配置函数
extern void RCC_Configuration(void);			//RCC
extern void GPIO_Configuration(void);			//GPIO

extern void TIM4_Configuration(void);            //TIM
extern void NVIC_Configuration(void);            //NVIC
/*******************************
**函数名:ChipHalInit()
**功能:片内硬件初始化
*******************************/
void  ChipHalInit(void)
{
	//初始化时钟源
	RCC_Configuration();
	
	//初始化GPIO
	GPIO_Configuration();
	
	//初始化TIM
	TIM4_Configuration();

	NVIC_Configuration();
	
}


/*********************************
**函数名:ChipOutHalInit()
**功能:片外硬件初始化
*********************************/
void  ChipOutHalInit(void)
{
	GPIO_Follow();
}
