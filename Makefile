
CC = gcc
CFLAGS = -Wall -std=c99 -Iinclude -g -pedantic

prog1:
	mkdir bin
	$(CC) $(CFLAGS) src/testMain.c src/String.c -o bin/prog1
clean:
	rm -r bin
