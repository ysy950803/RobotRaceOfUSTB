#ifndef __IOINPUT_H__
#define __IOINPUT_H__

/*-----------------------------------------  I N C L U D E S  -----------------------------------------*/
#include "Global.h"

/*---------------------------------------  D E F I N I T I O N  ---------------------------------------*/
#define IN1_PIN             GPIO_Pin_9
#define IN9_PIN             GPIO_Pin_1
#define IN13_PIN            GPIO_Pin_8
#define IN14_PIN            GPIO_Pin_5
#define IN15_PIN            GPIO_Pin_14
#define IN16_PIN            GPIO_Pin_13
#define IN1_16_GPIO         GPIOB

#define IN2_PIN            	GPIO_Pin_13
#define IN3_PIN            	GPIO_Pin_14
#define IN4_PIN            	GPIO_Pin_15
#define IN5_PIN            	GPIO_Pin_3
#define IN6_PIN            	GPIO_Pin_2
#define IN7_PIN            	GPIO_Pin_1
#define IN8_PIN            	GPIO_Pin_0
#define IN10_PIN           	GPIO_Pin_5
#define IN11_PIN           	GPIO_Pin_12
#define IN2_11_GPIO        	GPIOC


#define IN12_PIN            GPIO_Pin_2
#define IN12_GPIO           GPIOD
/*-------------------------------------------  M A C R O S  -------------------------------------------*/
/*--------------------------------------  D E C L A R A T I O N  --------------------------------------*/
/* Internal Variable */

/* External Variable */

/* Internal Function */

/* External Function */
void InputIOInit(void);
UINT8 GetKeyState(UINT8 keynum);

#endif

//===========================================  End Of File  ===========================================//

