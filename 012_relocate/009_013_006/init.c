/**
  *********************************************************************************************************
  * @File               : init.h 
  * @Author             : kang.yunjie 
  * @version            : V1.0 
  * @Date               : 2018-08-06 23:50:19 
  * @Brief              : SDRAM Init
  *********************************************************************************************************
  * @attention          : 
  *                       
  *********************************************************************************************************
  */

#include "init.h"

/**********************************************************************************************************
 @Function               void sdram_init(void)
 @Description            sdram_init
 @Input                  void
 @Return                 void
**********************************************************************************************************/
void sdram_init(void)
{
	BWSCON = 0x22000000;
	
	BANKCON6 = 0x00018001;
	BANKCON7 = 0x00018001;
	
	REFRESH = 0x008404F5;
	
	BANKSIZE = 0xB1;
	
	MRSRB6 = 0x20;
	MRSRB7 = 0x20;
}

/**********************************************************************************************************
 @Function               int sdram_test(void)
 @Description            sdram_test
 @Input                  void
 @Return                 int
**********************************************************************************************************/
int sdram_test(void)
{
	volatile unsigned char *p = (volatile unsigned char *)0x30000000;
	int i;
	
	for (i = 0; i < 1000; i++) {
		p[i] = 0x55;
	}
	
	for (i = 0; i < 1000; i++) {
		if (p[i] != 0x55) {
			return -1;
		}
	}
	
	return 0;
}

/**********************************************************************************************************
 @Function               void copy2sdram(volatile unsigned int* src, volatile unsigned int* dest, unsigned int len)
 @Description            copy2sdram
 @Input                  volatile unsigned int* src
					volatile unsigned int* dest
					unsigned int len
 @Return                 void
**********************************************************************************************************/
void copy2sdram(volatile unsigned int* src, volatile unsigned int* dest, unsigned int len)
{
	unsigned int i = 0;
	
	while (i < len) {
		*dest++ = *src++;
		i += 4;
	}
}

/**********************************************************************************************************
 @Function               void clean_bss(volatile unsigned int* start, volatile unsigned int* end)
 @Description            clean_bss
 @Input                  volatile unsigned int* start
					volatile unsigned int* end
 @Return                 void
**********************************************************************************************************/
void clean_bss(volatile unsigned int* start, volatile unsigned int* end)
{
	while (start <= end) {
		*start++ = 0;
	}
}

/********************************************** END OF FLEE **********************************************/
