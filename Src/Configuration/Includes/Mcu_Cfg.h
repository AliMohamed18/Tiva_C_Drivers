/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Cfg.h
 *       Module:  -
 *
 *  Description:  MicroController Config.
 *  
 *********************************************************************************************************************/
#ifndef MCU_CFG_H
#define MCU_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Mcu_Types.h"
#include "Std_Types.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define NUMBER_OF_ACTIVATED_GATES 8
#define NUMBER_OF_ACTIVATED_CLOCK_MODE 6

#define	MCU_CLOCK_0			0
#define	MCU_CLOCK_1			1
#define	MCU_CLOCK_2			2
#define	MCU_CLOCK_3			3
#define	MCU_CLOCK_4			4
#define	MCU_CLOCK_5			5


#define MCU_GPIOA_ENABLE_CLOCK 1
#define MCU_GPIOB_ENABLE_CLOCK 1
#define MCU_GPIOC_ENABLE_CLOCK 1
#define MCU_GPIOD_ENABLE_CLOCK 1
#define MCU_GPIOE_ENABLE_CLOCK 1
#define MCU_GPIOF_ENABLE_CLOCK 1
#define MCU_GPIOA_ENABLE_CLOCK 1

#define MCU_WATCHDOG_0_ENABLE_CLOCK 1
#define MCU_WATCHDOG_1_ENABLE_CLOCK 1

#define MCU_16_32_BIT_GP_TIMER_0_ENABLE_CLOCK 1
#define MCU_16_32_BIT_GP_TIMER_1_ENABLE_CLOCK 1
#define MCU_16_32_BIT_GP_TIMER_2_ENABLE_CLOCK 1
#define MCU_16_32_BIT_GP_TIMER_3_ENABLE_CLOCK 1
#define MCU_16_32_BIT_GP_TIMER_4_ENABLE_CLOCK 1
#define MCU_16_32_BIT_GP_TIMER_5_ENABLE_CLOCK 1

#define MCU_DMA_ENABLE_CLOCK 1

#define MCU_HIBERNATION_MODE_ENABLE_CLOCK 1

#define MCU_UART_0_ENABLE_CLOCK 1
#define MCU_UART_1_ENABLE_CLOCK 1
#define MCU_UART_2_ENABLE_CLOCK 1
#define MCU_UART_3_ENABLE_CLOCK 1
#define MCU_UART_4_ENABLE_CLOCK 1
#define MCU_UART_5_ENABLE_CLOCK 1
#define MCU_UART_6_ENABLE_CLOCK 1
#define MCU_UART_7_ENABLE_CLOCK 1

#define MCU_SSI_0_ENABLE_CLOCK 1
#define MCU_SSI_1_ENABLE_CLOCK 1
#define MCU_SSI_2_ENABLE_CLOCK 1
#define MCU_SSI_3_ENABLE_CLOCK 1

#define MCU_I2C_0_ENABLE_CLOCK 1
#define MCU_I2C_1_ENABLE_CLOCK 1
#define MCU_I2C_2_ENABLE_CLOCK 1
#define MCU_I2C_3_ENABLE_CLOCK 1

#define MCU_USB_ENABLE_CLOCK 1

#define MCU_CAN_0_ENABLE_CLOCK 1
#define MCU_CAN_1_ENABLE_CLOCK 1

#define MCU_ADC_0_ENABLE_CLOCK 1
#define MCU_ADC_1_ENABLE_CLOCK 1

#define MCU_ANALOG_COMPARATOR_ENABLE_CLOCK 1

#define MCU_PWM_0_ENABLE_CLOCK 1
#define MCU_PWM_1_ENABLE_CLOCK 1

#define MCU_QEI_0_ENABLE_CLOCK 1
#define MCU_QEI_1_ENABLE_CLOCK 1

#define MCU_EEPROM_ENABLE_CLOCK 1




/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/



#endif  /* MCU_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Cfg.h
 *********************************************************************************************************************/
