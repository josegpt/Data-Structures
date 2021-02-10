CC=gcc
CFLAGS=-Wall -Werror -std=c99 -pedantic
SOURCES=$(wildcard lib/**/*.c)
OBJECTS=$(patsubst %.c, %.o, $(SOURCES))

all: main

main: main.c $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm main

.PHONY: clean all
