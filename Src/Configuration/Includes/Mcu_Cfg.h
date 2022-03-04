/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Cfg.h
 *       Module:  -
 *
 *  Description:  MicroController Config.
 *  
 *********************************************************************************************************************/
#ifndef MCU_CFG_H
#define MCU_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Mcu_Types.h"
#include "Std_Types.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define NUMBER_OF_ACTIVATED_GATES 7
#define NUMBER_OF_ACTIVATED_CLOCK_MODE 3



typedef enum{
	MCU_CLOCK_0		=	0,
	MCU_CLOCK_1			,
	MCU_CLOCK_2			,
	
}Mcu_ClockType;


//extern  const  Mcu_ConfigType McuConfig[NUMBER_OF_ACTIVATED_CLOCK_MODE];
extern  const  uint8 MCU_ACTIVATED_GATES[NUMBER_OF_ACTIVATED_GATES];


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif  /* MCU_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Cfg.h
 *********************************************************************************************************************/
