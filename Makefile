#Makefile
CC = g++
CFLAGS = -g -Wall -Wextra

default: Stacker

Stacker: stacker.o main.o
	$(CC) $(CFLAGS) -o Stacker stacker.o main.o

stacker.o: stacker.cpp stacker.h
	$(CC) $(CFLAGS) -c stacker.cpp

main.o: main.cpp stacker.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) stacker *.o *~
