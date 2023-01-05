#ifndef LISTAGENERAL_H
#define LISTAGENERAL_H

typedef struct nodo_lista * lista;
typedef struct nodo_listaG * listaG;

lista NullLG();
// Crea la lista vacia.
lista ConsLG(listaG l, int e);
// Inserta el elemento e al principio de la lista l.
bool IsEmptyLG(listaG l);
// Retorna “true” si l es vacía, “false” en caso contrario.
int HeadLG(listaG l);
// Retorna si l no es vacía el primer elemento de la lista.
lista TailLG(listaG l);
// Retorna si la l no es vacía, la lista sin su primer elemento.
bool PerteneceLG(int x, listaG l);
//Retorna true si este pertenece a alguna de las listas simples, false en caso contrario.

lista Null();
// Crea la lista vacia.
lista Cons(lista l, int e);
// Inserta el elemento e al principio de la lista l.
bool IsEmpty(lista l);
// Retorna “true” si l es vacía, “false” en caso contrario.
int Head(lista l);
// Retorna si l no es vacía el primer elemento de la lista.
lista Tail(lista l);
// Retorna si la l no es vacía, la lista sin su primer elemento.
#endif