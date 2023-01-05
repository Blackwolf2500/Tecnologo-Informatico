#include "lista.h"
#include <iostream>

using namespace std;

struct nodo_lista{
    int dato;
    lista sig;
}

bool IsElement(int x, lista l){
// Retorna true si x pertenece a l, false en caso contrario.
    bool bus=false;
    while ((l!=NULL)&&(!bus)){//si l es distinto a null y bus esta en false
        if(l->dato==x){ bus=true; }//si el dato al que apunta l es igual a 'x' entonces bus es verdadero
        l=l->sig;//pase o no la condicion l pasara al siguiente nodo
    }
    return bus;
}

int Length(lista l){
// Retorna la cantidad de elementos de la lista
    int con = 0; //declaro contador
    while (l!=NULL){
        con++;//contador +1
        l=l->sig;
    }
    return con;
}

int Last(lista l){
// Retorna el último elemento de l.
// Pre: l no es vacía.
    while(l->sig!=NULL){//si el siguiente nodo no es null
        l=l->sig;
    }
    return l->dato;
}

int Max(lista l){
// Retorna el máximo elemento de l.
// Pre: l no es vacía.
    int max = l->dato;
    while(l->sig!=NULL){
        l->sig;
        if(max<l->dato){
            max=l->dato;
        }
    }
    return max;
}

float Average(lista l){
// Retorna si la lista no es vacía el promedio de sus elementos.
// Pre: l no es vacía.
    int prom=0,con=0;
    while(l->sig!=NULL){
        l=l->sig;
        prom += l->dato;//prom = prom + l->dato;
        con++;
    }
    return (float)(prom/con);
}

lista Insert(int x, lista l){
// Inserta ordenadamente el elemento x en la lista ordenada l. 
    lista ant = NULL, iter = l;//determinamos un iterador y un anterior para recorrer los nodos
    while((iter!=NULL)&&(x>iter->dato)){
        ant=iter; //anterior se pocisiona en iterador
        iter=iter->sig; // iterador avanza
    }
    lista aux = new(nodo_lista);
    aux->dato=x;
    aux->sig=iter;
    if(ant!=NULL){
        ant->sig=aux
    }else{
        l=aux; //aputa l al primero si el anterior es null
    }     
    return l;
}

lista Snoc(int x, lista l){
// Inserta el elemento x al final de la lista l.
    lista aux=new(nodo_lista);
    aux->dato=x;
    aux->sig=NULL;
    if(l==NULL){
        return aux;
    }else{
        lista iter=l;
        while(iter->sig!=NULL){
            iter=iter->sig;
        }
        iter->sig=aux;
    }
    return l;
}

lista Remove(int x, lista l){
// Elimina todas las ocurrencias de x en la lista l
    lista ant=NULL, iter=l;
    while(iter!=NULL){
        if(iter->dato==x){
            if(ant==NULL){//Regunta si es el primero
                l=l->sig;
                delete iter;
                iter=l;
            }else{
                ant->sig=iter->sig;// apunta el siguiente de ant a el siguiente de iter
                delete iter;// elimina iter
                iter=ant->sig;//apunta al siguiente de ant
            }
        }else{
            ant=iter;
            iter=iter->sig;
        }
    }
    return l;
}

bool Equals(lista l, lista p){
// Verifica si las listas l y p son iguales (mismos elementos en el mismo orden).
    bool igual = true;
    while((l!=NULL)&&(p!=NULL)&&(l->dato==p->dato)){
        l=l->sig;
        p=p->sig;
    }
    if((l==NULL)&&(p==NULL)){
        return true;
    }else{
        return false;
    }
}
