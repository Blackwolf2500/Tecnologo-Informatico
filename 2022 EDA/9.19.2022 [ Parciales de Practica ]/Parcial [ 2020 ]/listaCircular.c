#include "listaCircular.h"
struct nodo_listaC{
    int dato;
    listaC sig;
};

listaC eliminar(int x,listaC l){
//Eliminar un elemento x.
    if(l == NULL){
        return l;
    }else{
        bool borre = false;
        listaC ini = l, ant;
        do{
            if(!borre){
                ant = l;
                l = l->sig;
            }else{ borre = flase; }
            if(l->dato == x){
                ant->sig = l->sig;
                if(l == ini){
                    ini = ini->sig;
                }
                if(ant == l){
                    delete l;
                    l = NULL;
                    ini = NULL;
                }else{
                    delete l;
                    l = ant->sig;
                    borre = true;
                }
            }
        }while(l != ini);
        return ini;
    }
}