todo: racional.o main.o
	g++ -Wall -o prog main.o racional.o
main.o: main.c
	g++ -Wall -c main.c
racional.o: racional.h racional.c
	g++ -Wall -c racional.c
limpiar:
	rm -f *.o
	rm -f prog
	
