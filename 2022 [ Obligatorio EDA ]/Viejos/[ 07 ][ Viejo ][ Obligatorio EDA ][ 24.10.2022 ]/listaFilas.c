#include "listaFilas.h"
#include <stdio.h>
#include "define.h"
#include "fila.h"
#include "filaOrdenada.h"
#include "condicion.h"


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
    while (!esVaciaFila(siguienteFila(iter))) 
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

bool modificarFila(ListaFilas &lf, int posicion, condicion c, char * nuevoDato){
    return modificaDatoFila(lf->primero, posicion, c, nuevoDato);
}

bool eliminarFila(ListaFilas &lf, int pos, condicion c){
// elimina la/s fila/s que cumplen con la condicion "cond" 
//de la lista de filas fs 
    return elimFila(lf->primero, pos, c);
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

TipoDato returnTipoDato__(char * tipoCol){
// devuelve la clasificacion del tipo de dato pasado
	int i = atoi(tipoCol);
	if (i == 0 && strcmp(tipoCol, "0") != 0 )
		return TSTRING;
	else return TINTEGER;
}

void insertarEnLF(ListaFilas &lf, int pos, char* valorDato, int cantCols){
    Fila f = crearFilaEmpty(cantCols);
    TipoDato td = returnTipoDato__(valorDato);
    if(td == TSTRING)
        Dato d = crearDatoChar(valorDato);
    else
        Dato d = crearDatoInt(atoi(valorDato));
    insertarDato(f, d, pos);
}


void modificarTD(ListaFilas &lf, int pos){
//  modifica el dato de las tuplas de la tabla t en posicion pos en cada fila de la tabla
// ej: si el dato es un string, lo modifica a integer, y viceversa (Cambia "columna")
    ListaFilas iter = lf;
    while(iter != NULL) {
        modificarTDato(iter->primero, pos);
        iter = iter->sig;
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
        eliminarDato(iter->primero, pos);
        iter = iter->sig;
    }
}

bool esVaciaListaFila(ListaFilas lf){
// devuelve true si y solo si lf es vacia, de lo contrario retorna false
    return (lf == NULL);
}

void imprimirListaFilas(ListaFilas fs){
// imprime toda la lista filas y su fila correspondiente
    ListaFilas iter = fs;
    if(iter != NULL){
        imprimirFila(iter->primero);
        imprimirListaFilas(iter->sig); 
    }   
}

void elimNodoLF(ListaFilas &lf){
    delete(lf);
}

void destruirListaFilas(ListaFilas &lf){
// Destruye todas las listas y filas 
    ListaFilas aborrar = lf;
    while(lf != NULL) {
        destruirFila(lf->primero); // destruye toda la fila
        lf = lf->sig;
        delete(aborrar);
        aborrar = lf;
    }
}


//  ESTAS DOS SIGUIENTES NO ME CONVENCEN!!!!


void eliminarNodoListaFilaMedio(ListaFilas &ant, ListaFilas &borrar){
    ant->sig = borrar->sig;
    delete (borrar);
}

void eliminarNodoListaFilaFinal(ListaFilas &ant, ListaFilas &borrar){
    ant->sig = NULL;
    delete (borrar);
}
