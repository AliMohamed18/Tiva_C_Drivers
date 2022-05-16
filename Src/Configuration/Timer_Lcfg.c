// Not Finished Yet
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
#include "Std_Types.h"
#include "Timer_Cfg.h"
#include "Timer.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
void Gpt_NotificationFn(void);
void Gpt_NotificationFn2(void);

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
const Gpt_ConfigType Gpt_Config[GPT_ACTIVATED_CHANNELS_SIZE] =
{
	/* channel										channelTickFreq					channelTickMaxValue					channelMode								gptNotification */
	{GPT_16_32_BIT_TIMER0,				500,										0xFF,												GPT_CH_MODE_ONESHOT,			Gpt_NotificationFn},
	{GPT_16_32_BIT_TIMER1,				500,										0xFF,												GPT_CH_MODE_ONESHOT,			Gpt_NotificationFn2},
	
};
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void Gpt_NotificationFn(void)
{
	
}
void Gpt_NotificationFn2(void)
{
	
}



/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
