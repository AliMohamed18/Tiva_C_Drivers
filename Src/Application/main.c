#include "Mcu.h"
#include "Port.h"
#include "Dio.h"

int main(void)
 { 	
	 Mcu_InitClock(MCU_CLOCK_0);
	 Port_Init(Port_Config);

while(1){
		 Dio_WriteChannel(Dio_Channel_F2,STD_high);


	}
return 0;
}