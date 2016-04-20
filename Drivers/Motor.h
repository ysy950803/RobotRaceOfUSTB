#ifndef __MOTOR_H__
#define __MOTOR_H__

/*-----------------------------------------  I N C L U D E S  -----------------------------------------*/
#include "Global.h"

/*---------------------------------------  D E F I N I T I O N  ---------------------------------------*/
#define MOTOR1_DIR_PIN       GPIO_Pin_1
#define MOTOR2_DIR_PIN       GPIO_Pin_3

#define MOTOR1_PWM_PIN       GPIO_Pin_0
#define MOTOR2_PWM_PIN       GPIO_Pin_2
#define MOTOR_GPIO           GPIOA

#define MOTOR1_DIR_H         GPIO_SetBits(MOTOR_GPIO,MOTOR1_DIR_PIN)
#define MOTOR1_DIR_L		     GPIO_ResetBits(MOTOR_GPIO,MOTOR1_DIR_PIN)

#define MOTOR2_DIR_H         GPIO_SetBits(MOTOR_GPIO,MOTOR2_DIR_PIN)
#define MOTOR2_DIR_L		     GPIO_ResetBits(MOTOR_GPIO,MOTOR2_DIR_PIN)

#define MOTOR_TIM            TIM2
#define MOTOR_Period         2000

/*-------------------------------------------  M A C R O S  -------------------------------------------*/


/*--------------------------------------  D E C L A R A T I O N  --------------------------------------*/
/* Internal Variable */

/* External Variable */


/* Internal Function */


/* External Function */
void MotorIOInit(void);
void MotorTIMInit(void);
void MotorInit(void);
void SetMotor1PWM(s16 xpwm);
void SetMotor2PWM(s16 xpwm);
#endif

//===========================================  End Of File  ===========================================//

