#include "columna.h"
#include <stdio.h>
#include <string.h>
#include "define.h"
#include <iostream>

using namespace std;

struct nodo_col{
    char *nombre;
    TipoClas clas; 
    TipoDato tipo;
};

Columna crearCol(char * nombreCol, TipoClas c, TipoDato t){
// crea la columna con la informacion de la misma
    Columna c = new(nodo_col);
    c->nombre = new char[MAX_COMANDO];
    strcpy(c->nombre, nombreCol);
    c->clas = c;
    c->tipo = t;
    return c;
}

char * nombreColumna(Columna c){
// devuelve el nombre de la columna
    return c->nombre;    
}

void eliminarDatoCol(Columna c){
// elimina los datos de la columna

}

TipoDato tipoDatoCol(Columna c);
// devuelve el tipo de dato de la columna c

TipoClas tipoClasCol(Columna c);
// devuelve el tipo de clasif de la columna c

void imprimirColumna(Columna c);
//imprime la informacion de la columna c

