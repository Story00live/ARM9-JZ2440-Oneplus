/**
  *********************************************************************************************************
  * @File               : uart.h 
  * @Author             : kang.yunjie 
  * @version            : V1.0 
  * @Date               : 2018-08-03 21:54:47 
  * @Brief              : JZ2440 UART
  *********************************************************************************************************
  * @attention          : 
  *                       
  *********************************************************************************************************
  */

#include "uart.h"

/**********************************************************************************************************
 @Function               void uart0_init(void)
 @Description            uart0_init
 @Input                  void
 @Return                 void
 @attention			115200, 8, n, 1
					TXD0 : GPH2
					RXD0 : GPH3
**********************************************************************************************************/
void uart0_init(void)
{
	/* 设置串口0使用GPIO引脚 */
	GPHCON &= ~((3<<4) | (3<<6));
	GPHCON |=  ((2<<4) | (2<<6));
	
	/* 设置内部上拉 */
	GPHUP &= ~((1<<2) | (1<<3));
	
	/* 设置波特率
	 * UBRDIVn = (int)( UART clock / ( buad rate x 16) ) –1
	 * UART clock = 50M
	 * UBRDIVn = (int)( 50000000 / ( 115200 x 16) ) –1 = 26
	 * PCLK, 中断/查询模式
	 */
	UCON0 = 0x00000005;
	UBRDIV0 = 26;
	
	/* 设置数据格式 8n1: 8个数据位, 无较验位, 1个停止位 */
	ULCON0 = 0x00000003;
}

/**********************************************************************************************************
 @Function               int putchar(int cByte)
 @Description            putchar
 @Input                  int
 @Return                 int
**********************************************************************************************************/
int putchar(int cByte)
{
	while (!(UTRSTAT0 & (1<<2)));
	UTXH0 = (unsigned char)cByte;
	
	return (unsigned int)cByte;
}

/**********************************************************************************************************
 @Function               int getchar(void)
 @Description            getchar
 @Input                  void
 @Return                 int
**********************************************************************************************************/
int getchar(void)
{
	while (!(UTRSTAT0 & (1<<0)));
	
	return URXH0;
}

/**********************************************************************************************************
 @Function               int puts(const char *s)
 @Description            puts
 @Input                  void
 @Return                 const char*
**********************************************************************************************************/
int puts(const char *pString)
{
	while (*pString) {
		putchar(*pString);
		pString++;
	}
	
	return 0;
}

/**********************************************************************************************************
 @Function               int printHex(unsigned int val)
 @Description            printHex
 @Input                  void
 @Return                 unsigned int
**********************************************************************************************************/
int printHex(unsigned int val)
{
	int index;
	signed char arr[8];
	
	for (index = 0; index < 8; index++) {
		arr[index] = val & 0xF;
		val >>= 4;
	}
	
	puts("0x");
	for (index = 7; index >= 0; index--) {
		if (arr[index] >= 0 && arr[index] <= 9) {
			putchar(arr[index] + '0');
		}
		else if (arr[index] >= 0xA && arr[index] <= 0xF) {
			putchar(arr[index] - 0xA + 'A');
		}
	}
	
	return 0;
}

void dbg_print1(void)
{
	puts("\r\ndbg_print1\r\n");
}

void dbg_print2(void)
{
	puts("\r\ndbg_print2\r\n");
}

/********************************************** END OF FLEE **********************************************/
