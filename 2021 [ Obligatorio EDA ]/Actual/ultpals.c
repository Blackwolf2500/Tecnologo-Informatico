#include "ultpal.h"
#include "ultpals.h"
#include "definiciones.h"
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

struct nodo_ultPalabras{
	ultPal primeraP;
	ultPal ultimaP;
	int cantPal;
};

ultPals CrearUltimasPalabras(){
//crea la estructura de las ultimas palabras.
	ultPals u=new(nodo_ultPalabras);
	u->primeraP=NULL;
	u->ultimaP=NULL;
	u->cantPal=0;
	return u;
}

TipoRetorno ImprimirUltimasPalabrasU1(ultPals u){
// Imprime las últimas MAX_CANT_ULTIMAS_PALABRAS palabras ingresadas al texto.
// Ver más detalles en la letra del obligatorio.
	return ImprimirUltimasPalabrasU2(u->primeraP);
}

void GuardarUltimaPalabraU1(ultPals & u, Cadena palabraAIngresar){
//Guarda la palabra temporalmente.
	GuardarUltimaPalabraU2(u->primeraP, u->ultimaP, palabraAIngresar, u->cantPal);
	if(u->cantPal<MAX_CANT_ULTIMAS_PALABRAS)
		u->cantPal+=1;
}

TipoRetorno BorrarUltPals(ultPals & u){
//Borra la ultima palabra.
	while(u->cantPal!=0){
		BorrarUltElem(u->primeraP, u->ultimaP);
		u->cantPal-=1;
	}
	if(u->primeraP==NULL && u->ultimaP==NULL)
		return OK;
	else
		return ERROR;
}

/*
TipoRetorno ImprimirUltimasPalabrasU(ultPals u){
// Imprime las últimas MAX_CANT_ULTIMAS_PALABRAS palabras ingresadas al texto.
// Ver más detalles en la letra del obligatorio.
	while(u->primeraP != NULL){
        cout << u->primeraP->Pal << endl;
        u->primeraP=u->primeraP->sig;
    }
    return OK;
}*/
