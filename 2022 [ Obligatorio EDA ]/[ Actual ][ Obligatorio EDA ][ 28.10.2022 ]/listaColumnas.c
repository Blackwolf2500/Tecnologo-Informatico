#include "columna.h"
#include <stdio.h>
#include "define.h"
#include <string.h>
#include "listaColumnas.h"
#include <iostream>

using namespace std;

struct nodo_lista_columnas{
    Columna c;
    int cant;   //no deberia ir en tabla?
    ListaColumnas  sig;
};

ListaColumnas crearLCol(){
// crea una lista de columnas vacia
    return NULL;
}

ListaColumnas insertarColumna( ListaColumnas & lc, char * namecol, TipoClas c, TipoDato t){
// inserta una columna con datos nameCol, tipo de clasificacion C y Tipo de Dato t al final
// de la lista de columnas. Devuelve la posicion de la columna contando el primer lugar como 1  
// si ya existe una columna con el mismo nombre, no la agrega y devuelve cero ya que no inserto
    ListaColumnas nuevo = new(nodo_lista_columnas);
    nuevo->c = crearCol(namecol, c, t);
    nuevo->sig = NULL;
    if(lc == NULL) {
        nuevo->cant = 1;
        return nuevo; // seria la primer columna
    }
    else {
        ListaColumnas iter = lc;
        while(iter->sig != NULL && strcmp(nombreDeColumna(iter->c), namecol) != 0)
            iter = iter->sig;
        if (iter->sig == NULL && strcmp(nombreDeColumna(iter->c), namecol) != 0){ // llegamos al final y no hay columna con igual nombre
            iter->sig = nuevo;
            lc->cant++;
        }
        else 
            cout << "No se puede agregar la columna, ya existe una columna con el mismo nombre \n";
        return lc;
    }
}

TipoRet eliminarColumna(ListaColumnas & lc, char * nombre){
// eliminar de lc la columna con nombre "nombre"
//Pre: lc no es vacia
    ListaColumnas aux = lc;
    if (strcmp(nombreDeColumna(aux->c), nombre) == 0) { // si es la primera
        lc = lc->sig;
        eliminarDatoCol(aux->c);
        delete(aux);
        lc->cant--;
        return OK;
    }
    else {
        while (aux->sig != NULL && strcmp(nombreDeColumna(aux->sig->c), nombre) != 0)  // mientras la lista no sea vacia y no encontremos el nombre
            aux = aux->sig;
        if (aux->sig == NULL ){ // si no encontre el nombre
            cout << "No se pudo eliminar la columna, la misma no se encuentra en la tabla \n";
            return ERROR;
        }
        else {
            ListaColumnas aborrar = aux->sig;
            aux->sig = aborrar->sig;
            eliminarDatoCol(aborrar->c);
            delete(aborrar);
            lc->cant--;
            return OK;
        }
    }
}

int cantidadColumnas(ListaColumnas lc){
//Retorna la cantidad de columnas de la lista de columnas lc
    return lc->cant;
}

TipoClas tipoClaseColumna(ListaColumnas lc, char * nombreCol){
// Retorna el tipo de clasificacion de la columna de nombre nombreCol
//PRE: existe la columna nombreCol
    ListaColumnas iter = lc;
    while (iter!= NULL && strcmp(nombreDeColumna(iter->c), nombreCol) != 0)
        iter = iter->sig;
    return tipoClasCol(iter->c);
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

int posicionColumna(ListaColumnas &lc, char * nombre){
// devuelve la posicion de la columna con nombre "nombre", tomando como primera posicion la 1
// si la columna no existe, devuelve cero
    if (lc == NULL)
        return 0;
    if (strcmp(nombreDeColumna(lc->c), nombre) == 0) { // si es la primera
        return 1;
    }
    else {
        ListaColumnas aux = lc;
        int contador = 1;
        while (aux->sig != NULL && strcmp(nombreDeColumna(aux->sig->c), nombre) != 0){  // mientras la lista no sea vacia y no encontremos el nombre
            aux = aux->sig;
            contador++;
        }
        if (aux->sig == NULL ){// si no encontre el nombre
            cout << "La columna no pertenece a la tabla \n";
            return 0;
        } 
        else {
            return contador +1;
        }
    }    
}

bool existePK(ListaColumnas lc){
// devuelve true si y solo si existe una primary key en la lista de columnas lc
    if(lc== NULL)
        return false;
    else {
        ListaColumnas iter = lc;
        while (iter != NULL && tipoClasCol(iter->c) != PRIMARY_KEY)
            iter = iter->sig;
        if (iter == NULL) //si llego al final es porque no hay pk
            return false;
        else return true; 
    }
}

char * nombreColPos(ListaColumnas lc, int pos){
// devuelve el nombre de la columna en la posicion dada
        ListaColumnas iter = lc;
        for (int i = 1; i < pos; i++)
            iter = iter->sig;
        return nombreDeColumna(lc->c); 
}

Columna buscarcol(ListaColumnas lc, char * nombreColumna){
    if(lc == NULL)
        return NULL;
    ListaColumnas aux = lc;
    while (aux != NULL){  // mientras la lista no sea vacia
        if (strcmp(nombreDeColumna(aux->c), nombreColumna) == 0)
            return aux->c;
        else 
            aux = aux->sig;
    }
    return NULL;
}

bool perteneceColumna(ListaColumnas lc, char * nombreCol){
// devuelve true si la col "nombreCol" ya pertenece a lc
    return (buscarcol(lc, nombreCol) != NULL);
}

int posicionPk(ListaColumnas lc){
// devuelve la posicion de la columna pk
// PRE: existePk(lc)
    ListaColumnas iter = lc;
    int contador = 1; // arranca en la primer columna como 1
    while (iter != NULL && tipoClasCol(iter->c) != PRIMARY_KEY) {
        iter = iter->sig;
        contador++;
    }
    if (iter != NULL){ //no deberia pasar que llegue pq PRE: existePk
        if (tipoClasCol(iter->c) == PRIMARY_KEY)
            return contador;
    }
    cout << "Error, no existe PK \n";
    return -1;
}



TipoRet modificarCol(ListaColumnas & lc, char * nombreColActual, char * namecol, TipoClas c, TipoDato t){
// modifica en lc la columna con nombre "nombreColActual" por los datos nameCol, c, t
// si el nombre de c no es el nombre de otra columna de lc
// Pre: lc no es vacia
    cout << "entro a modificarCol \n";
    if(!perteneceColumna(lc, namecol)){ 
        cout << "La columna nueva no existe \n";
        Columna actual = buscarcol(lc, nombreColActual); // me devuelve la columna a modificar
        if (actual == NULL){
            cout << "La columna no pertenece a la tabla \n";
            return ERROR;
        }
        if (tipoDatoCol(actual) == TSTRING && t == TINTEGER)
            return ERROR;
        modificarColumnaActual(actual, namecol, t, c);
        cout << "se modifico la columna ok \n";
        return OK;
    }
    else{
        cout << "Ya pertenece la columna: " << namecol << " a la tabla \n";
        return ERROR;
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

void  imprimirNombresCol(ListaColumnas c){
// imprime los nombres de las columnas separados por :
    while (c != NULL) {
        imprimirNombre(c->c);
        if (c->sig != NULL)
            cout << ":";
        else 
            cout << "\n";
        c = c->sig;
    }
}

void destruirListaCol(ListaColumnas &lc){
// Destruye la lista de columnas completa lc
    if (lc != NULL) {
        ListaColumnas iter = lc;
        while (lc != NULL) {
            lc = lc->sig;
            eliminarColumna(iter, nombreDeColumna(iter->c));
            iter = lc;
        }
    }
}
