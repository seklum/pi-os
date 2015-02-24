#ifndef _STDIO_H
#define _STDIO_H 1
#include <uart.h>

#ifdef __cplusplus
extern "C" {
#endif

void uart_putc(unsigned char byte);
void uart_puts(const unsigned char* str);
unsigned char uart_getc();

#ifdef __cplusplus
}
#endif

#endif
