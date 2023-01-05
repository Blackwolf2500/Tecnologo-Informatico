#include "palabras.h"
#include "lineas.h"
#include "texto.h"
#include "editor.h"
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

struct nodo_linea{
	int cantPal;
	palabra primeraP;
	palabra ultimaP;
	linea sig;
};

TipoRetorno InsertarLineaL(linea & primeraL, linea & ultimaL){
// Inserta una nueva línea vacía al final del texto.
// Este requerimiento debe ser resuelto en O(1) peor caso.
// Ver más detalles en la letra del obligatorio.
	linea ln = new(nodo_linea);
	ln->cantPal=0;
	ln->primeraP=NULL;
	ln->ultimaP=NULL;
	ln->sig=NULL;
	if(primeraL==NULL){
		primeraL=ln;
		ultimaL=ln;
	}else{
		ultimaL->sig=ln;
		ultimaL=ln;
	}
	return OK;
}

TipoRetorno InsertarLineaEnPosicionL (linea & primeraL, linea & ultimaL, Posicion posicionLinea, int cantLineas){
// Inserta una nueva línea vacía en la posición indicada.
// Ver más detalles en la letra del obligatorio.
	linea aux = new(nodo_linea);
	aux->primeraP=NULL;
	aux->ultimaP=NULL;
	if (posicionLinea == 1){ //es la primera posición
		aux->sig = primeraL; 
		primeraL = aux;
	}else if(posicionLinea == cantLineas+1){ //es la última posición
			ultimaL->sig = aux;
			ultimaL = aux;
	}else{ //es cualquier posición del medio
		linea iter = primeraL;
		while(posicionLinea > 2){
			iter = iter->sig;
			posicionLinea--;
		}
		aux->sig = iter->sig;
		iter->sig = aux;
	}
	return OK;
}

TipoRetorno BorrarLineaL(linea & primeraL, linea & ultimaL, Posicion posicionLinea, int cantLineas){
// Borra la línea en la posición indicada.
// Ver más detalles en la letra del obligatorio.
	TipoRetorno hecho=OK;
	if(posicionLinea==1){
		if(cantLineas == 1){ //borro el primer y unico elemento
			while(primeraL->cantPal>0){
				hecho=BorrarPalabraP(primeraL->primeraP, primeraL->ultimaP, primeraL->cantPal, primeraL->cantPal);
				primeraL->cantPal--;
			}
			primeraL = NULL;
			ultimaL = NULL;
		}else{
			linea aux = primeraL->sig;
			while(primeraL->cantPal>0){
				hecho=BorrarPalabraP(primeraL->primeraP, primeraL->ultimaP, primeraL->cantPal, primeraL->cantPal);
				primeraL->cantPal--;
			}
			delete primeraL;
			primeraL = aux;
		}
	}else{
		linea iter = primeraL;
		Posicion contador = posicionLinea;
		while(contador > 2){
			iter = iter->sig;
			contador--;
		}
		if(posicionLinea == cantLineas){ //borro el ultimo elemento
			while(ultimaL->cantPal>0){
				hecho=BorrarPalabraP(ultimaL->primeraP, ultimaL->ultimaP, ultimaL->cantPal, ultimaL->cantPal);
				ultimaL->cantPal--;
			}
			delete ultimaL;
			iter->sig = NULL;
			ultimaL = iter;
		}else{ //es cualquier posición del medio
			linea aux = iter->sig;
			iter->sig = aux->sig;
			while(aux->cantPal>0){
				hecho=BorrarPalabraP(aux->primeraP, aux->ultimaP, aux->cantPal, aux->cantPal);
				aux->cantPal--;
			}
			delete aux;
		}
	}
	return hecho;
}

TipoRetorno BorrarPalabraL(linea & primeraL, linea & ultimaL, int cantLineas, Posicion posicionLinea, Posicion posicionPalabra){
// Borra la palabra en la posición indicada.
// Ver más detalles en la letra del obligatorio.
	TipoRetorno hecho=OK;
	if(posicionLinea==1){
		hecho=BorrarPalabraP(primeraL->primeraP, primeraL->ultimaP, posicionPalabra, primeraL->cantPal);
		if(hecho==OK)
			primeraL->cantPal-=1;
	}else if(posicionLinea==cantLineas){
		hecho=BorrarPalabraP(ultimaL->primeraP, ultimaL->ultimaP, posicionPalabra, ultimaL->cantPal);
		if(hecho==OK)
			ultimaL->cantPal-=1;
	}else{
		Posicion contadorL = posicionLinea;
		linea iterL=primeraL;
		while(contadorL > 1){
			iterL = iterL->sig;
			contadorL--;
		}
		hecho=BorrarPalabraP(iterL->primeraP, iterL->ultimaP, posicionPalabra, iterL->cantPal);
		if(hecho==OK)
			iterL->cantPal-=1;
	}
	return hecho;
}

bool haypalabra(linea l){
//Retorna true si hay palabras y false en caso contrario.
	if(l->cantPal==0)
		return false;
	 else 
		return true;	
}

TipoRetorno BorrarOcurrenciasPalabraEnLineaL(linea & ln, Posicion posicionLinea, Cadena palabraABorrar){
// Borra todas las ocurrencias de una palabra en la línea indicada.
// Ver más detalles en la letra del obligatorio.
	linea iterL = ln;
		while(posicionLinea > 1){
			iterL = iterL->sig;
			posicionLinea--;
		}
	if(haypalabra(iterL))
		return BorrarOcurrenciasPalabraEnPalabra(iterL->primeraP, iterL->ultimaP, palabraABorrar, iterL->cantPal);
	else
		return OK;
}

TipoRetorno InsertarPalabraL(linea & primeraL, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar){
// Inserta una palabra en una línea.
// Ver más detalles en la letra del obligatorio.
	linea iter = primeraL;
	while(posicionLinea > 1){
		iter = iter->sig;
		posicionLinea--;
	}
	if(iter->cantPal<MAX_CANT_PALABRAS_X_LINEA && posicionPalabra>=1 && posicionPalabra<=iter->cantPal+1){
		TipoRetorno hecho;
		hecho=InsertarPalabraP(iter->primeraP, iter->ultimaP, posicionPalabra, palabraAIngresar, iter->cantPal);
		iter->cantPal+=1;
		return hecho;
	}else{
		return ERROR;
	}
}

TipoRetorno ImprimirLineaL(linea ln, Posicion posicionLinea, int cantLineas){
// Imprime la línea por pantalla.
// Ver más detalles en la letra del obligatorio.
	if(posicionLinea>=1 && posicionLinea<=cantLineas){
		Posicion contL=posicionLinea;
		while(contL > 1){
			ln = ln->sig;
			contL--;
		}
		if(haypalabra(ln)){
			cout << posicionLinea << ": ";
			return imprimirPalabrasDeLineaP(ln->primeraP, ln->cantPal);
		}else{
			cout << posicionLinea << ": " << endl; //Linea vacia.
			return OK;
		}
	}else
		return ERROR;
}

int ComprimirTextoL(linea & primeraL, linea & ultimaL, int cantLineas){
// Comprime las palabras del texto. Para implementar esta operación no debe generarse un nuevo documento.
// Ver más detalles en la letra del obligatorio.
	linea linea1=primeraL;
	linea linea2=linea1->sig;
	Posicion cont=0;
	Cadena palabraACopiar;
	Posicion posL=1;
	while(linea1!=ultimaL->sig){
		if(linea1->primeraP==NULL){
			BorrarLineaL(primeraL, ultimaL, posL, cantLineas);
			cantLineas-=1;
			cont=posL;
			linea1=primeraL;
			while(cont > 1){
				linea1 = linea1->sig;
				cont--;
			}
			if(ultimaL->sig!=linea1)
				linea2=linea1->sig;
		}else{
			if(linea1->cantPal<MAX_CANT_PALABRAS_X_LINEA){
				if(linea2->primeraP==NULL){
					BorrarLineaL(linea1, ultimaL, 2, cantLineas-1);
					cantLineas-=1;
					linea2=linea1->sig;
				}else{
					palabraACopiar=new char[strlen(CopiarPalP(linea2->primeraP, 1)) + 1];
					strcpy(palabraACopiar, CopiarPalP(linea2->primeraP, 1));
					InsertarPalabraL(linea1, 1, linea1->cantPal+1, palabraACopiar);
					BorrarPalabraL(linea2, ultimaL, cantLineas, 1, 1);
					linea2->cantPal-=1;
				}
			}else{
				linea1=linea1->sig;
				linea2=linea2->sig;
				posL+=1;
			}
		}
	}
	cout << cantLineas << endl;
	return cantLineas;
}

int CopiarCantPalL(linea l, int posL){
//Copia la cantidad de palabras.
	
	while(posL > 1){
		l = l->sig;
		posL--;
	}
	return l->cantPal;
}

Cadena CopiarPalL(linea l, int posL, int posP){
//Copia una cadena de caracteres y la retorna.
	while(posL > 1){
		l = l->sig;
		posL--;
	}
	return CopiarPalP(l->primeraP, posP);
}