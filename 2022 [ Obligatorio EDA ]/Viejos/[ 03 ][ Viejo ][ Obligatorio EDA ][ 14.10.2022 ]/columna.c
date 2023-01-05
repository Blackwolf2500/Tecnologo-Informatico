#include "columna.h"
#include <stdio.h>
#include <string.h>
#include "define.h"


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

char * nombreColumna(Columna c){
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

void imprimirColumna(Columna c){
//imprime la informacion de la columna c
    for(unsigned int i=0; i< strlen(c->nombreCol); i++ ) {  // esta bien esto???? compila pero no se!
        cout << "Nombre de la columna: " << c->nombreCol[i];
        if (i == strlen(c->nombreCol))
            cout << "\n";
    } 
    cout << "Clasificacion de la Columna: " << c->clas << "\n";
    cout << "Tipo de Dato de la Columna: " << c->tipo << "\n";    
}

