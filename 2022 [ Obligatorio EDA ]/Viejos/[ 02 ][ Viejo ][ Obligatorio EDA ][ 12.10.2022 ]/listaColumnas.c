#include "columna.h"
#include <stdio.h>
#include "define.h"
#include <string.h>
#include "listaColumnas.h"
#include <iostream>

using namespace std;

struct nodo_lista_columnas{
    Columna c;
    ListaColumnas  sig;
};

ListaColumnas crearLCol(){
// crea una lista de columnas vacia
    return NULL;
}

ListaColumnas insertarColumna( ListaColumnas & lc, char * namecol, TipoClas c, TipoDato t){
// inserta una columna con datos nameCol, tipo de clasificacion C y Tipo de Dato t al final
// de la lista de columnas  
// si ya existe una columna con el mismo nombre, no la agrega
    ListaColumnas nuevo = new nodo_lista_columnas;
    nuevo->c = crearCol(char * namecol, TipoClas c, TipoDato t);
    nuevo->sig = NULL;
    if(lc == NULL)
        return nuevo;
    else {
        ListaColumnas iter = lc;
        while(iter->sig != NULL && strcmp(nombreColumna(iter->c), namecol) != 0)
            iter = iter->sig;
        if (iter->sig == NULL && strcmp(nombreColumna(iter->c), namecol) != 0) 
            iter->sig = nuevo;
        else 
            cout << "No se puede agregar la columna, ya existe una columna con el mismo nombre \n";
        return lc;
    }
}

ListaColumnas eliminarColumna(ListaColumnas & lc, char * nombre){
// eliminar de lc la columna con nombre "nombre"
//Pre: lc no es vacia
    ListaColumnas aux = lc;
    if (strcmp(nombreColumna(aux), nombre) == 0) { // si es la primera
        lc = lc->sig;
        eliminarDatoCol(aux->c);
        delete aux;
    }
    else {
        while (aux->sig != NULL && strcmp(nombreColumna(aux->sig), nombre) != 0)  // mientras la lista no sea vacia y no encontremos el nombre
            aux = aux->sig;
        if (aux->sig == NULL ) // si no encontre el nombre
            cout << "No se pudo eliminar la columna, la misma no se encuentra en la tabla \n";
        else {
            ListaColumnas aborrar = aux->sig;
            aux->sig = aborrar->sig;
            eliminarDatoCol(aborrar->c);
            delete aborrar;
        }
    }
    return lc;    
}


ListaColumnas finalListaCol(ListaColumnas lc){
//Devuelve el puntero al ultmo elemento de la lista de columnas
    if (lc != NULL){
        ListaColumnas iter = lc;
        while (iter->sig != NULL){
            iter = iter->sig;
        }
        return iter;        
    }
    else return lc;
}

int posicionColumna(ListaColumnas & lc, char * nombre){
// devuelve la posicion de la columna con nombre "nombre"
// Pre: lc no es vacia
    if (strcmp(nombreColumna(lc), nombre) == 0) { // si es la primera
        return 1;
    }
    else {
        ListaColumnas aux = lc;
        int contador = 1;
        while (aux->sig != NULL && strcmp(nombreColumna(aux->sig), nombre) != 0){  // mientras la lista no sea vacia y no encontremos el nombre
            aux = aux->sig;
            contador++;
        }
        if (aux->sig == NULL ) // si no encontre el nombre
            cout << "La columna no pertenece a la tabla \n";
        else {
            return contador;
        }
    }    

}


bool perteneceColumna(ListaColumnas lc, char * nombreCol){
// devuelve true si la col "nombreCol" ya pertenece a lc
    if(lc == NULL)
        return false;
    else if (strcmp(nombreColumna(lc), nombre) == 0) { // si es la primera
        return true;
    }
    else {
        ListaColumnas aux = lc;
        while (aux != NULL){  // mientras la lista no sea vacia
            if (strcmp(nombreColumna(aux->sig), nombre) == 0)
                return true;
            else 
                aux = aux->sig;
        }
        if (aux == NULL ) // si no encontre el nombre
            return false;
    }    
}

ListaColumnas modificarCol(ListaColumnas & lc, char * nombreColActual, char * namecol, TipoClas c, TipoDato t){
// modifica en lc la columna con nombre "nombreColActual" por los datos nameCol, c, t
// si el nombre de c no es el nombre de otra columna de lc
// Pre: lc no es vacia
    if(!perteneceColumna(lc, nombreColActual)){ //RE POCO EFICIENTE PQ RECORRE DOS VECES, NO SE ME OCURRE OTRA FORMA
        ListaColumnas aux = new nodo_lista_columnas:
        aux->c = crearLCol(namecol, c,t);
        if (strcmp(nombreColumna(lc), nombreColActual) == 0) { // si es la primera
            ListaColumnas aborrar = lc;
            aux->sig = lc->sig;
            lc = aux;
            eliminarDatoCol(aborrar->c);
            delete aborrar;
        }
        else {
            ListaColumnas aux = lc;
            int contador = 1;
            while (aux->sig != NULL && strcmp(nombreColumna(aux->sig), nombre) != 0){  // mientras la lista no sea vacia y no encontremos el nombre
                aux = aux->sig;
                contador++;
            }
            if (aux->sig == NULL ) // si no encontre el nombre
                cout << "La columna no pertenece a la tabla \n";
            else {
                return contador;
            }
        }    
    }
    
}

Columna infoCol(ListaColumnas lc){
// devuelve los datos de lc 
    return lc->c;
}

ListaColumnas siguienteCol(ListaColumnas lc){
// devuelve la siguiente columna de lc
    return lc->sig;
}

bool esVaciaListaCol(ListaColumnas lc){
// Devuelve true si la lista de columnas lc esta vacia, de lo contrario devuelve false
    return (lc == NULL);
}

void imprimirListaCol(ListaColumnas lc){
// imprime la lista de columnas con sus datos
    while (lc != NULL) {
        imprimirColumna(lc->c);
        lc = lc->sig;
    }
}

void destruirListaCol(ListaColumnas &lc){
// Destruye la lista de columnas completa lc
    while (lc != NULL) {
        eliminarColumna(lc, nombreColumna(lc->c));
    }
}
