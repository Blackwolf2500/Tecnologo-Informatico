#ifndef DATO_H
#define DATO_H

#include "define.h"

typedef struct nodo_dato * Dato;

Dato crearDatoInt(int * i) ;
//Crea el dato de tipo integer

Dato crearDatoChar(char * c) ;
//Crea el dato de tipo char

int datoInt(Dato d);

char * datoChar(Dato d);

TipoDato tipoDato(Dato d);
// devuelve el tipo de dato de D

void borrarDato( Dato d);
// borra el dato d

void imprimirDato(Dato d);
// Imprime el dato d


#endif
