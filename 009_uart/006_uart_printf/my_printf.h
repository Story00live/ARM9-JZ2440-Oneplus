#ifndef __MY_PRINTF_H
#define   __MY_PRINTF_H

//#include <stdio.h>
//#include <stdarg.h>
#include "uart.h"

#define __out_putchar					putchar
#define MAX_NUMBER_BYTES					64

int printf(const char *fmt, ...);
int my_printf_test(void);

#endif
