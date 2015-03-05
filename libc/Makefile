CC := arm-none-eabi-gcc
CFLAGS := -mcpu=arm1176jzf-s -fpic -c -std=gnu99 -O2 -Wall -Wextra
LIBK_CFLAGS := $(CFLAGS) -ffreestanding
INC_DIR := -I include/

FREEOBJS :=\
string/strlen.o \

HOSTEDOBJS :=\

OBJS :=\
	$(FREEOBJS) \
	$(HOSTEDOBJS) \

LIBK_OBJS :=$(FREEOBJS:.o = .libk.o)

.PHONY : all clean

all : libk.a libc.a

libc.a : $(OBJS)
	$(AR) rcs $@ $(OBJS)

libk.a : $(LIBK_OBJS)
	$(AR) rcs $@ $(LIBK_OBJS)

%.o : %.c
	$(CC) $(CFLAGS) $(INC_DIR) $< -o $@

%.libk.o : %.c
	$(CC) $(LIBK_CFLAGS) $< -o $@

clean :
	rm $(OBJS) $(LIBK_OBJS)
