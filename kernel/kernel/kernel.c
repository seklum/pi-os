#if !defined(__cplusplus)
#include <stdbool.h>
#endif

#include <stdint.h>
#include <kernel/uart.h>
#include <kernel/irq.h>

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

	irq_init();
	irq_test();

	while(true)
		uart_putc(uart_getc());
}
