/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port_Lcfg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Port_Driv_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

const Port_ConfigType Port_Config[NUMBER_OF_ACTIVATED_CHANNELS]=
{
	/* pin       			  Dir         		Mode     Attach      OutputCurr  */
	
	{  Dio_Channel_F2		 ,PORT_PIN_OUT   	,DIO	,DEFAULT   	,CURRENT_NA	},
	{  Dio_Channel_F3		 ,PORT_PIN_OUT   	,DIO	,DEFAULT   	,CURRENT_NA	},
	{  Dio_Channel_F1		 ,PORT_PIN_OUT   	,DIO	,DEFAULT   	,CURRENT_NA	}
	
 };

const Dio_ChannelGroupType RGB={0x0E,1,PORTF};
const Dio_ChannelGroupType KeypadInput;
const Dio_ChannelGroupType KeypadOutput;
const Dio_ChannelGroupType Lcd_Data;
 

/**********************************************************************************************************************
 *  END OF FILE: Port_Lcfg.c
 *********************************************************************************************************************/