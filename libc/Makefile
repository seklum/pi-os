CC = arm-none-eabi-gcc
CFLAGS = -mcpu=arm1176jzf-s -fpic -ffreestanding -c -std=gnu99 -O2 -Wall -Wextra
INC_DIR = -I include -I ../kernel/include

JOBS :=\
stdio/uart_getc.o \
stdio/uart_putc.o \
stdio/uart_putstr.o \
string/strlen.o \

.PHONY : all
all : $(JOBS)

%.o : %.c
	$(CC) $(CFLAGS) $(INC_DIR) $< -o $@
