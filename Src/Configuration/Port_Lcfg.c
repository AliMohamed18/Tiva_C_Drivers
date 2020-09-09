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
#include "Port_Cfg.h"

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
	/* pin       Dir         Mode             Attach      OutputCurr  */        
	{  PF0     ,Output   	,DIO    					,DEFAULT   	,CURRENT_NA	},
	{  PF1     ,Output   	,DIO        			,DEFAULT   	,CURRENT_NA	},
	{  PF2     ,Output  	,DIO         	  	,DEFAULT   	,CURRENT_NA	},
	{  PF3     ,Output   	,DIO    			  	,DEFAULT   	,CURRENT_NA	},
	{  PF4     ,Output   	,DIO       				,DEFAULT   	,CURRENT_NA	},
	{  PD0     ,Output  	,D0_SSI3Clk				,DEFAULT   	,CURRENT_NA	},
	{  PD1     ,Output  	,D1_SSI3Fss				,DEFAULT   	,CURRENT_NA	},
	{  PD2     ,Input  		,D2_SSI3Rx				,PULLDOWN   ,CURRENT_NA	},
	{  PD3     ,Output  	,D3_SSI3Tx				,DEFAULT   	,CURRENT_NA	},
	{  PD4     ,Input  		,DIO          	  ,PULLUP   	,CURRENT_NA	},
	{  PD5     ,Input  		,DIO         		  ,PULLDOWN   ,CURRENT_NA	},
	{  PD6     ,Input  		,DIO              ,PULLDOWN   ,CURRENT_NA	},
	{  PD7     ,Output  	,DIO              ,OPENDRAIN  ,CURRENT_NA	}
};

/**********************************************************************************************************************
 *  END OF FILE: Port_Lcfg.c
 *********************************************************************************************************************/