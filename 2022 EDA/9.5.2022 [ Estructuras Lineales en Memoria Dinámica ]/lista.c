#include "lista.h"
#include <iostream>

using namespace std;

struct nodo_lista{
int dato;
lista sig;
}

struct nodo_listagral{
lista dato;
listagral sig;
}

lista Null(){
// Crea la lista vacía.
    lista l = NULL;
}

lista Cons(int x, lista l){
// Inserta el elemento x al principio de la lista l.
  lista aux = new(nodo_lista);
    aux -> dato = dato;
    aux -> sig = l; 
    return aux;
}

bool IsEmpty(lista l){
// Retorna true si l es vacía, false en caso contrario.
    return (l==NULL);
}

int Head(lista l){
// Retorna el primer elemento de la lista.
// Pre: l no vacía.
    return l->dato;
}

lista Tail(lista l){
// Retorna la lista sin su primer elemento.
// Pre: l no vacía.
    return l->sig;
}

/*<--      EJERCICIO       -->*/

bool IsElement(int x, lista l){
// Retorna true si x pertenece a l, false en caso contrario.
    if(IsEmpty(l)){
        return false;
    }else if(Head(l)==x){
        return true;
    }else{
        return IsElement(x, Tail(l));
    }
}

lista Remove(int x, lista l){
// Retorna la lista fruto de eliminar x en l.
// l no comparte memoria con la lista resultado.
    if(IsEmpty(l)){
        return Null();
    }else if(Head(l)==x){
        return Remove(x,Tail(l));
    }else{
        return Cons(Head(l), Remove(x,Tail(l)));
    }
}

int Length(lista l){
// Retorna la cantidad de elementos de la lista.
    if(IsEmpty(l)){
        return 0;
    }else{
        return 1 + Length(Tail(l));
    }
}

lista Snoc(int x, lista l){
// Retorna la lista fruto de insertar el elemento x al final de la lista l.
// l no comparte memoria con la lista resultado.
    if(IsEmpty(l)){
        return Cons(x, Null());
    }else{
        return Cons(Head(l), Snoc(x, Tail(l)));
    }
}

lista Append(lista l, lista p){
// Retorna la lista fruto de agregar la lista p al final de la lista l.
// l y p no comparten memoria con la lista resultado.
    if(IsEmpty(l) || IsEmpty(p)){
        return Null();
    }else if(IsEmpty(l)){
        return Cons(Head(p),Append(l, Tail(p)));
    }else{
        return Cons(Head(l),Append(Tail(l), p));
    }
}

lista Insert(int x, lista l, bool inserte){
// Retorna la lista fruto de insertar ordenadamente el elemento x en la lista ordenada l.
// l no comparte memoria con la lista resultado.
    if(IsEmpty(l)){
        if(!inserte){
            return Cons(x, Null());
        }else{
            return Null();
        }
    }else if(Head(l) < x){
        return Cons(Head(l), Insert(x, Tail(l), false));
    }else if(!insete) >= x){
        return Cons(x,Cons(Head(l),Insert(x, Tail(l), true)));
    }else{
        return Cons(Head(l), Insert(x, Tail(l), true));
    }
}

int Last(lista l){
// Retorna el último elemento.
// Pre: l no vacía.
    if(IsEmpty(Tail(l))){
        return Head(l);
    }else{
        return Last(Tail(l));
    }
}

int HowMany(int x, lista l){
// Cuenta las ocurrencias del natural x en la lista l
    if(IsEmpty(l)){
        return 0;
    }else if(Head(l)==x){
        return 1 + HowMany(x, Tail(l));
    }else{
        return HowMany(x, Tail(l))
    }   
}

int Max(lista l){
// Retorna el máximo elemento de l.
// Pre: l no vacía.
    if(IsEmpty(Tail(l))){
        return Head(l);
    }else{
        int max_tail = Max(Tail(l));
        if(max_tail > Head(l)){
            return max_tail;
        }else{
            return Head(l);
        }
    }
}

bool IsSorted(lista l){
// Retorna true si l está ordenada, false en caso contrario.
    if(IsEmpty(l) || IsEmpty(Tail(l))){
        return true;
    }else if(Head(l)<Head(Tail(l)) && IsSorted(Tail(l))==true){
        return true;
    }else{
        return false;
    }
}

lista Change(int x, int y, lista l){
// Retorna una nueva lista fruto de cambiar x por y en l.
// l no comparte memoria con la lista resultado.
    if(IsEmpty(l)){
        return Null();
    }else if(Head(l)==x){
        return Cons(y, Change(x, y , Tail(l)));
    }else{
        return Cons(Head(l), Change(x, y, Tail(l)));
    }
}

lista InsBefore(int x, int y, lista l){
// Retorna una nueva lista fruto de insertar x antes de y en l.
// l no comparte memoria con la lista resultado
    if(IsEmpty(l)){
        return Null();
    }else if(Head(l)==y){
        return Cons(x, Cons(y, InsBefore(x, y, Tail(l))));
    }else{
        return Cons(Head(l), InsBefore(x, y, Tail(l)));
    }
}

lista InsAround(int x, int y, lista l){
// Retorna una nueva lista fruto de insertar x antes y después de y en l.
// l no comparte memoria con la lista resultado.
    if(IsEmpty(l)){
        return Null();
    }else if(Head(l)==y){
        return Cons(x, Cons(y, Cons(x, InsAround(x, y, Tail(l)))));
    }else{
        return Cons(Head(l), InsAround(x, y, Tail(l)));
    }
}

bool Equals(lista l, lista p){
// Retorna true si las listas l y p son iguales (mismos elementos en el mismo orden)
// false en caso contrario.
    if(IsEmpty(l) && IsEmpty(p)){
        return true;
    }else if(IsEmpty(l) || IsEmpty(p)){
        return false;
    }else if(Head(l) != Head(p)){
        return false;
    }else{
        return Equals(Tail(l), Tail(p));
    }
}

void Show(lista l){
// Muestra los elementos de la lista l.
    if(!IsEmpty(l)){
        cout << Head(e) << "->";
        Show(Tail(l));
    }else{
        cout << "-///" << endl;
    }
}

/*<--       Lista General       -->*/

listagral NullLG(){
// Crea la lista general vacía.
    return NULL;
}

listagral ConsLG(listagral lg, lista l){
// Inserta la lista elemento l al principio de la lista general lg.
    listagral aux = new(nodo_listagral);
    aux->dato = l;
    aux->sig = lg;
    return aux;
}

bool IsEmptyLG(listagral lg){
// Verifica si la lista general está vacía.
    return lg == NULL;
}

lista HeadLG(listagral lg){
// Retorna la primer lista elemento.
// Pre: lg no vacía.
    return lg->dato;
}

listagral TailLG(listagral lg){
// Retorna lg sin su primer elemento.
// Pre: lg no vacía.
    return lg->sig;
}

int LengthLG(listagral lg){
// Retorna la cantidad de naturales de la lista general lg.
    if(IsEmptyLG(lg)){
        return 0;
    }else{
        return Length(HeadLG(lg)) + LengthLG(TailLG(lg));
    }
}

void ShowLG(listagral lg){
// Muestra la lista general separando los naturales y listas de naturales por comas y
// encerrando cada lista de naturales entre paréntesis.
    if(!IsEmptyLG(lg)){
        cout << "["<< HeadLG(lg) << "] -> ";
        ShowLG(TailLG(lg));
    }else{
        cout << "-///" << endl;
    }
}