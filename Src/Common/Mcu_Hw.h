/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <MicroController Hardware>
 *       Module:  -Common Files
 *
 *  Description:  <Hardware Adresses>     
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REG- BitF.
 *********************************************************************************************************************/

typedef struct 
{

uint32 DISMCYC :1 ;
uint32 DISWBUF :1 ;
uint32 DISFOLD :1 ;
uint32         :5 ;
uint32 DISFPCA :1 ;
uint32 DISOOFP :1 ;
uint32         :22;

}ACTLR_BF;

typedef struct 
{
uint32 REV    :4  ;
uint32 PARTNO :12 ;
uint32 CON    :4  ;
uint32 VAR    :4  ;
uint32 IMP    :8  ;

}CPUID_BF;

typedef struct 
{
uint32  VECACT        :8  ;
uint32                :3  ;
uint32  RETBASE       :1  ;
uint32  VECPEND       :8  ;
uint32                :2  ;
uint32  ISRPEND       :1  ;
uint32  ISRPRE        :1  ;
uint32                :1  ;
uint32  PENDSTCLR     :1  ;
uint32  PENDSTSET     :1  ;
uint32  UNPENDSV      :1  ;
uint32  PENDSV        :1  ;
uint32                :2  ;
uint32  NMISET        :1	;

}INTCTRL_BF;

typedef struct 
{
uint32                :10 ;
uint32  OFFSET        :22 ;

}VTABLE_BF;


typedef struct 
{
uint32  VECTRESET     :1  ;
uint32  VECTCLRACT    :1  ;
uint32  SYSRESREQ     :1  ;
uint32                :5  ;
uint32  PRIGROUP      :3  ;
uint32                :4  ;
uint32  ENDIANESS     :1  ;
uint32  VECTKEY				:16 ;

}APINT_BF;

typedef struct 
{

uint32                :1  ;
uint32  SLEEPEXIT     :1  ;
uint32  SLEEPDEEP     :1  ;
uint32                :1  ;
uint32  SEVONPEND     :1  ;
uint32                :27  ;

}SYSCTRL_BF;

typedef struct 
{
    
uint32  BASETHR       :1  ;
uint32  MAINPEND      :1  ;
uint32                :1  ;
uint32  UNALIGNED     :1  ;
uint32  DIV0          :1  ;
uint32                :3  ;
uint32  BFHFNMIGN     :1  ;
uint32  STKALIGN      :1  ;
uint32                :22 ;

}CFGCTRL_BF;

typedef struct 
{
    
uint32                :5  ;
uint32  MEM           :3  ;
uint32                :5  ;
uint32  BUS           :3  ;
uint32                :5  ;
uint32  USAGE         :3  ;
uint32                :8  ;

}SYSPRI1_BF;

typedef struct 
{
    
uint32                :29  ;
uint32  SVC           :3  ;

}SYSPRI2_BF;

typedef struct 
{
    
uint32                :5  ;
uint32  DEBUG         :3  ;
uint32                :13  ;
uint32  PENDSV        :3  ;
uint32                :5  ;
uint32  TICK          :3  ;

}SYSPRI3_BF;

typedef struct 
{
    
uint32  MEMA          :1  ;
uint32  BUSA          :1  ;
uint32                :1  ;
uint32  USGA          :1  ;
uint32                :3  ;
uint32  SVCA          :1  ;
uint32  MON           :1  ;
uint32                :1  ;
uint32  PNDSV         :1  ;
uint32  TICK          :1  ;
uint32  USAGEP        :1  ;
uint32  MEMP          :1  ;
uint32  BUSP          :1  ;
uint32  SVC           :1  ;
uint32  MEM           :1  ;
uint32  BUS           :1  ;
uint32  USAGE         :1  ;
uint32                :13  ;

}SYSHNDCTRL_BF;

typedef struct 
{
    
uint32  IERR          :1  ;
uint32  DERR          :1  ;
uint32                :1  ;
uint32  MUSTKE        :1  ;
uint32  MSTKE         :1  ;
uint32  MLSPERR       :1  ;
uint32                :1  ;
uint32  MMARV         :1  ;
uint32  IBUS          :1  ;
uint32  PRECISE       :1  ;
uint32  IMPRE         :1  ;
uint32  BUSTKE        :1  ;
uint32  BSTKE         :1  ;
uint32  BLSPERR       :1  ;
uint32                :1  ;
uint32  BFARV         :1  ;
uint32  UNDEF         :1  ;
uint32  INVSTAT       :1  ;
uint32  NVPC          :1  ;
uint32  NOCP          :1  ;
uint32                :4  ;
uint32  UNALIGN       :1  ;
uint32  DIV0          :1  ;
uint32                :6  ;

}FAULTSTAT_BF;

typedef struct 
{
    
uint32                :1  ;
uint32  VECT          :1  ;
uint32                :28 ;
uint32  FORCED        :1  ;
uint32  DBG           :1  ;

}HFAULTSTAT_BF;

typedef struct 
{

uint32  ADDR          :32 ;

}MMADDR_BF;

typedef struct 
{

uint32  ADDR          :32 ;

}FAULTADDR_BF;


typedef struct{
	
uint32 											:5	;	
uint32 INT_NUM_0_IN_PRI			:3	;	
uint32 											:5	;	
uint32 INT_NUM_1_IN_PRI			:3	;	
uint32 											:5	;	
uint32 INT_NUM_2_IN_PRI			:3	;	
uint32 											:5	;	
uint32 INT_NUM_3_IN_PRI			:3	;
	
}NVIC_PRI_BF;





/**********************************************************************************************************************
 *  REG- TAG
 *********************************************************************************************************************/
typedef union 
{
    uint32 R;
    ACTLR_BF B;

}ACTLR_TAG;

typedef union 
{

    uint32 R;
    CPUID_BF B; 

}CPUID_TAG;

typedef union 
{

    uint32 R;
    INTCTRL_BF B; 

}INTCTRL_TAG;

typedef union 
{

    uint32 R;
    VTABLE_BF B; 

}VTABLE_TAG;

typedef union 
{

    uint32   R;
    APINT_BF B; 

}APINT_TAG;

typedef union 
{

    uint32 R;
    SYSCTRL_BF B; 

}SYSCTRL_TAG;

typedef union 
{

    uint32 R;
   CFGCTRL_BF B; 

}CFGCTRL_TAG;

typedef union 
{

    uint32 R;
    SYSPRI1_BF B; 

}SYSPRI1_TAG;

typedef union 
{

    uint32 R;
    SYSPRI2_BF B; 

}SYSPRI2_TAG;

typedef union 
{

    uint32 R;
    SYSPRI3_BF B; 

}SYSPRI3_TAG;

typedef union 
{

    uint32 R;
    SYSHNDCTRL_BF B; 

}SYSHNDCTRL_TAG;

typedef union 
{

    uint32 R;
    FAULTSTAT_BF B; 

}FAULTSTAT_TAG;

typedef union 
{

    uint32 R;
    HFAULTSTAT_BF B; 

}HFAULTSTAT_TAG;

typedef union 
{

    uint32 R;
    MMADDR_BF B; 

}MMADDR_TAG;

typedef union 
{

    uint32 R;
    FAULTADDR_BF B; 

}FAULTADDR_TAG;



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define CORTEX_M4_PERIPHERALS_BASE_ADDRESS 0xE000E000 
#define NVIC_PRIX_BASE_ADDRESS					  (CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0x400)

 NVIC_PRI_BF NVIC_PRIX[35] __attribute__((at(NVIC_PRIX_BASE_ADDRESS))) ;// Warning 



#define EN0                 (*((volatile uint32*        )(CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0x100)))
#define EN1                 (*((volatile uint32*        )(CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0x104)))
#define EN2                 (*((volatile uint32*        )(CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0x108)))
#define EN3                 (*((volatile uint32*        )(CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0x10C)))
#define EN4                 (*((volatile uint32*        )(CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0x110)))
/*NVIC PRI Registers*/







	
	




/*System Control Block (SCB) Registers*/

#define ACTLR                (*((volatile ACTLR_TAG*     )(CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0x008)))
#define CPUID                (*((volatile CPUID_TAG*     )(CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0xD00)))
#define INTCTRL              (*((volatile INTCTRL_TAG*   )(CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0xD04)))
#define VTABLE               (*((volatile VTABLE_TAG*    )(CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0xD08)))
#define APINT                (*((volatile APINT_TAG*     )(CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0xD0C)))
#define SYSCTRL              (*((volatile SYSCTRL_TAG*   )(CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0xD10)))
#define CFGCTRL              (*((volatile CFGCTRL_TAG*   )(CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0xD14)))
#define SYSPRI1              (*((volatile SYSPRI1_TAG*   )(CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0xD18)))
#define SYSPRI2              (*((volatile SYSPRI2_TAG*   )(CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0xD1C)))
#define SYSPRI3              (*((volatile SYSPRI3_TAG*   )(CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0xD20)))
#define SYSHNDCTRL           (*((volatile SYSHNDCTRL_TAG*)(CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0xD24)))
#define FAULTSTAT            (*((volatile FAULTSTAT_TAG* )(CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0xD28)))
#define HFAULTSTAT           (*((volatile HFAULTSTAT_TAG*)(CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0xD2C)))
#define MMADDR               (*((volatile MMADDR_TAG*    )(CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0xD34)))
#define FAULTADDR            (*((volatile FAULTADDR_TAG* )(CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0xD38)))



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
