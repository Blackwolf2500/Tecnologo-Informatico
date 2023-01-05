#include <iostream>
#include "listaDobleEncadenada.h"

using namespase std;

struct nodo_listaDE{
    int dato;
    listaDE sig;
    listaDE ant;
};

listaDE cons_DE(int x, listaDE l){
//Inserta un dato al inicio de la lista.
    listaDE aux = new(nodo_listaDE);
    aux->dato = x;
    aux->ant = NULL;
    if(l == NULL){
        aux->sig = NULL;
        l = aux;
    }else{
        listaDE iter = l;
        while(iter->ant != NULL){
            iter = iter->ant;
        }
        iter->ant = aux;
        aux->sig = iter;
    }
    return l;
}

listaDE snoc_DE(int x, listaDE l){
//Inserta un dato al final de la lista.
    listaDE aux = new(nodo_listaDE);
    aux->dato = x;
    aux->sig = NULL;
    if(l == NULL){
        aux->ant = NULL
        l = aux;
    }else{
        listaDE iter = l;
        while(iter->sig != NULL){
            iter = iter->sig;
        }
        iter->sig = aux;
        aux->ant = iter;
    }
    return l;
}

listaDE insert_DE(int x, listaDE l){
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

int cantidad(listaDE l){
//Forma recursiva.
//Retorna la cantidad de elementos en la lista.
    if(l == NULL){
        return 0;
    }else{
        return 1 + cant_ant(l->ant)+ cant_sig(l->sig);
    }
}

int cant_ant(listaDE l){
    if(l == NULL){
        return 0;
    }else{
        return 1 + cant_ant(l->ant);
    }
}

int cant_sig(listaDE l){
    if(l == NULL){
        return 0;
    }else{
        return 1 + cant_sig(l->ant);
    }
}

listaDE eliminar_DE(int x,listaDE l){
//Elimina l de la lista.
    if(l == NULL){
        return l;
    }else{
        listaDE iter = l;
        while(l->ant != NULL){
            l = l->ant;
            iter = l;
        }do{
            if(iter->dato == x){
                if(l == iter){ l = l->sig }
                listaDE aux = iter;
                iter = iter->sig;
                if(aux->ant!=NULL){ aux->ant->sig = iter; }
                if(iter!=NULL){ iter->ant = aux->ant; }
                delete aux;
            }else{
                iter = iter->sig;
            }
        }while(iter!=NULL);
        return l;
    }
}

listaDE imprimir(listaDE l){
//Imprime todos los elementos de l.
    if(l != NULL){
        imprimir_ant(l->ant);
        cout <<" [ "<< l->dato <<"] -" ;
        if(l->sig!=NULL){
            imprimir_sig(l->sig);
        }
    }
}

void imprimir_ant(listaDE l){
    if(l!=NULL){
        imprimir_ant(l->ant);
        cout <<" [ "<< l->dato <<"] -" ;
    }
}

void imprimir_sig(listaDE l){
    if(l!=NULL){
        imprimir_sig(l->sig);
        cout <<" [ "<< l->dato <<"] -" ;
    }
}

listaDE imprimir_inv(listaDE l){
//Imprime todos los elementos de l desde el ultimo al primero.

}