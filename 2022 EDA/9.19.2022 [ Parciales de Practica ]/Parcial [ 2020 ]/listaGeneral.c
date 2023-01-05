#include "listaGeneral.h"

struct nodo_lista{
    int dato;
    lista sig;
}
struct nodo_listaG{
    lista dato;
    listaG sig;
}

bool PerteneceLG(int x, listaG l){
    if(IsEmptyLG(l)){
        return false;
    }else if(IsEmpty(HeadLG(l))){
        return PerteneceLG(x,TailLG(l));
    }else{
        lista aux = HeadLG(l);
        while(!IsEmpty(aux) && Head(aux) != x){
            aux = Tail(aux);
        }
        if(Head(aux) == x){
            return true;
        }else{
            return PerteneceLG(x, TailLG(l));
        }
    }
}