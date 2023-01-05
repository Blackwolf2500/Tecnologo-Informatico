#ifndef FILA_H
#define FILA_H

#include "define.h"
#include "dato.h"

typedef struct nodo_fila * Fila;


Fila crearFila();
// crea una fila vacia

Fila insertarDato(Fila &f, Dato d, int pos);
// inserta el dato d  en la fila f  en la posicion pos
// Pre: pos >= 1

Fila eliminarDato(Fila &f, int pos);
// Elimina el dato en la posicion pos de la fila f
// Pre: f != NULL && pos >= 1

Fila modificarDato(Fila &f, int pos, Dato d);
// modifica el dato en la posicion pos en la fila f por el dato d
// Pre: f != NULL && pos >= 1

Fila siguienteFila(Fila f);
// devuelve la fila siguiente a f
// esto me da el f->sig

Dato infoDato(Fila f, int pos);
// me devuelve el dato de la fila f en la posicion pos
// Pre: f != NULL && pos >= 1

void imprimirFila(Fila f);
// imprime todos los datos de la fila f (va  a imprimir la tupla)

#endif