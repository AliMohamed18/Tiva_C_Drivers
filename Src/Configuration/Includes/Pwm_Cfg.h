/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Uart_Cfg.h
 *       Module:  -
 *
 *  Description:  Uart Config.
 *  
 *********************************************************************************************************************/
#ifndef PWM_CFG_H
#define PWM_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Pwm.h"

extern uint32 SystemCoreClock;


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define NUMBER_OF_ACTIVATED_PWMS 3

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
extern const Pwm_ConfigType Pwm_Config[];

#endif /* PWM_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: PWM_CFG_H
 *********************************************************************************************************************/
