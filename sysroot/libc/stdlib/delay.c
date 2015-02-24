#include <stdlib.h>

static inline void delay(uint32_t count)
{
	asm volatile("__delay_%=:subs %[count], %[count], #1;bne __delay_%=\n"
			:: [count]"r"(count) : "cc");
} 
