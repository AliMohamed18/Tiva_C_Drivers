/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef DIO_TYPES_H
#define DIO_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

 
typedef enum{ 

   Dio_Channel_A0,
   Dio_Channel_A1,
   Dio_Channel_A2,
   Dio_Channel_A3,
   Dio_Channel_A4,
   Dio_Channel_A5,
   Dio_Channel_A6,
   Dio_Channel_A7,
	
   Dio_Channel_B0,
   Dio_Channel_B1,
   Dio_Channel_B2,
   Dio_Channel_B3,
   Dio_Channel_B4,
   Dio_Channel_B5,
   Dio_Channel_B6,
   Dio_Channel_B7,
	
   Dio_Channel_C0,
   Dio_Channel_C1,
   Dio_Channel_C2,
   Dio_Channel_C3,
   Dio_Channel_C4,
   Dio_Channel_C5,
   Dio_Channel_C6,
   Dio_Channel_C7,

	 Dio_Channel_D0,
   Dio_Channel_D1,
   Dio_Channel_D2,
   Dio_Channel_D3,
   Dio_Channel_D4,
   Dio_Channel_D5,
   Dio_Channel_D6,
   Dio_Channel_D7,
	 
   Dio_Channel_E0,
   Dio_Channel_E1,
   Dio_Channel_E2,
   Dio_Channel_E3,
   Dio_Channel_E4,
   Dio_Channel_E5,	
	 Dio_Channel_E6_RESERVED,
	 Dio_Channel_E7_RESERVED,

   Dio_Channel_F0,
   Dio_Channel_F1,
   Dio_Channel_F2,
   Dio_Channel_F3,
   Dio_Channel_F4,
	 Dio_Channel_F5_RESERVED,	 
	 Dio_Channel_F6_RESERVED,
	 Dio_Channel_F7_RESERVED,
	 
}Dio_ChannelType ;

typedef enum{	
    
    PORTA,
    PORTB,
    PORTC,
    PORTD,
    PORTE,
    PORTF
}Dio_PortType; 

typedef STD_levelType Dio_LevelType;

typedef uint8 Dio_PortLevelType ;

typedef uint8 Dio_ChannelGroupType;





#endif  /* DIO_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio_Types.h
 *********************************************************************************************************************/
