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
uint8 Counter , Group_Temp , SubGroup_Temp , Interrupt_Number_Temp ,Grouping_Field	;
uint32 priRegOffset	,priBitOffset , enRegOffset ,enBitOffset;
	
APINT.B.VECTKEY=APINT_VECTKEY; 					 // Field Guard
APINT.B.ENDIANESS=STD_low;							 //Little-Endian Mode
	
	
APINT.B.PRIGROUP = GROUPING_SYSTEM;      //The Split Of Group Priority From Subpriority
	
for(Counter=0 ;Counter < NUM_OF_ACTIVATED_GROUPS;Counter++){
	
Interrupt_Number_Temp = Interrupt_Groups[Counter].Interrupt_Number;	
Group_Temp = Interrupt_Groups[Counter].Group_Priority;
SubGroup_Temp =	Interrupt_Groups[Counter].SubGroup_Priority;
	
// NVIC EN REG 
	
enRegOffset = (Interrupt_Number_Temp/32)*4;
enBitOffset = Interrupt_Number_Temp%32;
	
(*((volatile uint32*)(NVIC_ENX_BASE_ADDRESS + enRegOffset  )))|= (1 << enBitOffset);
	
#if   ( GROUPING_SYSTEM == GROUPING_SYSTEM_XXX)
	
	Grouping_Field=Group_Temp ;
	
#elif ( GROUPING_SYSTEM == GROUPING_SYSTEM_XXY)
	
	Grouping_Field=(((Group_Temp<<1)&(0x6))|((SubGroup_Temp)&(0x1)));

#elif ( GROUPING_SYSTEM == GROUPING_SYSTEM_XYY)
	
	Grouping_Field=(((Group_Temp<<2)&(0x4))|((SubGroup_Temp)&(0x3)));	

#elif ( GROUPING_SYSTEM == GROUPING_SYSTEM_YYY)
	
	Grouping_Field= SubGroup_Temp ;

#endif
// NVIC PRI REG 
priRegOffset = (Interrupt_Number_Temp/4)*4;
priBitOffset = 5 + (8 * (Interrupt_Number_Temp%4));
(*((volatile uint32*)(NVIC_PRIX_BASE_ADDRESS + priRegOffset  ))) |= ((uint32)(Grouping_Field << priBitOffset));

}
	
}
/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
