#include <stdio.h>

unsigned char uart_getc()
{
	while(mmio_read(UART_FR) & (1 << 4)){}
	return mmio_read(UART_DR);
} 
