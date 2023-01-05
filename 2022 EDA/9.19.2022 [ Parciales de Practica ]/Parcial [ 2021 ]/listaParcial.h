#ifndef LISTAPARCIAL_H
#define LISTAPARCIAL_H

typedef struct nodo_lista * lista;

lista Null();
//Inserta un la lista al vacio.
lista insert(int x, lista l);
//Inserta un dato ordenadamente dentro de la lista.
//Pre: la lista esta ordenada.
bool IsEmpty (lista l);
// Retorna “true” si l es vacía, “false” en caso contrario.
int Head (lista l);
// Retorna el primer elemento de la lista.
// Pre: l no vacía.
lista Tail (lista l);
// Retorna la lista sin su primer elemento.
// Pre: l no vacía.
bool par (lista l);
// Retorna true si la cantidad de elementos de l es par
// false en caso contrario.
bool subLista (lista s, lista l);
// Retorna true si s es una sublista de l.
// Pre: l y s están ordenadas y no hay elementos repetidos.
#endif