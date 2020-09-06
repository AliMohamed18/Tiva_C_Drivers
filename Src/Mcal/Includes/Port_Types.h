/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Types.h
 *       Module:  -
 *
 *  Description:  <Port Types Header>     
 *  
 *********************************************************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
typedef enum
{
	Input,
	Output
}Port_PinDirectionType;

typedef enum
{
PA0,
PA1,
PA2,
PA3,
PA4,
PA5,
PA6,
PA7,

PB0,
PB1,
PB2,
PB3,
PB4,
PB5,
PB6,
PB7,

PC0,
PC1,
PC2,
PC3,
PC4,
PC5,
PC6,
PC7,

PD0,
PD1,
PD2,
PD3,
PD4,
PD5,
PD6,
PD7,
	
PE0,
PE1,
PE2,
PE3,
PE4,
PE5,	
	
PF0,
PF1,
PF2,
PF3,
PF4	
}Port_PinType;

typedef enum
{
	DEFAULT,
	PULLUP,
	PULLDOWN,
	OPENDRAIN
}Port_PinInternalAttachType;

typedef enum
{
/********************************************************	PORTA	********************************************************/	
A0_U0Rx,
A0_CAN1Rx,
A0_DIO,	

A1_U0Tx,
A1_CAN1Tx,
A1_DIO,	

A2_SSI0Clk,
A2_DIO,	
	
A3_SSI0Fss,	
A3_DIO,	
	
A4_SSI0Rx,
A4_DIO,	

A5_SSI0Tx,
A5_DIO,	
	
A6_I2C1SCL,
A6_M1PWM2,	
A6_DIO,	
	
A7_I2C1SDA,
A7_M1PWM3,	
A7_DIO,	
/********************************************************	PORTB	********************************************************/	
B0_USB0ID,
B0_U1Rx,
B0_T2CCP0,
B0_DIO,

B1_USB0VBUS,
B1_U1Tx,
B1_T2CCP1,
B1_DIO,

B2_I2C0SCL,
B2_T3CCP0,
B2_DIO,

B3_I2C0SDA,
B3_T3CCP1,
B3_DIO,

B4_AIN10,
B4_SSI2Clk,
B4_M0PWM2,
B4_T1CCP0,
B4_CAN0Rx,
B4_DIO,

B5_AIN11,
B5_SSI2Fss,
B5_M0PWM3,
B5_T1CCP1,
B5_CAN0Tx,
B5_DIO,

B6_SSI2Rx,
B6_M0PWM0,
B6_T0CCP0,
B6_DIO,
	
B7_SSI2Tx,
B7_M0PWM1,
B7_T0CCP1,
B7_DIO,
/********************************************************	PORTC	********************************************************/	
C0_TCK_SWCLK,
C0_T4CCP0,
C0_DIO,

C1_TMS_SWDIO,
C1_T4CCP1,
C1_DIO,

C2_TDI,
C2_T5CCP0,
C2_DIO,

C3_TDO_SWO,
C3_T5CCP1,
C3_DIO,

C4_C1Neg,
C4_U4Rx,
C4_U1Rx,
C4_M0PWM6,
C4_IDX1,
C4_WT0CCP0,
C4_U1RTS,
C4_DIO,

C5_C1Pos,
C5_U4Tx,
C5_U1Tx,
C5_M0PWM7,
C5_PhA1,
C5_WT0CCP1,
C5_U1CTS,
C5_DIO,

C6_C0Pos,
C6_U3Rx,
C6_PhB1,
C6_WT1CCP0,
C6_USB0EPEN,
C6_DIO,

C7_C0Neg,
C7_U3Tx,
C7_WT1CCP1,
C7_USB0PFLT,
C7_DIO,
/********************************************************	PORTD	********************************************************/	
D0_AIN7,
D0_SSI3Clk,
D0_SSI1Clk,
D0_I2C3SCL,
D0_M0PWM6,
D0_M1PWM0,
D0_WT2CCP0,
D0_DIO,

D1_AIN6,
D1_SSI3Fss,
D1_SSI1Fss,
D1_I2C3SDA,
D1_M0PWM7,
D1_M1PWM1,
D1_WT2CCP1,
D1_DIO,

D2_AIN5,
D2_SSI3Rx,
D2_SSI1Rx,
D2_M0FAULT0,
D2_WT3CCP0,
D2_USB0EPEN,
D2_DIO,

D3_AIN4,
D3_SSI3Tx,
D3_SSI1Tx,
D3_IDX0,
D3_WT3CCP1,
D3_USB0PFLT,
D3_DIO,

D4_USB0DM,
D4_U6Rx,
D4_WT4CCP0,
D4_DIO,

D5_USB0DP,
D5_U6Tx,
D5_WT4CCP1,
D5_DIO,

D6_U2Rx,
D6_M0FAULT0,
D6_PhA0,
D6_WT5CCP0,
D6_DIO,

D7_U2Tx,
D7_PhB0,
D7_WT5CCP1,
D7_NMI,
D7_DIO,
/********************************************************	PORTE	********************************************************/	
E0_AIN3,
E0_U7Rx,
E0_DIO,

E1_AIN2,
E1_U7Tx,
E1_DIO,

E2_AIN1,
E2_DIO,

E3_AIN0,
E3_DIO,

E4_AIN9,
E4_U5Rx,
E4_I2C2SCL,
E4_M0PWM4,
E4_M1PWM2,
E4_CAN0Rx,
E4_DIO,

E5_AIN8,
E5_U5Tx,
E5_I2C2SDA,
E5_M0PWM5,
E5_M1PWM3,
E5_CAN0Tx,
E5_DIO,
/********************************************************	PORTF	********************************************************/	
F0_U1RTS,
F0_SSI1Rx,
F0_CAN0Rx,
F0_M1PWM4,
F0_PhA0,
F0_T0CCP0,
F0_NMI,
F0_C0o,
F0_DIO,

F1_U1CTS,
F1_SSI1Tx,
F1_M1PWM5,
F1_PhB0,
F1_T0CCP1,
F1_C1o,
F1_TRD1,
F1_DIO,

F2_SSI1Clk,
F2_M0FAULT0,
F2_M1PWM6,
F2_T1CCP0,
F2_TRD0,
F2_DIO,

F3_SSI1Fss,
F3_CAN0Tx,
F3_M1PWM7,
F3_T1CCP1,
F3_TRCLK,
F3_DIO,

F4_M1FAULT0,
F4_IDX0,
F4_T2CCP0,
F4_USB0EPEN,
F4_DIO,
}Port_PinModeType;

typedef enum
{
	CURRENT_NA,
	CURRENT_2M,
	CURRENT_4M,
	CURRENT_8M
}Port_PinOutputCurrentType;



typedef struct{

	Port_PinType Pin;
	Port_PinDirectionType Dir;
	Port_PinModeType Mode;
	Port_PinInternalAttachType Attach;
	Port_PinOutputCurrentType OutputCurr;
}Port_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/





#endif  /* PORT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Types.h
 *********************************************************************************************************************/
