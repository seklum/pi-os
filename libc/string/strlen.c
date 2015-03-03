#include <stdint.h>
#include <string.h>

size_t strlen(const char* str)
{
	size_t size;
	for(size = 0; str[size]; size++);
	return size;
}
