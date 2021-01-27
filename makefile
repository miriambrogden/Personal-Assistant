CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -g -Iinclude -c -o

main:
	$(CC) $(CFLAGS) bin/Main.o src/Main.c
	$(CC) $(CFLAGS) bin/Rule.o src/Rule.c
	$(CC) $(CFLAGS) bin/LinkedList.o src/LinkedList.c
	$(CC) $(CFLAGS) bin/BinaryTreeAPI.o src/BinaryTreeAPI.c
	$(CC) $(CFLAGS) bin/Simulation.o src/Simulation.c
	$(CC) bin/Main.o bin/Simulation.o bin/LinkedList.o bin/Rule.o bin/BinaryTreeAPI.o -o bin/runme

test:
	$(CC) $(CFLAGS) bin/BinaryTreeAPI.o src/BinaryTreeAPI.c
	$(CC) $(CFLAGS) bin/TestMain.o src/TestMain.c
	$(CC) $(CFLAGS) bin/Rule.o src/Rule.c
	$(CC) bin/TestMain.o bin/LinkedList.o bin/Rule.o bin/BinaryTreeAPI.o -o bin/testme

testme:
	./bin/testme

clean:
	rm bin/*
