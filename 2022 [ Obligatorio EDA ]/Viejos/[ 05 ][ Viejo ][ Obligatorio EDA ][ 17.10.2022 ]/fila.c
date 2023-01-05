#include "dato.h"
#include <stdio.h>
#include "define.h"
#include "fila.h"
#include <iostream>

using namespace std;

struct nodo_fila{
    Dato dato;
    Fila sig;
};

Fila crearFila(){
// crea una fila vacia
    return NULL;
}

void insertarDato(Fila &f, Dato d, int pos){
// inserta el dato d  en la fila f  en la posicion pos
// Pre: pos >= 1 
    Fila aux = new(nodo_fila);
    aux->dato = d;
    if (f == NULL || pos == 1){ // si la lista aun esta vacia o la posicion es la primera
        aux->sig == f; // si f apunta a NULL va a quedar aux sig NULL
        f = aux; // agrega como primer elemento 
    }
    else {
        Fila iter = f;
        int contador = 0;
        while (iter ->sig != NULL && contador < pos - 1){
            iter = iter->sig;
            contador++;
        }
            iter = iter->sig;
        if (iter->sig == NULL){ // si me fui del while porque llegue al final inserto al final
            iter->sig = aux;
            aux->sig = NULL;
        }        
        else { // llegue a la posicion anterior a la que quiero ingresar el dato
            aux->sig = iter->sig;
            iter->sig = aux;
        }
    }
}

void eliminarDato(Fila &f, int pos){
// Elimina el dato en la posicion pos de la fila f
// Pre: f != NULL && pos >= 1
    if (pos == 1) { // si es el primer elemento
        Fila aborrar = f;
        f = aborrar->sig;
        borrarDato(aborrar->dato);
        delete(aborrar);
    }
    else {
        Fila iter = f;
        int contador = 0;
        while (iter->sig != NULL && contador < pos -1){// me quedo en la posicion anterior 
            iter = iter->sig;
            contador++;
        } 
        if (iter->sig == NULL) 
            cout << "El elemento solicitado para eliminar no existe" << "\n";
        else {
            Fila aborrar = iter->sig;
            iter->sig = aborrar->sig;
            borrarDato(aborrar->dato);
            delete(aborrar);
        }
    }
}


void modificarTDato(Fila &f, int pos){
// modifica el dato de la fila f en posicion pos
    Fila iter = f;
    int i = 0;
    while (f != NULL && i < pos)  
        f = f->sig;
    if (f!= NULL) {
        cambiarTD(f->dato);
    } 
}


TipoDato tipoDatoFila(Fila f, int pos) {
// devuelve el tipo de dato del elemento en la posicion pos
// PRE: f!= NULL && pos>=1
    Fila iter = f;
    int i = 0;
    while (f != NULL && i < pos)  
        f = f->sig;
    if (f!= NULL) {
        return tipoDato(f->dato);
    }  

}

Fila modificarDato(Fila &f, int pos, Dato d){
// modifica el dato en la posicion pos en la fila f por el dato d
// Pre: f != NULL && pos >= 1
    Fila iter = f;
    int contador = 0;
    while (iter->sig != NULL && contador <= pos - 1 ){ // quedo parada en el que tengo que cambiar
        iter = iter->sig;
        contador++;
    }
    if (iter->sig == NULL) 
        cout << "El elemento solicitado para modificar no existe" << "\n";
    else{
        Dato nuevo = crearDato(d);
        Dato aborrar = iter->dato;
        iter->dato = nuevo;
        borrarDato(aborrar);
    }
    return f;
}

Fila siguienteFila(Fila f){
// devuelve la fila siguiente a f
    return f->sig;
}

bool esVaciaFila(Fila f){
// devuelve true si y solo si la fila f es vacia, false en caso contrario
    return (f == NULL);
}

Dato infoDato(Fila f, int pos){
// me devuelve el dato de la fila f en la posicion pos
// Pre: f != NULL && pos >= 1
    if( pos == 1)
        return f->dato;
    else{
        Fila iter = f;
        int contador = 0;
        while (iter->sig != NULL && contador <= pos - 1 ){ // quedo parada en el que tengo que cambiar
            iter = iter->sig;
            contador++;
        }
        return iter->dato;
    }    
}

void destruirFila(Fila &f) {
// Destruye toda la fila de datos
    Fila iter = f;
    while (f != NULL) {
        f = f->sig;
        borrarDato(iter->dato);
        delete(iter);
        iter = f;
    }
    delete(f);
}

void imprimirFila(Fila f){
// imprime todos los datos de la fila f (va  a imprimir la tupla)
    while (f != NULL) {
        imprimirDato(f->dato);
        f =  f->sig;
    }
}
