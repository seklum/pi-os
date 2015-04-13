CC = arm-none-eabi-gcc
CFLAGS = -mcpu=arm1176jzf-s -fpic -ffreestanding -c
INC_DIR = -I include -I ../libc/include
.PHONY : all
all : kernel.img

boot.o : arm/boot.S
	$(CC) $(CFLAGS) arm/boot.S -o boot.o

irq.o : arm/irq.S
	$(CC) $(CFLAGS) arm/irq.S -o irq.o

irqhandler.o : arm/irq.c
	$(CC) $(CFLAGS) $(INC_DIR) -std=gnu99 arm/irq.c -o irqhandler.o -O2 -Wall -Wextra

uart.o : arm/uart.c
	$(CC) $(CFLAGS) $(INC_DIR) -std=gnu99 arm/uart.c -o uart.o -O2 -Wall -Wextra

console.o : kernel/console.c
	$(CC) $(CFLAGS) $(INC_DIR) -std=gnu99 kernel/console.c -o console.o -O2 -Wall -Wextra

kernel.o : kernel/kernel.c
	$(CC) $(CFLAGS) $(INC_DIR) -std=gnu99 kernel/kernel.c -o kernel.o -O2 -Wall -Wextra

myos.elf : boot.o kernel.o uart.o irq.o irqhandler.o console.o
	$(CC) $(INC_DIR) -T arm/linker.ld -o myos.elf -ffreestanding -O2 -nostdlib boot.o kernel.o console.o uart.o irq.o irqhandler.o ../libc/libk.a

kernel.img : myos.elf
	arm-none-eabi-objcopy myos.elf -O binary kernel.img

.PHONY : clean
clean :
	rm *o *elf *img
