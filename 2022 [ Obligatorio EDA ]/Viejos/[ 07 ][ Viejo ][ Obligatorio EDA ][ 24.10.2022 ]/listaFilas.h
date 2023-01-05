#ifndef LISTAFILAS_H
#define LISTAFILAS_H

#include "define.h"
#include "fila.h"
#include "condicion.h"

typedef struct nodo_filas * ListaFilas;

ListaFilas crearFilas(Fila f);
//Crea una  lista de filas vacia

void agregar(ListaFilas &lf, ListaFilas agrego);
// inserta agrego luego de lf

bool eliminarFila(ListaFilas &lf, int pos, condicion c);
// elimina la/s fila/s que cumplen con la condicion "cond" 
//de la lista de filas fs

Fila primeraFila(ListaFilas lf);
// devuelve la primer fila de la lista Filas lf

ListaFilas siguienteListaFila(ListaFilas lf);
// Devuelve la siguiente fila de lf

void modificarTD(ListaFilas &lf, int pos);
//  modifica el dato de las tuplas de la tabla t en posicion pos en cada fila de la tabla
// ej: si el dato es un string, lo modifica a integer, y viceversa

bool esVaciaListaFila(ListaFilas lf);
// devuelve true si y solo si lf es vacia, de lo contrario retorna false

bool modificarFila(ListaFilas &lf, int posicion, condicion c, char * nuevoDato);
// modifica de la lista fila las tuplas de las posicion que cumplen con al condicion c

TipoDato tipoDatoTupla(ListaFilas lf, int pos);
// devuelve el tipo de dato de la fila en la posicion pos

void eliminarDatodeFila(ListaFilas &lf, int pos);
// elimina el dato de la/s fila/s que se encuentra en lf, en la posicion pos

void imprimirListaFilas(ListaFilas lf);
// imprime toda la lista filas y su fila correspondiente

void insertarEnLF(ListaFilas &lf, int pos, char* valorDato, int cantCols);
//inserta en lf el dato valorDato en la posicion pos

void elimNodoLF(ListaFilas &lf);

void destruirListaFilas(ListaFilas &lf);
// Destruye todas las listas y filas 

void eliminarNodoListaFilaMedio(ListaFilas &ant, ListaFilas &borrar);
// elimina el nodo borrar que se encuentra en el medio de una Lista de Filas

void eliminarNodoListaFilaFinal(ListaFilas &ant, ListaFilas &borrar);
// elimina el nodo borrar que se encuentra al final de una Lista de Filas




#endif
