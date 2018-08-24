#ifndef __JZ2440_UART_H
#define   __JZ2440_UART_H

#include "s3c2440_soc.h"

void uart0_init(void);

int putchar(int cByte);
int getchar(void);
int puts(const char *pString);
int printHex(unsigned int val);

#endif
