#include "lista.h"
#include <iostream>

struct NodoLista{
int dato;
lista sig;
}

lista Take_from_to (int i, int f, lista l){
// Retorna la lista resultado de tomar los elementos desde el i hasta el f.
// l no comparte memoria con la lista resultado.
// Se considera i = 1 al primer elemento.
// Pre: i <= f.
    if(IsEmpty(l)){
        return Null();
    }else{
        if(i>1){
            return Take_from_to(i-1,f-1,Tail(l));
        }else if(f>=1){
            return Cons(Head(l),Take_from_to(1,f-1,Tail(l)));
        }else{
            return Null();
        }
    }
}

int Min(lista l){
// Retorna el mínimo elemento de l.
// Pre: l no es vacía.
    if(IsEmpty(Tail(l))){
        return Head(l);
    }else{
        int min_tail = Min(Tail(l));
        if(min_tail > Head(l)){
            return min_tail;
        }else{
            return Head(l);
        }
    }
}