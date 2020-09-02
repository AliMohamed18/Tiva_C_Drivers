/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Mcu.c
 *        \brief  MicroController Driver
 *
 *      \details  The Driver Configure All MCU Clock and Reset 
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Mcu.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
 
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static const Mcu_ConfigType* Mcu_Config  ;

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
* \Syntax          : void Mcu_Init ( const Mcu_ConfigType* ConfigPtr )        
* \Description     :  initializes the MCU driver.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr       Pointer to MCU  configuration set.                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void Mcu_Init ( const Mcu_ConfigType* ConfigPtr ){

   Mcu_Config = ConfigPtr; 

}
/******************************************************************************
* \Syntax          : Std_ReturnType Mcu_InitClock( Mcu_ClockSourceType ClockSetting );        
* \Description     :  initializes MCU clock source  .                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ClockSetting                            
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType 
*******************************************************************************/
Std_ReturnType Mcu_InitClock( Mcu_ClockType ClockSetting ){
	uint8 Counter =0 , Gate_Temp=0 ;	
Std_ReturnType State= E_NOT_OK;

	
if(Mcu_Config[ClockSetting].CLOCK_SOURCE==MCU_CLOCK_SOURCE_MOSC){
	RCC.B.MOSCDIS=0;
	RCC.B.OSCSRC=0x0;
}
else if (Mcu_Config[ClockSetting].CLOCK_SOURCE==MCU_CLOCK_SOURCE_PIOSC) 				RCC.B.OSCSRC=0x1;
else if (Mcu_Config[ClockSetting].CLOCK_SOURCE==MCU_CLOCK_SOURCE_PIOSC_DIV_4) 	RCC.B.OSCSRC=0x2;
else if (Mcu_Config[ClockSetting].CLOCK_SOURCE==MCU_CLOCK_SOURCE_LFIOSC) 				RCC.B.OSCSRC=0x3;

if(Mcu_Config[ClockSetting].PLL_STATE==PLL_POWERED_AND_LOCKED)
{
RCC2.B.USERCC2=1; // Use RCC2
RCC.B.XTAL=0x15;  // FeedBack 
RCC2.B.BYPASS2=0; // To Use DIV400	
RCC2.B.DIV400=0;  // use 200 Mhz
RCC.B.BYPASS=0;	
	
if (Mcu_Config[ClockSetting].CLOCK_FREQ==MCU_CLOCK_FREQ_8){
RCC.B.SYSDIV=7;
RCC.B.USESYSDIV=1;	
}	

else if (Mcu_Config[ClockSetting].CLOCK_FREQ==MCU_CLOCK_FREQ_16){
RCC.B.SYSDIV=11;
RCC.B.USESYSDIV=1;	
}

else if (Mcu_Config[ClockSetting].CLOCK_FREQ==MCU_CLOCK_FREQ_40){
RCC.B.SYSDIV=4;
RCC.B.USESYSDIV=1;	
}

else if (Mcu_Config[ClockSetting].CLOCK_FREQ==MCU_CLOCK_FREQ_80){
RCC.B.SYSDIV=1;
RCC.B.USESYSDIV=1;	
}
}
else if(Mcu_Config[ClockSetting].PLL_STATE==PLL_UNPOWERED_OR_NOT_LOCKED_YET)
{
RCC.B.BYPASS=1;
	
if (Mcu_Config[ClockSetting].CLOCK_FREQ==MCU_CLOCK_FREQ_8){
RCC.B.SYSDIV=1;
RCC.B.USESYSDIV=1;	
}

else if (Mcu_Config[ClockSetting].CLOCK_FREQ==MCU_CLOCK_FREQ_16){
RCC.B.USESYSDIV=0;	
}
}
State=Mcu_GetPllStatus();


/****************************************Enable Gates****************************************/
for(Counter=0;Counter<NUMBER_OF_ACTIVATED_GATES;Counter++){
	Gate_Temp= MCU_ACTIVATED_GATES[Counter];
	if		 (Gate_Temp==MCU_GPIOA_ENABLE_CLOCK)RCGCGPIO.B.R0=1;
	else if(Gate_Temp==MCU_GPIOB_ENABLE_CLOCK)RCGCGPIO.B.R1=1;
	else if(Gate_Temp==MCU_GPIOC_ENABLE_CLOCK)RCGCGPIO.B.R2=1;
	else if(Gate_Temp==MCU_GPIOD_ENABLE_CLOCK)RCGCGPIO.B.R3=1;
	else if(Gate_Temp==MCU_GPIOE_ENABLE_CLOCK)RCGCGPIO.B.R4=1;
	else if(Gate_Temp==MCU_GPIOF_ENABLE_CLOCK)RCGCGPIO.B.R5=1;
	
	else if(Gate_Temp==MCU_WATCHDOG_0_ENABLE_CLOCK)RCGCWD.B.R0=1;
	else if(Gate_Temp==MCU_WATCHDOG_1_ENABLE_CLOCK)RCGCWD.B.R1=1;
	
	else if(Gate_Temp==MCU_16_32_BIT_GP_TIMER_0_ENABLE_CLOCK)RCGCTIMER.B.R0=1;
	else if(Gate_Temp==MCU_16_32_BIT_GP_TIMER_1_ENABLE_CLOCK)RCGCTIMER.B.R1=1;
	else if(Gate_Temp==MCU_16_32_BIT_GP_TIMER_2_ENABLE_CLOCK)RCGCTIMER.B.R2=1;
	else if(Gate_Temp==MCU_16_32_BIT_GP_TIMER_3_ENABLE_CLOCK)RCGCTIMER.B.R3=1;
	else if(Gate_Temp==MCU_16_32_BIT_GP_TIMER_4_ENABLE_CLOCK)RCGCTIMER.B.R4=1;
	else if(Gate_Temp==MCU_16_32_BIT_GP_TIMER_5_ENABLE_CLOCK)RCGCTIMER.B.R5=1;

	else if(Gate_Temp==MCU_DMA_ENABLE_CLOCK)RCGCDMA.B.R0=1;
	
	else if(Gate_Temp==MCU_HIBERNATION_MODE_ENABLE_CLOCK)RCGCHIB.B.R0=1;
	
	else if(Gate_Temp==MCU_UART_0_ENABLE_CLOCK)RCGCUART.B.R0=1;
	else if(Gate_Temp==MCU_UART_1_ENABLE_CLOCK)RCGCUART.B.R1=1;
	else if(Gate_Temp==MCU_UART_2_ENABLE_CLOCK)RCGCUART.B.R2=1;
	else if(Gate_Temp==MCU_UART_3_ENABLE_CLOCK)RCGCUART.B.R3=1;
	else if(Gate_Temp==MCU_UART_4_ENABLE_CLOCK)RCGCUART.B.R4=1;
	else if(Gate_Temp==MCU_UART_5_ENABLE_CLOCK)RCGCUART.B.R5=1;
	else if(Gate_Temp==MCU_UART_6_ENABLE_CLOCK)RCGCUART.B.R6=1;
	else if(Gate_Temp==MCU_UART_7_ENABLE_CLOCK)RCGCUART.B.R7=1;


	else if(Gate_Temp==MCU_SSI_0_ENABLE_CLOCK)RCGCSSI.B.R0=1;
	else if(Gate_Temp==MCU_SSI_1_ENABLE_CLOCK)RCGCSSI.B.R1=1;
	else if(Gate_Temp==MCU_SSI_2_ENABLE_CLOCK)RCGCSSI.B.R2=1;
	else if(Gate_Temp==MCU_SSI_3_ENABLE_CLOCK)RCGCSSI.B.R3=1;
	
	else if(Gate_Temp==MCU_I2C_0_ENABLE_CLOCK)RCGCI2C.B.R0=1;
	else if(Gate_Temp==MCU_I2C_1_ENABLE_CLOCK)RCGCI2C.B.R1=1;
	else if(Gate_Temp==MCU_I2C_2_ENABLE_CLOCK)RCGCI2C.B.R2=1;
	else if(Gate_Temp==MCU_I2C_3_ENABLE_CLOCK)RCGCI2C.B.R3=1;
	
	else if(Gate_Temp==MCU_USB_ENABLE_CLOCK)RCGCUSB.B.R0=1;
	
	else if(Gate_Temp==MCU_CAN_0_ENABLE_CLOCK)RCGCCAN.B.R0=1;
	else if(Gate_Temp==MCU_CAN_1_ENABLE_CLOCK)RCGCCAN.B.R1=1;
	
	else if(Gate_Temp==MCU_ADC_0_ENABLE_CLOCK)RCGCADC.B.R0=1;
	else if(Gate_Temp==MCU_ADC_1_ENABLE_CLOCK)RCGCADC.B.R1=1;
	
	else if(Gate_Temp==MCU_ANALOG_COMPARATOR_ENABLE_CLOCK)RCGCACMP.B.R0=1;
	
	else if(Gate_Temp==MCU_PWM_0_ENABLE_CLOCK)RCGCPWM.B.R0=1;
	else if(Gate_Temp==MCU_PWM_1_ENABLE_CLOCK)RCGCPWM.B.R1=1;	
	
	else if(Gate_Temp==MCU_QEI_0_ENABLE_CLOCK)RCGCQEI.B.R0=1;
	else if(Gate_Temp==MCU_QEI_1_ENABLE_CLOCK)RCGCQEI.B.R1=1;	

	else if(Gate_Temp==MCU_EEPROM_ENABLE_CLOCK)RCGCEEPROM.B.R0=1;	

}
/********************************************************************************************/


return State;
}
	



/******************************************************************************
* \Syntax          : Mcu_RawResetType Mcu_GetResetRawValue(void)                                      
* \Description     : Why The Reseet Occured ?                                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): none                                                      
* \Return value:   : uint8
*******************************************************************************/
Mcu_RawResetType Mcu_GetResetRawValue(void){
	
Mcu_RawResetType ResetRawValue=0;

if      (RESC.B.WDT0		==1) ResetRawValue=WATCHDOG_TIMER_0_RESET;
else if	(RESC.B.WDT1		==1) ResetRawValue=WATCHDOG_TIMER_1_RESET;
else if	(RESC.B.SW  		==1) ResetRawValue=SOFTWARE_RESET;
else if	(RESC.B.BOR 		==1) ResetRawValue=BROWN_OUT_RESET;
else if	(RESC.B.POR 		==1) ResetRawValue=POWER_ON_RESET;
else if	(RESC.B.EXT 		==1) ResetRawValue=EXTERNAL_RESET;
else if	(RESC.B.MOSCFAIL==1) ResetRawValue=MOSC_CIRCUIT_FAIL_RESET;	
	
	return ResetRawValue;
}

/******************************************************************************
* \Syntax          : void Mcu_PerformReset(void)                                      
* \Description     : Perform Reset                                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): none                                                      
* \Return value:   : none
*******************************************************************************/
void Mcu_PerformReset(void){
	
APINT.B.VECTKEY=APINT_VECTKEY;
APINT.B.SYSRESREQ=1;

}

/******************************************************************************
* \Syntax          : Mcu_PllStatusType Mcu_GetPllStatus(void)
* \Description     : Get Pll State                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): none                                                      
* \Return value:   : Mcu_PllStatusType
*******************************************************************************/
Mcu_PllStatusType Mcu_GetPllStatus(void){

Mcu_PllStatusType PLL_STATE =0;
	
if(PLLSTAT.B.LOCK==0)	PLL_STATE=PLL_UNPOWERED_OR_NOT_LOCKED_YET;
else 	PLL_STATE=PLL_POWERED_AND_LOCKED;
	
return	PLL_STATE;

}
	

/******************************************************************************
* \Syntax          : Std_ReturnType Mcu_DistributePllClock( void )        
* \Description     : This service activates the PLL clock to the MCU clock distribution.                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                            
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType 
*******************************************************************************/
Std_ReturnType Mcu_DistributePllClock(void)
{
	Std_ReturnType State = 0 ;
	if(RCC.B.PWRDN == 0)
	{
			if(Mcu_GetPllStatus() == PLL_POWERED_AND_LOCKED)
			{
				RCC.B.BYPASS = 1;
				State = E_OK;
			}
	}
	else State = E_NOT_OK;
	return State;
}


	
/**********************************************************************************************************************
 *  END OF FILE: Mcu.c
 *********************************************************************************************************************/
