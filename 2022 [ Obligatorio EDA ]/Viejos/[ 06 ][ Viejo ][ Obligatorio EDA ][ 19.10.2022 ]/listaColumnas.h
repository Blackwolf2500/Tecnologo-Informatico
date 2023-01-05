#ifndef LISTACOLUMNAS_H
#define LISTACOLUMNAS_H

#include "define.h"
#include "columna.h"


typedef struct nodo_lista_columnas * ListaColumnas;

ListaColumnas crearLCol();
// crea una lista de columnas vacia

ListaColumnas insertarColumna( ListaColumnas & lc, char * namecol, TipoClas c, TipoDato t);
// inserta una columna con datos nameCol, tipo de clasificacion C y Tipo de Dato t al final
// de la lista de columnas  
// si ya existe una columna con el mismo nombre, no la agrega

TipoRet eliminarColumna(ListaColumnas & lc, char * nombre);
// eliminar de lc la columna con nombre "nombre"
//Pre: lc no es vacia

ListaColumnas finalListaCol(ListaColumnas lc);
//Devuelve el puntero al ultmo elemento de la lista de columnas

int posicionColumna(ListaColumnas & lc, char * nombre);
// devuelve la posicion de la columna con nombre "nombre"
// Pre: lc no es vacia

bool existePK(ListaColumnas lc);
// devuelve true si y solo si existe una primary key en la lista de columnas lc


bool perteneceColumna(ListaColumnas lc, char * nombreCol);
// devuelve true si la col "nombreCol" ya pertenece a lc

int cantidadColumnas(ListaColumnas lc);
//Retorna la cantidad de columnas de la lista de columnas lc

TipoClas tipoClaseColumna(ListaColumnas lc, char * nombreCol);
// Retorna el tipo de clasificacion de la columna denombre nombreCol
//PRE: existe la columna nombreCol

Columna buscarcol(ListaColumnas lc, char * nombreColumna);


TipoRet modificarCol(ListaColumnas &lc, char * nombreColActual, char * namecol, TipoClas c, TipoDato t);
// modifica en lc la columna con nombre "nombreColumna" por los datos c 
// si el nombre de c no es el nombre de otra columna de lc
// Pre: lc no es vacia

Columna infoCol(ListaColumnas lc);
// devuelve los datos de lc 

ListaColumnas siguienteCol(ListaColumnas lc);
// devuelve la siguiente columna de lc

bool esVaciaListaCol(ListaColumnas lc);
// Devuelve true si la lista de columnas lc esta vacia, de lo contrario devuelve false

void imprimirListaCol(ListaColumnas lc);
// imprime la lista de columnas con sus datos

void destruirListaCol(ListaColumnas &lc);
// Destruye la lista de columnas completa lc

#endif