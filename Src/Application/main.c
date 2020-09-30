#include "Port.h"
#include "Dio.h"
int main(void)
 { 	
	 
	*((volatile uint32*)(0x400FE000+0x108))= 0x20; 				// GPIO Unlock 
 
Port_Init(Port_Config);
while(1){
	Dio_WriteChannel(Dio_Channel_F2,0);
	Dio_WriteChannel(Dio_Channel_F1,1);
	
for(uint32 i =0 ;i<1000;i++){}
	Dio_WriteChannel(Dio_Channel_F2,1);
		Dio_WriteChannel(Dio_Channel_F1,0);

for(uint32 i =0 ;i<1000;i++){}

	}
return 0;
} 
 



