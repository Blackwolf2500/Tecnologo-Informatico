#include "listaDEParcial.h"
#include <iostream>

struct nodo_listaDE{
    int dato;
    listaDE sig;
    listaDE ant;
};

bool simetrica(listaDE l){
    if(l == NULL){
        return true;
    }else{
        if((l->ant==NULL)&&(l->sig==NULL)){
            return true;
        }else{
            listaDE ini=l, fin=l;
            while(ini->ant != NULL){
                ini = ini->ant;
            }
            while(fin->sig != NULL){
                fin = fin->sig;
            }
            while((ini->dato==fin->dato) && ((ini!=fin)||(ini->sig!=fin && fin->ant!=ini))){
                ini=ini->sig;
                fin=fin->ant;
            }
            if(ini->dato==fin->dato){
                return true;
            }else{
                return false;
            }
        }
    }
}

//Leer insertshort y selectshort