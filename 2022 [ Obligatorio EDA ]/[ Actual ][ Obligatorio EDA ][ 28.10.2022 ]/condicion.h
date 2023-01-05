#ifndef CONDICION_H
#define CONDICION_H

#include "define.h"
#include "listaColumnas.h"


typedef struct nodo_condicion * condicion;

TipoOperador operador(char *cond);
// devuelve el operador de cond

char * primerElemCondicion(char *cond);
// retorna el nombre de la columna 

char * segundoElemCondicion(char *cond);
// devuelve el dato de la condicion 

condicion crearCondicion(char * condicion, ListaColumnas col);
// Cra la condicion siempre que la columna exista dentro de la Lista col

char * devuelveNomCol(condicion c);
// devuelve el nombre de la columna en c

bool esVaciaCondicion(condicion c);
// devuelve true si y solo si c es vacia

bool cumpleCondicion(condicion c, Dato d);
// devuelve true si y solo si el dato d cumple con la condicion c


#endif