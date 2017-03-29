#include "STM32Lib\\stm32f10x.h" 

//设置所有的中断允许
void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	/* 配置中断使用组合1*/
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	
	/* EXTI6、7、8*/
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);



}
