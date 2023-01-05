#ifndef LISTAGENERAL_H
#define LISTAGENERAL_H

typedef struct NodoLista * lista;

lista Null();
// Crea la lista vacia.
lista Cons(lista l, int e);
// Inserta el elemento e al principio de la lista l.
lista Snoc(lista l, int e);
//Retorna el dato al final de la lista
bool IsEmpty(lista l);
// Retorna “ true” si l es vacía, “false” en caso contrario.
bool IsElement(lista l, int e);
// Retorna “true” si e pertenece l, “false” en caso contrario.
int Head(lista l);
// Retorna si l no es vacía el primer elemento de la lista.
lista Tail(lista l);
// Retorna si la l no es vacía, la lista sin su primer elemento.

#endif