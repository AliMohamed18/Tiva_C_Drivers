#include "Includes/Cytron_Motor_Driver.h"
/* 
PWM		DIR		 OUT A	 OUT B
 0	 	 x		 Low	 Low		
 1		 0		 High	 Low
 1		 1		 Low	 High
 */
 
 /******************************************************************************
* \Syntax          : void Move(uint8 Motor ,char Diriction ,uint8 Speed       
* \Description     : Start the motor at specified Diriction                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Motor   	Which Motor
					 Diriction  Which Dirication
					 Speed		Motor Speed From 1:255
* \Parameters (out): Void                                                      
* \Return value:   : Void                                 
*******************************************************************************/
 void Cytron_Move(uint8 Motor ,char Diriction ,uint8 Speed)
{
	uint8 Motor_Diriction_Pin,Motor_Pwm_Pin,DutyCyc;

	DutyCyc =((255)/(100))*(Speed);

	
	if(Motor==MotorA)
	{
		Motor_Diriction_Pin=	MotorA_Diriction_Pin;
		Motor_Pwm_Pin=			MotorA_Pwm_Pin;
	}
	else if(Motor==MotorB)
	{
		Motor_Diriction_Pin=	MotorB_Diriction_Pin;
		Motor_Pwm_Pin=			MotorB_Pwm_Pin;
	}
	else if(Motor==MotorC)
	{
		Motor_Diriction_Pin=	MotorC_Diriction_Pin;
		Motor_Pwm_Pin=			MotorC_Pwm_Pin;
	}
	else if(Motor==MotorD)
	{
		Motor_Diriction_Pin=	MotorD_Diriction_Pin;
		Motor_Pwm_Pin=			MotorD_Pwm_Pin;
	}	
	else return;
	
		
	if (Diriction == Open)
	{
		Dio_WriteChannel(Motor_Diriction_Pin,STD_low);
		Pwm_SetDutyCycle(Motor_Pwm_Pin,DutyCyc);
	}
	else if (Diriction == Close)
	{
		Dio_WriteChannel(Motor_Diriction_Pin,STD_high);
		Pwm_SetDutyCycle(Motor_Pwm_Pin,DutyCyc);
	}
	else return;

}	

/******************************************************************************
* \Syntax          : void Stop(uint8 Motor)     
* \Description     : Stop the motor                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Motor   	Which Motor
* \Parameters (out): Void                                                      
* \Return value:   : Void                                 
*******************************************************************************/

				
void Cytron_Stop(uint8 Motor)
{
	uint8 Motor_Pwm_Pin;
	
	if		(Motor==MotorA)      Motor_Pwm_Pin=MotorA_Pwm_Pin;
	else if (Motor==MotorB)      Motor_Pwm_Pin=MotorB_Pwm_Pin;
	else if (Motor==MotorC)      Motor_Pwm_Pin=MotorC_Pwm_Pin;
	else if (Motor==MotorD)      Motor_Pwm_Pin=MotorD_Pwm_Pin;

	else return;


	Pwm_SetDutyCycle(Motor_Pwm_Pin,0);

}			

