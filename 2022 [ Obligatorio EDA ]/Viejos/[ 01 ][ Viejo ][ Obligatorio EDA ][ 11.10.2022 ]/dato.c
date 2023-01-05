
#include <stdio.h>
#include "define.h"
#include "dato.h"
#include <iostream>

using namespace std;

struct nodo_dato{
    int dint; 
    char * dstr;
};

Dato crearDato(int i){
//Crea el dato de tipo integer
    Dato d = new nodo_dato;
    d->dint = i;
    d->dstr = NULL;
    return d;

}

Dato crearDato(char * c){
//Crea el dato de tipo cadena de caracteres
    Dato d = new nodo_dato;
    d->dstr = new char[MAX_COMANDO];
    strcpy(d->dstr, c);
    return d;
}


void borrarDato( Dato d){
    if(d->dstr != NULL)
        delete [] d->dstr;
    else 
        delete d->dint;

}
// borra el dato d

void imprimirDato(Dato d){
// Imprime el dato d
    if(d->dstr != NULL)
        cout << d->dstr << "\n";
    else
        cout << d->dint << "\n";

}
