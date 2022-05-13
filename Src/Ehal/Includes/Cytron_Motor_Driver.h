/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Cytron_Motor_Driver.h
 *       Module:  Motor Driver
 *
 *  Description:  header file for Motor Module    
 *  
 *********************************************************************************************************************/
#ifndef CYTRON_MOTOR_DRIVER_H
#define CYTRON_MOTOR_DRIVER_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../Common/Std_Types.h"
#include "../../Common/Bit_Operations.h"
#include "../../Common/Mcu_Hw.h"

#include "../../Mcal/Includes/Dio.h"
#include "../../Mcal/Includes/Pwm.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
 
#define Back_Motor 0
#define Seat_Motor 1

#define Left_Motor 2
#define Right_Motor 3

#define Open  0
#define Close 1

#define Forward  0
#define Backward 1

#define MotorA Back_Motor
#define MotorB Seat_Motor

#define MotorC Left_Motor
#define MotorD Right_Motor


#define MotorA_Diriction_Pin Dio_Channel_D0
#define MotorB_Diriction_Pin Dio_Channel_F4

#define MotorC_Diriction_Pin Dio_Channel_B5
#define MotorD_Diriction_Pin Dio_Channel_B4


#define MotorA_Pwm_Pin       M1PWM6
#define MotorB_Pwm_Pin       M1PWM7

#define MotorC_Pwm_Pin       M0PWM0 
#define MotorD_Pwm_Pin       M0PWM1


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void Move(uint8 Motor ,char Diriction ,uint8 Speed )      
* \Description     : Start the motor at specified Diriction                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Motor   	Which Motor
					 Diriction  Which Dirication
					 Speed		Motor Speed From 1:255
* \Parameters (out): Void                                                      
* \Return value:   : Void                                 
*******************************************************************************/

 void Cytron_Move(uint8 Motor ,char Diriction ,uint8 Speed);

/******************************************************************************
* \Syntax          : void Stop(uint8 Motor)     
* \Description     : Stop the motor                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Motor   	Which Motor
* \Parameters (out): Void                                                      
* \Return value:   : Void                                 
*******************************************************************************/

 void Cytron_Stop(uint8 Motor);


#endif /* CYTRON_MOTOR_DRIVER_H */

/**********************************************************************************************************************
 *  END OF FILE: Cytron_Motor_Driver.h
 *********************************************************************************************************************/
