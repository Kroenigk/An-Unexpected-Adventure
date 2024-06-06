#Made by Kylie Roenigk to test and compile files needed for the project The Hobbit
#Variables
CC = g++
CFLAGS = -g -Wall -std=c++11

a.out: the_Hobbit.o the_Hobbit_main.o the_Hobbit.o
	$(CC) $(CFLAGS) the_Hobbit.o the_Hobbit_main.o -o a.out

the_Hobbit.o: the_Hobbit.cc the_Hobbit.h
	$(CC) -c $(CFLAGS) the_Hobbit.cc -o the_Hobbit.o

the_Hobbit_main.o: the_Hobbit_main.cc the_Hobbit.h
	$(CC) -c $(CFLAGS) the_Hobbit_main.cc -o the_Hobbit_main.o

