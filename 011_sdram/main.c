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
	sdram_init();
	uart0_init();
	
	while (true) {
		puts("JZ2440 SDRAM Test");
		if (sdram_test() == 0) {
			led_test();
		}
	}
	
	return 0;
}

/********************************************** END OF FLEE **********************************************/
