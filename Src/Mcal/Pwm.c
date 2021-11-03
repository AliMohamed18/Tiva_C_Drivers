/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Pwm.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Pwm.h"
#include "Pwm_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
static const uint32 Pwm_BaseAddress[2] = {
	PWM0_BASE_ADDRESS,
	PWM1_BASE_ADDRESS
};
static const uint32 GeneratorA_Offset[4] = {
	PWM0GENA_OFFSET,
	PWM1GENA_OFFSET,
	PWM2GENA_OFFSET,
	PWM3GENA_OFFSET
};
static const uint32 GeneratorB_Offset[4] = {
	PWM0GENB_OFFSET,
	PWM1GENB_OFFSET,
	PWM2GENB_OFFSET,
	PWM3GENB_OFFSET
};
static const uint32 LoadReg_Offset[4] = {
	PWM0LOAD_OFFSET,
	PWM1LOAD_OFFSET,
	PWM2LOAD_OFFSET,
	PWM3LOAD_OFFSET
};

static const uint32 CompareA_Offset[4] = {
	PWM0CMPA_OFFSET,
	PWM1CMPA_OFFSET,
	PWM2CMPA_OFFSET,
	PWM3CMPA_OFFSET
};
static const uint32 CompareB_Offset[4] = {
	PWM0CMPB_OFFSET,
	PWM1CMPB_OFFSET,
	PWM2CMPB_OFFSET,
	PWM3CMPB_OFFSET
};
static const uint32 PwmCtl_Offset[4] = {
	PWM0CTL_OFFSET,
	PWM1CTL_OFFSET,
	PWM2CTL_OFFSET,
	PWM3CTL_OFFSET
};

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
* \Syntax          : void Pwm_Init( const Pwm_ConfigType* ConfigPtr )        
* \Description     : Service for PWM initialization.                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr   Pointer to configuration set.                   
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Pwm_Init(const Pwm_ConfigType *ConfigPtr)
{
	Pwm_ChannelType Temp_PwmPin,TempPin,Gen_A_or_B;
	uint64 Temp_Freq,Load_Value,Duty;
	uint16 Temp_DutyCycle;
	uint8 Counter,Module,Generator;

	for (Counter = 0; Counter < NUMBER_OF_ACTIVATED_PWMS; Counter++)
	{
		Temp_PwmPin = ConfigPtr[Counter].PWMPIN;
		Temp_DutyCycle = ConfigPtr[Counter].DutyCycle;
		Temp_Freq=ConfigPtr[Counter].Freq;
		
		if          (Temp_PwmPin>8)                 		TempPin=Temp_PwmPin-8;
		else if     ((Temp_PwmPin<=8)&&(Temp_PwmPin>=0))    TempPin=Temp_PwmPin;
		
		if          (Temp_PwmPin%2==0)                 		Gen_A_or_B=GenA;
		else                                  				Gen_A_or_B=GenB;
		Module=Temp_PwmPin/8;
		Generator=TempPin/2;
		RCC.R &= ~0x00100000; /* no pre-divide for PWM clock */
		Load_Value=((SystemCoreClock / Temp_Freq)-1);
		Duty=(100-Temp_DutyCycle)*Load_Value/100;
		
		HwAccess(Pwm_BaseAddress[Module]+PwmCtl_Offset[Generator])=0; //Countdown
/*
For Generator A
the action to be taken when the counter matches the load value.					   -----> Drive pwmA High.
the action to be taken when the counter matches comparator A while counting down.  -----> Drive pwmA Low.
¦ Write the PWMnGENA register with a value of 0x0000.008C.

For Generator B 
the action to be taken when the counter matches the load value. 					----> Drive pwmB High.
the action to be taken when the counter matches comparator B while counting down. 	----> Drive pwmB Low.
¦ Write the PWMnGENB register with a value of 0x0000.080C.
*/		
		if (Gen_A_or_B==GenA)		HwAccess(Pwm_BaseAddress[Module]+GeneratorA_Offset[Generator])|=0x8C;
		else if (Gen_A_or_B==GenB)	HwAccess(Pwm_BaseAddress[Module]+GeneratorB_Offset[Generator])|=0x80C;
/*
Set the frequency. 
¦  Write the PWMnLOAD register with a value of ( Load Counter ).
*/
		HwAccess(Pwm_BaseAddress[Module]+LoadReg_Offset[Generator])|=Load_Value;
/*
Set the pulse width of the MnPWMn pin for a 25% duty cycle.
¦ Write the PWMnCMPn register with a value of ( Pwm Duty ).
*/
		
		if (Gen_A_or_B==GenA)		HwAccess(Pwm_BaseAddress[Module]+CompareA_Offset[Generator])=Duty;
		else if (Gen_A_or_B==GenB)	HwAccess(Pwm_BaseAddress[Module]+CompareB_Offset[Generator])=Duty;

/*
Start the timers in PWM generator 0.
¦ Write the PWMnCTL register 
*/
		HwAccess(Pwm_BaseAddress[Module]+PwmCtl_Offset[Generator])|=1; 

/*
Enable PWM outputs.
¦ Write the PWMENABLE register.
*/
		HwAccess(Pwm_BaseAddress[Module]+PWMENABLE_OFFSET)|=(1 << TempPin); 
	}

	
	
}


/******************************************************************************
* \Syntax          : void Pwm_SetDutyCycle( Pwm_ChannelType ChannelNumber, uint16 DutyCycle )       
* \Description     : Send Char                                                                             
* \Sync\Async      : Asynchronous                                               
* \Reentrancy      : Reentrant for different channel numbers                                             
* \Parameters (in) : ChannelNumber   Numeric identifier of the PWM
*					 DutyCycle
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/

void Pwm_SetDutyCycle( Pwm_ChannelType ChannelNumber, uint8 DutyCycle ){
		uint8 Counter,Module,Generator,TempPin,Gen_A_or_B;
		uint32 Load,Temp_Freq,Value;


		if          (ChannelNumber>8)                 			TempPin=ChannelNumber-8;
		else if     ((ChannelNumber<=8)&&(ChannelNumber>=0))    TempPin=ChannelNumber;
		
		if          (ChannelNumber%2==0)                 		Gen_A_or_B=GenA;
		else                                  					Gen_A_or_B=GenB;
		Module=ChannelNumber/8;
		Generator=TempPin/2;
		Temp_Freq=1000;

		Load=((SystemCoreClock / Temp_Freq)-1);
		Value=(100-DutyCycle)*Load/100;


		if (Gen_A_or_B==GenA)		HwAccess(Pwm_BaseAddress[Module]+CompareA_Offset[Generator])=Value;
		else if (Gen_A_or_B==GenB)	HwAccess(Pwm_BaseAddress[Module]+CompareB_Offset[Generator])=Value;



}
/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
