#ifndef _MOTOR_TIM4_H_
#define _MOTOR_TIM4_H_


#define Motor_L_IN1_Set GPIO_SetBits(GPIOB,GPIO_Pin_14);		//输入1为高电平
#define Motor_L_IN1_Reset GPIO_ResetBits(GPIOB,GPIO_Pin_14);	//输入1为低电平
#define Motor_L_IN2_Set GPIO_SetBits(GPIOB,GPIO_Pin_15);		//输入2为高电平
#define Motor_L_IN2_Reset GPIO_ResetBits(GPIOB,GPIO_Pin_15);	//输入2为低电平

#define Motor_R_IN1_Set GPIO_SetBits(GPIOB,GPIO_Pin_10);		//输入1为高电平
#define Motor_R_IN1_Reset GPIO_ResetBits(GPIOB,GPIO_Pin_10);	//输入1为低电平
#define Motor_R_IN2_Set GPIO_SetBits(GPIOB,GPIO_Pin_11);		//输入2为高电平
#define Motor_R_IN2_Reset GPIO_ResetBits(GPIOB,GPIO_Pin_11);	//输入2为低电平

extern void Motor_PWM_EN(void);
extern void Motor_Set(s16 LS,s16 RS);

#endif
