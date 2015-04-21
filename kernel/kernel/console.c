#include <kernel/console.h>

void printk(const char* str)
{
	uart_puts(str);
}

void newline()
{
	uart_putc('\n');
}

void printChar(unsigned char c)
{
	uart_putc(c);
}

unsigned char* getInputString()
{
	int iter = 0;
	unsigned char * input;
	unsigned char cur;

	do
	{
		cur = uart_getc();
		uart_putc(cur);
		input[iter++] = cur;
	}
	while(cur != '\n');
	input[iter] = '\0';

	return input;
}
