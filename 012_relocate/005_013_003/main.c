/**
  *********************************************************************************************************
  * @File               : main.c 
  * @Author             : kang.yunjie 
  * @version            : V1.0 
  * @Date               : 2018-08-03 22:05:27 
  * @Brief              : Main
  *********************************************************************************************************
  * @attention          : 
  *                       
  *********************************************************************************************************
  */

#include "s3c2440_soc.h"
#include "led.h"
#include "uart.h"
#include "my_printf.h"
#include "init.h"

char g_Char = 'A';
char g_Char3 = 'a';
const char g_Char2 = 'B';
int g_A = 0;
int g_B;

/**********************************************************************************************************
 @Function               int main(void)
 @Description            main
 @Input                  void
 @Return                 void
**********************************************************************************************************/
int main(void)
{
	uart0_init();
	
	puts("\r\ng_A = ");
	printHex(g_A);
	puts("\r\n");
	
	while (true) {
		putchar(g_Char);
		g_Char++;
		
		putchar(g_Char3);
		g_Char3++;
		
		delay(1000000);
	}
	
	return 0;
}

/********************************************** END OF FLEE **********************************************/
