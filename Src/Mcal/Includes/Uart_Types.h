/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef UART_TYPES_H
#define UART_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

 
typedef enum{ 
Uart0 = 0,
Uart1,
Uart2,
Uart3,
Uart4,
Uart5,
Uart6,
Uart7,
}Uart_ChannelType;

typedef uint32 BaudRateType;


typedef struct{

	Uart_ChannelType UARTPIN;
	BaudRateType BAUDRATE;
}Uart_ConfigType;



#endif  /* DIO_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio_Types.h
 *********************************************************************************************************************/