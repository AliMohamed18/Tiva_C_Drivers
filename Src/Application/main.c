//#include "Mcu.h"
#include "Port.h"
#include "Dio.h"

int main(void)
 { 	

   Port_Init(Port_Config);
	 Dio_WriteChannel(Dio_Channel_F4,STD_high);

while(1){
	
	}
return 0;
}