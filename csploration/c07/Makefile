CC = gcc
CFLAGS = -Wall -I.
LDFLAGS =
OBJFILES = symtable.c symtable.h
TARGET = symtable

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
