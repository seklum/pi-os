#if !defined(__cplusplus)
#include <stdbool.h>
#endif
#include <stddef.h>
#include <stdint.h>
#include <kernel/uart.h>
#include <stdio.h>


#if defined(__cplusplus)
extern "C"
#endif
void kernel_main(uint32_t r0, uint32_t r1, uint32_t atags)
{
	(void) r0;
	(void) r1;
	(void) atags;

	uart_init();
	uart_puts("Congratulations!\n The boot was succesfull!\r\n");

	while(true)
		uart_putc(uart_getc());
}
