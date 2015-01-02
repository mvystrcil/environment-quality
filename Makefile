CC = avr-gcc
OBJCOPY = avr-objcopy
MCU_TARGET = atmega328p
TARGET = module.elf
HEX = program.hex
BACKUP = $(HEX)_OLD
CFLAGS = -g -Wall -c -mmcu=$(MCU_TARGET)
OBJDIR = $(shell pwd)/obj
OBJECTS = $(OBJDIR)/uart.o $(OBJDIR)/bt.o $(OBJDIR)/io.o $(OBJDIR)/main.o $(OBJDIR)/temp-lib.o $(OBJDIR)/sw-uart.o

export CC
export MCU_TARGET
export CFLAGS
export OBJDIR

all: templib uartlib btlib iolib app
	@echo "Linking together"
	$(CC) -g -mmcu=$(MCU_TARGET) -o $(TARGET) $(OBJECTS)
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

templib:
	@echo "Bulding library for DHT sensor"
	cd temp-lib; make all

app:
	@echo "Main application"
	cd main; make all

flash: all
	avrdude -C /etc/avrdude.conf -p $(MCU_TARGET) -c arduino -P /dev/ttyUSB0 -b 57600 -D -U flash:w:$(HEX)

backup:
	avrdude -vvv -C /etc/avrdude.conf -p $(MCU_TARGET) -c arduino -P /dev/ttyUSB0 -b 57600 -D -U flash:r:$(BACKUP):r
