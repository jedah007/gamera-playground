CC=gcc
CFLAGS=-std=c++11 -pg -D_DEBUG -g -Wall

PROG ?= prog
OBJS = main.o

# -lstdc++: Links cpp standard library
# -lm

all: $(PROG)

.cpp.o:
	$(CC) $(CFLAGS) -c -o $@ $< -lm -lstdc++

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -lm -lstdc++

clean:
	rm prog main.o
