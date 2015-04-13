#include <kernel/console.h>

void printk(const unsigned char* str)
{

}

void newline()
{

}

void printChar(const unsigned char c)
{
	uart_putc(c);
}

char* getInputString()
{
	char * input = uart_getc();
	char cur;
	do
	{
		cur = uart_getc();
		input = input + cur;
	}
	while(cur != '\n');

	return input;
}
