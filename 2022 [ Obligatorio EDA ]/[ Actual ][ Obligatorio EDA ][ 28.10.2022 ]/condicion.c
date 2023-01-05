#include "dato.h"
#include <stdio.h>
#include <string.h>
#include "define.h"
#include "listaColumnas.h"
#include "condicion.h"

#include <iostream>

using namespace std;

struct nodo_condicion {
    char * nombreCol;
    TipoOperador op;
    Dato d;
};

TipoOperador operador(char *cond){
// devuelve el operador de cond
    unsigned int i = 0;
    while( i < strlen(cond)){ // ojo strlen no retorna in int por lo que hay que ver como hcerlo
        if (cond[i] == '>')
            return MAYOR;
        else if (cond[i] == '<')
            return MENOR;
        else if (cond[i] == '=')
            return IGUAL;
        else if (cond[i] == '!')
            return DIFERENTE;
        else i++;
    }
    cout << "Error, no hay operador buscado, el siguiente es incorrecto\n";
    return MENOR;
}

char * primerElemCondicion(char *cond){ 
// retorna el nombre de la columna 
    char * pch = strtok(cond, "<>=!"); // esto me va a devolver el nombre de la col
    return pch;
}

char * segundoElemCondicion(char *cond) { 
// devuelve el dato 
    char *pch = strtok(NULL, "<>=!");
    return pch; 
}

condicion crearCondicion(char * cond, ListaColumnas lc){
    TipoOperador op = operador(cond);
    char * nombreCol = primerElemCondicion(cond); // esto me rompe condicion??? strtok???
    char * comparacion = segundoElemCondicion(cond);
    Columna col = buscarcol(lc, nombreCol);
    if (col == NULL) // si la columna no esta 
        return NULL;
    TipoDato datoCol = tipoDatoCol(col); // sabemos el tipo de datos de la columna
    Dato d;
    if ( isEmpty(comparacion)) { 
        d = crearDatoEmpty();
    }
    else if (datoCol == TSTRING)
        d = crearDatoChar(comparacion);
    else // es INTEGER
        d = crearDatoInt(atoi(comparacion));
    condicion c = new(nodo_condicion); // aca ya se que la columna esta
    c->op = op;
    c->nombreCol = new(char[MAX_COMANDO]);
    strcpy(c->nombreCol, primerElemCondicion(cond));
    c->d = d;
    return c;
}

bool cumpleCondicion(condicion c, Dato d){
    TipoDato td = tipoDato(c->d); // tipo de dato coincide con cond para comparar?
    if( td == TSTRING ){ // si los dos son string podemos comaparar
        if (c->op == MAYOR) 
            return strcmp(datoChar(d), datoChar(c->d)) > 0;
        if (c->op == MENOR) 
            return strcmp(datoChar(d), datoChar(c->d)) < 0; 
        if (c->op == IGUAL)
            return strcmp(datoChar(d), datoChar(c->d)) == 0; 
        return strcmp(datoChar(d), datoChar(c->d)) != 0; 
    }
    else { // si es integer
        int i = datoInt(c->d);
        if (c->op == MAYOR) 
            return (datoInt(d)> i); 
        if (c->op == MENOR) 
            return (datoInt(d) < i); 
        if (c->op == IGUAL)
            return (datoInt(d) == i);
        return (datoInt(d) != i); 
    } 
}

char * devuelveNomCol(condicion c){
    return c->nombreCol;
}









