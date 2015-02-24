#include <stdio.h>

void uart_puts(const unsigned char* str)
{
	mmio_write((const unsigned char*) str, strlen(str));
}
