#include "Lcd.h"
void delay(int n)
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<3000;j++)
 {}
}

void LCD_int()
{ 
	Dio_WriteChannel(RW,STD_low);	// To Write Into Regesters
	LCD_WriteCommand(0x28);			// 2 lines and 5×7 matrix (4-bit mode)
  LCD_WriteCommand(0x0c);			// Display on , Cursor of
	LCD_WriteCommand(0x06);			// Increment cursor (shift cursor to right)
	LCD_WriteCommand(0x01);			// Clear display screen
	LCD_WriteCommand(0x80);			// Force cursor to beginning ( 1st line)
	delay(40);
}

void LCD_Clear(void)
{
	LCD_WriteCommand(0x01); // Clear display screen
		delay(40);
	LCD_WriteCommand(0x80); // Force cursor to beginning ( 1st line)
}

void LCD_WriteString(uint8 *String)
{
	while((*String) != 0)
	{
		LCD_WriteData(*String);
		String++;
	}
}

void LCD_WriteCommand(uint8 Command)
{   
	
	Dio_WriteChannel(RW,STD_low);
		delay(40);
	Dio_WriteChannelGroup(&LCD_Port,((Dio_ReadChannelGroup(&LCD_Port) & 0x0F) | (Command & 0xF0)));
		delay(40);

	Dio_WriteChannel(RS,STD_low);
		delay(40);

	Dio_WriteChannel(EN,STD_high);
		delay(40);

	Dio_WriteChannel(EN,STD_low);
	delay(40);
	
	Dio_WriteChannelGroup(&LCD_Port,((Dio_ReadChannelGroup(&LCD_Port) & 0x0F) | (Command << 4)));
		delay(40);

	Dio_WriteChannel(EN,STD_high);
		delay(40);

	Dio_WriteChannel(EN,STD_low);	
}

void LCD_WriteData(uint8 Data)
{	delay(40);

	Dio_WriteChannelGroup(&LCD_Port,((Dio_ReadChannelGroup(&LCD_Port) & 0x0F) | (Data & 0xF0)));
		delay(40);

	Dio_WriteChannel(RS,STD_high);
		delay(40);

	Dio_WriteChannel(EN,STD_high);
		delay(40);

	Dio_WriteChannel(EN,STD_low);
		delay(40);

	Dio_WriteChannelGroup(&LCD_Port,((Dio_ReadChannelGroup(&LCD_Port) & 0x0F) | (Data << 4)));
		delay(40);

	Dio_WriteChannel(EN,STD_high);
		delay(40);

	Dio_WriteChannel(EN,STD_low);
}

void LCD_GoToRowColumn(uint8 row, uint8 col)
{
	uint8 Address=0;
	switch(row)
	{
		case 0:
		Address=col;
		break;
		case 1:
		Address=col+0x40;
		break;
	}
	
	LCD_WriteCommand(Address | 0x80);
}
