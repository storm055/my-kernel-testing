TARGET = terminal-root-os.bin

CC = gcc
AS = as
LD = ld

CFLAGS = -g -O1 -Wall -Werror
CFLAGS += -m64 -nostdlib -ffreestanding -fno-builtin

ASFLAGS = --64
LDFLAGS = -m elf_x86_64

OBJS = loader.o kernel.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

$(TARGET): linker.ld $(OBJS)
	$(LD) $(LDFLAGS) -T linker.ld -o $@ $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)