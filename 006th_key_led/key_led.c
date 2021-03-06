/**
  *********************************************************************************************************
  * @file    led.c
  * @author  kang.yunjie@qq.com
  * @version V1.0
  * @date    2018-07-29
  * @brief   JZ2440 LED
  *********************************************************************************************************
  * @attention
  *		   nLED_1		: GPF4
  *		   nLED_2		: GPF5
  *		   nLED_4		: GPF6
  *		   EINT0		: GPF0 
  *		   EINT2		: GPF2
  *		   EINT11		: GPG3
  *		   GPFCON		: 0x56000050u
  *		   GPFDAT		: 0x56000054u
  *		   GPFUP		: 0x56000058u
  *********************************************************************************************************
  */

#include "s3c2440_soc.h"

#define	true				1

void delay(volatile int nCount);
int led_on(int which);

/**********************************************************************************************************
 @Function			void
 @Description			按键点亮LED
 @Input				void
 @Return				void
**********************************************************************************************************/
int main(void)
{
	int val1, val2;

	/* 设置GPFCON让GPF4/5/6配置为输出引脚 */
	GPFCON &= ~((3<<8) | (3<<10) | (3<<12));
	GPFCON |=  ((1<<8) | (1<<10) | (1<<12));

	/* 配置3个按键引脚为输入引脚 */
	GPFCON &= ~((3<<0) | (3<<4));
	GPGCON &= ~((3<<6));

	while (true) {
		val1 = GPFDAT;
		val2 = GPGDAT;

		if (val1 & (1<<0)) {
			/* 松开 */
			GPFDAT |= (1<<6);
		}
		else {
			/* 按下 */
			GPFDAT &= ~(1<<6);
		}

		if (val1 & (1<<2)) {
			/* 松开 */
			GPFDAT |= (1<<5);
		}
		else {
			/* 按下 */
			GPFDAT &= ~(1<<5);
		}

		if (val2 & (1<<3)) {
			/* 松开 */
			GPFDAT |= (1<<4);
		}
		else {
			/* 按下 */
			GPFDAT &= ~(1<<4);
		}		
	}

	return 0;
}

/**********************************************************************************************************
 @Function			int led_on(int which)
 @Description			选择点亮LED
 @Input				int
 @Return				int
**********************************************************************************************************/
int led_on(int which)
{
	switch (which) {
	case 4:
		GPFCON = 0x00000100u;
		break;

	case 5:
		GPFCON = 0x00000400u;
		break;

	case 6:
		GPFCON = 0x00001000u;
		break;
	
	default:
		GPFCON = 0x00000100u;
		break;
	}

	GPFDAT = 0x00000000u;

	return 0;
}

/**********************************************************************************************************
 @Function			void delay(volatile int nCount)
 @Description			延时
 @Input				nCount
 @Return				void
**********************************************************************************************************/
void delay(volatile int nCount)
{
	while (nCount--);
}

/********************************************** END OF FLEE **********************************************/
