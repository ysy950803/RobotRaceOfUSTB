#ifndef _ZLG7290_H_
#define _ZLG7290_H_

/*---------------------------   H E A D E R S  ----------------------------*/
#include "Global.h"


#define SDA_HIGH   GPIO_SetBits(GPIOB,GPIO_Pin_11)
#define SDA_LOW    GPIO_ResetBits(GPIOB,GPIO_Pin_11)
#define READ_SDA   GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11)

#define SCL_HIGH   GPIO_SetBits(GPIOB,GPIO_Pin_10)
#define SCL_LOW    GPIO_ResetBits(GPIOB,GPIO_Pin_10)

/*---------------------------  F U N C T I O N S  ----------------------------*/
static void Start(void) ;
static void Stop(void) ;
static void WriteByte(uint8 out_byte) ;
static uint8 ReadByte(void) ;
uint8 GetAck(void) ;
static void PutAck(uint8 ack) ;
void IICSendByte(uint8 dev_add,uint8 reg_add,uint8 out_byte) ;
void SendSingleCommandToZLG7290(uint8 command) ;
void SendCompuondCommandToZLG7290(uint8 command1, uint8 command2) ;
uint8 SwitchNumber(uint8 key_code) ;


extern void ZLG7290Init(void) ;
extern void ZLG7290ClearAll(void) ;
extern void UpdataZLG7290(uint8 which, uint8 display, uint8 point) ;
extern uint8 ReadKeys(void) ;
extern void KeyBoardShowLong(uint16 show);
extern int ReadKeyAndDisplay(void);

extern void Test(void);

#endif

