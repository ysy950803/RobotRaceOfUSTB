#include "STM32Lib\\stm32f10x.h"
#include "Motor_TIM4.h"
/*******************************************************************************
* Function Name  : GPIO_Configuration
* 设置PA2~PA7,PB0~PB1为输出LED灯
*******************************************************************************/
void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/*允许总线CLOCK,在使用GPIO之前必须允许相应端的时钟.
	从STM32的设计角度上说,没被允许的端将不接入时钟,也就不会耗能,
	这是STM32节能的一种技巧,*/
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
/**********************************************************************************
**************************喇叭部分  PA9************************************************
***********************************************************************************/
	/*喇叭Beep->PA9 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_ResetBits(GPIOA,GPIO_Pin_9);

/**********************************************************************************
**************************循迹避障部分*************************************************
***********************************************************************************/	
	/*循迹检测开关  SW_XJ()->PB1  */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	/*避障检测开关  SW_	BZ()->PB1  */
/*	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;	
	GPIO_Init(GPIOB, &GPIO_InitStructure);		*/

/**********************************************************************************
**************************电机部分*************************************************
***********************************************************************************/
	/* GPIOB Configuration:TIM4 Channel1, 2in Output */
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  	GPIO_Init(GPIOB, &GPIO_InitStructure);

	/*Motor_Enable:
		Motor_L_IN1	->	(PB14,27)
		Motor_L_IN2 ->	(PB15,28)	 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 	//GPIO最高输出速度
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	//初始的时候，关闭电机开关,即IN1=0;IN2=0;
	Motor_L_IN1_Reset;				//输入1为低电平
	Motor_L_IN2_Reset;				//输入2为低电平

	/*Motor_Enable:
		Motor_R_IN1	->	(PB10,21)
		Motor_R_IN2 ->	(PB11,22)	 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 	//GPIO最高输出速度
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	//初始的时候，关闭电机开关,即IN1=0;IN2=0;
	Motor_R_IN1_Reset;				//输入1为低电平
	Motor_R_IN2_Reset;				//输入2为低电平

}


