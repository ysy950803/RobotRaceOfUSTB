#ifndef __IOOUTPUT_H__
#define __IOOUTPUT_H__

/*-----------------------------------------  I N C L U D E S  -----------------------------------------*/
#include "Global.h"

/*---------------------------------------  D E F I N I T I O N  ---------------------------------------*/
#define OUT1_PIN          GPIO_Pin_9
#define OUT5_PIN          GPIO_Pin_8
#define OUT1_5_GPIO       GPIOC

//#define OUT2_PIN          GPIO_Pin_8
#define OUT3_PIN          GPIO_Pin_12
#define OUT4_PIN          GPIO_Pin_11
#define OUT2_4_GPIO       GPIOA


#define OUT6_PIN          GPIO_Pin_15
#define OUT7_PIN          GPIO_Pin_12
#define OUT8_PIN          GPIO_Pin_0
#define OUT6_8_GPIO       GPIOB

/*-------------------------------------------  M A C R O S  -------------------------------------------*/
/*--------------------------------------  D E C L A R A T I O N  --------------------------------------*/
/* Internal Variable */

/* External Variable */

/* Internal Function */

/* External Function */
void OutputIOInit(void);
void SetHigh(u8 key);
void SetLow(u8 key);

#endif

//===========================================  End Of File  ===========================================//

