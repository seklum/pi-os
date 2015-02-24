CC = arm-none-eabi-gcc
CFLAGS = -mcpu=arm1176jzf-s -fpic -ffreestanding -c
INC_DIR = -I include/kernel -I ../libc/include
.PHONY : all
all : boot.o kernel.o myos.elf myos.bin

boot.o : arm/boot.S
	$(CC) $(CFLAGS) arm/boot.S -o boot.o

uart.o : arm/uart.c
	$(CC) $(CFLAGS) $(INC_DIR) -std=gnu99 arm/uart.c -o uart.o -O2 -Wall -Wextra

kernel.o : kernel/kernel.c uart.o
	$(CC) $(CFLAGS) $(INC_DIR) -std=gnu99 kernel/kernel.c -o kernel.o -O2 -Wall -Wextra

myos.elf : boot.o kernel.o
	$(CC) -T arm/linker.ld -o myos.elf -ffreestanding -O2 -nostdlib boot.o kernel.o

myos.bin : myos.elf
	arm-none-eabi-objcopy myos.elf -O binary myos.bin

.PHONY : clean
clean :
	rm *o *elf *bin
