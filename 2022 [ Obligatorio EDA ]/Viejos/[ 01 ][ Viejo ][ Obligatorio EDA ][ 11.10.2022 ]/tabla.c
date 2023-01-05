#include "tabla.h"
#include "listaColumnas.h"
#include "define.h"
#include "listaFilas.h"
#include <stdio.h>
#include <iostream>

using namespace std;

struct nodo_tabla{
    ListaColumnas columnas;
    ListaFilas inicioFila;
    ListaFilas finFila;
};

Tabla crearTabla(){
    Tabla t = new(nodo_tabla);
    t->columnas= crearLCol();
    t->inicioFila = crearLFilas();
    t->finFila = crearLFilas();
    return t;
}

Tabla insertarListaColumna(Tabla &t, ListaColumnas lc){
//agrega una lista de columnas lc a la tabla t al final
    if (esVaciaListaCol(lc)){ // si aun no hay una lista de columnas la agrego
        t->columnas = lc;
    }
    return t;
}

Tabla eliminarListaColumna(Tabla &t){
// elimina lc de la tabla t
    if (!esVaciaListaCol(lc)){
        destruirListaCol(lc);
    }
    return t;
}

Tabla insertarListaFila(Tabla &t, ListaFilas lf){
//agrega una lista de filas al final de la tabla t
    if (t->inicioFila == NULL) {
        t->inicioFila = lf;
        t->finFila = lf;
    }
    else {
        Tabla aux = t->inicioFila;
        while (!esVaciaListaFila(siguienteListaFila(aux))){ //si la siguiente no es vacia
            aux = siguienteListaFila(aux); // me muevo para agregar la nueva lf al final
        }
        siguienteListaFila(aux) = lf; // aca las conecto ?????? DUDA! 
        t->finFila = lf;        
    }
}

Tabla eliminarListaFila(Tabla &t){
// elimina todas las listas de filas de la tabla t
    Tabla aux = t->inicioFila;
    while (!esVaciaListaFila(aux)){        
        destruirListaFilas(t->inicioFila);
        t->inicioFila = aux;
        aux = siguienteListaFila(aux);
    }
    return t;
}

void imprimirTabla(Tabla t){
// imprime la tabla entera, primero la lista de columnas y luego la lista de filas
    if (!esVaciaListaCol(t->columnas)) {
        imprimirListaCol(t->columnas);
        if (!esVaciaListaFila(t->inicioFila))
            imprimirListaFilas(t->inicioFila);
    }
}

void destruirTabla(Tabla t){
// destruye la tabla t

}






