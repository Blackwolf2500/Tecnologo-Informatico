todo: main.o bd.o tablas.o tabla.o listaColumnas.o columnas.o listaFilas.o fila.o filaOrdenada.o dato.o
	g++ -Wall -o main bd.o main.o
main.o: bd.o main.c
	g++ -Wall -c main.c
bd.o: bd.c bd.h
	g++ -Wall -c bd.c
tablas.o: tablas.c tablas.h
	g++ -Wall -c tablas.c
tabla.o: tabla.c tabla.h
	g++ -Wall -c tabla.c
columnas.o: columnas.c columnas.h
	g++ -Wall -c columnas.c
listaFilas.o: listaFilas.c listaFilas.h
	g++ -Wall -c listaFilas.c
listaColumnas.o: listaColumnas.c listaColumnas.h
	g++ -Wall -c listaColumnas.c
fila.o: fila.c fila.h
	g++ -Wall -c fila.c
filaOrdenada.o: filaOrdenada.c filaOrdenada.h
	g++ -Wall -c filaOrdenada.c
dato.o: dato.c dato.h
	g++ -Wall -c dato.c
clean:
	rm -f *.o
	rm -f main

