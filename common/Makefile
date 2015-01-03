SOURCES = delay.c
OBJECTS = $(SOURCES:.c=.o)

all: $(OBJECTS)

.c.o:
	$(CC) $(CFLAGS) $< -o $(OBJDIR)/$@

clean:
	rm *.o
