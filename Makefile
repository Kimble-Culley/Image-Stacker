# @file Makefile
# @author Kimble Culley and Sydney
# @date 2024-02-21
#
# Compiles all the files into one excutable, and does error checking.
#
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
