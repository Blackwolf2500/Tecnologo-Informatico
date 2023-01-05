#include "Listageneral.h"
#include <iostream>

using namespace std;

struct NodoLista{
    int dato;
    lista sig;
}

lista Null(){
// Crea la lista vacia.
    return NULL;
}

lista Cons(lista l, int dato){
// Inserta el elemento e al principio de la lista l.
    lista aux = new(NodoLista);
    aux->dato = dato;
    aux->sig = l;
    return aux;
}

lista Snoc(lista l, int dato){
//Retorna el dato al final de la lista
    while(l->sig == NULL){
        l = l->sig;
        Snoc();
    }
    lista aux = new(NodoLista);
    aux->dato = dato;
    l->sig = aux;
    return l->sig;
}

bool IsEmpty(lista l){
// Retorna “ true” si l es vacía, “false” en caso contrario.
    return (l==NULL);
}

bool IsElement(lista l, int dato){
// Retorna “true” si e pertenece l, “false” en caso contrario.
    if(l->e == NULL){ return (l==NULL); }
}

int Head(lista l){
// Retorna si l no es vacía el primer elemento de la lista.
//Pre: l != NULL
    return l->dato;
}

lista Tail(lista l){
// Retorna si la l no es vacía, la lista sin su primer elemento.
    return l->sig;
}