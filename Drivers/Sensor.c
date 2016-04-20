/*-----------------------------------------  I N C L U D E S  -----------------------------------------*/
#include "Sensor.h"

u8 const AD_Map[6] = {0,4,5,6,7,14};

/*---------------------------------------  D E F I N I T I O N  ---------------------------------------*/


/*----------------------------------------  F U N C T I O N S  ----------------------------------------*/
/********************************************************************************************************
Function Name: SensorIOInit
Description  :
Inputs       : None
Outputs      : None
Notes        :
Revision     :
********************************************************************************************************/
void SensorIOInit(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = SENSOR1_PIN|SENSOR2_PIN|SENSOR3_PIN|SENSOR4_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(SENSOR1_4_GPIO, &GPIO_InitStructure);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    GPIO_InitStructure.GPIO_Pin = SENSOR5_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(SENSOR5_GPIO, &GPIO_InitStructure);
}

/********************************************************************************************************
Function Name: SensorADCInit
Description  :
Inputs       : None
Outputs      : None
Notes        :
Revision     :
********************************************************************************************************/
void SensorADCInit(void)
{
    ADC_InitTypeDef ADC_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC2, ENABLE);

    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NbrOfChannel = 16;// 用于转换的通道数
    ADC_Init(SENSOR_ADC, &ADC_InitStructure);

    ADC_Cmd(SENSOR_ADC, ENABLE);
    ADC_ResetCalibration(SENSOR_ADC);
    while(ADC_GetResetCalibrationStatus(SENSOR_ADC));

    ADC_StartCalibration(SENSOR_ADC);
    while(ADC_GetCalibrationStatus(SENSOR_ADC));
    ADC_SoftwareStartConvCmd(SENSOR_ADC, ENABLE);
}

/********************************************************************************************************
Function Name: SensorInit
Description  :
Inputs       : None
Outputs      : None
Notes        :
Revision     :
********************************************************************************************************/
void SensorInit(void)
{
    SensorIOInit();
    SensorADCInit();
}

/*******************************************************************************
* Function Name  : GetADCValue
* Description    : Get a specific ADC value.
* Input          : 1,2,3,4,5
* Return         : u16
*******************************************************************************/
u16 GetADCValue(u8 ch)
{
    //u8 id;
    u16  ADC_data = 0;
    ADC_SoftwareStartConvCmd(SENSOR_ADC, DISABLE);
    ADC_RegularChannelConfig(SENSOR_ADC, AD_Map[ch], 1, ADC_SampleTime_7Cycles5);
    ADC_SoftwareStartConvCmd(SENSOR_ADC, ENABLE);
    while(!ADC_GetFlagStatus(SENSOR_ADC,ADC_FLAG_EOC));
    ADC_data = ADC_GetConversionValue(SENSOR_ADC);
    ADC_SoftwareStartConvCmd(SENSOR_ADC, DISABLE);
    return ADC_data;
}

//===========================================  End Of File  ===========================================//
