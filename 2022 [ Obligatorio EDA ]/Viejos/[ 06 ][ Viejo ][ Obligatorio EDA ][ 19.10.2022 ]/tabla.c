#include "tabla.h"
#include "listaColumnas.h"
#include "define.h"
#include "listaFilas.h"
#include "filas.h"
#include "filaOrdenada.h"
#include "condicion.h"

#include <stdio.h>
#include <iostream>

using namespace std;


struct nodo_tabla{
    FilaOrdenada ford;
    ListaColumnas columnas;
    ListaColumnas finColumnas;
    ListaFilas inicioFila;
    ListaFilas finFila;
};

Tabla crearTabla(){
    Tabla t = new(nodo_tabla);
    t->ford = NULL;
    t->columnas= NULL;
    t->inicioFila = NULL;
    t->finFila = NULL;
    return t;
}

bool existePKenTabla(Tabla t) {
// devuelve true si y solo si existe una columna con clasificacion primary key en la tabla  t
    return existePK(t->columnas);
}

int insertarListaColumna(Tabla &t, char * namecol, TipoClas clase, TipoDato tipo){ 
//agrega una lista de columnas lc a la tabla t al final y retorna la posicion de la columna
    t->columnas = insertarColumna(t->columnas, namecol, clase, tipo);
    int i = posicionColumna(t->columnas, namecol);
    return i;
}

TipoRet eliminarListaColumna(Tabla &t, char * namecol){
// elimina lc de la tabla t
    TipoRet i = eliminarColumna(t->columnas, namecol);
    return i;
}

Tabla insertarFila(Tabla &t, Fila f){
//agrega una lista de filas al final de la tabla t
    ListaFilas filas = crearLFilas(f); //aca creo la fila completa 
    if (t->inicioFila == NULL) {
        t->inicioFila = filas;
        t->finFila = filas;
    }
    else {
        agregar(t->finFila, filas);
        t->finFila = filas;
    }
    return t;
}

Tabla eliminarListaFila(Tabla &t){
// elimina todas las listas de filas de la tabla t
    ListaFilas aux = siguienteListaFila(t->inicioFila);
    while (!esVaciaListaFila(aux)){        
        destruirListaFilas(t->inicioFila);
        t->inicioFila = aux;
        aux = siguienteListaFila(aux);
    }
    return t;
}

TipoRet modificarColumnaTabla(Tabla &t, char * nombreColActual, char * namecol, TipoClas clas, TipoDato tipo){
// modifica la columna con nombre nombreActual en la tabla t
    return modificarCol(t->columnas, nombreColActual, nombrecol,clas, tipo);
}

int cantidadColumnasenTabla(Tabla t){
//Retorna la cantidad de columnas de la tabla t
    return cantidadColumnas(t->columnas);
}

TipoClas tipoClasificacionColumna(Tabla t, char* nombreCol) {
//Retorna el tipo de clasificacion de la columna de nombre nombreCol de la tabla t
//PRE: existe la columna nombreCol
    return tipoClaseColumna(t->columnas, nombreCol);
}

ListaFilas primerFiladeFilas(Tabla t) {
// devuelve el primer nodo de la lista de filas de la tabla t
    return t->inicioFila;
}

ListaColumnas primeraColumna(Tabla t) {
// devuelve el primer nodo de la lista de filas de la tabla t
    return t->columnas;
}

TipoDato tipoDatoTuplaenCol(Tabla t, int pos) {
// devuelve el tipo de dato de las tuplas en posicion pos
    return tipoDatoTupla(t->inicioFila, pos);
}

void conversionDato(Tabla &t, int pos){
// modifica el dato de las tuplas de la tabla t en posicion pos
// ej: si el dato es un string, lo modifica a integer, y viceversa
    modificarTD(t->inicioFila, pos);
}

void eliminarDatodeTabla(Tabla &t,  int pos) {
// elimina el dato de la tabla t que se encuentra en la posicion pos de cada fila
    eliminarDatodeFila(t->inicioFila, pos);
}

void eliminarFilaCond(Tabla &t, condicion c){
// elimina la fila de datos completa
    // aca que estou en la Tabla tengo acceso a las filas y a las col
    // aca es donde tengo que sacar cual es la columna para ya ver si existe o no
    // si la col existe ahi me meto en las filas
    int pos = posicionColumna(t->columnas, devuelveNomCol(c));// obtengo la posicion de la col
    ListaFilas aux = t->inicioFila;
    ListaFilas iter = t->inicioFila;
    while(!esVaciaListaFila(iter)){
        bool elimine = eliminarFila(iter, pos, condicion);
        if (elimine){
            if (iter == t->inicioFila){
                if (iter != t->finFila){
                    t->inicioFila = siguienteListaFila(iter);
                    delete (iter);
                    iter = t->inicioFila;
                    aux = iter;
                }else{                          //Queda vacia la lista
                    t->inicioFila = NULL;
                    t->finFila = NULL;
                    delete (iter);      
                }
            }else if(iter == t->finFila){
                t->finFila = aux;
                eliminarNodoListaFilaFinal(aux, iter);
            }else{
                eliminarNodoListaFilaMedio(aux, iter);
            }
        }else{    
            if (iter != t->inicioFila)
                aux = iter;                                      //No lo elimine
            iter = siguienteListaFila(iter);            
        }
    }
}


void vaciarTabla(Tabla &t) {
// elimina todas las filas y lista de filas
    destruirFilaOrd(t->ford); // elimina la estructura ordenada si es que hay
    destruirListaFilas(t->inicioFila); // elimina las filas
}
    

void imprimirTabla(Tabla t){
// imprime la tabla entera, primero la lista de columnas y luego la lista de filas
    if (!esVaciaListaCol(t->columnas)) {
        imprimirListaCol(t->columnas);
        if (!esVaciaListaFila(t->inicioFila))
            imprimirListaFilas(t->inicioFila);
    }
}

void destruirTabla(Tabla &t){
// destruye la tabla t
    destruirListaCol(t->columnas); // elimina todas las columnas
    destruirListaFilas(t->inicioFila); // elimina las filas
    destruirFilaOrd(t->ford); // elimina la estructura ordenada 
    delete(t);
}






