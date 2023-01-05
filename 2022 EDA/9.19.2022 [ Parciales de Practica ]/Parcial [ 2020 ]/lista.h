#ifndef LISTA_H
#define LISTA_H

typedef struct NodoLista * lista;

lista Null ();
// Crea la lista vacia.
lista Cons (lista l, int e);
// Inserta el elemento e al principio de la lista l.
bool IsEmpty (lista l);
// Retorna “true” si l es vacía, “false” en caso contrario.
int Head (lista l);
// Retorna si l no es vacía el primer elemento de la lista.
lista Tail (lista l);
// Retorna si la l no es vacía, la lista sin su primer elemento.

lista Take_from_to (int i, int f, lista l);
// Retorna la lista resultado de tomar los elementos desde el i hasta el f.
// l no comparte memoria con la lista resultado.
// Se considera i = 1 al primer elemento.
// Pre: i <= f.

int Min(lista l);
// Retorna el mínimo elemento de l.
// Pre: l no es vacía.
#endif