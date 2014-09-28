
projet: projet.o
	gcc -o hello hello.o main.o

projet.o: projet.c projet.h
	gcc -o projet.o -c projet.c -W -Wall -ansi -pedantic
