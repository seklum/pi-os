CC = arm-none-eabi-gcc
CFLAGS = -mcpu=arm1176jzf-s -fpic -ffreestanding -c -std=gnu99 -O2 -Wall -Wextra
INC_DIR = -I include -I ../kernel/include

JOBS :=\
string/strlen.o \

.PHONY : all

all : $(JOBS)

libk.a : $(JOBS)
	$(CC) $(CFLAGS) $(JOBS) -o libk.a

%.o : %.c
	$(CC) $(CFLAGS) $(INC_DIR) $< -o $@
