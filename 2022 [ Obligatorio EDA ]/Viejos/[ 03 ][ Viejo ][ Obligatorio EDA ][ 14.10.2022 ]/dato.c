
#include <stdio.h>
#include "define.h"
#include "dato.h"
#include <string.h>
#include <iostream>

using namespace std;

struct nodo_dato{
    int * dint; 
    char * dstr;
};

Dato crearDatoInt(int * i){
//Crea el dato de tipo integer
    Dato d = new nodo_dato;
    d->dint = new int;
    d->dint = i;
    d->dstr = NULL;
    return d;
}

Dato crearDatoChar(char * c){
//Crea el dato de tipo cadena de caracteres
    Dato d = new nodo_dato;
    d->dstr = new char[MAX_COMANDO];
    strcpy(d->dstr, c);
    d->dint = NULL;
    return d;
}

TipoDato tipoDato(Dato d){
// devuelve el tipo de dato de D
    int i = atoi(d);
	if (i == 0 && d != "0")
		return TSTRING;
	else return TINTEGER;
}

void cambiarTD(Dato &d){
//cambia de int a string o de string a int 
    int i = atoi(d);
	if (i == 0 && d != "0")
		d = i;
	else {
        // aca no se como cambiar de int a char* ideas??

    }
}

void borrarDato(Dato &d){
  // borra el dato d
    while(d->dstr != NULL)
        delete [] d->dstr;
    while(d->dint != NULL)
        delete [] d->dint;
}

void imprimirDato(Dato d){
// Imprime el dato d
    if(d->dstr != NULL)
        for(unsigned int i=0; i< strlen(d->dstr); i++ ) { 
            cout << d->dstr[i];
            if (i == strlen(d->dstr))
                cout << "\n";
    }       
    else
        cout << d->dint << "\n";
}
