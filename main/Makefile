SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

all: $(OBJECTS)
	@echo "Main"

.c.o:
	@echo "Making main"
	$(CC) $(CFLAGS) $< -o $(OBJDIR)/$@

clean:
	rm *.o
