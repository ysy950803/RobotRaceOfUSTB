#ifndef HAL_H
#define HAL_H

//Ó²¼þ³õÊ¼»¯
extern void  ChipHalInit(void);
extern void  ChipOutHalInit(void);

#define Beep() GPIO_SetBits(GPIOA,GPIO_Pin_9);	//À®°ÈÏì

#endif

