#ifndef LISTAFILAS_H
#define LISTAFILAS_H

#include "define.h"
#include "fila.h"


typedef struct nodo_filas * ListaFilas;

ListaFilas crearLFilas();
//Crea una  lista de filas vacia

ListaFilas insertarFila(ListaFilas &lf, Fila f);
// inserta la fila f al final en la Lista lf

ListaFilas eliminarFila(ListaFilas &lf, char * cond);
// elimina la/s fila/s que cumplen con la condicion "cond" 
//de la lista de filas lf

Fila primeraFila(ListaFilas lf);
// devuelve la primer fila de la lista Filas lf

ListaFilas siguienteListaFila(ListaFilas lf);
// Devuelve la siguiente fila de lf

bool esVaciaListaFila(ListaFilas lf);
// Devuelve true si y solo si la lista lf es vacia

void imprimirListaFilas(ListaFilas lf);
// imprime toda la lista filas y su fila correspondiente

void destruirListaFilas(ListaFilas &lf);
// Destruye todas las listas y filas 


#endif