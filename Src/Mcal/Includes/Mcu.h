/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu.h
 *       Module:  Mcu
 *
 *  Description:  header file for Mcu Module    
 *  
 *********************************************************************************************************************/
#ifndef MCU_H
#define MCU_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Mcu_Types.h"
#include "Mcu_Cfg.h"
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Bit_Operations.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define APINT_VECTKEY 0xFA05

#define MOSC_CIRCUIT_FAIL_RESET 	0
#define WATCHDOG_TIMER_1_RESET		1
#define SOFTWARE_RESET			  		2
#define WATCHDOG_TIMER_0_RESET 		3
#define BROWN_OUT_RESET         	4
#define POWER_ON_RESET						5
#define EXTERNAL_RESET          	6

#define PLL_UNPOWERED_OR_NOT_LOCKED_YET 0
#define PLL_POWERED_AND_LOCKED 1

extern uint32 SystemCoreClock;


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 /******************************************************************************
* \Syntax          : void Mcu_Init ( const Mcu_ConfigType* ConfigPtr )        
* \Description     :  initializes the MCU driver.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr       Pointer to MCU  configuration set.                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void Mcu_Init ( void );

/******************************************************************************
* \Syntax          : Std_ReturnType Mcu_InitClock( Mcu_ClockSourceType ClockSetting );        
* \Description     :  initializes MCU clock source  .                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ClockSetting                            
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType 
*******************************************************************************/
Std_ReturnType Mcu_InitClock( Mcu_ClockType ClockSetting );


/******************************************************************************
* \Syntax          : Mcu_RawResetType Mcu_GetResetRawValue(void)                                      
* \Description     : Why The Reseet Occured ?                                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): none                                                      
* \Return value:   : Mcu_RawResetType
*******************************************************************************/

Mcu_RawResetType Mcu_GetResetRawValue(void);

/******************************************************************************
* \Syntax          : void Mcu_PerformReset(void)                                      
* \Description     : Perform Reset                                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): none                                                      
* \Return value:   : none
*******************************************************************************/
void Mcu_PerformReset(void);

/******************************************************************************
* \Syntax          : Mcu_PllStatusType Mcu_GetPllStatus(void)
* \Description     : Get Pll State                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): none                                                      
* \Return value:   : Mcu_PllStatusType
*******************************************************************************/
Mcu_PllStatusType Mcu_GetPllStatus(void); 

/******************************************************************************
* \Syntax          : Std_ReturnType Mcu_DistributePllClock(void )        
* \Description     : activat the PLL clock                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                            
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType 
*******************************************************************************/
Std_ReturnType Mcu_DistributePllClock(void);

#endif  /* MCU_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Mcu.h
 *********************************************************************************************************************/
