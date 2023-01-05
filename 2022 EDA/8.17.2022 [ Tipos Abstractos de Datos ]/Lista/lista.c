#include "lista.h"
#include <iostream>

struct nodo_lista{
    int dato;
    lista sig;
}

lista crear(){
//Crea la lista
    return NULL;
}

lista cons(lista l, int dato){
//Inserta al principio de l el dato
    lista aux = new(nodo_lista); // Creo un auxiliar con un espacio de memoria
    aux -> dato = dato; // Iguala aux al dato dado
    aux -> sig = l; // Despues de colocar el dato en primer lugar, le sigue la lista
    return aux;
}

int head(lista l){
//Retorna el primer elemento de l
//Pre: l != NULL
    return l->dato;
}

lista tail(lista l){
//Retorna l sin su primer elemento
//Pre: l != NULL
    return l->sig;
}

bool isEmpty(lista l){
//Retorna true si l es vacia, false si es lo contrario
    return (l==NULL);
}

lista destruir_iterativa(lista l){
//Destruye l y libera la memoria asociada
//Version Iterativa
    lista aux;//Crea auxiliar
    while (l!=NULL){
        aux = l; // auxiliar apunta al mismo lugar que l
        l = l->sig; // apunta l a la siguiente pocision
        delete aux; // elimina ese espacio de memoria
    }
    return l;
}

lista destruir_recursiva(lista l){
//Destruye l y libera la memoria asociada
//Version Recursiva
    if(l == NULL){
        return l;
    }else{
        l->sig = destruir_recursiva(l->sig);// Recorre toda la lista hasta encontrar el NULL
        delete l; // elimina la memoria en l
    }
    return l;
}