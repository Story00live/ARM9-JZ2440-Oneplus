/**
  *********************************************************************************************************
  * @File               : exception.c 
  * @Author             : kang.yunjie 
  * @version            : V1.0 
  * @Date               : 2018-08-24 21:07:37 
  * @Brief              : 
  *********************************************************************************************************
  * @attention          : 
  *                       
  *********************************************************************************************************
  */

#include "exception.h"
#include "uart.h"

/**********************************************************************************************************
 @Function               void printException(unsigned int cpsr, char *str)
 @Description            printException
 @Input                  unsignde int
					char*
 @Return                 void
**********************************************************************************************************/
void printException(unsigned int cpsr, char* str)
{
	puts("Exception! cpsr = ");
	printHex(cpsr);
	puts(" ");
	puts(str);
	puts("\r\n");
}

/********************************************** END OF FLEE **********************************************/