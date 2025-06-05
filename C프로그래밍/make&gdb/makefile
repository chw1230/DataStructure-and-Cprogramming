CC = gcc
CFLAGS = -g
TARGET = foo
OBJECTS = foo.o bar.o
SRCS = foo.c bar.c

all: $(TARGET)

foo: $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(OBJECTS)

$(OBJECTS): $(SRCS)
	$(CC) -c $(CFLAGS) $(SRCS)

clean: 
	rm -f $(OBJECTS)
