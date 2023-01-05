todo: Main.o Recurcion.o
	g++ -Wall -o programa Main.o Recurcion.o 

Main.o: Main.c
	g++ -Wall -c Main.c

Recurcion.o: Recurcion.c Recurcion.h
	g++ -Wall -c Recurcion.c

clean:
	rm -f *.o
	rm -f programa
