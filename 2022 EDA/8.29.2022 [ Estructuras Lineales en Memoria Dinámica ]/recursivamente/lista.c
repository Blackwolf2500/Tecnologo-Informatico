#include "lista.h"
#include <iostream>

using namespace std;

struct nodo_lista{
    int dato;
    lista sig;
}

bool IsElement(int x, lista l){
// Retorna true si x pertenece a l, false en caso contrario.
    if(l==NULL){return false;} //si l es null entonces IsElement es false
    else if(l->dato==x){return true;}//si el dato es igual a 'x' entonces IsElement es true
    else{return IsElement(x,l->sig);}//Si no es nunguna de las anteriores sigue al siguiente nodo
}

int Length(lista l){
// Retorna la cantidad de elementos de la lista
    int con=0;
    if(l==NULL){return con;}//contador esta en 0 y retorna 0
    else{
        con++;
        Length(l->sig;);
    }
    return con;//Contador va a retornar la cantidad que sume
}

int Last(lista l){
// Retorna el último elemento de l.
// Pre: l no es vacía.
    if(l->sig==NULL){
        return l->dato;
    }else{
        return Last(l->sig);
    }
}

int Max(lista l){
// Retorna el máximo elemento de l.
// Pre: l no es vacía.
    int max = l->dato;
    if(l->sig!=NULL){
        if(l->dato > max){
            max=l->dato;
        }
        Max(l->sig);
    }
    return max;
}

float Average(lista l){
// Retorna si la lista no es vacía el promedio de sus elementos.
// Pre: l no es vacía.
    int prom=0,con=0;
    if(l->sig!=NULL){
        prom += l->dato;//prom = prom + l->dato;
        con++;
        Average(l->sig);
    }
    return (float)(prom/con);
}

lista Insert(int x, lista l){
// Inserta ordenadamente el elemento x en la lista ordenada l. 
    lista ant = NULL, iter = l;//determinamos un iterador y un anterior para recorrer los nodos
    if((iter!=NULL)&&(x>iter->dato)){
        ant=iter; //anterior se pocisiona en iterador
        iter=iter->sig; // iterador avanza
        Insert(x, iter->sig);
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
    
}

lista Remove(int x, lista l){
// Elimina todas las ocurrencias de x en la lista l
}

bool Equals(lista l, lista p){
// Verifica si las listas l y p son iguales (mismos elementos en el mismo orden).
}

lista Take(int i, lista l){
// Retorna la lista resultado de tomar los primeros i elementos.
// l no comparte memoria con la lista resultado.
    if(l == NULL || i==0){//Paso Base
        return NULL;
    }else{
        lista aux=new(nodo_lista);
        axu->dato=l->dato;
        aux->sig=Take(i-1, l->sig);
        return aux;
    }
}

lista Drop(int u, lista l){
// Retorna la lista resultado de no tomar los primeros u elementos.
// l no comparte memoria con la lista resultado.
    if(l==NULL){
        return NULL;
    }else if(u>0){
        return Drop(u-1, l->sig);
    }else{
        lista aux=new(nodo_lista);
        aux->dato=l->dato;
        aux->sig=Drop(0, l->sig);
        return aux;
    }
}

lista Merge(lista l, lista p){
// Genera una lista fruto de intercalar ordenadamente las listas
// l y p que vienen ordenadas.
// l y p no comparten memoria con la lista resultado.
    if(l==NULL && p==NULL){
        return NULL;
    }else{
        lista aux = new(nodo_lista);
        if(l==NULL){
            aux->dato=p->dato;
            aux->sig=Merge(NULL,p->sig);
        }else if(p==NULL){
            aux->dato=l->dato;
            aux->sig=Merge(l->sig, NULL);           
        }else if(l->dato<p->dato){
            aux->dato=l->dato;
            aux->sig=Merge(l->sig, p);
        }else{
            aux->dato=p->dato;
            aux->sig=Merge(l, p->sig);
        }
    }
    return aux;
}

lista Append(lista l, lista p){
// Agrega la lista p al final de la lista l.
// l y p no comparten memoria con la lista resultado.
    if(l==NULL && p==NULL){
        return NULL;
    }else{
        lista aux=new(nodo_lista);
        if(l==NULL){
            aux->dato=p->dato;
            aux->sig=Append(NULL, p->sig);
        }else{
            aux->dato=l->dato;
            aux->sig=Append(l->sig, p);
        }
        return aux;
    }
}