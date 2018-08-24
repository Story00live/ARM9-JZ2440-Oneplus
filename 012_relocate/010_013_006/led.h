#ifndef __JZ2440_LED_H
#define   __JZ2440_LED_H

#include "s3c2440_soc.h"

int led_test(void);
int led_on(int which);
void delay(volatile int nCount);

#endif
