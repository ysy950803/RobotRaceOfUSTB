#include "STM32Lib\\stm32f10x.h"
#include "Motor_TIM4.h"
#include "hal.h"
#include "Follow.h"

int main(void)
{
	ChipHalInit();
	ChipOutHalInit();

	while(1)
	{
		 Beep();
		//Motor_Set(108,108);
		//Follow();
	}
	
}


