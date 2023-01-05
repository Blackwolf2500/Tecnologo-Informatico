#include <stdio.h>
#include "define.h"
#include "filaOrdenada.h"
#include "listaFilas.h"
#include "dato.h"




struct nodo_fila_ordenada{
    Dato pk; // dato de la clave 
    ListaFilas lf; //puntero a una ListaFilas de fila
    FilaOrdenada izq;
    FilaOrdenada der;
};  

FilaOrdenada crearFilaOrdenada(){
//crea una fila ordenada vacia
    return NULL;
}

FilaOrdenada insertarFila(FilaOrdenada & fo, ListaFilas lf, Dato d);
// inserta la listaFila lf en la Fila Ordenada fo en orden segun el dato d

void eliminarFilaOrd(FilaOrdenada &fo, ListaFilas lf);
// elimina el elemento fila de fo que contiene el Dato d


void destruirFilaOrd(FilaOrdenada &fo){
// destruye toda la estructura de las filas ordenadas
    if (fo != NULL){
		ts->izq = destruirFilaOrd(fo->izq);
		ts->der = destruirFilaOrd(fo->der);
        borrarDato(fo->pk);
		delete(fo);
	}
}