#include "Port.h"
#include "Dio.h"
#include "Mcu.h"
#include "Uart.h"

int main(void)
 { 	
Mcu_Init(); 
Port_Init(Port_Config);
Uart_Init(Uart_Config);
	 char Button;
	 char A[]="Ali Is The Here \n";
while(1){
Button=Dio_ReadChannel(Dio_Channel_F0);
if(Button==0)	{
Uart_SendString(Uart0,A);
//	Uart_SendChar(Uart0,'A');
//	Uart_SendChar(Uart0,'\n');
}
else {
		Uart_SendChar(Uart0,'C');
		Uart_SendChar(Uart0,'\n');


}
}
} 
 



