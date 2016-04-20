#ifndef __SENSOR_H__
#define __SENSOR_H__

/*-----------------------------------------  I N C L U D E S  -----------------------------------------*/
#include "Global.h"

/*---------------------------------------  D E F I N I T I O N  ---------------------------------------*/

#define  SENSOR1_PIN          GPIO_Pin_4
#define  SENSOR2_PIN          GPIO_Pin_5
#define  SENSOR3_PIN          GPIO_Pin_6
#define  SENSOR4_PIN          GPIO_Pin_7
#define  SENSOR1_4_GPIO       GPIOA

#define  SENSOR5_PIN          GPIO_Pin_4
#define  SENSOR5_GPIO         GPIOC

#define  SENSOR_ADC           ADC2
/*-------------------------------------------  M A C R O S  -------------------------------------------*/


/*--------------------------------------  D E C L A R A T I O N  --------------------------------------*/
/* Internal Variable */

/* External Variable */


/* Internal Function */


/* External Function */
void SensorIOInit(void);
void SensorADCInit(void);
void SensorInit(void);
u16 GetADCValue(u8 ch);
#endif

//===========================================  End Of File  ===========================================//

