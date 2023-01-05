#ifndef FILAORDENADA_H
#define FILAORDENADA_H


#include "define.h"
#include "listaFilas.h"
#include "dato.h"

typedef struct nodo_fila_ordenada * FilaOrdenada;

FilaOrdenada crearFilaOrdenada();
//crea una fila ordenada vacia

FilaOrdenada insertarFila(FilaOrdenada & fo, ListaFilas lf, int pos);
// inserta la listaFila lf en la Fila Ordenada fo en orden segun el el dato que se encuentra en la posicion pos

void eliminarFilaOrd(FilaOrdenada &fo, ListaFilas lf, int posPK);
// elimina el elemento que contiene a la listaFila lf segun su pk

void imprimirTuplasOrdenadas(FilaOrdenada fo);
// imprime las tuplas de forma ordenada ascendente separadas por :

void destruirFilaOrd(FilaOrdenada &fo);
// destruye toda la estructura de las filas ordenadas


#endif