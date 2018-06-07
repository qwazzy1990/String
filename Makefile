
CC = gcc
CFLAGS = -Wall -std=c99 -Iinclude -g -pedantic
BIN = bin/
SRC = src/
TST = test/

prog1:
	$(CC) $(CFLAGS) -Iinclude $(SRC)String.c $(TST)testMain.c -o $(BIN)prog1


clean:
	rm -f $(BIN)*o $(BIN)*a
