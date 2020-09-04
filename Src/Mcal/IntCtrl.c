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
uint8 Counter , PRIGROUP_CHOICE , Group_Temp , SubGroup_Temp , Interrupt_Number_Temp ,POSINTION_IN_PRIX ,PRIX_NUMBER	;
	
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

__asm ("CPSID i"); // Disable all interrupts first then enable used interrupts only	

for(Counter=0 ;Counter < NUM_OF_ACTIVATED_GROUPS;Counter++){
	
Interrupt_Number_Temp = Interrupt_Groups[Counter].Interrupt_Number;	
Group_Temp = Interrupt_Groups[Counter].Group_Priority;
SubGroup_Temp =	Interrupt_Groups[Counter].SubGroup_Priority;
	
	
	
if	   (Interrupt_Number_Temp == 0	 || Interrupt_Number_Temp < 32  )  SET(EN0,(Interrupt_Number_Temp));
else if(Interrupt_Number_Temp >= 32  &&	Interrupt_Number_Temp < 64  )  SET(EN1,(Interrupt_Number_Temp-32));
else if(Interrupt_Number_Temp >= 64  &&	Interrupt_Number_Temp < 96  )  SET(EN2,(Interrupt_Number_Temp-64));
else if(Interrupt_Number_Temp >= 96  &&	Interrupt_Number_Temp < 128 )  SET(EN3,(Interrupt_Number_Temp-96));
else if(Interrupt_Number_Temp >= 128 &&	Interrupt_Number_Temp <= 138)  SET(EN4,(Interrupt_Number_Temp-128));

POSINTION_IN_PRIX=Interrupt_Number_Temp	%	4;	
PRIX_NUMBER	= ((Interrupt_Number_Temp-POSINTION_IN_PRIX)/4);

#if   ( GROUPING_SYSTEM == 1)
	
switch(POSINTION_IN_PRIX){
	
	case 0 :
	NVIC_PRIX[PRIX_NUMBER].INT_NUM_0_IN_PRI =Group_Temp ;
	break ;
	
	case 1 :
	NVIC_PRIX[PRIX_NUMBER].INT_NUM_1_IN_PRI =Group_Temp ;
	break ;
	
	case 2 :
	NVIC_PRIX[PRIX_NUMBER].INT_NUM_2_IN_PRI =Group_Temp ;
	break ;
		
	case 3 :
	NVIC_PRIX[PRIX_NUMBER].INT_NUM_3_IN_PRI =Group_Temp ;
	break ;
}
#elif ( GROUPING_SYSTEM == 2)
	
switch(POSINTION_IN_PRIX){
	
	case 0 :
	NVIC_PRIX[PRIX_NUMBER].INT_NUM_0_IN_PRI =(((Group_Temp<<1)&(0x6))|((SubGroup_Temp)&(0x1)));
	break ;
	
	case 1 :
	NVIC_PRIX[PRIX_NUMBER].INT_NUM_1_IN_PRI =(((Group_Temp<<1)&(0x6))|((SubGroup_Temp)&(0x1)));
	break ;
	
	case 2 :
	NVIC_PRIX[PRIX_NUMBER].INT_NUM_2_IN_PRI =(((Group_Temp<<1)&(0x6))|((SubGroup_Temp)&(0x1)));
	break ;
		
	case 3 :
	NVIC_PRIX[PRIX_NUMBER].INT_NUM_3_IN_PRI =(((Group_Temp<<1)&(0x6))|((SubGroup_Temp)&(0x1)));
	break ;
}	
	
#elif ( GROUPING_SYSTEM == 3)
	
switch(POSINTION_IN_PRIX){
	
	case 0 :
	NVIC_PRIX[PRIX_NUMBER].INT_NUM_0_IN_PRI =(((Group_Temp<<2)&(0x4))|((SubGroup_Temp)&(0x3)));
	break ;
	
	case 1 :
	NVIC_PRIX[PRIX_NUMBER].INT_NUM_1_IN_PRI =(((Group_Temp<<2)&(0x4))|((SubGroup_Temp)&(0x3)));
	break ;
	
	case 2 :
	NVIC_PRIX[PRIX_NUMBER].INT_NUM_2_IN_PRI =(((Group_Temp<<2)&(0x4))|((SubGroup_Temp)&(0x3)));
	break ;
		
	case 3 :
	NVIC_PRIX[PRIX_NUMBER].INT_NUM_3_IN_PRI =(((Group_Temp<<2)&(0x4))|((SubGroup_Temp)&(0x3)));
	break ;
}	
	
#elif ( GROUPING_SYSTEM == 4)
	
switch(POSINTION_IN_PRIX){
	
	case 0 :
	NVIC_PRIX[PRIX_NUMBER].INT_NUM_0_IN_PRI = SubGroup_Temp ;
	break ;
	
	case 1 :
	NVIC_PRIX[PRIX_NUMBER].INT_NUM_1_IN_PRI =SubGroup_Temp ;
	break ;
	
	case 2 :
	NVIC_PRIX[PRIX_NUMBER].INT_NUM_2_IN_PRI =SubGroup_Temp ;
	break ;
		
	case 3 :
	NVIC_PRIX[PRIX_NUMBER].INT_NUM_3_IN_PRI =SubGroup_Temp ;
	break ;
}	
	
#endif	
	
}
	
	
__asm("MOV R0, 0x1"); // Switch to user 
__asm("MSR CONTROL, R0");

	
	
  /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  

}
/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
