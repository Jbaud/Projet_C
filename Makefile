projet: projet.o
	gcc projet.o -o projet_baud_deman -lSDLmain -lSDL
projet.o: projet.c projet.h
	gcc -O3 -c projet.c
clean:
	rm -rf *o
start:
	./projet_baud_deman