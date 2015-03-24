#include <kernel/uart.h>
#include <stdbool.h>
#include <kernel/irq.h>

#if defined(__cplusplus)
extern "C"
#endif
void irq_handler()
{
	uart_puts("Interrupt");
	return;
}

bool irq_init()
{
	volatile uint32_t* address = (volatile uint32_t*)(0x2000b000);

	//Enable IRQ 1
	*(address + 0x210) = 0xFFFFFFFF;

	//Enable IRQ 2
	*(address + 0x214) = 0xFFFFFFFF;

	//Enable basic IRQ
	*(address + 0x218) = 0x000000FF;

	return true;
}

void irq_test()
{
	asm volatile("SWI #0x0000FF");
}
