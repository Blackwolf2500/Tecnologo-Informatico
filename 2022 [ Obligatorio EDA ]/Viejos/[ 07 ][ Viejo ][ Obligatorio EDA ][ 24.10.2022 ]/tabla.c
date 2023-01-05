#include "tabla.h"
#include "listaColumnas.h"
#include "define.h"
#include "listaFilas.h"
#include "fila.h"
#include "filaOrdenada.h"
#include "condicion.h"
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;


struct nodo_tabla{
    FilaOrdenada ford;
    ListaColumnas columnas;
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
    ListaFilas filas = crearFilas(f); //aca creo la fila completa 
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
    return modificarCol(t->columnas, nombreColActual, namecol,clas, tipo);
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

TipoDato return_TipoDato(char * tipoCol){
// devuelve la clasificacion del tipo de dato pasado
	int i = atoi(tipoCol);
	if (i == 0 && strcmp(tipoCol, "0") != 0 )
		return TSTRING;
	else return TINTEGER;
}

bool modificarTuplaCond(Tabla &t, condicion c, char * nuevoDato){
// modifica las tuplas que cumplen con la condicion
    char * nombreColumna = devuelveNomCol(c);
    TipoDato datoCol = tipoDatoCol(buscarcol(t->columnas, nombreColumna));
    TipoDato nuevo = return_TipoDato(nuevoDato);
    if( datoCol == nuevo) {
        int pos = posicionColumna(t->columnas, nombreColumna);// obtengo la posicion de la col
        ListaFilas iter = t->inicioFila;
        bool modifique;
        while (!esVaciaListaFila(iter)){
           modifique = modificarFila(iter, pos, c, nuevoDato);
        }
        return modifique;
    }else return false;
   
}

void insertarTupla(Tabla &t, int pos, char * valorDato){
//inserta en la tabla t el valor del dato valorDato en la posicion pos 
	int cantcol = cantidadColumnas(t->columnas);
	
	insertarEnLF(t->inicioFila, pos, valorDato, cantCol);
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
        bool elimine = eliminarFila(iter, pos, c);
        if (elimine){
            int posPK = posicionPk(t->columnas); // me da la posicion de la pk
            if (iter == t->inicioFila){
                if (iter != t->finFila){
                    t->inicioFila = siguienteListaFila(iter);
                    eliminarFilaOrd(t->ford, iter , posPK); // con el fo, ListaFila y posicion de la pk 
                    elimNodoLF(iter);
                    iter = t->inicioFila;
                    aux = iter;
                }else{ //Queda vacia la lista
                    t->inicioFila = NULL;
                    t->finFila = NULL;
                    eliminarFilaOrd(t->ford, iter , posPK);
                    elimNodoLF(iter);
                }
            }else if(iter == t->finFila){
                t->finFila = aux;
                eliminarFilaOrd(t->ford, iter , posPK);
                eliminarNodoListaFilaFinal(aux, iter);
            }else{
                eliminarFilaOrd(t->ford, iter , posPK);
                eliminarNodoListaFilaMedio(aux, iter);
            }
        }else{   // si no lo elimine
            if (iter != t->inicioFila)
                aux = iter;                                 
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

void imprimirNombresColumnas(Tabla t){
// imprime los nombres de las columnas
    imprimirNombresCol(t->columnas);
}

void imprimirInfoColumnas(Tabla t){
// imprime solo la informacion de las columnas
    if (!esVaciaListaCol(t->columnas)) 
        imprimirListaCol(t->columnas);
}

void imprimirTuplasOrd(Tabla t) {
// imprime las tuplas de forma ordenada separadas con :
    imprimirTuplasOrdenadas(t->ford);
}

void destruirTabla(Tabla &t){
// destruye la tabla t
    destruirListaCol(t->columnas); // elimina todas las columnas
    destruirListaFilas(t->inicioFila); // elimina las filas
    destruirFilaOrd(t->ford); // elimina la estructura ordenada 
    delete(t);
}






