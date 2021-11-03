/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Mcu_Lcfg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Mcu_Cfg.h"
#include "Mcu_Types.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
 
 const  uint8 MCU_ACTIVATED_GATES[NUMBER_OF_ACTIVATED_GATES]={
	 
	 MCU_GPIOF_ENABLE_CLOCK,
	 MCU_PWM_1_ENABLE_CLOCK

 };

 
/**********************************************************************************************************************
 *  END OF FILE: Mcu_Lcfg.c
 *********************************************************************************************************************/
