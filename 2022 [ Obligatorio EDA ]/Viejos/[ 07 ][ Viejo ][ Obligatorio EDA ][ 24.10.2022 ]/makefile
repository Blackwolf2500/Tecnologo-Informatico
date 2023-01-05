todo: main.o bd.o tablas.o tabla.o listaColumnas.o columna.o listaFilas.o fila.o filaOrdenada.o dato.o condicion.o
	g++ -Wall -o main bd.o main.o tablas.o tabla.o listaColumnas.o columna.o listaFilas.o fila.o filaOrdenada.o dato.o condicion.o
main.o: bd.o main.c
	g++ -Wall -c main.c
bd.o: bd.c bd.h
	g++ -Wall -c bd.c
tablas.o: tablas.c tablas.h
	g++ -Wall -c tablas.c
tabla.o: tabla.c tabla.h
	g++ -Wall -c tabla.c
columna.o: columna.c columna.h
	g++ -Wall -c columna.c
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
condicion.o: condicion.c condicion.h
	g++ -Wall -c condicion.c
clean:
	clear
	rm -f *.o
	rm -f main

