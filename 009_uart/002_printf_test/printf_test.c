/**
  *********************************************************************************************************
  * @File               : printf_test.c 
  * @Author             : kang.yunjie 
  * @version            : V1.0 
  * @Date               : 2018-08-05 20:01:14 
  * @Brief              : printf_test
  *********************************************************************************************************
  * @attention          : 
  *                       
  *********************************************************************************************************
  */

#include <stdio.h>

/**********************************************************************************************************
 @Function               void printf_test(void)
 @Description            printf_test
 @Input                  void
 @Return                 void
**********************************************************************************************************/
void printf_test(void)
{
	printf("hello word\n");
	printf("This is www.100ask.org   my_printf test\n");
	printf("test char           =%c,%c\n", 'A','a');
	printf("test decimal number =%d\n", 123456);
	printf("test decimal number =%d\n", -123456);
	printf("test hex     number =0x%x\n", 0x55aa55aa);
	printf("test string         =%s\n", "www.100ask.org");
}

/**********************************************************************************************************
 @Function               void
 @Description            main
 @Input                  void
 @Return                 void
**********************************************************************************************************/
int main(int argc, char const *argv[])
{
	printf_test();
	
	return 0;
}

/********************************************** END OF FLEE **********************************************/
