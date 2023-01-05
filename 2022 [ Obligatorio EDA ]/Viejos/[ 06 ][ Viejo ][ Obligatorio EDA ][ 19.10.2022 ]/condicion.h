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
// devuelve el dato 

condicion crearCondicion(char * condicion, ListaColumnas col);


bool esVaciaCondicion(condicion c);

#endif