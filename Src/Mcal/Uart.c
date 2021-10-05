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
#include "Uart.h"
#include "Uart_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
static const uint32 Uart_BaseAddress[8] = {
	UART0_BASE_ADDRESS,
	UART1_BASE_ADDRESS,
	UART2_BASE_ADDRESS,
	UART3_BASE_ADDRESS,
	UART4_BASE_ADDRESS,
	UART5_BASE_ADDRESS,
	UART6_BASE_ADDRESS,
	UART7_BASE_ADDRESS};

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

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void Uart_Init ( const Uart_ConfigType* ConfigPtr )        
* \Description     : initializing the Uart diver module                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr   Pointer to configuration set.                   
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Uart_Init(const Uart_ConfigType *ConfigPtr)
{
	Uart_ChannelType Temp_UartPin;
	BaudRateType Temp_BuadRate;
	uint32 IBRD = 0, FBRD = 0;
	float BR = 0;
	uint8 Counter;

	for (Counter = 0; Counter < NUMBER_OF_ACTIVATED_UARTS; Counter++)
	{
		Temp_UartPin = ConfigPtr[Counter].UARTPIN;
		Temp_BuadRate = ConfigPtr[Counter].BAUDRATE;

		HwAccess(Uart_BaseAddress[Temp_UartPin] + UARTCTL_OFFSET) = 0; /* disable UART */ // HSE IS 0 So CLkDiv = 16

		BR = ((float)(((float)SysClk) / (Temp_BuadRate * 16)));
		IBRD = ((uint32)BR);
		FBRD = ((uint32)((((float)(BR - IBRD)) * 64) + 0.5));

		HwAccess(Uart_BaseAddress[Temp_UartPin] + UARTIBRD_OFFSET) = IBRD;	   /* 16MHz/16=1MHz, 1MHz/104=9600 baud rate */
		HwAccess(Uart_BaseAddress[Temp_UartPin] + UARTFBRD_OFFSET) = FBRD;	   /* fraction part, see Example 4-4 */
		HwAccess(Uart_BaseAddress[Temp_UartPin] + UARTCC_OFFSET) = 0;		   /* use system clock */
		HwAccess(Uart_BaseAddress[Temp_UartPin] + UARTLCRH_OFFSET) = 0x60;	   /* 8-bit, no parity, 1-stop bit, no FIFO */
		HwAccess(Uart_BaseAddress[Temp_UartPin] + UARTCTL_OFFSET) |= (1 << 8); /* enable TXE  */
		HwAccess(Uart_BaseAddress[Temp_UartPin] + UARTCTL_OFFSET) |= (1 << 9); /* enable RXE  */
		HwAccess(Uart_BaseAddress[Temp_UartPin] + UARTCTL_OFFSET) |= (1 << 0); /* enable UART */
	}
}
/******************************************************************************
* \Syntax          : void Uart_SendChar(Uart_ChannelType Channel , char Char )       
* \Description     : Send Char                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel   ID of Uart channel                     
* \Parameters (out): Char                                                      
* \Return value:   : Void                                 
*******************************************************************************/

void Uart_SendChar(Uart_ChannelType Channel, char Char)
{

	while (((HwAccess(Uart_BaseAddress[Channel] + UARTFR_OFFSET)) & 0x20) != 0)
	{
	} /* wait until Tx buffer not full */
	HwAccess(Uart_BaseAddress[Channel] + UARTDR_OFFSET) = Char;
}

/******************************************************************************
* \Syntax          : void Uart_ReceiveChar(Uart_ChannelType Channel , char Char )       
* \Description     : Send Char                                       
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel   ID of Uart channel                     
* \Parameters (out): void                                                      
* \Return value:   : char                                 
*******************************************************************************/

char Uart_ReceiveChar(Uart_ChannelType Channel)
{
	{
		char CHAR;
		while ((HwAccess(Uart_BaseAddress[Channel] + UARTFR_OFFSET) & 0x10) != 0)
			;																/* wait until the buffer is not empty */
		CHAR = ((char)HwAccess(Uart_BaseAddress[Channel] + UARTDR_OFFSET)); /* read the received data */
		return CHAR;														/* and return it */
	}
}
/******************************************************************************
* \Syntax          : void Uart_SendString(Uart_ChannelType Channel,const sint8 *Str)       
* \Description     : Send String                                       
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel   ID of Uart channel                     
* \Parameters (out): void                                                      
* \Return value:   : char                                 
*******************************************************************************/
void Uart_SendString(Uart_ChannelType Channel, char *Str)
{
	uint8 i = 0;
	while (Str[i] != '\0')
	{
		Uart_SendChar(Channel, Str[i]);
		i++;
	}
}
/******************************************************************************
* \Syntax          : void Uart_SendString(Uart_ChannelType Channel,const sint8 *Str)       
* \Description     : Send String                                       
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel   ID of Uart channel                     
* \Parameters (out): void                                                      
* \Return value:   : char                               
*******************************************************************************/

void Uart_ReceiveString(Uart_ChannelType Channel, char *Str)
{
	uint8 i = 0;
	Str[i] = Uart_ReceiveChar(Channel);
	while (Str[i] != '#')
	{
		i++;
		Str[i] = Uart_ReceiveChar(Channel);
	}
	Str[i] = '\0';
}
/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
