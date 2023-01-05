#include "columna.h"
#include <stdio.h>
#include "define.h"
#include <string.h>
#include "listaColumnas.h"
#include <iostream>


//COMPILA OK


using namespace std;

struct nodo_lista_columnas{
    Columna c;
    int cant;
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
        lc->cant++;
        return nueva; // seria la primer columna
    }
    else {
        ListaColumnas iter = lc;
        while(iter->sig != NULL && strcmp(nombreColumna(iter->c), namecol) != 0)
            iter = iter->sig;
        if (iter->sig == NULL && strcmp(nombreColumna(iter->c), namecol) != 0){ // llegamos al final y no hay columna con igual nombre
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
    if (strcmp(nombreColumna(aux->c), nombre) == 0) { // si es la primera
        lc = lc->sig;
        eliminarDatoCol(aux->c);
        delete(aux);
        lc->cant--;
        return OK;
    }
    else {
        while (aux->sig != NULL && strcmp(nombreColumna(aux->sig->c), nombre) != 0)  // mientras la lista no sea vacia y no encontremos el nombre
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
    return lc;    
}

int cantidadColumnas(ListaColumnas lc){
//Retorna la cantidad de columnas de la lista de columnas lc
    return lc->cant;
}

TipoClas tipoClaseColumna(ListaColumnas lc, char * nombreCol){
// Retorna el tipo de clasificacion de la columna denombre nombreCol
//PRE: existe la columna nombreCol
    ListaColumnas iter = lc;
    while (iter!= NULL && strcmp(nombreColumna(iter->c), nombreCol) != 0)
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


int posicionColumna(ListaColumnas & lc, char * nombre){
// devuelve la posicion de la columna con nombre "nombre", tomando como primera posicion la 1
// si la columna no existe, devuelve cero
// Pre: lc no es vacia
    if (strcmp(nombreColumna(lc->c), nombre) == 0) { // si es la primera
        return 1;
    }
    else {
        ListaColumnas aux = lc;
        int contador = 1;
        while (aux->sig != NULL && strcmp(nombreColumna(aux->sig->c), nombre) != 0){  // mientras la lista no sea vacia y no encontremos el nombre
            aux = aux->sig;
            contador++;
        }
        if (aux->sig == NULL ){// si no encontre el nombre
            cout << "La columna no pertenece a la tabla \n";
            return 0;
        } 
        else {
            return contador;
        }
    }    
}

bool existePK(ListaColumnas lc){
// devuelve true si y solo si existe una primary key en la lista de columnas lc
    if(lc== NULL)
        return false;
    else {
        ListaColumnas iter = lc;
        while (iter != NULL && tipoClasCol(lc->c) != PRIMARY_KEY)
            iter = iter->sig;
        if (iter == NULL) //si llego al final es porque no hay pk
            return false;
        else return true; 
    }
}

bool perteneceColumna(ListaColumnas lc, char * nombreCol){
// devuelve true si la col "nombreCol" ya pertenece a lc
    bool encontre;
    if(lc == NULL)
        encontre = false;
    else if (strcmp(nombreColumna(lc->c), nombreCol) == 0) { // si es la primera
        encontre = true;
    }
    else {
        ListaColumnas aux = lc;
        while (aux != NULL){  // mientras la lista no sea vacia
            if (strcmp(nombreColumna(aux->sig->c), nombreCol) == 0)
                encontre = true;
            else 
                aux = aux->sig;
        }
        if (aux == NULL ) // si no encontre el nombre
            encontre = false;
    }  
    return encontre;
}

TipoRet modificarCol(ListaColumnas & lc, char * nombreColActual, char * namecol, TipoClas c, TipoDato t){
// modifica en lc la columna con nombre "nombreColActual" por los datos nameCol, c, t
// si el nombre de c no es el nombre de otra columna de lc
// Pre: lc no es vacia
    if(!perteneceColumna(lc, nombreColActual)){ //RE POCO EFICIENTE PQ RECORRE DOS VECES, NO SE ME OCURRE OTRA FORMA
        Columna aux = crearCol(namecol, c,t); // creo un nuevo nodo de datos columna
        if (strcmp(nombreColumna(lc->c), nombreColActual) == 0) { // si es la primera
            Columna aborrar = lc->c;
            lc->c = aux;
            eliminarDatoCol(aborrar);
            return OK;
        }
        else {
            ListaColumnas iter = lc;
            while (iter->sig != NULL && strcmp(nombreColumna(iter->sig->c), nombreColActual) != 0){  // mientras la lista no sea vacia y no encontremos el nombre
                iter = iter->sig;
            }
            if (iter->sig == NULL ) { // si no encontre el nombre
                cout << "La columna no pertenece a la tabla \n";
                return ERROR;
            }
            else {
                Columna aborrar = lc->c;
                iter->c = aux;
                eliminarDatoCol(aborrar);
                return OK;
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
    if (lc != NULL) {
        ListaColumnas iter = lc;
        while (lc != NULL) {
            lc = lc->sig;
            eliminarColumna(iter, nombreColumna(iter->c));
            iter = lc;
        }
    }
}
