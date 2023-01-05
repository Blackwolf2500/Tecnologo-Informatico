todo: main.o editor.o texto.o lineas.o palabras.o diccionario.o ultpals.o ultpal.o
	g++ -Wall -o main main.o editor.o texto.o lineas.o palabras.o diccionario.o ultpals.o ultpal.o
main.o: main.c
	g++ -Wall -c main.c
editor.o: editor.c editor.h
	g++ -Wall -c editor.c
texto.o: texto.c texto.h
	g++ -Wall -c texto.c
lineas.o: lineas.c lineas.h
	g++ -Wall -c lineas.c
palabras.o: palabras.c palabras.h
	g++ -Wall -c palabras.c
diccionario.o: diccionario.c diccionario.h
	g++ -Wall -c diccionario.c
ultpals.o: ultpals.c ultpals.h
	g++ -Wall -c ultpals.c
ultpal.o: ultpal.c ultpal.h
	g++ -Wall -c ultpal.c
clean:
	rm -f main
	rm -f *.o
