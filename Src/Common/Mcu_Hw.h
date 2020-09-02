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

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*                                                                     _PERIPHERALS_                                                                           */
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct {
uint32 DISMCYC                     : 1  ;
uint32 DISWBUF                     : 1  ;
uint32 DISFOLD                     : 1  ;
uint32                             : 5  ;
uint32 DISFPCA                     : 1  ;
uint32 DISOOFP                     : 1  ;
uint32                             : 22 ;
}ACTLR_BF;


typedef struct {
uint32 REV                         : 4  ;
uint32 PARTNO                      : 12 ;
uint32 CON                         : 4  ;
uint32 VAR                         : 4  ;
uint32 IMP                         : 8  ;
}CPUID_BF;


typedef struct {
uint32 VECACT                      : 8  ;
uint32                             : 3  ;
uint32 RETBASE                     : 1  ;
uint32 VECPEND                     : 8  ;
uint32                             : 2  ;
uint32 ISRPEND                     : 1  ;
uint32 ISRPRE                      : 1  ;
uint32                             : 1  ;
uint32 PENDSTCLR                   : 1  ;
uint32 PENDSTSET                   : 1  ;
uint32 UNPENDSV                    : 1  ;
uint32 PENDSV                      : 1  ;
uint32                             : 2  ;
uint32 NMISET                      : 1  ;
}INTCTRL_BF;

typedef struct {
uint32                             : 10 ;
uint32 OFFSET                      : 22 ;
}VTABLE_BF;


typedef struct {
uint32 VECTRESET                   : 1  ;
uint32 VECTCLRACT                  : 1  ;
uint32 SYSRESREQ                   : 1  ;
uint32                             : 5  ;
uint32 PRIGROUP                    : 3  ;
uint32                             : 4  ;
uint32 ENDIANESS                   : 1  ;
uint32 VECTKEY				     			   : 16 ;
}APINT_BF;


typedef struct {
uint32                             : 1  ;
uint32 SLEEPEXIT                   : 1  ;
uint32 SLEEPDEEP                   : 1  ;
uint32                             : 1  ;
uint32 SEVONPEND                   : 1  ;
uint32                             : 27 ;
}SYSCTRL_BF;


typedef struct {
uint32 BASETHR                     : 1  ;
uint32 MAINPEND                    : 1  ;
uint32                             : 1  ;
uint32 UNALIGNED                   : 1  ;
uint32 DIV0                        : 1  ;
uint32                             : 3  ;
uint32 BFHFNMIGN                   : 1  ;
uint32 STKALIGN                    : 1  ;
uint32                             : 22 ;
}CFGCTRL_BF;


typedef struct {  
uint32                             : 5  ;
uint32 MEM                         : 3  ;
uint32                             : 5  ;
uint32 BUS                         : 3  ;
uint32                             : 5  ;
uint32 USAGE                       : 3  ;
uint32                             : 8  ;
}SYSPRI1_BF;


typedef struct {    
uint32                             : 29 ;
uint32 SVC                         : 3  ;
}SYSPRI2_BF;


typedef struct {
uint32                             : 5  ;
uint32 DEBUG                       : 3  ;
uint32                             : 13 ;
uint32 PENDSV                      : 3  ;
uint32                             : 5  ;
uint32 TICK                        : 3  ;
}SYSPRI3_BF;


typedef struct {    
uint32 MEMA                        : 1  ;
uint32 BUSA                        : 1  ;
uint32                             : 1  ;
uint32 USGA                        : 1  ;
uint32                             : 3  ;
uint32 SVCA                        : 1  ;
uint32 MON                         : 1  ;
uint32                             : 1  ;
uint32 PNDSV                       : 1  ;
uint32 TICK                        : 1  ;
uint32 USAGEP                      : 1  ;
uint32 MEMP                        : 1  ;
uint32 BUSP                        : 1  ;
uint32 SVC                         : 1  ;
uint32 MEM                         : 1  ;
uint32 BUS                         : 1  ;
uint32 USAGE                       : 1  ;
uint32                             : 13 ;
}SYSHNDCTRL_BF;


typedef struct {    
uint32 IERR                        : 1  ;
uint32 DERR                        : 1  ;
uint32                             : 1  ;
uint32 MUSTKE                      : 1  ;
uint32 MSTKE                       : 1  ;
uint32 MLSPERR                     : 1  ;
uint32                             : 1  ;
uint32 MMARV                       : 1  ;
uint32 IBUS                        : 1  ;
uint32 PRECISE                     : 1  ;
uint32 IMPRE                       : 1  ;
uint32 BUSTKE                      : 1  ;
uint32 BSTKE                       : 1  ;
uint32 BLSPERR                     : 1  ;
uint32                             : 1  ;
uint32 BFARV                       : 1  ;
uint32 UNDEF                       : 1  ;
uint32 INVSTAT                     : 1  ;
uint32 NVPC                        : 1  ;
uint32 NOCP                        : 1  ;
uint32                             : 4  ;
uint32 UNALIGN                     : 1  ;
uint32 DIV0                        : 1  ;
uint32                             : 6  ;
}FAULTSTAT_BF;


typedef struct {
uint32                             : 1  ;
uint32 VECT                        : 1  ;
uint32                             : 28 ;
uint32 FORCED                      : 1  ;
uint32 DBG                         : 1  ;
}HFAULTSTAT_BF;


typedef struct {
uint32 ADDR                        : 32 ;
}MMADDR_BF;


typedef struct {
uint32 ADDR                        : 32 ;
}FAULTADDR_BF;


typedef struct{	
uint32 							   						 : 5	;	
uint32 INT_NUM_0_IN_PRI		       	 : 3	;	
uint32 							  						 : 5	;	
uint32 INT_NUM_1_IN_PRI			   		 : 3	;	
uint32 							   						 : 5	;	
uint32 INT_NUM_2_IN_PRI			    	 : 3	;	
uint32 							    	 		 	   : 5	;	
uint32 INT_NUM_3_IN_PRI			   		 : 3	;
}NVIC_PRI_BF;

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*                                                                   _SYSTEM_CONTROL_                                                                          */
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct{
uint32 EXT                         : 1  ;
uint32 POR                         : 1  ;
uint32 BOR                         : 1  ;
uint32 WDT0                        : 1  ;
uint32 SW                          : 1  ;
uint32 WDT1                        : 1  ;
uint32                             : 10 ;
uint32 MOSCFAIL                    : 1  ;
uint32 	                           : 15 ;	
}RESC_BF;


typedef struct {
uint32 MOSCDIS                     : 1  ;
uint32                             : 3  ;
uint32 OSCSRC                      : 2  ;
uint32 XTAL                        : 5  ;
uint32 BYPASS                      : 1  ;
uint32                             : 1  ;
uint32 PWRDN                       : 1  ;   
uint32                             : 3  ;
uint32 PWMDIV                      : 3  ;
uint32 USEPWMDIV                   : 1  ;
uint32                             : 1  ;
uint32 USESYSDIV                   : 1  ;
uint32 SYSDIV                      : 4  ;
uint32 ACG                         : 1  ;
uint32                             : 4  ;
}RCC_BF;


typedef struct {
uint32                             : 4  ;
uint32 OSCSRC2                     : 3  ;
uint32                             : 4  ;
uint32 BYPASS2                     : 1  ;
uint32                             : 1  ;
uint32 PWRDN2                      : 1  ; 
uint32 USBPWRDN                    : 1  ;   
uint32                             : 7  ;
uint32 SYSDIV2LSB                  : 1  ;
uint32 SYSDIV2                     : 6  ;
uint32                             : 1  ;
uint32 DIV400                      : 1  ;
uint32 USERCC2                     : 1  ;
}RCC2_BF;

typedef struct{
uint32 LOCK								  			 : 1  ;
uint32 														 : 31 ;
}PLLSTAT_BF;	

typedef struct{
uint32 R0								  			   : 1  ;
uint32 R1								  	 		   : 1  ;	
uint32 														 : 30 ;
}RCGCWD_BF;

typedef struct{
uint32 R0								  			   : 1  ;	
uint32 R1								  			   : 1  ;
uint32 R2								  	 		   : 1  ;
uint32 R3								  			   : 1  ;
uint32 R4								  	 		   : 1  ;
uint32 R5								  			   : 1  ;
uint32 														 : 26 ;	
}RCGCTIMER_BF;

typedef struct{
uint32 R0								  			   : 1  ;	
uint32 R1								  			   : 1  ;
uint32 R2								  	 		   : 1  ;
uint32 R3								  			   : 1  ;
uint32 R4								  	 		   : 1  ;
uint32 R5								  			   : 1  ;
uint32 														 : 26 ;	
}RCGCGPIO_BF;

typedef struct{
uint32 R0 								  			 : 1  ;
uint32 														 : 31 ;
}RCGCDMA_BF;

typedef struct{
uint32 R0 								  			 : 1  ;
uint32 														 : 31 ;
}RCGCHIB_BF;

typedef struct{
uint32 R0								  			   : 1  ;	
uint32 R1								  			   : 1  ;
uint32 R2								  	 		   : 1  ;
uint32 R3								  			   : 1  ;
uint32 R4								  	 		   : 1  ;
uint32 R5								  			   : 1  ;
uint32 R6								  			   : 1  ;
uint32 R7								  			   : 1  ;	
uint32 														 : 24 ;	
}RCGCUART_BF;

typedef struct{
uint32 R0								  			   : 1  ;	
uint32 R1								  			   : 1  ;
uint32 R2								  	 		   : 1  ;
uint32 R3								  			   : 1  ;	
uint32 														 : 28 ;	
}RCGCSSI_BF;

typedef struct{
uint32 R0								  			   : 1  ;	
uint32 R1								  			   : 1  ;
uint32 R2								  	 		   : 1  ;
uint32 R3								  			   : 1  ;	
uint32 														 : 28 ;	
}RCGCI2C_BF;

typedef struct{
uint32 R0								  			   : 1  ;		
uint32 														 : 31 ;	
}RCGCUSB_BF;

typedef struct{
uint32 R0								  			   : 1  ;
uint32 R1								  			   : 1  ;			
uint32 														 : 30 ;	
}RCGCCAN_BF;

typedef struct{
uint32 R0								  			   : 1  ;
uint32 R1								  			   : 1  ;			
uint32 														 : 30 ;	
}RCGCADC_BF;

typedef struct{
uint32 R0								  			   : 1  ;
uint32 														 : 31 ;	
}RCGCACMP_BF;

typedef struct{
uint32 R0								  			   : 1  ;
uint32 R1								  			   : 1  ;			
uint32 														 : 30 ;	
}RCGCPWM_BF;

typedef struct{
uint32 R0								  			   : 1  ;
uint32 R1								  			   : 1  ;			
uint32 														 : 30 ;	
}RCGCQEI_BF;

typedef struct{
uint32 R0								  			   : 1  ;
uint32 														 : 31 ;	
}RCGCEEPROM_BF;



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*                                                                  _PERIPHERALS_TAG_                                                                          */
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef union {
    uint32 R;
    ACTLR_BF B;
}ACTLR_TAG;

typedef union {
    uint32 R;
    CPUID_BF B; 
}CPUID_TAG;

typedef union {
    uint32 R;
    INTCTRL_BF B; 
}INTCTRL_TAG;

typedef union {
    uint32 R;
    VTABLE_BF B; 
}VTABLE_TAG;

typedef union {
    uint32   R;
    APINT_BF B; 
}APINT_TAG;

typedef union {
    uint32 R;
    SYSCTRL_BF B; 
}SYSCTRL_TAG;

typedef union {
    uint32 R;
   CFGCTRL_BF B; 
}CFGCTRL_TAG;

typedef union {
    uint32 R;
    SYSPRI1_BF B; 
}SYSPRI1_TAG;

typedef union {
    uint32 R;
    SYSPRI2_BF B; 
}SYSPRI2_TAG;

typedef union {
    uint32 R;
    SYSPRI3_BF B; 
}SYSPRI3_TAG;

typedef union {
    uint32 R;
    SYSHNDCTRL_BF B; 
}SYSHNDCTRL_TAG;

typedef union {
    uint32 R;
    FAULTSTAT_BF B; 
}FAULTSTAT_TAG;

typedef union {
    uint32 R;
    HFAULTSTAT_BF B; 
}HFAULTSTAT_TAG;

typedef union {
    uint32 R;
    MMADDR_BF B; 
}MMADDR_TAG;

typedef union {
    uint32 R;
    FAULTADDR_BF B; 
}FAULTADDR_TAG;

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*                                                                _SYSTEM_CONTROL_TAG_                                                                         */
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef union{
    uint32 R;
    RESC_BF B;	
}RESC_TAG;

typedef union{
    uint32 R;
    RCC_BF B;	
}RCC_TAG;

typedef union{
    uint32 R;
    RCC2_BF B;	
}RCC2_TAG;

typedef union{
    uint32 R;
    PLLSTAT_BF B;	
}PLLSTAT_TAG;

typedef union{
    uint32 R;
    RCGCWD_BF B;	
}RCGCWD_TAG;

typedef union{
    uint32 R;
    RCGCTIMER_BF B;	
}RCGCTIMER_TAG;
typedef union{
    uint32 R;
    RCGCGPIO_BF B;	
}RCGCGPIO_TAG;

typedef union{
    uint32 R;
    RCGCDMA_BF B;	
}RCGCDMA_TAG;

typedef union{
    uint32 R;
    RCGCHIB_BF B;	
}RCGCHIB_TAG;

typedef union{
    uint32 R;
    RCGCUART_BF B;	
}RCGCUART_TAG;

typedef union{
    uint32 R;
    RCGCSSI_BF B;	
}RCGCSSI_TAG;

typedef union{
    uint32 R;
    RCGCI2C_BF B;	
}RCGCI2C_TAG;

typedef union{
    uint32 R;
    RCGCUSB_BF B;	
}RCGCUSB_TAG;

typedef union{
    uint32 R;
    RCGCCAN_BF B;	
}RCGCCAN_TAG;

typedef union{
    uint32 R;
    RCGCADC_BF B;	
}RCGCADC_TAG;

typedef union{
    uint32 R;
    RCGCACMP_BF B;	
}RCGCACMP_TAG;

typedef union{
    uint32 R;
    RCGCPWM_BF B;	
}RCGCPWM_TAG;

typedef union{
    uint32 R;
    RCGCQEI_BF B;	
}RCGCQEI_TAG;

typedef union{
    uint32 R;
    RCGCEEPROM_BF B;	
}RCGCEEPROM_TAG;










/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define CORTEX_M4_PERIPHERALS_BASE_ADDRESS      0xE000E000 
#define CORTEX_M4_SYSTEM_CONTROL_BASE_ADDRESS   0x400FE000

#define NVIC_PRIX_BASE_ADDRESS					  (CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0x400)

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*                                                            _SYSTEM_CONTROL_ADDRESS_                                                                         */
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define RESC								(*((volatile RESC_TAG*     )(CORTEX_M4_SYSTEM_CONTROL_BASE_ADDRESS+0x05C)))
#define RCC 								(*((volatile RCC_TAG*      )(CORTEX_M4_SYSTEM_CONTROL_BASE_ADDRESS+0x060)))
#define RCC2 								(*((volatile RCC2_TAG*     )(CORTEX_M4_SYSTEM_CONTROL_BASE_ADDRESS+0x070)))
#define PLLSTAT 						(*((volatile PLLSTAT_TAG*  )(CORTEX_M4_SYSTEM_CONTROL_BASE_ADDRESS+0x168)))
#define RCGCWD 						  (*((volatile RCGCWD_TAG*   )(CORTEX_M4_SYSTEM_CONTROL_BASE_ADDRESS+0x600)))
#define RCGCTIMER 					(*((volatile RCGCTIMER_TAG*)(CORTEX_M4_SYSTEM_CONTROL_BASE_ADDRESS+0x604)))
#define RCGCGPIO 						(*((volatile RCGCGPIO_TAG* )(CORTEX_M4_SYSTEM_CONTROL_BASE_ADDRESS+0x608)))
#define RCGCDMA 						(*((volatile RCGCDMA_TAG*  )(CORTEX_M4_SYSTEM_CONTROL_BASE_ADDRESS+0x60C)))
#define RCGCHIB 					  (*((volatile RCGCHIB_TAG*  )(CORTEX_M4_SYSTEM_CONTROL_BASE_ADDRESS+0x614)))
#define RCGCUART 						(*((volatile RCGCUART_TAG* )(CORTEX_M4_SYSTEM_CONTROL_BASE_ADDRESS+0x618)))
#define RCGCSSI 						(*((volatile RCGCSSI_TAG*  )(CORTEX_M4_SYSTEM_CONTROL_BASE_ADDRESS+0x61C)))
#define RCGCI2C 						(*((volatile RCGCI2C_TAG*  )(CORTEX_M4_SYSTEM_CONTROL_BASE_ADDRESS+0x620)))
#define RCGCUSB 						(*((volatile RCGCUSB_TAG*  )(CORTEX_M4_SYSTEM_CONTROL_BASE_ADDRESS+0x628)))
#define RCGCCAN 						(*((volatile RCGCCAN_TAG*  )(CORTEX_M4_SYSTEM_CONTROL_BASE_ADDRESS+0x634)))
#define RCGCADC 						(*((volatile RCGCADC_TAG*  )(CORTEX_M4_SYSTEM_CONTROL_BASE_ADDRESS+0x638)))
#define RCGCACMP 						(*((volatile RCGCACMP_TAG* )(CORTEX_M4_SYSTEM_CONTROL_BASE_ADDRESS+0x63C)))
#define RCGCPWM 						(*((volatile RCGCPWM_TAG*  )(CORTEX_M4_SYSTEM_CONTROL_BASE_ADDRESS+0x640)))
#define RCGCQEI 						(*((volatile RCGCQEI_TAG*  )(CORTEX_M4_SYSTEM_CONTROL_BASE_ADDRESS+0x644)))
#define RCGCEEPROM 				 (*((volatile RCGCEEPROM_TAG*)(CORTEX_M4_SYSTEM_CONTROL_BASE_ADDRESS+0x658)))

	



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*                                                            __PERIPHERALS_ADDRESS_                                                                           */
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

#define EN0                 (*((volatile uint32*        )(CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0x100)))
#define EN1                 (*((volatile uint32*        )(CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0x104)))
#define EN2                 (*((volatile uint32*        )(CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0x108)))
#define EN3                 (*((volatile uint32*        )(CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0x10C)))
#define EN4                 (*((volatile uint32*        )(CORTEX_M4_PERIPHERALS_BASE_ADDRESS+0x110)))



extern NVIC_PRI_BF NVIC_PRIX[35] __attribute__((at(NVIC_PRIX_BASE_ADDRESS))) ;// Warning 

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
