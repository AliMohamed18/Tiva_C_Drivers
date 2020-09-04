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
 MCU_GPIOA_ENABLE_CLOCK ,
 MCU_GPIOB_ENABLE_CLOCK ,
 MCU_GPIOC_ENABLE_CLOCK ,
 MCU_GPIOD_ENABLE_CLOCK ,
 MCU_GPIOE_ENABLE_CLOCK ,
 MCU_GPIOF_ENABLE_CLOCK ,
 MCU_WATCHDOG_0_ENABLE_CLOCK ,
 MCU_WATCHDOG_1_ENABLE_CLOCK 
 };

 const  Mcu_ConfigType McuConfig[NUMBER_OF_ACTIVATED_CLOCK_MODE]=
{
	{MCU_CLOCK_SOURCE_MOSC						,PLL_POWERED_AND_LOCKED								,MCU_CLOCK_FREQ_8		},
	{MCU_CLOCK_SOURCE_MOSC						,PLL_POWERED_AND_LOCKED								,MCU_CLOCK_FREQ_16	},
	{MCU_CLOCK_SOURCE_MOSC						,PLL_POWERED_AND_LOCKED								,MCU_CLOCK_FREQ_40	},
	{MCU_CLOCK_SOURCE_MOSC						,PLL_POWERED_AND_LOCKED								,MCU_CLOCK_FREQ_80	},
	{MCU_CLOCK_SOURCE_MOSC						,PLL_UNPOWERED_OR_NOT_LOCKED_YET			,MCU_CLOCK_FREQ_8	  },
	{MCU_CLOCK_SOURCE_MOSC						,PLL_UNPOWERED_OR_NOT_LOCKED_YET			,MCU_CLOCK_FREQ_16	},

	
	{MCU_CLOCK_SOURCE_MOSC						,PLL_UNPOWERED_OR_NOT_LOCKED_YET			,MCU_CLOCK_FREQ_8		},
	{MCU_CLOCK_SOURCE_MOSC						,PLL_UNPOWERED_OR_NOT_LOCKED_YET			,MCU_CLOCK_FREQ_16	},

	
	{MCU_CLOCK_SOURCE_PIOSC						,PLL_POWERED_AND_LOCKED								,MCU_CLOCK_FREQ_8		},
	{MCU_CLOCK_SOURCE_PIOSC_DIV_4			,PLL_POWERED_AND_LOCKED								,MCU_CLOCK_FREQ_16	},
	{MCU_CLOCK_SOURCE_PIOSC_DIV_4			,PLL_UNPOWERED_OR_NOT_LOCKED_YET			,MCU_CLOCK_FREQ_16	},	
	
	
	{MCU_CLOCK_SOURCE_LFIOSC					,PLL_POWERED_AND_LOCKED								,MCU_CLOCK_FREQ_8		},
	{MCU_CLOCK_SOURCE_LFIOSC					,PLL_UNPOWERED_OR_NOT_LOCKED_YET			,MCU_CLOCK_FREQ_8		},
	{MCU_CLOCK_SOURCE_LFIOSC					,PLL_UNPOWERED_OR_NOT_LOCKED_YET			,MCU_CLOCK_FREQ_16	},		
	
};

 
/**********************************************************************************************************************
 *  END OF FILE: Mcu_Lcfg.c
 *********************************************************************************************************************/
