#ifndef __CONSOLE_H_
#define __CONSOLE_H_

#include <string.h>
#include <uart.h>

#define MAX_CHARS_PER_ROW 120

void printk(const unsigned char* str);
void newLine();
void printChar(const unsigned char c);

#endif
