#ifndef __MAIN_H__
#define __MAIN_H__

/*-----------------------------------------  I N C L U D E S  -----------------------------------------*/
#include "Global.h"
#include "Config.h"
/*---------------------------------------  D E F I N I T I O N  ---------------------------------------*/

/*-------------------------------------------  M A C R O S  -------------------------------------------*/

/*--------------------------------------  D E C L A R A T I O N  --------------------------------------*/
/* Internal Variable */

/* External Variable */

/* Internal Function */
void SystemStart(void);

void Test_InputIO(void); //数字输入测试
void Test_OutputIO(void);//数字输出测试
void Test_Sensor(void);  //模拟输入测试
void Test_Usart(void);   //串口测试
void Test_ZLG7290(void); //键盘测试
void Test_Motor(void);   //电机测试
void Test_Servo(void);   //舵机测试
void Test_Encoder(void); //编码器测试
void Test_V_PID(void);   //电机闭环测试
void Escape(UINT8 mode, UINT16 time, UINT16 v_left, UINT16 v_right);
int Current_State(UINT8 HL, UINT8 HR, UINT8 BL, UINT8 BR);
void Test_Main(void);


/* External Function */

#endif

//===========================================  End Of File  ===========================================//

