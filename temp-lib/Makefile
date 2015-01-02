SOURCES = temp-lib.c sw-uart.c
OBJECTS = $(SOURCES:.c=.o)

all: $(OBJECTS)

.c.o:
	$(CC) $(CFLAGS) $< -o $(OBJDIR)/$@

clean:
	rm *.o
