/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Uart.h
 *       Module:  Uart
 *
 *  Description:  header file for Uart Module    
 *  
 *********************************************************************************************************************/
#ifndef PWM_H
#define PWM_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../Common/Std_Types.h"
#include "../../Common/Bit_Operations.h"
#include "../../Common/Mcu_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	M0PWM0 = 0,
	M0PWM1,
	M0PWM2,
	M0PWM3,
	M0PWM4,
	M0PWM5,
	M0PWM6,
	M0PWM7,
	M1PWM0,
	M1PWM1,
	M1PWM2,
	M1PWM3,
	M1PWM4,
	M1PWM5,
	M1PWM6,
	M1PWM7,
} Pwm_ChannelType;


typedef struct
{
	Pwm_ChannelType PWMPIN;
	uint32      Freq;
	uint8       DutyCycle;
	
} Pwm_ConfigType;

#define GenA 0
#define GenB 1
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void Pwm_Init( const Pwm_ConfigType* ConfigPtr )        
* \Description     : Service for PWM initialization.                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr   Pointer to configuration set.                   
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Pwm_Init(const Pwm_ConfigType *ConfigPtr);

/******************************************************************************
* \Syntax          : void Pwm_SetDutyCycle( Pwm_ChannelType ChannelNumber, uint16 DutyCycle )       
* \Description     : Send Char                                                                             
* \Sync\Async      : Asynchronous                                               
* \Reentrancy      : Reentrant for different channel numbers                                             
* \Parameters (in) : ChannelNumber   Numeric identifier of the PWM
*					 DutyCycle
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/

void Pwm_SetDutyCycle( Pwm_ChannelType ChannelNumber, uint8 DutyCycle );
	
#endif /* PWM_H */

/**********************************************************************************************************************
 *  END OF FILE: PWM_H
 *********************************************************************************************************************/
