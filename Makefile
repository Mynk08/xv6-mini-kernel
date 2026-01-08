CC = gcc
CFLAGS = -fno-pic -static -fno-builtin -fno-strict-aliasing -O2 -Wall -MD
ASFLAGS = -m32
LDFLAGS = -m elf_i386

OBJS = main.o proc.o

xv6.img: $(OBJS)
	$(LD) $(LDFLAGS) -T kernel.ld -o kernel $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o *.d kernel
