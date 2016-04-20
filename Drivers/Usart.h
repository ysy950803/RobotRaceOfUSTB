#ifndef __USART_H__
#define __USART_H__

/*-----------------------------------------  I N C L U D E S  -----------------------------------------*/
#include "Global.h"

/*---------------------------------------  D E F I N I T I O N  ---------------------------------------*/
#define UART1_TX_PIN        GPIO_Pin_9
#define UART1_RX_PIN        GPIO_Pin_10
#define UART1_GPIO          GPIOA
#define UART1x              USART1

#define UART_TX_PIN        GPIO_Pin_10
#define UART_RX_PIN        GPIO_Pin_11
#define UART_GPIO          GPIOC
#define UARTx              UART4
/*-------------------------------------------  M A C R O S  -------------------------------------------*/


/*--------------------------------------  D E C L A R A T I O N  --------------------------------------*/
/* Internal Variable */

/* External Variable */

/* Internal Function */

/* External Function */
void UsartIOInit(void);
void UsartConfig(void);
void UsartInit(void);
void SendData(u8 ch);
void Send1Data(u8 ch);
#endif

//===========================================  End Of File  ===========================================//

