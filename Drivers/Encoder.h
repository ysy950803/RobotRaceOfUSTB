#ifndef __ENCODER_H__
#define __ENCODER_H__

/*-----------------------------------------  I N C L U D E S  -----------------------------------------*/
#include "Global.h"

/*---------------------------------------  D E F I N I T I O N  ---------------------------------------*/


#define ENCODER1_A_PIN      GPIO_Pin_8
#define ENCODER1_B_PIN      GPIO_Pin_9
#define ENCODER1_GPIO       GPIOA

#define ENCODER_L_TIMER   	TIM1


#define ENCODER2_A_PIN      GPIO_Pin_6
#define ENCODER2_B_PIN      GPIO_Pin_7
#define ENCODER2_GPIO       GPIOC

#define ENCODER_R_TIMER    	TIM8

#define ENCODER_APP     	65535
#define COUNTER_RESET   	(0)
#define ICx_FILTER      	(6)

/* External Function */
void EncoderIOInit(void);
void EncoderTIMInit(void);
void EncoderInit(void);
void GetSpeed(void);
#endif

//===========================================  End Of File  ===========================================//

