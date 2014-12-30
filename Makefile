CC = avr-gcc
OBJCOPY = avr-objcopy
MCU_TARGET = atmega328p
TARGET = module.elf
HEX = program.hex
CFLAGS = -g -Wall -O1 -c -mmcu=$(MCU_TARGET)
OBJDIR = $(shell pwd)/obj
OBJECTS = $(OBJDIR)/uart.o $(OBJDIR)/bt.o $(OBJDIR)/io.o $(OBJDIR)/main.o

export CC
export MCU_TARGET
export CFLAGS
export OBJDIR

all: uartlib btlib iolib app
	@echo "Linking together"
	$(CC) -o $(TARGET) $(OBJECTS)
	$(OBJCOPY) -j .text -j .data -O ihex $(TARGET) $(HEX)

uartlib:
	@echo "Building UART library"
	cd uart-lib; make all

btlib:
	@echo "Building Bluetooth library"
	cd bt-lib; make all

iolib:
	@echo "Building IO library"
	cd io-lib; make all

app:
	@echo "Main application"
	cd main; make all

flash:
	#avrdude -vvv -C /etc/avrdude.conf -p atmega328p -c arduino -P /dev/ttyUSB0 -b 57600 -D -U flash:r:pokus.hex:r
