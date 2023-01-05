#include "palabras.h"
#include "lineas.h"
#include "texto.h"
#include "editor.h"
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

struct nodo_palabra{
	Cadena Pal;
	palabra sig;
};

TipoRetorno InsertarPalabraP(palabra & primeraP, palabra & ultimaP, Posicion posicionPalabra, Cadena palabraAIngresar, int cantPal){
// Inserta una palabra en una línea.
// Ver más detalles en la letra del obligatorio.
	palabra aux=new(nodo_palabra);
	aux->Pal=new char[strlen(palabraAIngresar) + 1];
	strcpy(aux->Pal, palabraAIngresar);
	if(posicionPalabra==1){ //insertar en la primera posicion
		if(cantPal==0){ //si la linea es vacia
			primeraP=aux;
			primeraP->sig=NULL;
			ultimaP=primeraP;
		}else{ //si la linea no es vacia
			aux->sig=primeraP;
			primeraP=aux;
		}
	}else if(posicionPalabra==cantPal+1){ //insertar en la ultima posicion
		aux->sig=NULL;
		ultimaP->sig=aux;
		ultimaP=aux;
	}else{ //lo demas
		palabra iterP=primeraP;
		while(posicionPalabra > 2){
			iterP=iterP->sig;
			posicionPalabra--;
		}
		aux->sig=iterP->sig;
		iterP->sig=aux;
	}
	return OK;
}

TipoRetorno BorrarPalabraP(palabra & primeraP, palabra & ultimaP, Posicion posicionPalabra, int cantPal){
// Borra la palabra en la posición indicada.
// Ver más detalles en la letra del obligatorio.
		if(posicionPalabra>=1 && posicionPalabra<=cantPal){ //Entra si existe la palabra
			palabra aux = primeraP;
			if(posicionPalabra==1 && aux->sig==NULL){ //Si solo tiene una palabra
				delete aux;
				primeraP=NULL;
				ultimaP=NULL;
			}else{ //Si hay mas de una palabra
				Posicion contadorP = posicionPalabra;
				palabra iterP=aux;
				while(contadorP > 2){
					iterP = iterP->sig;
					contadorP--;
				}
				if(posicionPalabra==1){ //Si es la primera palabra
					iterP=iterP->sig;
					delete aux;
					primeraP=iterP;
				}else if(posicionPalabra==cantPal){ //Si es la ultima
					aux=iterP->sig;
					delete aux;
					iterP->sig=NULL;
					ultimaP=iterP;
				} 
				else{ // el resto
					aux=iterP->sig;
					iterP->sig=aux->sig;
					delete aux;
				}
			}
			return OK;
		}else
			return ERROR;
}

TipoRetorno BorrarOcurrenciasPalabraEnPalabra(palabra & primeraP, palabra & ultimaP, Cadena palabraABorrar, int & cantPal){
// Borra todas las ocurrencias de una palabra.
	palabra auxP = primeraP;
	TipoRetorno hecho=OK;
	int posP=1;
	while(auxP!=NULL){
		if(strcmp(auxP->Pal, palabraABorrar)==0){
			auxP=auxP->sig;
			hecho=BorrarPalabraP(primeraP, ultimaP, posP, cantPal);
			cantPal-=1;
		}else{
			auxP=auxP->sig;
			posP+=1;
		}
	}
	return hecho;
}

TipoRetorno imprimirPalabrasDeLineaP(palabra primeraP, int cantPal){
//Imprime todas las palabras de una linea dada.
	for (int i = 1; i <= cantPal; i++){
		cout << "   " << primeraP->Pal << "   "; //Imprimir la palabra
		primeraP=primeraP->sig;
	}
	cout << endl;
	return OK;
}

Cadena CopiarPalP(palabra NodPal, int posP){
//Copia una cadena de caracteres y la retorna.
	while(posP > 1){
		NodPal = NodPal->sig;
		posP--;
	}
	return NodPal->Pal;
}
