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

/**********************************************************************************************************
 @Function			void
 @Description			点亮LED
 @Input				void
 @Return				void
**********************************************************************************************************/
int main(void)
{
	unsigned int* pGPFCON = (unsigned int*)0x56000050u;
	unsigned int* pGPFDAT = (unsigned int*)0x56000054u;

	/* 配置GPF4 GPF5 GPF6为输出引脚 */
	*pGPFCON = 0x00001500u;

	/* 设置GPF4 GPF5 GPF6输出0 */
	*pGPFDAT = 0x00000000u;

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
