#ifndef _FOLLOW_H_
#define _FOLLOW_H_

//extern u8 Flag_L,Flag_R;

//#define SW_XJ()    GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)	//读取循迹开关状态
#define Follow_L() GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)	//读取左侧循迹传感器状态
#define Follow_M() GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7)	//读取中间循迹传感器状态
#define Follow_R() GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)	//读取右侧循迹传感器状态

extern void  Follow(void);
extern void  GPIO_Follow(void);

#endif

