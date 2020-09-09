/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Wdt.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
 
#include "Wdt.h"


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define MCU_FREQ 8

extern Wdg_ConfigType Wdg_Config;
extern volatile  WdgMaxTimeout	MaxTimeout_Temp;

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

typedef void (*Ptr2FuncType)(void);
Ptr2FuncType CallBackPtr = NULL;

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
* \Syntax          : void Wdg_Init ( const Wdg_ConfigType* ConfigPtr )        
* \Description     : Watchdog Init                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Wdg_ConfigType                        
* \Parameters (out): None                                                      
* \Return value:   : void  
*******************************************************************************/
void Wdg_Init ( const Wdg_ConfigType* ConfigPtr )
{
	WdgNotificationEnable	NotificationEn_Temp;
	WdgInterruptType			InterruptType_Temp;
	WdgInitialTimeout			IntialTimeout_Temp;
	uint32 								NumberOfTicks;
	
	NotificationEn_Temp	=	ConfigPtr->notificationEn;
	InterruptType_Temp	=	ConfigPtr->interruptType;
	IntialTimeout_Temp	=	ConfigPtr->intialTimeout;
	MaxTimeout_Temp			=	ConfigPtr->maxTimeout;
	
  WDTLOCK=WATCHDOG_UNLOCK_VALUE;

	NumberOfTicks=(IntialTimeout_Temp/MCU_FREQ)*1000;
	
	WDTLOAD=NumberOfTicks;
	
	
	while(WDTCTL.B.WRC == 0){}
	
	WDTCTL.B.RESEN=1;
	
	while(WDTCTL.B.WRC == 0){}

  if     (InterruptType_Temp==WDG_TIMER_INT_STANDARD) 			WDTCTL.B.INTTYPE=0;
  else if(InterruptType_Temp==WDG_TIMER_INT_NON_MASKABLE)  WDTCTL.B.INTTYPE=1;
	
	while(WDTCTL.B.WRC == 0){}

  WDTLOCK=0;
		
	CallBackPtr = CALL_BACK_FUNC_PTR;

		
}

void WDT0_Handler(void){

	if(CallBackPtr != NULL)
	{
		CallBackPtr();
		
	}	
}

/******************************************************************************
* \Syntax          : void Wdg_SetTriggerCondition ( uint16 timeout )        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) :                        
* \Parameters (out): None                                                      
* \Return value:   : None  
*******************************************************************************/
void Wdg_SetTriggerCondition ( uint16 timeout )
{

	uint32 NumberOfTicks;

	
	  WDTLOCK=WATCHDOG_UNLOCK_VALUE;
  
	if(timeout<=MaxTimeout_Temp){
		
		NumberOfTicks=(timeout/MCU_FREQ)*1000;
		WDTLOAD=NumberOfTicks;

		while(WDTCTL.B.WRC == 0){}	
		WDTLOCK=0;
		}
	else {/*Error*/}
	
	
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
