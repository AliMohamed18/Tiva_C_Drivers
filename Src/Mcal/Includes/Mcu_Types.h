/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Types.h
 *       Module:  -
 *
 *  Description:  <MicroController Types Header>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../Common/Std_Types.h"
#include "../../Configuration/Includes/Mcu_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


typedef enum {
	MCU_CLOCK_SOURCE_MOSC	=	0x0			,
	MCU_CLOCK_SOURCE_PIOSC			 	,
	MCU_CLOCK_SOURCE_PIOSC_DIV_4  ,
	MCU_CLOCK_SOURCE_LFIOSC			
}Mcu_ClockSourceType;

typedef uint32 Mcu_FreqType; 

typedef enum {
 MCU_GPIOA_ENABLE_CLOCK ,
 MCU_GPIOB_ENABLE_CLOCK ,
 MCU_GPIOC_ENABLE_CLOCK ,
 MCU_GPIOD_ENABLE_CLOCK ,
 MCU_GPIOE_ENABLE_CLOCK ,
 MCU_GPIOF_ENABLE_CLOCK ,
	
MCU_WATCHDOG_0_ENABLE_CLOCK ,
MCU_WATCHDOG_1_ENABLE_CLOCK ,

MCU_16_32_BIT_GP_TIMER_0_ENABLE_CLOCK ,
MCU_16_32_BIT_GP_TIMER_1_ENABLE_CLOCK ,
MCU_16_32_BIT_GP_TIMER_2_ENABLE_CLOCK ,
MCU_16_32_BIT_GP_TIMER_3_ENABLE_CLOCK ,
MCU_16_32_BIT_GP_TIMER_4_ENABLE_CLOCK ,
MCU_16_32_BIT_GP_TIMER_5_ENABLE_CLOCK ,

MCU_DMA_ENABLE_CLOCK ,

MCU_HIBERNATION_MODE_ENABLE_CLOCK ,

MCU_UART_0_ENABLE_CLOCK ,
MCU_UART_1_ENABLE_CLOCK ,
MCU_UART_2_ENABLE_CLOCK ,
MCU_UART_3_ENABLE_CLOCK ,
MCU_UART_4_ENABLE_CLOCK ,
MCU_UART_5_ENABLE_CLOCK ,
MCU_UART_6_ENABLE_CLOCK ,
MCU_UART_7_ENABLE_CLOCK ,

 MCU_SSI_0_ENABLE_CLOCK ,
 MCU_SSI_1_ENABLE_CLOCK ,
 MCU_SSI_2_ENABLE_CLOCK ,
 MCU_SSI_3_ENABLE_CLOCK ,

 MCU_I2C_0_ENABLE_CLOCK ,
 MCU_I2C_1_ENABLE_CLOCK ,
 MCU_I2C_2_ENABLE_CLOCK ,
 MCU_I2C_3_ENABLE_CLOCK ,

 MCU_USB_ENABLE_CLOCK ,

 MCU_CAN_0_ENABLE_CLOCK ,
 MCU_CAN_1_ENABLE_CLOCK ,

 MCU_ADC_0_ENABLE_CLOCK ,
 MCU_ADC_1_ENABLE_CLOCK ,

 MCU_ANALOG_COMPARATOR_ENABLE_CLOCK ,

 MCU_PWM_0_ENABLE_CLOCK ,
 MCU_PWM_1_ENABLE_CLOCK ,

 MCU_QEI_0_ENABLE_CLOCK ,
 MCU_QEI_1_ENABLE_CLOCK ,

 MCU_EEPROM_ENABLE_CLOCK 

}Mcu_GatesType;

typedef uint8 Mcu_RawResetType ;
typedef enum{ 
	
	PLL_NOT_USED=0,
	PLL_USED

}Mcu_PllStatusType ;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/



typedef struct{
	Mcu_ClockSourceType CLOCK_SOURCE ;
	Mcu_PllStatusType PLL_STATE ;
	Mcu_FreqType CLOCK_FREQ   ;
}Mcu_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/





#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
