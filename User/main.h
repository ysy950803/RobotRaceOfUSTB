#ifndef __MAIN_H__
#define __MAIN_H__

/*-----------------------------------------  I N C L U D E S  -----------------------------------------*/
#include "Global.h"

/*---------------------------------------  D E F I N I T I O N  ---------------------------------------*/

/*-------------------------------------------  M A C R O S  -------------------------------------------*/

/*--------------------------------------  D E C L A R A T I O N  --------------------------------------*/
/* Internal Variable */

/* External Variable */

/* Internal Function */
void SystemStart(void);

void Test_InputIO(void); //Êı×ÖÊäÈë²âÊÔ
void Test_OutputIO(void);//Êı×ÖÊä³ö²âÊÔ
void Test_Sensor(void);  //Ä£ÄâÊäÈë²âÊÔ
void Test_Usart(void);   //´®¿Ú²âÊÔ
void Test_ZLG7290(void); //¼üÅÌ²âÊÔ
void Test_Motor(void);   //µç»ú²âÊÔ
void Test_Servo(void);   //¶æ»ú²âÊÔ
void Test_Encoder(void); //±àÂëÆ÷²âÊÔ
void Test_V_PID(void);   //µç»ú±Õ»·²âÊÔ
int Current_State(UINT8 HL, UINT8 HR, UINT8 BL, UINT8 BR);
void Test_Main(void);


/* External Function */

#endif

//===========================================  End Of File  ===========================================//

