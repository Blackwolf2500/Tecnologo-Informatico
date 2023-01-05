#ifndef FILA_H
#define FILA_H

#include "define.h"
#include "dato.h"

typedef struct nodo_fila * Fila;


Fila crearFila();
// crea una fila vacia

void insertarDato(Fila &f, Dato d, int pos);
// inserta el dato d  en la fila f  en la posicion pos
// Pre: pos >= 1

void eliminarDato(Fila &f, int pos);
// Elimina el dato en la posicion pos de la fila f
// Pre: f != NULL && pos >= 1

Fila modificarDato(Fila &f, int pos, Dato d);
// modifica el dato en la posicion pos en la fila f por el dato d
// Pre: f != NULL && pos >= 1

Fila siguienteFila(Fila f);
// devuelve la fila siguiente a f
// esto me da el f->sig

bool esVaciaFila(Fila &f);
// devuelve true si y solo si la fila f es vacia, false en caso contrario

void modificarTDato(Fila &f, int pos);
// modifica el dato de la fila f en posicion pos

TipoDato tipoDatoFila(Fila f, int pos);
// devuelve el tipo de dato del elemento en la posicion pos

void destruirFila(Fila &f);
// Destruye toda la fila de datos

Dato infoDato(Fila f, int pos);
// me devuelve el dato de la fila f en la posicion pos
// Pre: f != NULL && pos >= 1

void imprimirFila(Fila f);
// imprime todos los datos de la fila f (va  a imprimir la tupla)

#endif