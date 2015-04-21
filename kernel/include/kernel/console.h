#ifndef __CONSOLE_H_
#define __CONSOLE_H_

#include <string.h>
#include <kernel/uart.h>

#define MAX_CHARS_PER_ROW 120

void printk(const char* str);
void newLine();
void printChar(const unsigned char c);
unsigned char* getInputString();

#endif
