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
	puts("Enter the Tacc val: \n\r");
	
	while (true) {
		c = getchar();
		putchar(c);
		if (c >= '0' && c <= '7') {
			bank0_tacc_set(c - '0');
			led_test();
		}
		else {
			puts("Error, val should between 0~7\n\r");
			puts("Enter the Tacc val: \n\r");
		}
	}
	
	return 0;
}

/********************************************** END OF FLEE **********************************************/
