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
 extern const Interrupt_CfgType  Interrupt_Groups[];

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
uint8 Counter , PRIGROUP_CHOICE , Group_Temp , SubGroup_Temp , Interrupt_Number_Temp ,Grouping_Field	;
uint32 priRegOffset	,priBitOffset;
	
APINT.B.VECTKEY=APINT_VECTKEY; 					 // Field Guard
APINT.B.ENDIANESS=STD_low;							 //Little-Endian Mode
for(Counter=0 ;Counter < NUM_OF_ACTIVATED_GROUPS;Counter++){
	
Interrupt_Number_Temp = Interrupt_Groups[Counter].Interrupt_Number;	
Group_Temp = Interrupt_Groups[Counter].Group_Priority;
SubGroup_Temp =	Interrupt_Groups[Counter].SubGroup_Priority;

	
#if   ( GROUPING_SYSTEM == 1)
	
	PRIGROUP_CHOICE = XXX;
	Grouping_Field=Group_Temp ;
	
#elif ( GROUPING_SYSTEM == 2)
	
	PRIGROUP_CHOICE = XXY;
	Grouping_Field=(((Group_Temp<<1)&(0x6))|((SubGroup_Temp)&(0x1)));

#elif ( GROUPING_SYSTEM == 3)
	
	PRIGROUP_CHOICE = XYY;	
	Grouping_Field=(((Group_Temp<<2)&(0x4))|((SubGroup_Temp)&(0x3)));	

#elif ( GROUPING_SYSTEM == 4)
	
	PRIGROUP_CHOICE = YYY;		
	Grouping_Field= SubGroup_Temp ;

#endif

APINT.B.PRIGROUP = PRIGROUP_CHOICE;        //The Split Of Group Priority From Subpriority

if	   (Interrupt_Number_Temp == 0	 || Interrupt_Number_Temp < 32  )  SET(EN0,(Interrupt_Number_Temp));
else if(Interrupt_Number_Temp >= 32  &&	Interrupt_Number_Temp < 64  )  SET(EN1,(Interrupt_Number_Temp-32));
else if(Interrupt_Number_Temp >= 64  &&	Interrupt_Number_Temp < 96  )  SET(EN2,(Interrupt_Number_Temp-64));
else if(Interrupt_Number_Temp >= 96  &&	Interrupt_Number_Temp < 128 )  SET(EN3,(Interrupt_Number_Temp-96));
else if(Interrupt_Number_Temp >= 128 &&	Interrupt_Number_Temp <= 138)  SET(EN4,(Interrupt_Number_Temp-128));

			priRegOffset = (Interrupt_Number_Temp/4)*32;
			priBitOffset = 5 + (8 * (Interrupt_Number_Temp%4));
			(*((volatile uint32*)(NVIC_PRIX_BASE_ADDRESS + priRegOffset  ))) |= ((uint8)(Grouping_Field << priBitOffset));
}
	
}
/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
