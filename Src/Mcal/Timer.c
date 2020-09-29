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

static const Gpt_ConfigType* globalGptConfig;

GptNotification	locGptNotification[MAX_NUMBER_OF_GPIO_GPT];

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
	globalGptConfig = ConfigPtr;

for(uint8 Counter =0 ; Counter <GPT_ACTIVATED_CHANNELS_SIZE;	Counter ++){
Channel_Temp=ConfigPtr[Counter].channel;			
TickFrequency_Temp=ConfigPtr[Counter].channelTickFreq;	
TickValueMax_Temp=ConfigPtr[Counter].channelTickMaxValue;	
Mode_Temp=ConfigPtr[Counter].channelMode;
locGptNotification[Channel_Temp]= ConfigPtr[Counter].gptNotification;
	
	
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
* \Syntax          : Gpt_GetTimeElapsed( Gpt_ChannelType Channel )        
* \Description     : Returns the time already elapsed.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                    
* \Parameters (out): Gpt_ValueType                                                      
* \Return value:   : Gpt_ValueType  uint32                                  
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed( Gpt_ChannelType Channel )
{
	Gpt_ValueType value;

	uint32 divisor;
	
	Gpt_ChannelTickFrequency 	locChannelTickFreq=0;
	GptChannelTickValueMax  	locChannelMaxValue=0;
	
	for(uint32 Counter=0;Counter<MAX_NUMBER_OF_GPIO_GPT;Counter++)
	{
		if (globalGptConfig[Counter].channel == Channel)
		{
			locChannelTickFreq = globalGptConfig[Counter].channelTickFreq;
			locChannelMaxValue = globalGptConfig[Counter].channelTickMaxValue;
			
			break;
		}
	}
	
	divisor = GlobalSystemClock / locChannelTickFreq;
	
	for(uint8 Counter=2;;Counter*=2)
	{
		if(divisor/Counter == 1)
		{
			if(divisor%Counter <= (Counter/2))
			{
				divisor = Counter;
			}
			else
			{
				divisor = Counter*2;
			}
			break;
		}
	}
	 
	value = ((*((volatile uint32*)(Gpt_BaseAddress[Channel] + GPTMTAV_OFFSET  ))) / divisor) & locChannelMaxValue;
	
	return value;
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
	Gpt_ValueType value, currentValue, remainingValue;
	uint32 divisor;
	
	Gpt_ChannelTickFrequency 	locChannelTickFreq=0;
	GptChannelTickValueMax  	locChannelMaxValue=0;
	
	for(uint32 Counter=0;Counter<MAX_NUMBER_OF_GPIO_GPT;Counter++)
	{
		if (globalGptConfig[Counter].channel == Channel)
		{
			locChannelTickFreq = globalGptConfig[Counter].channelTickFreq;
			locChannelMaxValue = globalGptConfig[Counter].channelTickMaxValue;
			
			break;
		}
	}
	
	divisor = GlobalSystemClock / locChannelTickFreq;
	
	for(uint8 Counter=2;;Counter*=2)
	{
		if(divisor/Counter == 1)
		{
			if(divisor%Counter <= (Counter/2))
			{
				divisor = Counter;
			}
			else
			{
				divisor = Counter*2;
			}
			break;
		}
	}
	currentValue = ((*((volatile uint32*)(Gpt_BaseAddress[Channel] + GPTMTAV_OFFSET  ))) / divisor) & locChannelMaxValue;
	value =((*((volatile uint32*)(Gpt_BaseAddress[Channel] + GPTMTAILR_OFFSET  ))) / divisor) & locChannelMaxValue;
	
	remainingValue = value - currentValue;
	
	return remainingValue;
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
	uint32 divisor;
	Gpt_ChannelTickFrequency 	locChannelTickFreq=0;
	 
		for(uint8 Counter=0; Counter < MAX_NUMBER_OF_GPIO_GPT ; Counter++)
	{
		if (globalGptConfig[Counter].channel == Channel)
		{
			locChannelTickFreq = globalGptConfig[Counter].channelTickFreq;			
			break;
		}
	}
	
	divisor = GlobalSystemClock / locChannelTickFreq;
	
	for(uint8 Counter=2 ;; Counter*=2)
	{

		if(divisor/Counter == 1)
		{
			if(divisor%Counter <= (Counter/2))
			{
				divisor = Counter;
			}
			else
			{
				divisor = Counter*2;
			}
			break;
		}
	}
	
	(*((volatile uint32*)(Gpt_BaseAddress[Channel] + GPTMTAILR_OFFSET  ))) = Value * divisor;
	(*((volatile uint32*)(Gpt_BaseAddress[Channel] + GPTMCTL_OFFSET  ))) |= ((uint32)(1<<0));

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
	static GptNotification gptNotificationFn_TIMER0A;
	if (locGptNotification[GPT_16_32_BIT_TIMER0] != NULL)
	{
		gptNotificationFn_TIMER0A = locGptNotification[GPT_16_32_BIT_TIMER0];
		gptNotificationFn_TIMER0A();
	}
}

void TIMER1A_Handler(void)
{
	static GptNotification gptNotificationFn_TIMER1A;
	if (locGptNotification[GPT_16_32_BIT_TIMER1] != NULL)
	{
		gptNotificationFn_TIMER1A = locGptNotification[GPT_16_32_BIT_TIMER1];
		gptNotificationFn_TIMER1A();
	}
}

void TIMER2A_Handler(void)
{
	static GptNotification gptNotificationFn_TIMER2A;
	if (locGptNotification[GPT_16_32_BIT_TIMER2] != NULL)
	{
		gptNotificationFn_TIMER2A = locGptNotification[GPT_16_32_BIT_TIMER2];
		gptNotificationFn_TIMER2A();
	}
}

void TIMER3A_Handler(void)
{
	static GptNotification gptNotificationFn_TIMER3A;
	if (locGptNotification[GPT_16_32_BIT_TIMER3] != NULL)
	{
		gptNotificationFn_TIMER3A = locGptNotification[GPT_16_32_BIT_TIMER3];
		gptNotificationFn_TIMER3A();
	}
}

void TIMER4A_Handler(void)
{
	static GptNotification gptNotificationFn_TIMER4A;
	if (locGptNotification[GPT_16_32_BIT_TIMER4] != NULL)
	{
		gptNotificationFn_TIMER4A = locGptNotification[GPT_16_32_BIT_TIMER4];
		gptNotificationFn_TIMER4A();
	} 
}

void TIMER5A_Handler(void)
{
	static GptNotification gptNotificationFn_TIMER5A;
	if (locGptNotification[GPT_16_32_BIT_TIMER5] != NULL)
	{
		gptNotificationFn_TIMER5A = locGptNotification[GPT_16_32_BIT_TIMER5];
		gptNotificationFn_TIMER5A();
	}
}

void WTIMER0A_Handler(void)
{
	static GptNotification gptNotificationFn_WTIMER0A;
	if (locGptNotification[GPT_32_64_BIT_WIDE_TIMER0] != NULL)
	{
		gptNotificationFn_WTIMER0A = locGptNotification[GPT_32_64_BIT_WIDE_TIMER0];
		gptNotificationFn_WTIMER0A();
	}
}

void WTIMER1A_Handler(void)
{
	static GptNotification gptNotificationFn_WTIMER1A;
	if (locGptNotification[GPT_32_64_BIT_WIDE_TIMER1] != NULL)
	{
		gptNotificationFn_WTIMER1A = locGptNotification[GPT_32_64_BIT_WIDE_TIMER1];
		gptNotificationFn_WTIMER1A();
	}
}

void WTIMER2A_Handler(void)
{
	static GptNotification gptNotificationFn_WTIMER2A;
	if (locGptNotification[GPT_32_64_BIT_WIDE_TIMER2] != NULL)
	{
		gptNotificationFn_WTIMER2A = locGptNotification[GPT_32_64_BIT_WIDE_TIMER2];
		gptNotificationFn_WTIMER2A();
	}
}

void WTIMER3A_Handler(void)
{
	static GptNotification gptNotificationFn_WTIMER3A;
	if (locGptNotification[GPT_32_64_BIT_WIDE_TIMER3] != NULL)
	{
		gptNotificationFn_WTIMER3A = locGptNotification[GPT_32_64_BIT_WIDE_TIMER3];
		gptNotificationFn_WTIMER3A();
	}
}

void WTIMER4A_Handler(void)
{
	static GptNotification gptNotificationFn_WTIMER4A;
	if (locGptNotification[GPT_32_64_BIT_WIDE_TIMER4] != NULL)
	{
		gptNotificationFn_WTIMER4A = locGptNotification[GPT_32_64_BIT_WIDE_TIMER4];
		gptNotificationFn_WTIMER4A();
	}
}

void WTIMER5A_Handler(void)
{
	static GptNotification gptNotificationFn_WTIMER5A;
	if (locGptNotification[GPT_32_64_BIT_WIDE_TIMER5] != NULL)
	{
		gptNotificationFn_WTIMER5A = locGptNotification[GPT_32_64_BIT_WIDE_TIMER5];
		gptNotificationFn_WTIMER5A();
	}
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
