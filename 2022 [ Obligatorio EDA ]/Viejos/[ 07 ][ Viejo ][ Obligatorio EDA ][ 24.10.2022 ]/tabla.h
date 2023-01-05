#ifndef TABLA_H
#define TABLA_H
#include "listaColumnas.h"
#include "listaFilas.h"


typedef struct nodo_tabla * Tabla;


Tabla crearTabla();
/*crea una tabla vacia
punteros: t->inicioFila
            t->finFila
            t->inicioCol
            t->finCol
todos a NULL */

int insertarListaColumna(Tabla &t, char * namecol, TipoClas clase, TipoDato tipo);
//agrega una lista de columnas lc a la tabla t al final y retorna la posicion de la columna

TipoRet eliminarListaColumna(Tabla &t, char * namecol);
// elimina lc de la tabla t

Tabla insertarFilaEnPos(Tabla &t, int pos);
//Inserta a la

ListaColumnas primeraColumna(Tabla t);
// devuelve el primer nodo de la lista de filas de la tabla t

Tabla eliminarListaFila(Tabla &t, ListaFilas f);
// elimina f de la tabla t

TipoClas tipoClasificacionColumna(Tabla t, char* nombreCol);
//Retorna el tipo de clasificacion de la columna de nombre nombreCol de la tabla t
//PRE: existe la columna nombreCol

int cantidadColumnasenTabla(Tabla t);
//Retorna la cantidad de columnas de la tabla t

bool modificarTuplaCond(Tabla &t, condicion c, char * nuevoDato);
// modifica las tuplas que cumplen con la condicion

void eliminarDatodeTabla(Tabla &t,  int pos);
// elimina el dato de la tabla t que se encuentra en la posicion pos de cada fila

TipoRet modificarColumnaTabla(Tabla &t, char * nombreColActual, char * namecol, TipoClas clas, TipoDato tipo);
// modifica la columna con nombre nombreActual en la tabla t

ListaFilas primerFiladeFilas(Tabla t);
// devuelve el primer nodo de la lista de filas de la tabla t

TipoDato tipoDatoTuplaenCol(Tabla t, int pos);
// devuelve el tipo de dato de las tuplas en posicion pos

void conversionDato(Tabla &t, int pos);
// modifica el dato de las tuplas de la tabla t en posicion pos
// ej: si el dato es un string, lo modifica a integer, y viceversa

bool existePKenTabla(Tabla t);
// devuelve true si y solo si existe una columna con clasificacion primary key en la tabla  t

void vaciarTabla(Tabla &t);
// elimina todas las filas y lista de filas

void insertarTupla(Tabla &t, int pos, char * valorDato);
//inserta en la tabla t el valor del dato valorDato en la posicion pos 

void imprimirTabla(Tabla t);
// imprime la tabla entera, primero la lista de columnas y luego la lista de filas

void destruirTabla(Tabla &t);
// destruye la tabla t

void insertarTupla(Tabla &t, char * columnasTupla, char * valoresTupla);
//inserta los datos a una nueva tupla

void eliminarFilaCond(Tabla &t, condicion c);
// elimina la fila de datos completa

void imprimirNombresColumnas(Tabla t);
// imprime los nombres de las columnas

void imprimirTuplasOrd(Tabla t);
// imprime las tuplas de forma ordenada separadas con :

void imprimirInfoColumnas(Tabla t);
// imprime solo la informacion de las columnas

#endif
