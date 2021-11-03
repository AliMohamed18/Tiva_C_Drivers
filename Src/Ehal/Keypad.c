#include "Keypad.h"

const uint8 symbol[ROWS_NUMBER][COLUMNS_NUMBER] = {
{ '1', '2',  '3', 'A'},      
{ '4', '5',  '6', 'B'},      
{ '7', '8',  '9', 'C'},      
{ '*', '0',  '#', 'D'}
};

char KeyPad_getPressedKey(void)
{
    for(int i = 0; i < COLUMNS_NUMBER; i++)
    {
			Dio_WriteChannelGroup(&KEYPAD_COLUMNS,(1U<<i));
      for(int j = 0; j < ROWS_NUMBER; j++)  
      {
       if((Dio_ReadChannelGroup(&KEYPAD_RAWS)&(1U<<j))!=0) return symbol[j][i];
      }
    }
	return NULL;
}






