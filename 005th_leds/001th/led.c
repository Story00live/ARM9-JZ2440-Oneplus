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
  *		   GPFCON		: 0x56000050u
  *		   GPFDAT		: 0x56000054u
  *		   GPFUP		: 0x56000058u
  *********************************************************************************************************
  */

#define	true				1

void delay(volatile int nCount);
int led_on(int which);

/**********************************************************************************************************
 @Function			void
 @Description			点亮LED
 @Input				void
 @Return				void
**********************************************************************************************************/
int main(void)
{
	volatile unsigned int* pGPFCON = (volatile unsigned int*)0x56000050u;
	volatile unsigned int* pGPFDAT = (volatile unsigned int*)0x56000054u;
	int val = 0, tmp;

	/* 设置GPFCON让GPF4/5/6配置为输出引脚 */
	*pGPFCON &= ~((3<<8) | (3<<10) | (3<<12));
	*pGPFCON |=  ((1<<8) | (1<<10) | (1<<12));

	/* 循环点亮 */
	while (true) {
		tmp = ~val;
		tmp &= 7;
		*pGPFDAT &= ~(7<<4);
		*pGPFDAT |=  (tmp<<4);
		delay(100000);
		if (val++ == 8) {
			val = 0;
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
	unsigned int* pGPFCON = (unsigned int*)0x56000050u;
	unsigned int* pGPFDAT = (unsigned int*)0x56000054u;

	switch (which) {
	case 4:
		*pGPFCON = 0x00000100u;
		break;

	case 5:
		*pGPFCON = 0x00000400u;
		break;

	case 6:
		*pGPFCON = 0x00001000u;
		break;
	
	default:
		*pGPFCON = 0x00000100u;
		break;
	}

	*pGPFDAT = 0x00000000u;

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
