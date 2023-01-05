#include "columna.h"
#include <stdio.h>
#include <string.h>
#include "define.h"

#include <iostream>

using namespace std;

struct nodo_columna{
    char * nombreCol; 
    TipoClas clas; 
    TipoDato tipo;
};

Columna crearCol(char * nombreCol, TipoClas clase, TipoDato tipo){
// crea la columna con la informacion de la misma
    Columna c = new(nodo_columna);
    c->nombreCol = new char[MAX_COMANDO];
    strcpy(c->nombreCol, nombreCol);
    c->clas = clase;
    c->tipo = tipo;
    return c;
}

char * nombreDeColumna(Columna c){
// devuelve el nombre de la columna
    return c->nombreCol;    
}

void eliminarDatoCol(Columna c){
// elimina los datos de la columna
    delete [] (c->nombreCol);
    delete(c);
}

TipoDato tipoDatoCol(Columna c){
// devuelve el tipo de dato de la columna c
    return c->tipo;
}

TipoClas tipoClasCol(Columna c){
// devuelve el tipo de clasif de la columna c
    return c->clas;
}

void modificarColumnaActual(Columna &c, char * nuevoNombre, TipoDato td, TipoClas clas){
// modifica la info de c por los datos nuevos pasados
    strcpy(c->nombreCol, nuevoNombre);
    c->clas = clas;
    c->tipo = td;
}

void imprimirColumna(Columna c){
//imprime la informacion de la columna c
    if(c != NULL){
        cout << "Nombre de la columna: ";
        for(unsigned int i=0; i< strlen(nombreDeColumna(c)); i++ ) {
            cout << c->nombreCol[i]; // Nombre de la columna:[h][o][l][a]
            if (i == strlen(nombreDeColumna(c)))
                cout << " \n";
        } 
        cout << " Clasificacion de la Columna: " << tipoClasCol(c) << " \n";
        cout << " Tipo de Dato de la Columna: " << tipoDatoCol(c) << " \n";    
    }
}

void imprimirNombre(Columna c) {
// imprime el nombre de la columna
    for(unsigned int i=0; i< strlen(nombreDeColumna(c)); i++ ) 
            cout << c->nombreCol[i];
}
