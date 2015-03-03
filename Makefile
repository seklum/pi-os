CC = arm-none-eabi-gcc
CFLAGS = -mcpu=arm1176jzf-s -fpic -ffreestanding -c
INC_DIR = -I kernel/include -I libc/include

.PHONY : all clean

all : myos.elf kernel libc

kernel :
	cd kernel; make

libc : 
	cd libc; make

myos.elf : kernel/boot.o kernel/kernel.o
	$(CC) -T kernel/arm/linker.ld -o myos.elf -ffreestanding -O2 -nostdlib kernel/boot.o kernel/kernel.o

myos.bin : myos.elf
	arm-none-eabi-objcopy myos.elf -O binary myos.bin

clean :
	rm *.elf *.bin
	cd kernel; make clean
	cd libc; make clean
