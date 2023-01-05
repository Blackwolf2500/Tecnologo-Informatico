#include "listaFilas.h"
#include <stdio.h>
#include "define.h"
#include "fila.h"

struct nodo_filas{
    Fila primero; //primer dato de la fila
    Fila ultimo; // ultimo dato de la fila
    ListaFilas sig; // siguiente tupla
};

ListaFilas crearFilas(Fila f){
//Crea una  lista de filas vacia
    ListaFilas fs = new(nodo_filas);
    fs->primero = f;
    Fila iter = f;
    while (!esVaciaFila(siguienteFila(iter))) //  (!siguienteFila(esVaciaFila(iter))) Asi estaba antes(MAL)
        iter = siguienteFila(iter);
    fs->ultimo = iter; // apunta al ultimo de f 
    fs->sig = NULL;
    return fs;
}

//SAQUE EL INSERTAR PORQUE ASI YA EN CREAR SE CREA CON UNA FILA POR LO QUE INSERTAR  NO TIENE SENTIDO

void agregar(ListaFilas &lf, ListaFilas agrego) {
//esta es para ser llamada por tabla para agregar la fila
    lf->sig = agrego;
}

ListaFilas eliminarFila(ListaFilas &fs, char * cond){
// elimina la/s fila/s que cumplen con la condicion "cond" 
//de la lista de filas fs
}


Fila primeraFila(ListaFilas fs){
// devuelve la primer fila de la lista Filas fs
    return fs->primero;
}

Fila ultimaFila(ListaFilas fs){
// devuelve la primer fila de la lista Filas fs
    return fs->ultimo;
}

ListaFilas siguienteListaFila(ListaFilas fs){
// Devuelve la siguiente fila de fs
    return fs->sig;
}

void modificarTD(ListaFilas &lf, int pos){
//  modifica el dato de las tuplas de la tabla t en posicion pos en cada fila de la tabla
// ej: si el dato es un string, lo modifica a integer, y viceversa (Cambia "columna")
    ListaFilas iter = lf;
    while(iter != NULL) {
        modificarTDato(primeraFila(iter), pos);
        iter = siguienteListaFila(iter);
    }
}

TipoDato tipoDatoTupla(ListaFilas lf, int pos){
// devuelve el tipo de dato de la fila en la posicion pos
    return tipoDatoFila(primeraFila(lf), pos);
}

void eliminarDatodeFila(ListaFilas &lf, int pos) {
// elimina el dato de la/s fila/s que se encuentra en lf, en la posicion pos
    ListaFilas iter = lf;
    while(iter != NULL) {
        eliminarDato(primeraFila(iter), pos);
        iter = siguienteListaFila(iter);
    }
}

bool esVaciaListaFila(ListaFilas lf){
// devuelve true si y solo si lf es vacia, de lo contrario retorna false
    return (lf == NULL);
}

void imprimirListaFilas(ListaFilas fs){
// imprime toda la lista filas y su fila correspondiente
    ListaFilas iter;
    if(iter != NULL){
        imprimirFila(iter->primero);
        imprimirListaFilas(siguienteListaFila(iter)); 
    }   
}

void destruirListaFilas(ListaFilas &lf){
    destruirFila(lf->primero); // destruye toda la fila
    delete(lf);
}
// Destruye todas las listas y filas 