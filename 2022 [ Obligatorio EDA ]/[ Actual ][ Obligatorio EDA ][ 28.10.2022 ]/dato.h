#ifndef DATO_H
#define DATO_H

#include "define.h"

typedef struct nodo_dato * Dato;

Dato crearDatoEmpty();
//Crea el dato "EMPTY"

Dato crearDatoInt(int i) ;
//Crea el dato de tipo integer

Dato crearDatoChar(char * c) ;
//Crea el dato de tipo char

int  datoInt(Dato d);
// retorna el dato int de d 
// PRE: d tiene dato integer valido

char * datoChar(Dato d);
// retorna el dato int de d 
// PRE: d tiene dato string valido

TipoDato tipoDato(Dato d);
// devuelve el tipo de dato de D

bool cambiarDato(Dato &d, char * valorNuevo);
//cambia el valor de d por valorNuevo siempre y cuando sean 
// del mismo tipo de dato o si es EMPTY agrega de cualquier forma

void cambiarTD(Dato &d);
//cambia de int a string o de string a int

void borrarDato(Dato &d);
// borra el dato d

void imprimirDato(Dato d);
// Imprime el dato d

bool isEmpty(char * c);
// devuelve true si y solo si el string c es igual a "EMPTY"

#endif
