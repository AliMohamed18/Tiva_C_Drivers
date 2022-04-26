#include "H_Bridge_Motor_Driver.h"
/*

void Move(uint8 Speed,uint8 Turn,uint8 Time)
{
    sint8 LeftSpeed	    =	Speed-Turn;
	sint8 RightSpeed	=	Speed+Turn;
		
	if 		    (LeftSpeed 	> 100) 		LeftSpeed=100;
	else if 	(LeftSpeed	< (-100))	LeftSpeed=-100;
	if 		    (RightSpeed > 100 )		RightSpeed=100;
	else if 	(RightSpeed	< (-100)) 	RightSpeed=-100;

    Pwm_SetDutyCycle(EnA,LeftSpeed);
    Pwm_SetDutyCycle(EnB,RightSpeed);
		
    if  (LeftSpeed  > 0)
	{
        Dio_WriteChannel(In1A,STD_low);
		Dio_WriteChannel(In2A,STD_high);
    }				
	else 
	{
        )
        Dio_WriteChannel(In1A,STD_high);
		Dio_WriteChannel(In2A,STD_low);	
    }			
			
	if  (RightSpeed	> 0	)
    {
	    Dio_WriteChannel(In1B,STD_low);
		Dio_WriteChannel(In2B,STD_high);
    }				
	else 
    {
		Dio_WriteChannel(In1B,STD_high);
		Dio_WriteChannel(In2B,STD_low);	
    }
}


				
	void  Stop(void)
    {
    Pwm_SetDutyCycle(EnA,0);
    Pwm_SetDutyCycle(EnB,0);
    }			

		
*/
