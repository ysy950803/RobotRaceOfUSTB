#include "main.h"

/*---------------------------------------  D E F I N I T I O N  ---------------------------------------*/

int Test_count = 0;
u8  Test_InputIO_Data[16]={0};
u16 Test_Sensor_Data[5]  ={0};
int Test_ZLG7290_Data = 0;
int Test_Motor_PWM=0;
int Test_Motor_PWM_L=0;
int Test_Motor_PWM_R=0;
int Test_Sover_PWM = 100;
int Test_Sover_PWM_L = 100;
int Test_Sover_PWM_R = 100;

int v0 = 0;
int v1 = 512;
int v2 = 1024;
int v3 = 1536;

// four sensors
UINT8 HeadLeft_Sensor = 1; // sensor active low and inter / no use high and out 
UINT8 HeadRight_Sensor = 1;
UINT8 BackLeft_Sensor = 1;
UINT8 BackRight_Sensor = 1;

int isDelayed = 0; // 0false 1true
int isFirstRun = 1; // after beginning with 1 and be always 0
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
	//Test_InputIO(); //数字输入测试
	//Test_OutputIO();//数字输出测试
	//Test_Sensor();  //模拟输入测试
	//Test_ZLG7290(); //键盘测试
	//Test_Motor();   //电机测试
	//Test_Servo();   //舵机测试
	//Test_Encoder(); //编码器测试
	//Test_V_PID(void);   //电机闭环测试
	Test_Main();

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
	
	Delay_ms(5000);
	
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
		//Test_count++;if(Test_count>=4000)Test_count=0;
		GetSpeed();
		Delay_ms(1000);
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

void Test_Main(void)
{
	/*
	int read_tempe=0;

	//显示数据
	UpdataZLG7290(4, 0, 0) ;Delay_ms(3000);
	UpdataZLG7290(5, 0, 0) ;Delay_ms(3000);
	UpdataZLG7290(6, 0, 0) ;Delay_ms(3000);
	UpdataZLG7290(7, 0, 0) ;Delay_ms(3000);
	Delay_ms(5000);	
	//清除数据
	ZLG7290ClearAll() ;
	Delay_ms(5000);
	
  while(1)
  {
 		while(1)
 		{
			while(ReadKeys() == 16){} //按键没有按下时 一直循环扫描 直到 ReadKeys() ！= 16
				read_tempe=ReadKeys();
			while(ReadKeys() != 16);//按键没松开时，等待。。。。

			switch(read_tempe)
			{
				case 1:
				{
					UpdataZLG7290(4, 0, 0) ;Delay_ms(2000);
					UpdataZLG7290(5, 0, 0) ;Delay_ms(2000);
					UpdataZLG7290(6, 0, 0) ;Delay_ms(2000);
					UpdataZLG7290(7, 1, 0) ;Delay_ms(2000);
					
					Test_Sover_PWM_L=ReadKeyAndDisplay();
					Delay_ms(2000);
					break;
				}
				case 2:
				{
					UpdataZLG7290(4, 0, 0) ;Delay_ms(2000);
					UpdataZLG7290(5, 0, 0) ;Delay_ms(2000);
					UpdataZLG7290(6, 0, 0) ;Delay_ms(2000);
					UpdataZLG7290(7, 2, 0) ;Delay_ms(2000);
					Test_Sover_PWM_R=ReadKeyAndDisplay();
					Delay_ms(2000);
					break;
				}
				case 3:
				{
					UpdataZLG7290(4, 0, 0) ;Delay_ms(2000);
					UpdataZLG7290(5, 0, 0) ;Delay_ms(2000);
					UpdataZLG7290(6, 0, 0) ;Delay_ms(2000);
					UpdataZLG7290(7, 3, 0) ;Delay_ms(2000);
					Test_Motor_PWM_L=ReadKeyAndDisplay()-2000;
					Delay_ms(2000);
					break;
				}
				case 4:
				{
					UpdataZLG7290(4, 0, 0) ;Delay_ms(2000);
					UpdataZLG7290(5, 0, 0) ;Delay_ms(2000);
					UpdataZLG7290(6, 0, 0) ;Delay_ms(2000);
					UpdataZLG7290(7, 4, 0) ;Delay_ms(2000);
					Test_Motor_PWM_R=ReadKeyAndDisplay()-2000;
					Delay_ms(2000);
					break;
				}
			}
			
			SetServo1PWM(Test_Sover_PWM_L);
 			SetServo2PWM(Test_Sover_PWM_R);
 			SetMotor1PWM(Test_Motor_PWM_L);
 			SetMotor2PWM(Test_Motor_PWM_R);
			
			Test_count++;if(Test_count>=4000)Test_count=0;
		}
  }
	*/
	
	HeadLeft_Sensor = 0;
	HeadRight_Sensor = 0;
	BackLeft_Sensor = 0;
	BackRight_Sensor = 0;
	
	v0 = 0;
	v1 = 384;
	v2 = 768;
	v3 = 1024;
	
	isDelayed = 0;
	isFirstRun = 1;
	
	while(1)
	{
		HeadLeft_Sensor = GetKeyState(5); // 1BL 15BR 3HR 5HL
		HeadRight_Sensor = GetKeyState(3);
		BackLeft_Sensor = GetKeyState(1);
		BackRight_Sensor = GetKeyState(15);
		// double sensors
		if(HeadLeft_Sensor == 1 && HeadRight_Sensor == 1 && BackLeft_Sensor == 0 && BackRight_Sensor == 0) {
				int i = 0;
				int j = 0;
				isDelayed = 0;
				Test_Motor_PWM = -v1;
				for(i = 0; i < 2000; i++) // delay
				{
						for(j = 0; j < 1040; j++)
						{
								// waiting for down
								SetMotor1PWM(Test_Motor_PWM + 128);
								SetMotor2PWM(Test_Motor_PWM);
						}
				}
				//SetMotor1PWM(Test_Motor_PWM);
				//SetMotor2PWM(Test_Motor_PWM);
		}
		else if(BackLeft_Sensor == 1 && BackRight_Sensor == 1 && HeadLeft_Sensor == 0 && HeadRight_Sensor == 0) {
				int i = 0;
				int j = 0;	
				isDelayed = 0;
				Test_Motor_PWM = v1;
				for(i = 0; i < 2000; i++) // delay
				{
						for(j = 0; j < 1040; j++)
						{
								// waiting for down
								SetMotor1PWM(Test_Motor_PWM + 128);
								SetMotor2PWM(Test_Motor_PWM);
						}
				}
				//SetMotor1PWM(Test_Motor_PWM);
				//SetMotor2PWM(Test_Motor_PWM);
		}
		else if(HeadLeft_Sensor == 1 && BackLeft_Sensor == 1 && HeadRight_Sensor == 0 && BackRight_Sensor == 0) {
				isDelayed = 0;
				Test_Motor_PWM_L = v1;
				Test_Motor_PWM_R = v0;
				SetMotor1PWM(Test_Motor_PWM_L);
				SetMotor2PWM(Test_Motor_PWM_R);
		}
		else if(HeadRight_Sensor == 1 && BackRight_Sensor == 1 && HeadLeft_Sensor == 0 && BackLeft_Sensor == 0) {
				isDelayed = 0;
				Test_Motor_PWM_L = v0;
				Test_Motor_PWM_R = v1;
				SetMotor1PWM(Test_Motor_PWM_L);
				SetMotor2PWM(Test_Motor_PWM_R);
		}
		// single sensor
		else if(BackLeft_Sensor == 1 && HeadLeft_Sensor == 0 && BackRight_Sensor == 0 && HeadRight_Sensor == 0)	{
				isDelayed = 0;
				Test_Motor_PWM_L = v1;
				Test_Motor_PWM_R = v0;
				SetMotor1PWM(Test_Motor_PWM_L);
				SetMotor2PWM(Test_Motor_PWM_R);
		}
		else if(BackRight_Sensor == 1 && HeadRight_Sensor == 0 && BackLeft_Sensor == 0 && HeadLeft_Sensor == 0)	{
				isDelayed = 0;
				Test_Motor_PWM_L = v0;
				Test_Motor_PWM_R = v1;
				SetMotor1PWM(Test_Motor_PWM_L);
				SetMotor2PWM(Test_Motor_PWM_R);
		}
		else if(HeadRight_Sensor == 1 && HeadLeft_Sensor == 0 && BackRight_Sensor == 0 && BackLeft_Sensor == 0)	{
				isDelayed = 0;
				Test_Motor_PWM_L = -v1;
				Test_Motor_PWM_R = v1;
				SetMotor1PWM(Test_Motor_PWM_L);
				SetMotor2PWM(Test_Motor_PWM_R);
		}
		else if(HeadLeft_Sensor == 1 && HeadRight_Sensor == 0 && BackLeft_Sensor == 0 && BackRight_Sensor == 0)	{
				isDelayed = 0;
				Test_Motor_PWM_L = v1;
				Test_Motor_PWM_R = -v1;
				SetMotor1PWM(Test_Motor_PWM_L);
				SetMotor2PWM(Test_Motor_PWM_R);
		}
		else if(HeadLeft_Sensor == 0 && HeadRight_Sensor == 0 && BackLeft_Sensor == 0 && BackRight_Sensor == 0) {
				if(isDelayed == 0) { // not yet delayed
						UINT16 i = 0;
						UINT16 j = 0;	
						Test_Motor_PWM = v1;
						for(i = 0; i < 500; i++) // delay to rejust
						{
								for(j = 0; j < 1040; j++)
								{
										// waiting for down
									SetMotor1PWM(Test_Motor_PWM);
									SetMotor2PWM(Test_Motor_PWM);
								}
						}
						isDelayed = 1;
				}
				else if(isDelayed == 1) { // run from static
						if(isFirstRun == 0) {
								Test_Motor_PWM = v2;
								SetMotor1PWM(Test_Motor_PWM);
								SetMotor2PWM(Test_Motor_PWM);
						}
						else if(isFirstRun == 1) {
								UINT16 i = 0;
								UINT16 j = 0;
								Test_Motor_PWM = v3;
								for(i = 0; i < 2000; i++) // delay 3s
								{
										for(j = 0; j < 1040; j++)
										{
												SetMotor1PWM(Test_Motor_PWM);
												SetMotor2PWM(Test_Motor_PWM);
										}
								}
								isFirstRun = 0;
						}
				}
		}
		else { // impossible by nature
				isDelayed = 0;
				Test_Motor_PWM = v0;
				SetMotor1PWM(Test_Motor_PWM);
				SetMotor2PWM(Test_Motor_PWM);
		}
		
	}

}
//===========================================  End Of File  ===========================================//

