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

int v_Rejust = 128;
int v0 = 0;
int v1 = 512;
int v2 = 1024;
int v3 = 1536;
int v_Max = 1896;

// four sensors
UINT8 HeadLeft_Sensor = 1; // sensor active low and inter / no use high and out 
UINT8 HeadRight_Sensor = 1;
UINT8 BackLeft_Sensor = 1;
UINT8 BackRight_Sensor = 1;

// find enemy
UINT8 Head_Sensor = 1;
UINT8 Back_Sensor = 1;
UINT8 Right_Sensor = 1;
UINT8 Left_Sensor = 1;

UINT8 isDelayed = 1; // 0false 1true
UINT8 isFirstRun = 1; // after beginning with 1 and be always 0
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
		Test_Motor_PWM = v1;
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

void Escape(UINT8 mode, UINT16 time, UINT16 v_left, UINT16 v_right)
{
		UINT16 I = 0;
		UINT16 J = 0;
		if(mode == 0) {
			for(I = 0; I < time; I++) {
					for(J = 0; J < 1040; J++) {
							SetMotor1PWM(v_left);
							SetMotor2PWM(v_right);
					}
			}
		}
		else if(mode == 1) {
			for(I = 0; I < time; I++) {
					for(J = 0; J < 1040; J++) {
							SetMotor1PWM(v_left);
							SetMotor2PWM(v_right);
					}
					if(GetKeyState(3) == 1 || GetKeyState(4) == 1)
							break;
			}
		}
		else if(mode == 2) {
			for(I = 0; I < time; I++) {
					for(J = 0; J < 1040; J++) {
							SetMotor1PWM(v_left);
							SetMotor2PWM(v_right);
					}
					if(GetKeyState(1) == 1 || GetKeyState(2) == 1)
							break;
			}
		}
		// single process
		else if(mode == 3) { // headleft
			for(I = 0; I < time; I++) {
					for(J = 0; J < 1040; J++) {
							SetMotor1PWM(v_left);
							SetMotor2PWM(v_right);
					}
					if(GetKeyState(2) == 1 || GetKeyState(3) == 1 || GetKeyState(4) == 1)
							break;
			}
		}
		else if(mode == 4) {
			for(I = 0; I < time; I++) { // headright
					for(J = 0; J < 1040; J++) {
							SetMotor1PWM(v_left);
							SetMotor2PWM(v_right);
					}
					if(GetKeyState(1) == 1 || GetKeyState(3) == 1 || GetKeyState(4) == 1)
							break;
			}
		}
		else if(mode == 5) { // backleft
			for(I = 0; I < time; I++) {
					for(J = 0; J < 1040; J++) {
							SetMotor1PWM(v_left);
							SetMotor2PWM(v_right);
					}
					if(GetKeyState(1) == 1 || GetKeyState(2) == 1 || GetKeyState(4) == 1)
							break;
			}
		}
		else if(mode == 6) { // backright
			for(I = 0; I < time; I++) {
					for(J = 0; J < 1040; J++) {
							SetMotor1PWM(v_left);
							SetMotor2PWM(v_right);
					}
					if(GetKeyState(1) == 1 || GetKeyState(2) == 1 || GetKeyState(3) == 1)
							break;
			}
		}
}

int Current_State(UINT8 HL, UINT8 HR, UINT8 BL, UINT8 BR)
{
		int STATE_VALUE = 0;
		// get current state and ready to break circle
		Head_Sensor = GetKeyState(5);
		Back_Sensor = GetKeyState(6);
		Left_Sensor = GetKeyState(7);
		Right_Sensor = GetKeyState(8);
		// double sensors active
		if(HL == 1 && HR == 1 && BL == 0 && BR == 0) { //  HeadLeft and HeadRight
				if(Back_Sensor == 0 && Left_Sensor == 1 && Right_Sensor == 1)
						STATE_VALUE = 11;
				else if(Back_Sensor == 1 && Left_Sensor == 0 && Right_Sensor == 1)
						STATE_VALUE = 12;
				else if(Back_Sensor == 1 && Left_Sensor == 1 && Right_Sensor == 0)
						STATE_VALUE = 13;
				else if(Back_Sensor == 1 && Left_Sensor == 1 && Right_Sensor == 1) // normal mode
						STATE_VALUE = 14;
				else // error mode to kill all
						STATE_VALUE = 15;
		}
		else if(BL == 1 && BR == 1 && HL == 0 && HR == 0) { // BackLeft and BackRight
				if(Head_Sensor == 0 && Left_Sensor == 1 && Right_Sensor == 1)
						STATE_VALUE = 21;
				else if(Head_Sensor == 1 && Left_Sensor == 0 && Right_Sensor == 1)
						STATE_VALUE = 22;
				else if(Head_Sensor == 1 && Left_Sensor == 1 && Right_Sensor == 0)
						STATE_VALUE = 23;
				else if(Head_Sensor == 1 && Left_Sensor == 1 && Right_Sensor == 1)
						STATE_VALUE = 24;
				else // error mode to kill all
						STATE_VALUE = 25;
		}
		else if(HL == 1 && BL == 1 && HR == 0 && BR == 0) { // HeadLeft and BackLeft
				if(Head_Sensor == 0 && Back_Sensor == 1 && Right_Sensor == 1)
						STATE_VALUE = 31;
				else if(Head_Sensor == 1 && Back_Sensor == 0 && Right_Sensor == 1)
						STATE_VALUE = 32;
				else if(Head_Sensor == 1 && Back_Sensor == 1 && Right_Sensor == 0)
						STATE_VALUE = 33;
				else if(Head_Sensor == 1 && Back_Sensor == 1 && Right_Sensor == 1)
						STATE_VALUE = 34;
				else // error mode to kill all
						STATE_VALUE = 35;
		}
		else if(HR == 1 && BR == 1 && HL == 0 && BL == 0) { // HeadRight and BackRight
				if(Head_Sensor == 0 && Back_Sensor == 1 && Left_Sensor == 1)
						STATE_VALUE = 41;
				else if(Head_Sensor == 1 && Back_Sensor == 0 && Left_Sensor == 1)
						STATE_VALUE = 42;
				else if(Head_Sensor == 1 && Back_Sensor == 1 && Left_Sensor == 0)
						STATE_VALUE = 43;
				else if(Head_Sensor == 1 && Back_Sensor == 1 && Left_Sensor == 1)
						STATE_VALUE = 44;
				else // error mode to kill all
						STATE_VALUE = 45;
		}
		// single active
		else if(HL == 1 && HR == 0 && BL == 0 && BR == 0) { // HeadLeft
				if(Head_Sensor == 0 && Back_Sensor == 1 && Left_Sensor == 1 && Right_Sensor == 1)
						STATE_VALUE = 51;
				else if(Head_Sensor == 1 && Back_Sensor == 0 && Left_Sensor == 1 && Right_Sensor == 1)
						STATE_VALUE = 52;
				else if(Head_Sensor == 1 && Back_Sensor == 1 && Left_Sensor == 0 && Right_Sensor == 1)
						STATE_VALUE = 53;
				else if(Head_Sensor == 1 && Back_Sensor == 1 && Left_Sensor == 1 && Right_Sensor == 0)
						STATE_VALUE = 54;
				else if(Head_Sensor == 1 && Back_Sensor == 1 && Left_Sensor == 1 && Right_Sensor == 1) // normal
						STATE_VALUE = 55;
				else // error mode to kill all
						STATE_VALUE = 56;
		}
		else if(BL == 0 && BR == 0 && HL == 0 && HR == 1) { // HeadRight
				if(Head_Sensor == 0 && Back_Sensor == 1 && Left_Sensor == 1 && Right_Sensor == 1)
						STATE_VALUE = 61;
				else if(Head_Sensor == 1 && Back_Sensor == 0 && Left_Sensor == 1 && Right_Sensor == 1)
						STATE_VALUE = 62;
				else if(Head_Sensor == 1 && Back_Sensor == 1 && Left_Sensor == 0 && Right_Sensor == 1)
						STATE_VALUE = 63;
				else if(Head_Sensor == 1 && Back_Sensor == 1 && Left_Sensor == 1 && Right_Sensor == 0)
						STATE_VALUE = 64;
				else if(Head_Sensor == 1 && Back_Sensor == 1 && Left_Sensor == 1 && Right_Sensor == 1)
						STATE_VALUE = 65;
				else // error mode to kill all
						STATE_VALUE = 66;
		}
		else if(BL == 1 && BR == 0 && HL == 0 && HR == 0) { // BackLeft
				if(Head_Sensor == 0 && Back_Sensor == 1 && Left_Sensor == 1 && Right_Sensor == 1)
						STATE_VALUE = 71;
				else if(Head_Sensor == 1 && Back_Sensor == 0 && Left_Sensor == 1 && Right_Sensor == 1)
						STATE_VALUE = 72;
				else if(Head_Sensor == 1 && Back_Sensor == 1 && Left_Sensor == 0 && Right_Sensor == 1)
						STATE_VALUE = 73;
				else if(Head_Sensor == 1 && Back_Sensor == 1 && Left_Sensor == 1 && Right_Sensor == 0)
						STATE_VALUE = 74;
				else if(Head_Sensor == 1 && Back_Sensor == 1 && Left_Sensor == 1 && Right_Sensor == 1)
						STATE_VALUE = 75;
				else // error mode to kill all
						STATE_VALUE = 76;
		}
		else if(BL == 0 && BR == 1 && HL == 0 && HR == 0) { // BackRight
				if(Head_Sensor == 0 && Back_Sensor == 1 && Left_Sensor == 1 && Right_Sensor == 1)
						STATE_VALUE = 81;
				else if(Head_Sensor == 1 && Back_Sensor == 0 && Left_Sensor == 1 && Right_Sensor == 1)
						STATE_VALUE = 82;
				else if(Head_Sensor == 1 && Back_Sensor == 1 && Left_Sensor == 0 && Right_Sensor == 1)
						STATE_VALUE = 83;
				else if(Head_Sensor == 1 && Back_Sensor == 1 && Left_Sensor == 1 && Right_Sensor == 0)
						STATE_VALUE = 84;
				else if(Head_Sensor == 1 && Back_Sensor == 1 && Left_Sensor == 1 && Right_Sensor == 1)
						STATE_VALUE = 85;
				else // error mode to kill all
						STATE_VALUE = 86; 
		}
		// normal situation
		else if(HR == 0 && HL == 0 && BR == 0 && BL == 0) { // inter
				// single 4
				if(Head_Sensor == 0 && Back_Sensor == 1 && Left_Sensor == 1 && Right_Sensor == 1)
						STATE_VALUE = 1;
				else if(Head_Sensor == 1 && Back_Sensor == 0 && Left_Sensor == 1 && Right_Sensor == 1)
						STATE_VALUE = 2;
				else if(Head_Sensor == 1 && Back_Sensor == 1 && Left_Sensor == 0 && Right_Sensor == 1)
						STATE_VALUE = 3;
				else if(Head_Sensor == 1 && Back_Sensor == 1 && Left_Sensor == 1 && Right_Sensor == 0)
						STATE_VALUE = 4;
				// double 6
				else if(Head_Sensor == 0 && Back_Sensor == 0 && Left_Sensor == 1 && Right_Sensor == 1)
						STATE_VALUE = 5;
				else if(Head_Sensor == 0 && Back_Sensor == 1 && Left_Sensor == 0 && Right_Sensor == 1)
						STATE_VALUE = 6;
				else if(Head_Sensor == 0 && Back_Sensor == 1 && Left_Sensor == 1 && Right_Sensor == 0)
						STATE_VALUE = 7;
				else if(Head_Sensor == 1 && Back_Sensor == 0 && Left_Sensor == 0 && Right_Sensor == 1)
						STATE_VALUE = 8;
				else if(Head_Sensor == 1 && Back_Sensor == 0 && Left_Sensor == 1 && Right_Sensor == 0)
						STATE_VALUE = 9;
				else if(Head_Sensor == 1 && Back_Sensor == 1 && Left_Sensor == 0 && Right_Sensor == 0)
						STATE_VALUE = 10;
				else // error mode to kill all
						STATE_VALUE = 0; 
		}
		else { // error mode
				if(Head_Sensor == 0 || Back_Sensor == 0 || Left_Sensor == 0 || Right_Sensor == 0)
						STATE_VALUE = -1;
		}
		return STATE_VALUE;
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
	
	Head_Sensor = 1;
	Back_Sensor = 1;
	Left_Sensor = 1;
	Right_Sensor = 1;
	
	v_Rejust = 128;
	v0 = 0;
	v1 = 512;
	v2 = 768;
	v3 = 1280;
	v_Max = 1536;
	
	isDelayed = 1;
	isFirstRun = 1;
	
	while(1)
	{
		HeadLeft_Sensor = GetKeyState(1);
		HeadRight_Sensor = GetKeyState(2);
		BackLeft_Sensor = GetKeyState(3);
		BackRight_Sensor = GetKeyState(4);
		
		if(HeadLeft_Sensor == 0 && HeadRight_Sensor == 0 && BackLeft_Sensor == 0 && BackRight_Sensor == 0) {
					if(isFirstRun == 1) {
						UINT16 i = 0;
						UINT16 j = 0;
						for(i = 0; i < 2000; i++) // delay 3s
						{
								for(j = 0; j < 1040; j++)
								{
										SetMotor1PWM(v2);
										SetMotor2PWM(v2);
								}
								if(GetKeyState(1) == 1 || GetKeyState(2) == 1)
										break;
						}
						isFirstRun = 0;
				}
				else if(isFirstRun == 0) {
						//int state_value = 0;
						Test_Motor_PWM = v2;
						SetMotor1PWM(v2);
						SetMotor2PWM(v2);
						/*state_value = Current_State(HeadLeft_Sensor, HeadRight_Sensor, BackLeft_Sensor, BackRight_Sensor);
						if(state_value == 1)
								Escape(1, 1500, -v2 - v_Rejust, -v2);
						else if(state_value == 2)
								Escape(2, 1500, v2, v2 + v_Rejust);
						else if(state_value == 3)
								Escape(2, 1500, v2, v2);
						else if(state_value == 4)
								Escape(1, 1500, -v2, -v2);
						else if(state_value == 5)
								Escape(2, 1500, v2, v2 + v_Rejust);
						else if(state_value == 6)
								Escape(2, 1500, v2 + v_Rejust, v2);
						else if(state_value == 7)
								Escape(2, 1500, v2, v2 + v_Rejust);
						else if(state_value == 8)
								Escape(2, 1500, v2 + v_Rejust, v2);
						else if(state_value == 9)
								Escape(2, 1500, v2, v2 + v_Rejust);
						else if(state_value == 10)
								Escape(2, 1500, v2, v2);*/		
				}
				
		}
		// double sensors
		else if(HeadLeft_Sensor == 1 && HeadRight_Sensor == 1 && BackLeft_Sensor == 0 && BackRight_Sensor == 0) {
				int state_value = 0;
				UINT16 i = 0;
				UINT16 j = 0;
				isDelayed = 0;
				Test_Motor_PWM_L = -v1;
				Test_Motor_PWM_R = -v1;
				Test_Motor_PWM = -v1;

				for(i = 0; i < 2500; i++) // delay
				{
						if(i > 1000) { // forbidden head to right
								Test_Motor_PWM_L = Test_Motor_PWM - v_Rejust;
								Test_Motor_PWM_R = Test_Motor_PWM + v_Rejust;
						}
						for(j = 0; j < 1040; j++)
						{
								// waiting for rejusting
								SetMotor1PWM(Test_Motor_PWM_L);
								SetMotor2PWM(Test_Motor_PWM_R);
						}
						
						state_value = Current_State(HeadLeft_Sensor, HeadRight_Sensor, BackLeft_Sensor, BackRight_Sensor);
						if(state_value == 15) // kill all
								Escape(0, 1500, v_Max, -v_Max);
						else if(state_value == 11 || state_value == 13) // back and right
								Escape(1, 1500, -v2, -v2 - v_Rejust * 2);
						else if(state_value == 12) // left
								Escape(1, 1500, -v2 - v_Rejust * 2, -v2);
						if(GetKeyState(3) == 1 || GetKeyState(4) == 1)
								break;
				}
		}
		else if(BackLeft_Sensor == 1 && BackRight_Sensor == 1 && HeadLeft_Sensor == 0 && HeadRight_Sensor == 0) {
				int state_value = 0;	
				UINT16 i = 0;
				UINT16 j = 0;
				isDelayed = 0;
				Test_Motor_PWM_L = v1;
				Test_Motor_PWM_R = v1;
				Test_Motor_PWM = v1;

				for(i = 0; i < 2500; i++) // delay
				{
						if(i > 1000) { // forbidden head to left
								Test_Motor_PWM_L = Test_Motor_PWM + v_Rejust;
								Test_Motor_PWM_R = Test_Motor_PWM - v_Rejust;
						}
						for(j = 0; j < 1040; j++)
						{
								// waiting for rejusting
								SetMotor1PWM(Test_Motor_PWM_L);
								SetMotor2PWM(Test_Motor_PWM_R);
						}
						
						state_value = Current_State(HeadLeft_Sensor, HeadRight_Sensor, BackLeft_Sensor, BackRight_Sensor);
						if(state_value == 25) // kill all
								Escape(0, 1500, v_Max, -v_Max);
						else if(state_value == 21 || state_value == 22) // left and head
								Escape(2, 1500, v2 + v_Rejust * 2, v2);
						else if(state_value == 23) // right
								Escape(2, 1500, v2, v2 + v_Rejust * 2);
						if(GetKeyState(1) == 1 || GetKeyState(2) == 1)
								break;
				}
		}
		else if(HeadLeft_Sensor == 1 && BackLeft_Sensor == 1 && HeadRight_Sensor == 0 && BackRight_Sensor == 0) {
				int state_value = 0;
				isDelayed = 0;
				Test_Motor_PWM_L = v1;
				Test_Motor_PWM_R = v0;
		
				SetMotor1PWM(Test_Motor_PWM_L);
				SetMotor2PWM(Test_Motor_PWM_R);
				
				state_value = Current_State(HeadLeft_Sensor, HeadRight_Sensor, BackLeft_Sensor, BackRight_Sensor);
				if(state_value == 35)
						Escape(0, 1500, v_Max, -v_Max);
				else if(state_value == 31)
						Escape(2, 1500, v2 + v_Rejust, v2 - v_Rejust);
				else if(state_value == 32 || state_value == 33)
						Escape(2, 1500, v2 + v_Rejust * 2, v2);
		}
		else if(HeadRight_Sensor == 1 && BackRight_Sensor == 1 && HeadLeft_Sensor == 0 && BackLeft_Sensor == 0) {
				int state_value = 0;
				isDelayed = 0;
				Test_Motor_PWM_L = v1;
				Test_Motor_PWM_R = v0;
		
				SetMotor1PWM(Test_Motor_PWM_L);
				SetMotor2PWM(Test_Motor_PWM_R);
				
				state_value = Current_State(HeadLeft_Sensor, HeadRight_Sensor, BackLeft_Sensor, BackRight_Sensor);
				if(state_value == 45)
						Escape(0, 1500, v_Max, -v_Max);
				else if(state_value == 41)
						Escape(2, 1500, v2 - v_Rejust, v2 + v_Rejust);
				else if(state_value == 42 || state_value == 43)
						Escape(2, 1500, v2, v2 + v_Rejust * 2);
		}
		// single sensor
		else if(BackLeft_Sensor == 0 && HeadLeft_Sensor == 1 && BackRight_Sensor == 0 && HeadRight_Sensor == 0)	{
				int state_value = 0;
				UINT16 i = 0;
				UINT16 j = 0;
				isDelayed = 0;
				Test_Motor_PWM_L = -v1;
				Test_Motor_PWM_R = v0;
				for(i = 0; i < 2500; i++)
				{
						if(i > 1000)
								Test_Motor_PWM_R = -v1;
						for(j = 0; j < 1040; j++)
						{
								SetMotor1PWM(Test_Motor_PWM_L);
								SetMotor2PWM(Test_Motor_PWM_R);
						}
						state_value = Current_State(HeadLeft_Sensor, HeadRight_Sensor, BackLeft_Sensor, BackRight_Sensor);
						if(state_value == 56) // kill all
								Escape(0, 1500, v_Max, -v_Max);
						else if(state_value == 51 || state_value == 53 || state_value == 54)
								Escape(3, 1500, -v3, -v3);
						else if(state_value == 52)
								Escape(3, 1500, -v2 - v_Rejust * 4, -v2);
						if(GetKeyState(2) == 1 || GetKeyState(3) == 1 || GetKeyState(4) == 1)
								break;
				}
		}
		else if(BackRight_Sensor == 0 && HeadRight_Sensor == 1 && BackLeft_Sensor == 0 && HeadLeft_Sensor == 0)	{
				int state_value = 0;
				UINT16 i = 0;
				UINT16 j = 0;
				isDelayed = 0;
				Test_Motor_PWM_L = v0;
				Test_Motor_PWM_R = -v1;
				for(i = 0; i < 2500; i++)
				{
						if(i > 1000)
								Test_Motor_PWM_L = -v1;
						for(j = 0; j < 1040; j++)
						{
								SetMotor1PWM(Test_Motor_PWM_L);
								SetMotor2PWM(Test_Motor_PWM_R);
						}
						
						state_value = Current_State(HeadLeft_Sensor, HeadRight_Sensor, BackLeft_Sensor, BackRight_Sensor);
						if(state_value == 66) // kill all
								Escape(0, 1500, v_Max, -v_Max);
						else if(state_value == 61 || state_value == 63 || state_value == 64)
								Escape(4, 1500, -v3, -v3);
						else if(state_value == 62)
								Escape(4, 1500, -v2, -v2 - v_Rejust * 4);
						if(GetKeyState(1) == 1 || GetKeyState(3) == 1 || GetKeyState(4) == 1)
								break;
				}
		}
		else if(HeadRight_Sensor == 0 && HeadLeft_Sensor == 0 && BackRight_Sensor == 0 && BackLeft_Sensor == 1)	{
				int state_value = 0;
				UINT16 i = 0;
				UINT16 j = 0;
				isDelayed = 0;
				Test_Motor_PWM_L = v1;
				Test_Motor_PWM_R = v0;
				for(i = 0; i < 2500; i++)
				{
						if(i > 1000)
								Test_Motor_PWM_R = v1;
						for(j = 0; j < 1040; j++)
						{
								SetMotor1PWM(Test_Motor_PWM_L);
								SetMotor2PWM(Test_Motor_PWM_R);
						}
						
						state_value = Current_State(HeadLeft_Sensor, HeadRight_Sensor, BackLeft_Sensor, BackRight_Sensor);
						if(state_value == 76) // kill all
								Escape(0, 1500, v_Max, -v_Max);
						else if(state_value == 72 || state_value == 73 || state_value == 74)
								Escape(5, 1500, v3, v3);
						else if(state_value == 71)
								Escape(5, 1500, v2 + v_Rejust * 4, v2);
						if(GetKeyState(1) == 1 || GetKeyState(2) == 1 || GetKeyState(4) == 1)
								break;
				}
		}
		else if(HeadLeft_Sensor == 0 && HeadRight_Sensor == 0 && BackLeft_Sensor == 0 && BackRight_Sensor == 1)	{
				int state_value = 0;
				UINT16 i = 0;
				UINT16 j = 0;
				isDelayed = 0;
				Test_Motor_PWM_L = v0;
				Test_Motor_PWM_R = v1;
				for(i = 0; i < 2500; i++)
				{
						if(i > 1000)
								Test_Motor_PWM_L = v1;
						for(j = 0; j < 1040; j++)
						{
								SetMotor1PWM(Test_Motor_PWM_L);
								SetMotor2PWM(Test_Motor_PWM_R);
						}
						
						state_value = Current_State(HeadLeft_Sensor, HeadRight_Sensor, BackLeft_Sensor, BackRight_Sensor);
						if(state_value == 86) // kill all
								Escape(0, 1500, v_Max, -v_Max);
						else if(state_value == 82 || state_value == 83 || state_value == 84)
								Escape(6, 1500, v3, v3);
						else if(state_value == 81)
								Escape(6, 1500, v2, v2 + v_Rejust * 4);
						if(GetKeyState(1) == 1 || GetKeyState(2) == 1 || GetKeyState(3) == 1)
								break;
				}
		}
		
		/*else if(HeadLeft_Sensor == 0 && HeadRight_Sensor == 0 && BackLeft_Sensor == 0 && BackRight_Sensor == 0) {
				if(isDelayed == 1) { // run from static
						if(isFirstRun == 1) {
								UINT16 i = 0;
								UINT16 j = 0;
								for(i = 0; i < 2000; i++) // delay 3s
								{
										for(j = 0; j < 1040; j++)
										{
												SetMotor1PWM(v1);
												SetMotor2PWM(v1);
										}
										//if(GetKeyState(1) != 0 || GetKeyState(2) != 0 || GetKeyState(3) != 0 || GetKeyState(4) != 0)
												//break;
								}
								isFirstRun = 0;
						}
						else if(isFirstRun == 0) {
								//int state_value = 0;
								//Test_Motor_PWM = v2;
								SetMotor1PWM(v2);
								SetMotor2PWM(v2);
								state_value = Current_State(HeadLeft_Sensor, HeadRight_Sensor, BackLeft_Sensor, BackRight_Sensor);
								if(state_value == 1)
										Escape(1, 1500, -v2 - v_Rejust, -v2);
								else if(state_value == 2)
										Escape(2, 1500, v2, v2 + v_Rejust);
								else if(state_value == 3)
										Escape(2, 1500, v2, v2);
								else if(state_value == 4)
										Escape(1, 1500, -v2, -v2);
								else if(state_value == 5)
										Escape(2, 1500, v2, v2 + v_Rejust);
								else if(state_value == 6)
										Escape(2, 1500, v2 + v_Rejust, v2);
								else if(state_value == 7)
										Escape(2, 1500, v2, v2 + v_Rejust);
								else if(state_value == 8)
										Escape(2, 1500, v2 + v_Rejust, v2);
								else if(state_value == 9)
										Escape(2, 1500, v2, v2 + v_Rejust);
								else if(state_value == 10)
										Escape(2, 1500, v2, v2);
						}
				}
				else if(isDelayed == 0) { // not yet delayed
						int state_value = 0;
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
								state_value = Current_State(HeadLeft_Sensor, HeadRight_Sensor, BackLeft_Sensor, BackRight_Sensor);
								if(state_value == 1)
										Escape(1, 1500, -v2 - v_Rejust, -v2);
								else if(state_value == 2)
										Escape(2, 1500, v2, v2 + v_Rejust);
								else if(state_value == 3)
										Escape(2, 1500, v2, v2);
								else if(state_value == 4)
										Escape(1, 1500, -v2, -v2);
								else if(state_value == 5)
										Escape(2, 1500, v2, v2 + v_Rejust);
								else if(state_value == 6)
										Escape(2, 1500, v2 + v_Rejust, v2);
								else if(state_value == 7)
										Escape(2, 1500, v2, v2 + v_Rejust);
								else if(state_value == 8)
										Escape(2, 1500, v2 + v_Rejust, v2);
								else if(state_value == 9)
										Escape(2, 1500, v2, v2 + v_Rejust);
								else if(state_value == 10)
										Escape(2, 1500, v2, v2);
								else
										Escape(0, 1500, v_Max, -v_Max);
						}
						isDelayed = 1;
				}
				
		}*/
		else { // impossible by nature
				UINT16 i = 0;
				UINT16 j = 0;
				isDelayed = 0;
				Test_Motor_PWM = v0;
				SetMotor1PWM(Test_Motor_PWM);
				SetMotor2PWM(Test_Motor_PWM);
				if(Current_State(HeadLeft_Sensor, HeadRight_Sensor, BackLeft_Sensor, BackRight_Sensor) == -1) {
						Test_Motor_PWM = v3;
						for(i = 0; i < 1500; i++) // delay 3s
						{
								for(j = 0; j < 1040; j++)
								{
										SetMotor1PWM(Test_Motor_PWM);
										SetMotor2PWM(-Test_Motor_PWM);
								}
						}
						if(GetKeyState(1) == 1 || GetKeyState(2) == 1 )
								break;
				}
		}
		
	}

}
//===========================================  End Of File  ===========================================//

