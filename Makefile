projet: projet.o
	gcc projet.o -Wall -ggdb -o projet_baud_deman  -lm
projet.o: projet.c projet.h
	gcc -c projet.c
clean:
	rm -rf *o
start:
	./projet_baud_deman
