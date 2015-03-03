#ifndef _KERNEL_UART_H
#define _KERNEL_UART_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

void uart_init();
void uart_putc(unsigned char byte);
void uart_puts(const unsigned char* str);
unsigned char uart_getc();
void uart_write(const unsigned char* str, size_t size);

enum
{
	//GPIO registers base address.
	GPIO_BASE = 0x20200000,

	//The offsets for each register.

	//Controls actuation of pull up/down to ALL GPIO pins.
	GPPUD = (GPIO_BASE + 0x94),

	//Controls actuation of pull up/down for specific GPIO pin.
	GPPUDCLK0 = (GPIO_BASE + 0x98),

	//UART base address.
	UART0_BASE = 0x20201000,

	//Offsets for each UART register
	UART0_DR     = (UART0_BASE + 0x00),
	UART0_RSRECR = (UART0_BASE + 0x04),
	UART0_FR     = (UART0_BASE + 0x18),
	UART0_ILPR   = (UART0_BASE + 0x20),
	UART0_IBRD   = (UART0_BASE + 0x24),
	UART0_FBRD   = (UART0_BASE + 0x28),
	UART0_LCRH   = (UART0_BASE + 0x2C),
	UART0_CR     = (UART0_BASE + 0x30),
	UART0_IFLS   = (UART0_BASE + 0x34),
	UART0_IMSC   = (UART0_BASE + 0x38),
	UART0_RIS    = (UART0_BASE + 0x3C),
	UART0_MIS    = (UART0_BASE + 0x40),
	UART0_ICR    = (UART0_BASE + 0x44),
	UART0_DMACR  = (UART0_BASE + 0x48),
	UART0_ITCR   = (UART0_BASE + 0x80),
	UART0_ITIP   = (UART0_BASE + 0x84),
	UART0_ITOP   = (UART0_BASE + 0x88),
	UART0_TDR    = (UART0_BASE + 0x8C),
};

static inline void mmio_write(uint32_t reg, uint32_t data)
{
	uint32_t* ptr = (uint32_t*) reg;
	asm volatile("str %[data], [%[reg]]" :: [reg]"r"(ptr), [data]"r"(data));
}

static inline uint32_t mmio_read(uint32_t reg)
{
	uint32_t *ptr = (uint32_t*) reg;
	uint32_t data;
	asm volatile("ldr %[data], [%[reg]]" : [data]"=r"(data) : [reg]"r"(ptr));
	return data;
}

static inline void delay(uint32_t count)
{
	asm volatile("__delay_%=:subs %[count], %[count], #1;bne __delay_%=\n"
			:: [count]"r"(count) : "cc");
}

#endif
