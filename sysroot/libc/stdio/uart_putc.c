#include <stdio.h>

void uart_putc(unsigned char byte)
{
	//Waits for UART to be ready for input
	while(mmio_read(UART_FR) & (1 << 5)){}
	mmio_write(UART_DR, byte);
} 
