CC = arm-none-eabi-gcc
CFLAGS = -mcpu=arm1176jzf-s -fpic -ffreestanding -c
INC_DIR = -I include -I ../libc/include
.PHONY : all
all : boot.o kernel.o

boot.o : arm/boot.S
	$(CC) $(CFLAGS) arm/boot.S -o boot.o

uart.o : arm/uart.c
	$(CC) $(CFLAGS) $(INC_DIR) -std=gnu99 arm/uart.c -o uart.o -O2 -Wall -Wextra

kernel.o : kernel/kernel.c uart.o
	$(CC) $(CFLAGS) $(INC_DIR) -std=gnu99 kernel/kernel.c -o kernel.o -O2 -Wall -Wextra

.PHONY : clean
clean :
	rm *o
