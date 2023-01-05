#include "listaFilas.h"
#include <stdio.h>
#include "define.h"
#include "fila.h"

struct nodo_filas{
    Fila primero; //primer dato de la fila
    Fila ultimo; // ultimo dato de la fila
    ListaFilas sig; // siguiente tupla
};

ListaFilas crearFilas(){
//Crea una  lista de filas vacia
    ListaFilas fs = new nodo_filas;
    fs->primero = crearFila();
    fs->ultimo = crearFila();
    fs->sig = NULL;
    return fs;
}

ListaFilas insertarFila(ListaFilas &fs, Fila f){
// inserta la fila f al final de filas fs
}

ListaFilas eliminarFila(ListaFilas &fs, char * cond);
// elimina la/s fila/s que cumplen con la condicion "cond" 
//de la lista de filas fs

Fila primeraFila(ListaFilas fs);
// devuelve la primer fila de la lista Filas fs

ListaFilas siguienteFila(ListaFilas fs);
// Devuelve la siguiente fila de fs

void imprimirListaFilas(ListaFilas fs);
// imprime toda la lista filas y su fila correspondiente