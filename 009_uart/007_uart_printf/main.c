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

/**********************************************************************************************************
 @Function               int main(void)
 @Description            main
 @Input                  void
 @Return                 void
**********************************************************************************************************/
int main(void)
{
	unsigned char c;
	
	uart0_init();
	puts("Hello World!!\r\n");
	my_printf_test();
	
	while (true) {
		c = getchar();
		if (c == '\r') {
			putchar('\n');
		}
		if (c == '\n') {
			putchar('\r');
		}
		
		putchar(c);
	}
	
	return 0;
}

/********************************************** END OF FLEE **********************************************/
