#include "main.h"

/*---------------------------------------  D E F I N I T I O N  ---------------------------------------*/

int Test_count = 0;
u8  Test_InputIO_Data[16]={0};
u16 Test_Sensor_Data[5]  ={0};
int Test_ZLG7290_Data = 0;
int Test_Motor_PWM=1000;
int Test_Motor_PWM_L=1000;
int Test_Motor_PWM_R=1000;
int Test_Sover_PWM = 140;
int Test_Sover_PWM_L = 140;
int Test_Sover_PWM_R = 140;

/*----------------------------------------  F U N C T I O N S  ----------------------------------------*/
/********************************************************************************************************
Function Name: main
Description  : 
Inputs       : None
Outputs      : None
Notes        : 
Revision     : 
********************************************************************************************************/
int main(void)
{
    SystemInit();  //系统时钟初始化 
    InputIOInit(); //数字输入初始化
 		OutputIOInit();//数字输出初始化
	 	SensorInit();  //模拟输入初始化
	
 		ZLG7290Init(); //键盘初始化
	
 		MotorInit();	 //电机初始化
 		ServoInit();   //舵机初始化
	
		EncoderInit(); //编码器初始化
 		/*
 		V_PIDInit();   //电机闭环输出
	  */
	  Delay_ms(1000);
    SystemStart();
	
		//UsartInit();	 //串口初始化
}

/********************************************************************************************************
Function Name: SystemStart
Description  : 
Inputs       : None
Outputs      : None
Notes        : 
Revision     : 
********************************************************************************************************/
void SystemStart(void)
{
	int temple_read=0;
	//Test_InputIO(); //数字输入测试
	//Test_OutputIO();//数字输出测试
	//Test_Sensor();  //模拟输入测试
	//Test_ZLG7290(); //键盘测试
	//Test_Motor();   //电机测试
	//Test_Servo();   //舵机测试
	//Test_Encoder(); //编码器测试
	//Test_V_PID(void);   //电机闭环测试
	UpdataZLG7290(0, 0, 0) ;Delay_ms(200);
	UpdataZLG7290(1, 0, 0) ;Delay_ms(200);
	UpdataZLG7290(2, 0, 0) ;Delay_ms(200);
	UpdataZLG7290(3, 0, 0) ;Delay_ms(200);
	
	Delay_ms(1000);
	//清除数据
	ZLG7290ClearAll() ;
  
	
	
  while(1)
  {
		Test_count++;if(Test_count>=4000)Test_count=0;
		temple_read=ReadKeys() ;
		switch(temple_read)
		{
			case 1:
			{
				UpdataZLG7290(0, 0, 0) ;Delay_ms(200);
				UpdataZLG7290(1, 0, 0) ;Delay_ms(200);
				UpdataZLG7290(2, 0, 0) ;Delay_ms(200);
				UpdataZLG7290(3, 1, 0) ;Delay_ms(200);
				Test_Sover_PWM_L=ReadKeyAndDisplay();
				break;
			}
			case 2:
			{
				UpdataZLG7290(0, 0, 0) ;Delay_ms(200);
				UpdataZLG7290(1, 0, 0) ;Delay_ms(200);
				UpdataZLG7290(2, 0, 0) ;Delay_ms(200);
				UpdataZLG7290(3, 2, 0) ;Delay_ms(200);
				Test_Sover_PWM_R=ReadKeyAndDisplay();
				break;
			}
			case 3:
			{
				UpdataZLG7290(0, 0, 0) ;Delay_ms(200);
				UpdataZLG7290(1, 0, 0) ;Delay_ms(200);
				UpdataZLG7290(2, 0, 0) ;Delay_ms(200);
				UpdataZLG7290(3, 3, 0) ;Delay_ms(200);
				Test_Motor_PWM_L=2000-ReadKeyAndDisplay();
				break;
			}
			case 4:
			{
				UpdataZLG7290(0, 0, 0) ;Delay_ms(200);
				UpdataZLG7290(1, 0, 0) ;Delay_ms(200);
				UpdataZLG7290(2, 0, 0) ;Delay_ms(200);
				UpdataZLG7290(3, 4, 0) ;Delay_ms(200);
				Test_Motor_PWM_R=2000-ReadKeyAndDisplay();
				break;
			}
			
		}
		SetMotor1PWM(Test_Motor_PWM_L);
		SetMotor2PWM(Test_Motor_PWM_R);
		SetServo1PWM(Test_Sover_PWM_L);
		SetServo2PWM(Test_Sover_PWM_R);
  }
	
}
/********************************************************************************************************
Function Name: Test_InputIO
Description  : 数字输入测试
Inputs       : None
Outputs      : None
Notes        : 
Revision     : 
********************************************************************************************************/
void Test_InputIO(void)
{
	int i = 0;
	while(1)
	{
		for( i=0 ; i<16 ; i++ )
		{
			Test_InputIO_Data[i] = GetKeyState(i+1);
		}
	}
}
/********************************************************************************************************
Function Name: Test_OutputIO
Description  : 数字输出测试
Inputs       : None
Outputs      : None
Notes        : 
Revision     : 
********************************************************************************************************/
void Test_OutputIO(void)
{
	
	while(1)
	{
		
		SetHigh(1);SetHigh(2);SetHigh(3);SetHigh(4);SetLow(5);SetLow(6);SetLow(7);SetLow(8);
		
		Delay_ms(1000);

		SetLow(1);SetLow(2);SetLow(3);SetLow(4);SetHigh(5);SetHigh(6);SetHigh(7);SetHigh(8);
		
		Delay_ms(1000);	
	}
}
/********************************************************************************************************
Function Name: Test_Sensor
Description  : 模拟输入测试
Inputs       : None
Outputs      : None
Notes        : 
Revision     : 
********************************************************************************************************/
void Test_Sensor(void)
{
	int i = 0;
	while(1)
	{
		for( i=1 ; i<6 ; i++ )
		{
			Test_Sensor_Data[i] = GetADCValue(i);
			
			Delay_ms(3);
		}
	}
}
/********************************************************************************************************
Function Name: Test_Usart
Description  : 串口测试
Inputs       : None
Outputs      : None
Notes        : 
Revision     : 
********************************************************************************************************/
void Test_Usart(void)
{
	while(1)
	{
		SendData(0xf0);//串口0
		Send1Data(0xf1);//串口1
		
		Delay_ms(500);
	}
}
/********************************************************************************************************
Function Name: Test_ZLG7290
Description  : 键盘测试
Inputs       : None
Outputs      : None
Notes        : 
Revision     : 
********************************************************************************************************/
void Test_ZLG7290(void)
{
	//显示数据
	UpdataZLG7290(0, 0, 0) ;Delay_ms(2000);
	UpdataZLG7290(1, 1, 0) ;Delay_ms(2000);
	UpdataZLG7290(2, 2, 0) ;Delay_ms(2000);
	UpdataZLG7290(3, 3, 0) ;Delay_ms(2000);
	UpdataZLG7290(4, 4, 0) ;Delay_ms(2000);
	UpdataZLG7290(5, 5, 0) ;Delay_ms(2000);
	UpdataZLG7290(6, 6, 0) ;Delay_ms(2000);
	UpdataZLG7290(7, 7, 0) ;Delay_ms(2000);
	
	Delay_ms(3000);
	
	//清除数据
	ZLG7290ClearAll() ;
	
	//输入数据
	Test_ZLG7290_Data = ReadKeyAndDisplay();
	while(1)
	{
	}
}		
/********************************************************************************************************
Function Name: Test_Motor
Description  : 电机测试
Inputs       : None
Outputs      : None
Notes        : 
Revision     : 
********************************************************************************************************/
void Test_Motor(void)
{
	while(1)
	{
		SetMotor1PWM(Test_Motor_PWM);
		SetMotor2PWM(Test_Motor_PWM);
	}
}	
/********************************************************************************************************
Function Name: Test_Servo
Description  : 舵机测试
Inputs       : None
Outputs      : None
Notes        : 
Revision     : 
********************************************************************************************************/
void Test_Servo(void)
{
	while(1)
	{
		SetServo1PWM(Test_Sover_PWM);
		SetServo2PWM(Test_Sover_PWM);
		
		
	}
}	
/********************************************************************************************************
Function Name: Test_Encoder
Description  : 编码器测试
Inputs       : None
Outputs      : None
Notes        : 
Revision     : 
********************************************************************************************************/
void Test_Encoder(void)
{
	while(1)
	{
		GetSpeed();
	}
}	
/********************************************************************************************************
Function Name: Test_V_PID
Description  : 电机闭环测试
Inputs       : None
Outputs      : None
Notes        : 
Revision     : 
********************************************************************************************************/
void Test_V_PID(void)
{
	
}	
//===========================================  End Of File  ===========================================//

