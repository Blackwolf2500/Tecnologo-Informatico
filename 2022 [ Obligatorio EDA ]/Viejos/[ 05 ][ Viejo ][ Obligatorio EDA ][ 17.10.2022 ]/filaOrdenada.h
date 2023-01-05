#ifndef FILAORDENADA_H
#define FILAORDENADA_H


#include "define.h"
#include "listaFilas.h"
#include "dato.h"

typedef struct nodo_fila_ordenada * FilaOrdenada;

FilaOrdenada crearFilaOrdenada();
//crea una fila ordenada vacia

FilaOrdenada insertarFila(FilaOrdenada & fo, ListaFilas lf, Dato d);
// inserta la listaFila lf en la Fila Ordenada fo en orden segun el dato d

FilaOrdenada eliminarFila(FilaOrdenada &fo, Dato d);
// elimina el elemento fila de fo que contiene el Dato d

void destruirFilaOrd(FilaOrdenada &fo);
// destruye toda la estructura de las filas ordenadas


#endif