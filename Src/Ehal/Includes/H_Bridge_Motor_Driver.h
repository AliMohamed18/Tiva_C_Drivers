/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Uart.h
 *       Module:  Uart
 *
 *  Description:  header file for Uart Module    
 *  
 *********************************************************************************************************************/
#ifndef MOTOR_H
#define MOTOR_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../Common/Std_Types.h"
#include "../Common/Mcu_Hw.h"
#include "../Common/Bit_Operations.h"
#include "../Mcal/Includes/Dio.h"
#include "../Mcal/Includes/Pwm.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
typedef struct
{
	uint8 EnA ;
    uint8 In1A;
    uint8 In1B;
    uint8 EnB ;
    uint8 In2A;
    uint8 In2B;

} Motor_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
void Move(uint8 Speed,uint8 Turn,uint8 Time);
void Stop(void);


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* MOTOR_H */

/**********************************************************************************************************************
 *  END OF FILE: MOTOR_H
 *********************************************************************************************************************/
