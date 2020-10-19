/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Mcu.c
 *        \brief  MicroController Driver
 *
 *      \details  The Driver Configure All MCU Clock and Reset 
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Mcu.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
extern const  uint8 MCU_ACTIVATED_GATES[];
extern const	Mcu_ConfigType McuConfig[];

extern volatile uint32 GlobalSystemClock;

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static const Mcu_ConfigType* Mcu_Config  ;

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
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

void Mcu_Init ( void ){

uint32 	locGateRegOffset ,locGateBitOffset;
	

	
 for(uint8 Counter=0;Counter<NUMBER_OF_ACTIVATED_GATES;Counter++)
	    {
	    	locGateRegOffset = (MCU_ACTIVATED_GATES[Counter] / 10) * 4 ;
	    	locGateBitOffset = MCU_ACTIVATED_GATES[Counter] % 10 ;
	    (*((volatile uint32*)(0x400FE600 + locGateRegOffset  )))  |= (1<<locGateBitOffset);	
	    }
}
	


/******************************************************************************
* \Syntax          : Mcu_RawResetType Mcu_GetResetRawValue(void)                                      
* \Description     : Why The Reseet Occured ?                                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): none                                                      
* \Return value:   : uint8
*******************************************************************************/
Mcu_RawResetType Mcu_GetResetRawValue(void){
	
Mcu_RawResetType ResetRawValue=0;

if      (RESC.B.WDT0		==1) ResetRawValue=WATCHDOG_TIMER_0_RESET;
else if	(RESC.B.WDT1		==1) ResetRawValue=WATCHDOG_TIMER_1_RESET;
else if	(RESC.B.SW  		==1) ResetRawValue=SOFTWARE_RESET;
else if	(RESC.B.BOR 		==1) ResetRawValue=BROWN_OUT_RESET;
else if	(RESC.B.POR 		==1) ResetRawValue=POWER_ON_RESET;
else if	(RESC.B.EXT 		==1) ResetRawValue=EXTERNAL_RESET;
else if	(RESC.B.MOSCFAIL==1) ResetRawValue=MOSC_CIRCUIT_FAIL_RESET;	
	
RESC.R = 0;	


	
	return ResetRawValue;
}

/******************************************************************************
* \Syntax          : void Mcu_PerformReset(void)                                      
* \Description     : Perform Reset                                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): none                                                      
* \Return value:   : none
*******************************************************************************/
void Mcu_PerformReset(void){
	
RESC.R = 0;	
APINT.B.VECTKEY=APINT_VECTKEY;
APINT.B.SYSRESREQ=1;
	
}

/******************************************************************************
* \Syntax          : Mcu_PllStatusType Mcu_GetPllStatus(void)
* \Description     : Get Pll State                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): none                                                      
* \Return value:   : Mcu_PllStatusType
*******************************************************************************/
Mcu_PllStatusType Mcu_GetPllStatus(void){

Mcu_PllStatusType PLL_STATE =0;
	
if(PLLSTAT.B.LOCK==0)	PLL_STATE=PLL_UNPOWERED_OR_NOT_LOCKED_YET;
else 	PLL_STATE=PLL_POWERED_AND_LOCKED;
	
return	PLL_STATE;

}
	

/******************************************************************************
* \Syntax          : Std_ReturnType Mcu_DistributePllClock( void )        
* \Description     : This service activates the PLL clock to the MCU clock distribution.                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                            
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType 
*******************************************************************************/
Std_ReturnType Mcu_DistributePllClock(void)
{
	Std_ReturnType State = E_NOT_OK ;
	if(RCC.B.PWRDN == 0)
	{
			
				while(Mcu_GetPllStatus() == PLL_UNPOWERED_OR_NOT_LOCKED_YET){}
				RCC.B.BYPASS = 1;
				State = E_OK;
			
	}
	return State;
}


	
/**********************************************************************************************************************
 *  END OF FILE: Mcu.c
 *********************************************************************************************************************/
