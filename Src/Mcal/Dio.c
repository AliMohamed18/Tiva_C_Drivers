/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
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
#include "Dio.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
static const uint32 Port_APB_BaseAddress[6] = {
GPIO_PORTA_APB_BASE_ADDRESS,
GPIO_PORTB_APB_BASE_ADDRESS,
GPIO_PORTC_APB_BASE_ADDRESS,
GPIO_PORTD_APB_BASE_ADDRESS,
GPIO_PORTE_APB_BASE_ADDRESS,
GPIO_PORTF_APB_BASE_ADDRESS
};

/*static const uint32 Port_AHB_BaseAddress[6] = {
GPIO_PORTA_AHB_BASE_ADDRESS,
GPIO_PORTB_AHB_BASE_ADDRESS,
GPIO_PORTC_AHB_BASE_ADDRESS,
GPIO_PORTD_AHB_BASE_ADDRESS,
GPIO_PORTE_AHB_BASE_ADDRESS,
GPIO_PORTF_AHB_BASE_ADDRESS
};
*/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

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
* \Syntax          : Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId )        
* \Description     : Reads channel value
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId                       
* \Parameters (out): None                                                      
* \Return value:   : Dio_LevelType                                   
*******************************************************************************/
Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId ){

	Dio_LevelType level;
	uint8 portPos,channelPos;
	
	portPos = ChannelId / 8;
	channelPos = ChannelId % 8;
		
	level = (((*((uint32*)(Port_APB_BaseAddress[portPos] + GPIODATA_OFFSET + (4 * (1<<channelPos)) ))) >> channelPos) &1);
	

	return level;
}

/******************************************************************************
* \Syntax          : void Dio_WriteChannel ( Dio_ChannelType ChannelId, Dio_LevelType Level )        
* \Description     : Writes channel value
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId   ID of DIO channel                     
* \Parameters (out): None                                                      
* \Return value:   : None                                  
*******************************************************************************/
void Dio_WriteChannel ( Dio_ChannelType ChannelId, Dio_LevelType Level ){

uint8 portPos,channelPos;
	
	portPos = ChannelId / 8;
	channelPos = ChannelId % 8;
	
	(*((volatile uint32*)(Port_APB_BaseAddress[portPos] + GPIODATA_OFFSET + (4 * (1<<channelPos)) ))) = ((uint32)(Level << channelPos));


}

/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort ( Dio_PortType PortId )       
* \Description     : Reads Port value
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId   ID of DIO port                    
* \Parameters (out): Dio_PortLevelType                                                      
* \Return value:   : Dio_PortLevelType   uint8                                  
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort ( Dio_PortType PortId ){
Dio_PortLevelType portLevel ;
	
portLevel = ((uint8)(*((uint32*)(Port_APB_BaseAddress[PortId]+GPIODATA_OFFSET+0X3FC))));
	
	return portLevel;
}

/******************************************************************************
* \Syntax          : void Dio_WritePort ( Dio_PortType PortId, Dio_PortLevelType Level );       
* \Description     : writes Port value
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId   ID of DIO port
										 Level  	Value to be written                    
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level ){

 (*((uint32*)(Port_APB_BaseAddress[PortId]+GPIODATA_OFFSET+0X3FC)))=Level ;
}

/******************************************************************************
* \Syntax          : void Dio_WritePort ( Dio_PortType PortId, Dio_PortLevelType Level );       
* \Description     : writes Port value
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId   ID of DIO channel                   
* \Parameters (out): Dio_LevelType                                                      
* \Return value:   : Dio_LevelType	STD_LOW,
																		STD_HIGH                                 
*******************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId){


	if (Dio_ReadChannel(ChannelId) == STD_low) Dio_WriteChannel(ChannelId,STD_high);
	else 																			 Dio_WriteChannel(ChannelId,STD_low);
	
	return Dio_ReadChannel(ChannelId);

}


/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
