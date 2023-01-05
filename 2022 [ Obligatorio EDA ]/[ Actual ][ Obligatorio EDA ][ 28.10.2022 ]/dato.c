
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

Dato crearDatoEmpty(){
//Crea el dato "EMPTY"
    Dato d = new(nodo_dato);
    d->dint = NULL;
    d->dstr = NULL;
    return d;
}

Dato crearDatoInt(int i){
//Crea el dato de tipo integer
    Dato d = new(nodo_dato);
    d->dint = new int(i);
    d->dstr = NULL;
    return d;
}

Dato crearDatoChar(char * c){
//Crea el dato de tipo cadena de caracteres
    Dato d = new(nodo_dato);
    d->dstr = new char[MAX_COMANDO];
    strcpy(d->dstr, c);
    d->dint = NULL;
    return d;
}



int datoInt(Dato d){
    return *(d->dint);
}

char * datoChar(Dato d){
    return d->dstr;
}

bool isEmpty(char * c){
    return (strcasecmp(c, "EMPTY") == 0);
}

TipoDato tipoDato(Dato d){
// devuelve el tipo de dato de D
    if (d->dint == NULL && d->dstr == NULL)
        return EMPTY;
    else if (d->dint != NULL)
        return TINTEGER;
    else return TSTRING;
}

void cambiarTD(Dato &d){
//cambia de int a string  por letra es lo unico que se puede
//PRE tipo dato d == Integer
    if(tipoDato(d) != TINTEGER)
        cout << "tipo de dato pasado incorrecto \n";
    int i = *(d->dint); 
    char str[50]; 
    sprintf(str, "%d", i); 
    d->dstr = str;
    d->dint = NULL;
}

TipoDato returnTipoDato(char * tipoCol){
// devuelve la clasificacion del tipo de dato pasado
	int i = atoi(tipoCol);
	if (i == 0 && strcmp(tipoCol, "0") != 0 ){
        if(isEmpty(tipoCol))
            return EMPTY;
        else return TSTRING;
    }else return TINTEGER;
}

bool cambiarDato(Dato &d, char * valorNuevo){ // va a agregar segun el tipo y si es EMPTY AGREGA! 
    TipoDato nuevo = returnTipoDato(valorNuevo);
    if (nuevo == TSTRING){
        if (tipoDato(d) == TSTRING || tipoDato(d) == EMPTY){ //son el mismo tipo de dato o EMPTY
            strcpy(d->dstr, valorNuevo);
            return true;
        }else return false;
    }else if (nuevo == TINTEGER){
        if(tipoDato(d) == TINTEGER || tipoDato(d) == EMPTY){ // son el mismo tipo de dato
            if (strcasecmp(valorNuevo, "0")!=0){
                int i = atoi(valorNuevo);
                d->dint = &i;
            }
            else d->dint = 0;
            return true;
        }else return false;
    }else return false; 
}

void borrarDato(Dato &d){
  // borra el dato d
    cout << "entra a borrarDato \n";
    TipoDato td = tipoDato(d);
    if(td == TSTRING)
        while(d->dstr != NULL)
            delete [] d->dstr;
    if (td == TINTEGER)
        while(d->dint != NULL)
            delete [] d->dint;
    delete(d);
    cout << "elimino el dato \n";
}

void imprimirDatoChar(char * datoC){
    for(unsigned int i=0; i < strlen(datoC); i++ ) 
        cout << datoC[i];
    cout << ":";
}

void imprimirDatoInt( int i){
    cout << i << ":";
}

void imprimirDato(Dato d){ 
// Imprime el dato d
    TipoDato td = tipoDato(d);
    if(td == TSTRING){
        imprimirDatoChar(datoChar(d));
    }       
    else if (td == TINTEGER)
        imprimirDatoInt(datoInt(d));
    else   
        cout << "EMPTY:";
}

