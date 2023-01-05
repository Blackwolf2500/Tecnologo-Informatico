#include <iostream>
#include "listaParcial.h"

using namespase std;

struct nodo_lista{
    int dato;
    listaDE sig;
};

lista insert(int x, listaDE l){
//Inserta un dato ordenadamente dentro de la lista.
//Pre: la lista esta ordenada.
    listaDE aux = new(nodo_listaDE);
    aux->dato = x;
    if(l == NULL){
        l = aux;
        aux->ant = NULL;
        aux->sig = NULL;
    }else if(l != NULL){
        listaDE iter = l;
        while((iter->ant != NULL)&&(iter->dato > x)){
            iter = iter->ant;
        }
        while((iter->sig != NULL)&&(iter->dato <= x)){
            iter = iter->sig;
        }
        if(iter->dato > x){
            aux->sig = iter;
            if(iter->ant!=NULL){
                iter->ant->sig = aux;
            }
            aux->ant = iter->ant;
            iter->ant = aux;
        }else{
            aux->ant = iter;
            iter->sig = aux;
            aux->sig = NULL;
        }
        return l;
    }
}

bool IsEmpty (lista l){
// Retorna “true” si l es vacía, “false” en caso contrario.
    return false;
}
int Head (lista l){
// Retorna el primer elemento de la lista.
// Pre: l no vacía.
    return l->dato;
}
lista Tail (lista l){
// Retorna la lista sin su primer elemento.
// Pre: l no vacía.
    return l->sig;
}

bool par (lista l){
// Retorna true si la cantidad de elementos de l es par
// false en caso contrario.
    if(IsEmpty(l)){
        return true;
    }else{
        return !par(Tail(l));
    }
}

bool subLista (lista s, lista l){
// Retorna true si s es una sublista de l.
// Pre: l y s están ordenadas y no hay elementos repetidos.
   if(IsEmpty(s)){
       return true;
   }else if(!IsEmpty(l)){
    if(Head(l)>Head(s)){
       return false;
    }else if(Head(l)==Head(s)){
       if(IsEmpty(s)){
           return true;
       }else if(IsEmpty(Tail(l))){
           return false;
       }else if(Head(Tail(l))==Head(Tail(s))){
           return subLista(Tail(s), Tail(l));
       }else{
           return false;
       }
   }else{
       return subLista(s, Tail(l));
   }
}