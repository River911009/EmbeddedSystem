CC = arm-none-eabi-gcc
LD = arm-none-eabi-gcc
BIN = arm-none-eabi-objcopy
STL = st-flash
CFLAGS = -mthumb -mcpu=cortex-m3 -Wall

all: app.bin

main.o: core.S
	$(CC) -x assembler-with-cpp -c -O0 $(CFLAGS) core.S -o core.o

app.elf: linker.ld core.o
	$(LD) core.o $(CFLAGS) --specs=nosys.specs -nostdlib -lgcc -T linker.ld -o app.elf

app.bin: app.elf
	$(BIN) -O binary app.elf app.bin

clean:
	rm -f *.o *.elf *.bin

flash: app.bin
	$(STL) write app.bin 0x8000000

erase:
	$(STL) erase
