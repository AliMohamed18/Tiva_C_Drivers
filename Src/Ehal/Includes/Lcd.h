#ifndef LCD_H_
#define LCD_H_

#include "Port_Driv_Cfg.h"
#include "Dio.h"
#include "Lcd_Cfg.h"

void LCD_int(void);
void LCD_WriteCommand(uint8 Command);
void LCD_WriteData(uint8 Data);
void LCD_WriteString(uint8 *String);
void LCD_Clear(void);
void LCD_GoToRowColumn(uint8 row, uint8 col);

#endif /* LCD_H_ */


