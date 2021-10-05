#include "Port_Driv.h"
#include "Dio.h"
#include "Mcu.h"
#include "Uart.h"
#include "Uart_Cfg.h"
#include "Port_Driv_Cfg.h"

int main(void){
	
	Mcu_Init();
	Uart_Init(Uart_Config);
	Port_Init(Port_Config);
while(1){
	
	Dio_WriteChannel(Dio_Channel_F2,STD_high);

}
}
 



