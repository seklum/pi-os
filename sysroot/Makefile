CC = arm-none-eabi-gcc
CFLAGS = -mcpu=arm1176jzf-s -fpic -ffreestanding -c

.PHONY : all
all : boot.o kernel.o myos.elf myos.bin

boot.o : boot.S
	$(CC) $(CFLAGS) boot.S -o boot.o

kernel.o : kernel.c
	$(CC) $(CFLAGS) -std=gnu99 kernel.c -o kernel.o -O2 -Wall -Wextra

myos.elf : boot.o kernel.o
	$(CC) -T linker.ld -o myos.elf -ffreestanding -O2 -nostdlib boot.o kernel.o

myos.bin : myos.elf
	arm-none-eabi-objcopy myos.elf -O binary myos.bin

.PHONY : clean
clean :
	rm *o *elf *bin
