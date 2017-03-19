/*-----------------------------------------  I N C L U D E S  -----------------------------------------*/
#include "Servo.h"

/********************************************************************************************************
Function Name: ServoIOInit
Description  :
Inputs       : None
Outputs      : None
Notes        :
Revision     :
********************************************************************************************************/
void ServoIOInit(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = SERVO1_PWM_PIN|SERVO2_PWM_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(SERVO_GPIO, &GPIO_InitStructure);
}

/********************************************************************************************************
Function Name: ServoTIMInit
Description  :
Inputs       : None
Outputs      : None
Notes        :
Revision     :
********************************************************************************************************/
void ServoTIMInit(void)
{
    TIM_TimeBaseInitTypeDef TIM4_TimeBaseStructure;
    TIM_OCInitTypeDef TIM4_OCInitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

    TIM4_TimeBaseStructure.TIM_Prescaler = 700;                               // ÏµÍ³  72MHz    TIMÊ±ÖÓ= 72MHz/5=14400000
    TIM4_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM4_TimeBaseStructure.TIM_Period = SERVO_Period;                        // Frequency = 14400000 / 2000=7200
    TIM4_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM4_TimeBaseStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(SERVO_TIM, &TIM4_TimeBaseStructure);

    TIM4_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
    TIM4_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM4_OCInitStructure.TIM_OutputNState=TIM_OutputState_Disable;
    TIM4_OCInitStructure.TIM_Pulse =140; //SERVO_Period >> 1;                       // TIM4 dutycycle = 50%
    TIM4_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM4_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
    TIM4_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;

    TIM_OC1Init(SERVO_TIM, &TIM4_OCInitStructure);
    TIM_OC1PreloadConfig(SERVO_TIM, TIM_OCPreload_Enable);

    TIM_OC2Init(SERVO_TIM, &TIM4_OCInitStructure);
    TIM_OC2PreloadConfig(SERVO_TIM, TIM_OCPreload_Enable);

    TIM_Cmd(SERVO_TIM, ENABLE);
    TIM_CtrlPWMOutputs(SERVO_TIM,ENABLE);
}

/********************************************************************************************************
Function Name: ServoInit
Description  :
Inputs       : None
Outputs      : None
Notes        :
Revision     :
********************************************************************************************************/
void ServoInit(void)
{
    ServoIOInit();
    ServoTIMInit();
}

/********************************************************************************************************
Function Name: SetServo1PWM
Description  :
Inputs       : xpwm
Outputs      : None
Notes        :
Revision     :
********************************************************************************************************/
void SetServo1PWM(u16 xpwm)
{
    TIM_SetCompare1(SERVO_TIM,xpwm);
}

/********************************************************************************************************
Function Name: ServoTIMInit
Description  :
Inputs       : SetServo2PWM
Outputs      : None
Notes        :
Revision     :
********************************************************************************************************/
void SetServo2PWM(u16 xpwm)
{
    TIM_SetCompare2(SERVO_TIM,xpwm);
}
/*---------------------------------------  D E F I N I T I O N  ---------------------------------------*/


/*----------------------------------------  F U N C T I O N S  ----------------------------------------*/


//===========================================  End Of File  ===========================================//
