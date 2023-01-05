#ifndef LISTA_H
#define LISTA_H

typedef struct nodo_lista * lista;

lista crear();
//Crea la lista
lista cons(lista l, int dato);
//Inserta al principio de l el dato
int head(lista l);
//Retorna el primer elemento de l
lista tail(lista l);
//Retorna l sin su primer elemento
bool isEmpty(lista l);
//Retorna true si l es vacia, false si es lo contrario
lista destruir_iterativa(lista l);
//Destruye l y libera la memoria asociada
lista destruir_recursiva(lista l);
//Destruye l y libera la memoria asociada


#endif