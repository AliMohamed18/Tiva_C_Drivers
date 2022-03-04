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

const Port_ConfigType Port_Config[NUMBER_OF_ACTIVATED_CHANNELS] =
	{
		/* pin       		Dir         	Mode     	Attach   	OutputCurr  */
		{Dio_Channel_B0, PORT_PIN_IN , 		B0_U1Rx, 	DEFAULT,	CURRENT_NA},
		{Dio_Channel_B1, PORT_PIN_OUT, 		B1_U1Tx, 	DEFAULT,	CURRENT_NA},
		
		{Dio_Channel_A0, PORT_PIN_IN , 		A0_U0Rx, 	DEFAULT,	CURRENT_NA},
		{Dio_Channel_A1, PORT_PIN_OUT, 		A1_U0Tx, 	DEFAULT,	CURRENT_NA},
		
		{Dio_Channel_F1, PORT_PIN_OUT, 		F1_M1PWM5, 	DEFAULT, 	CURRENT_NA},
		{Dio_Channel_A2, PORT_PIN_OUT, 		DIO, 		DEFAULT,	CURRENT_NA},
		{Dio_Channel_A3, PORT_PIN_OUT, 		DIO, 		DEFAULT, 	CURRENT_NA},
		
		{Dio_Channel_F2, PORT_PIN_OUT, 		F2_M1PWM6, 	DEFAULT, 	CURRENT_NA},
		{Dio_Channel_D0, PORT_PIN_OUT, 		DIO, 		DEFAULT, 	CURRENT_NA},
		{Dio_Channel_D1, PORT_PIN_OUT, 		DIO,	 	DEFAULT, 	CURRENT_NA},



				

};


const Dio_ChannelGroupType RGB = {0x0E, 1, PORTF};
const Dio_ChannelGroupType KeypadInput;
const Dio_ChannelGroupType KeypadOutput;
const Dio_ChannelGroupType Lcd_Data;

/**********************************************************************************************************************
 *  END OF FILE: Port_Lcfg.c
 *********************************************************************************************************************/
