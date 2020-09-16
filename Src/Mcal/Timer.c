/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Timer.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern volatile uint32 GlobalSystemClock;
static const uint32 Gpt_BaseAddress[MAX_NUMBER_OF_GPIO_GPT] = {_16_32_BIT_TIMER_0_BASE_ADDRESS,			
																															 _16_32_BIT_TIMER_1_BASE_ADDRESS,		
																															 _16_32_BIT_TIMER_2_BASE_ADDRESS,			
																															 _16_32_BIT_TIMER_3_BASE_ADDRESS,			
																															 _16_32_BIT_TIMER_4_BASE_ADDRESS,			
	                                                             _16_32_BIT_TIMER_5_BASE_ADDRESS,			
																															 _32_64_BIT_WIDE_TIMER_0_BASE_ADDRESS,
																															 _32_64_BIT_WIDE_TIMER_1_BASE_ADDRESS,
																															 _32_64_BIT_WIDE_TIMER_2_BASE_ADDRESS,
																															 _32_64_BIT_WIDE_TIMER_3_BASE_ADDRESS,
																															 _32_64_BIT_WIDE_TIMER_4_BASE_ADDRESS,
																															 _32_64_BIT_WIDE_TIMER_5_BASE_ADDRESS};
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
* \Syntax          : void Gpt_Init( const Gpt_ConfigType* ConfigPtr)        
* \Description     : Initializes the GPT driver.                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr   Pointer to a selected configuration structure                     
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_Init( const Gpt_ConfigType* ConfigPtr)
{
	Gpt_ChannelType 						Channel_Temp ;					
	Gpt_ChannelTickFrequency 		TickFrequency_Temp; 
	GptChannelTickValueMax  		TickValueMax_Temp;
	ChannelMode									Mode_Temp;
for(uint8 Counter =0 ; Counter <GPT_ACTIVATED_CHANNELS_SIZE;	Counter ++){
Channel_Temp=ConfigPtr[Counter].channel;			
TickFrequency_Temp=ConfigPtr[Counter].channelTickFreq;	
TickValueMax_Temp=ConfigPtr[Counter].channelTickMaxValue;	
Mode_Temp=ConfigPtr[Counter].channelMode;
	
(*((volatile uint32*)(Gpt_BaseAddress[Channel_Temp] + GPTMCFG_OFFSET  ))) = 0x4;        // To Use 16-Bit Or 32-Bit Only 

	
	if		(Mode_Temp==GPT_CH_MODE_CONTINUOUS) (*((volatile uint32*)(Gpt_BaseAddress[Channel_Temp] + GPTMTAMR_OFFSET  ))) |= 0x2;
else if (Mode_Temp==GPT_CH_MODE_ONESHOT)		(*((volatile uint32*)(Gpt_BaseAddress[Channel_Temp] + GPTMTAMR_OFFSET  ))) |= 0x1;		
	
(*((volatile uint32*)(Gpt_BaseAddress[Channel_Temp] + GPTMTAMR_OFFSET  ))) |= (1<<4) ;        // The Timer Counts Up. 
	
Gpt_DisableNotification(Channel_Temp);	
}







}
	/******************************************************************************
* \Syntax          : void Gpt_DisableNotification( Gpt_ChannelType Channel )        
* \Description     : Reentrant (but not for the same timer channel)                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                     
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_DisableNotification( Gpt_ChannelType Channel )
{
	(*((volatile uint32*)(Gpt_BaseAddress[Channel] + GPTMIMR_OFFSET  ))) &= ((uint32)(~(1<<0)));
}

	/******************************************************************************
* \Syntax          : void Gpt_EnableNotification( Gpt_ChannelType Channel )        
* \Description     : Reentrant (but not for the same timer channel)                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                     
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_EnableNotification( Gpt_ChannelType Channel )
{
	(*((volatile uint32*)(Gpt_BaseAddress[Channel] + GPTMIMR_OFFSET  ))) |= ((uint32)(1<<0));
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
Std_ReturnType Gpt_GetPredefTimerValue( Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr)
{
}

/******************************************************************************
* \Syntax          : Gpt_ValueType Gpt_GetTimeRemaining( Gpt_ChannelType Channel )       
* \Description     : Returns the time remaining until the target time is reached.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                     
* \Parameters (out): None                                                      
* \Return value:   : Gpt_ValueType  uint32                                 
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining( Gpt_ChannelType Channel )
{
}


/******************************************************************************
* \Syntax          : void Gpt_StartTimer( Gpt_ChannelType Channel, Gpt_ValueType Value );        
* \Description     : Starts a timer channel.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant(but not for the same timer channel)                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel. 
*										 Value		 Target time in number of ticks.
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_StartTimer( Gpt_ChannelType Channel, Gpt_ValueType Value )
{
}

/******************************************************************************
* \Syntax          : void Gpt_StopTimer( Gpt_ChannelType Channel )       
* \Description     : Stops a timer channel.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant (but not for the same timer channel)                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                     
* \Parameters (out): None                                                      
* \Return value:   : None                           
*******************************************************************************/
void Gpt_StopTimer( Gpt_ChannelType Channel )
{
		(*((volatile uint32*)(Gpt_BaseAddress[Channel] + GPTMCTL_OFFSET  ))) &= ((uint32)(~(1<<0)));

}

void TIMER0A_Handler(void)
{
}

void TIMER1A_Handler(void)
{
}

void TIMER2A_Handler(void)
{
}

void TIMER3A_Handler(void)
{
}

void TIMER4A_Handler(void)
{
}

void TIMER5A_Handler(void)
{
}

void WTIMER0A_Handler(void)
{
}

void WTIMER1A_Handler(void)
{
}

void WTIMER2A_Handler(void)
{
}
void WTIMER3A_Handler(void)
{
}
void WTIMER4A_Handler(void)
{
}
void WTIMER5A_Handler(void)
{
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
