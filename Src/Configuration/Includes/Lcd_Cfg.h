#ifndef LCD_CFG_H_
#define LCD_CFG_H_
#include "Lcd.h"

/*  
	Replace PORTX with Used Port
	Define Pins Of RS , RW And EN
	Remember To Make: 
	1) Used Port  -> Output
	2) Used Pin   -> Output
	3) Connect In This Sequence  **D7,D6,D5,D4**<--------- From Pin0
*/
extern const Dio_ChannelGroupType Lcd_Data;
#define LCD_Port        	  Lcd_Data

#define RS 	                  Dio_Channel_A7
#define RW 	                  Dio_Channel_A6
#define EN 	                  Dio_Channel_E4

#endif /* LCD_CFG_H_ */
