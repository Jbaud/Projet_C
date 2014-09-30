projet: projet.o
	gcc projet.o -o projet_baud_deman
projet.o: projet.c projet.h
	gcc -c projet.c
clean:
	rm -rf *o
start:
	./projet_baud_deman