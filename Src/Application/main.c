#include "Port.h"
#include "Dio.h"
#include "Mcu.h"
int main(void)
 { 	
	 
Mcu_Init(); 
Port_Init(Port_Config);
while(1){
	Dio_WriteChannel(Dio_Channel_F2,0);
	Dio_WriteChannel(Dio_Channel_F1,1);
	
for(uint32 i =0 ;i<100000;i++){}
	Dio_WriteChannel(Dio_Channel_F2,1);
	Dio_WriteChannel(Dio_Channel_F1,0);

for(uint32 i =0 ;i<100000;i++){}

	}
return 0;
} 
 



