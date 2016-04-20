#ifndef __SERVO_H__
#define __SERVO_H__

/*-----------------------------------------  I N C L U D E S  -----------------------------------------*/
#include "Global.h"

/*---------------------------------------  D E F I N I T I O N  ---------------------------------------*/
#define SERVO1_PWM_PIN       GPIO_Pin_6
#define SERVO2_PWM_PIN       GPIO_Pin_7
#define SERVO_GPIO           GPIOB

#define SERVO_TIM            TIM4
#define SERVO_Period         2000
/*-------------------------------------------  M A C R O S  -------------------------------------------*/


/*--------------------------------------  D E C L A R A T I O N  --------------------------------------*/
/* Internal Variable */

/* External Variable */


/* Internal Function */

/* External Function */
void ServoIOInit(void);
void ServoTIMInit(void);
void ServoInit(void);
void SetServo1PWM(u16 xpwm);
void SetServo2PWM(u16 xpwm);
#endif

//===========================================  End Of File  ===========================================//

