#include "ultpal.h"
#include "definiciones.h"
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

struct nodo_ultPal{
	Cadena Pal;
	ultPal sig;
};

void GuardarUltimaPalabraU2(ultPal & primeraP, ultPal & ultimaP, Cadena palabraAIngresar, int cantPal){
//Guarda la palabra temporalmente.
    ultPal aux=new(nodo_ultPal);
    aux->Pal=new char[strlen(palabraAIngresar) + 1];
    strcpy(aux->Pal, palabraAIngresar);
	aux->sig=NULL;
	if((primeraP == NULL) && (ultimaP == NULL)){ //primera palabra a guardar
		primeraP=aux;
		ultimaP=primeraP;
	}else{
		ultimaP->sig=aux;
		ultimaP=aux;
	}
	if(cantPal==MAX_CANT_ULTIMAS_PALABRAS){
		BorrarUltElem(primeraP, ultimaP);
	}
}

void BorrarUltElem(ultPal & primeraP, ultPal & ultimaP){
//Borra la ultima palabra.
	if(primeraP!=ultimaP){
		ultPal aux=primeraP;
		primeraP=primeraP->sig;
		delete aux;
	}else{
		delete ultimaP;
		ultimaP=NULL;
		primeraP=NULL;
	}
}

TipoRetorno ImprimirUltimasPalabrasU2(ultPal iter){
// Imprime las últimas MAX_CANT_ULTIMAS_PALABRAS palabras ingresadas al texto.
// Ver más detalles en la letra del obligatorio.
	while(iter != NULL){
        cout << iter->Pal << endl;
        iter=iter->sig;
    }
    return OK;
}
