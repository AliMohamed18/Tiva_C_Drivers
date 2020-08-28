/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl.h"


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

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


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{
uint8 Counter , Group_Temp , SubGroup_Temp , Interrupt_Number_Temp ;
	
APINT.B.VECTKEY=APINT_VECTKEY; 					 // Field Guard
APINT.B.ENDIANESS=STD_low;							 //Little-Endian Mode
	
#if   ( GROUPING_SYSTEM == 1)
	
PRIGROUP_CHOICE = XXX;
	
#elif ( GROUPING_SYSTEM == 2)
	
PRIGROUP_CHOICE = XXY;	
	
#elif ( GROUPING_SYSTEM == 3)
	
PRIGROUP_CHOICE = XYY;	
	
#elif ( GROUPING_SYSTEM == 4)
	
PRIGROUP_CHOICE = YYY;		
	
#endif

APINT.B.PRIGROUP = PRIGROUP_CHOICE;        //The Split Of Group Priority From Subpriority

for(Counter=0 ;Counter < NUMBER_OF_ACTIVATED_GRPUPS;Counter++){
	
Interrupt_Number_Temp = Interrupt_Groups[Counter].Interrupt_Number;	
Group_Temp = Interrupt_Groups[Counter].Group_Priority;
SubGroup_Temp =	Interrupt_Groups[Counter].SubGroup_Priority;
	/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
if	   (Interrupt_Number_Temp == 0	 || Interrupt_Number_Temp < 32  )  SET(EN0,(Interrupt_Number_Temp));
else if(Interrupt_Number_Temp >= 32  &&	Interrupt_Number_Temp < 64  )  SET(EN1,(Interrupt_Number_Temp-32));
else if(Interrupt_Number_Temp >= 64  &&	Interrupt_Number_Temp < 96  )  SET(EN2,(Interrupt_Number_Temp-64));
else if(Interrupt_Number_Temp >= 96  &&	Interrupt_Number_Temp < 128 )  SET(EN3,(Interrupt_Number_Temp-96));
else if(Interrupt_Number_Temp >= 128 &&	Interrupt_Number_Temp <= 138)  SET(EN4,(Interrupt_Number_Temp-128));

	
	

	
	
  /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  
}
}
/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
