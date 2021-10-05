/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Uart_Cfg.h
 *       Module:  -
 *
 *  Description:  Uart Config.
 *  
 *********************************************************************************************************************/
#ifndef UART_CFG_H
#define UART_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Uart.h"
extern uint32 SystemCoreClock;

#define SysClk SystemCoreClock

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define NUMBER_OF_ACTIVATED_UARTS 1

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
extern const Uart_ConfigType Uart_Config[];

#endif /* UART_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Cfg.h
 *********************************************************************************************************************/
