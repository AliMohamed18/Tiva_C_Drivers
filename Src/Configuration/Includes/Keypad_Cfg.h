#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#include "Keypad.h"

/*  
	Replace PORTX with Used Port
	Define Numbers Of Columns & Raws
	Remember To Make: 
	1) Columns -> Output
	2) Raws    -> Input
	3) Active The PullDown Resistance For Raws
	Row0,Row1,Row2,Row3,Col0,Col1,Col2,Col3
*/



#define COLUMNS_NUMBER 4 
#define ROWS_NUMBER    4

extern const Dio_ChannelGroupType KeypadInput;
extern const Dio_ChannelGroupType KeypadOutput;


#define KEYPAD_RAWS  KeypadInput	
#define KEYPAD_COLUMNS  KeypadOutput 

extern const uint8 symbol[ROWS_NUMBER][COLUMNS_NUMBER];



#endif /* KEYPAD_CFG_H_ */
