#include "Includes/VNH_Motor_Driver.h"

 
/******************************************************************************
* \Syntax          : void Motor_Driver_Move(char Diriction ,uint8 Speed);    
* \Description     : Start the motor at specified Diriction                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Diriction  Which Dirication
					 Speed		Motor Speed From 1:255
* \Parameters (out): Void                                                      
* \Return value:   : Void                                 
*******************************************************************************/
 void VNH_Motor_Driver_Move(char Diriction ,uint8 Speed)
{
	Pwm_SetDutyCycle(Motor_Pwm_Pin,Speed);
	
	if (Diriction == Open)
	{
		Dio_WriteChannel(Motor_DirictionA_Pin,STD_low);
		Dio_WriteChannel(Motor_DirictionB_Pin,STD_high);
	}
	else if (Diriction == Close)
	{
		Dio_WriteChannel(Motor_DirictionA_Pin,STD_high);
		Dio_WriteChannel(Motor_DirictionB_Pin,STD_low);
	}
	else return;

}	
/******************************************************************************
* \Syntax          : void Motor_Driver_Stop(void);    
* \Description     : Stop the motor                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Void
* \Parameters (out): Void                                                      
* \Return value:   : Void                                 
*******************************************************************************/
				
void VNH_Motor_Driver_Stop(void)
{
	Pwm_SetDutyCycle(Motor_Pwm_Pin,0);
}			

