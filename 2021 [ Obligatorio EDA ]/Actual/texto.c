#include "palabras.h"
#include "lineas.h"
#include "texto.h"
#include "editor.h"
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

struct nodo_texto{
	linea primeraL;
	linea ultimaL;
	int cantLineas;
};

texto CrearTexto(){
//crea la estructura texto
	texto t=new(nodo_texto);
	t->primeraL=NULL;
	t->ultimaL=NULL;
	t->cantLineas=0;
	return t;
}

TipoRetorno InsertarLineaT(texto & t){
// Inserta una nueva línea vacía al final del texto.
// Este requerimiento debe ser resuelto en O(1) peor caso.
// Ver más detalles en la letra del obligatorio.
	t->cantLineas+=1;
	return InsertarLineaL(t->primeraL, t->ultimaL);
}

TipoRetorno InsertarLineaEnPosicionT(texto & t, Posicion posicionLinea){
// Inserta una nueva línea vacía en la posición indicada.
// Ver más detalles en la letra del obligatorio.
	if(posicionLinea >= 1 && posicionLinea <= t->cantLineas+1){
		t->cantLineas+=1;
		return InsertarLineaEnPosicionL(t->primeraL, t->ultimaL, posicionLinea, t->cantLineas);
	}else
		return ERROR;
}

TipoRetorno BorrarLineaT(texto & t, Posicion posicionLinea){
// Borra la línea en la posición indicada.
// Ver más detalles en la letra del obligatorio.
	if(posicionLinea >= 1 && posicionLinea <= t->cantLineas){
		TipoRetorno hecho=OK;
		hecho=BorrarLineaL(t->primeraL, t->ultimaL, posicionLinea, t->cantLineas);
		if(hecho==OK)
			t->cantLineas-=1;
		return hecho;
	}else
		return ERROR;
}

TipoRetorno BorrarTodoT(texto & t){
// Borra todas las líneas del texto.
// Ver más detalles en la letra del obligatorio.
	TipoRetorno hecho=OK;
	for(Posicion i=1; i<=t->cantLineas; i++)
		hecho=BorrarLineaL(t->primeraL, t->ultimaL, i, t->cantLineas);
	t->primeraL=NULL;
	t->ultimaL=NULL;
	t->cantLineas=0;
	return hecho;
}

TipoRetorno BorrarOcurrenciasPalabraEnTextoT(texto & t, Cadena palabraABorrar){
// Borra todas las ocurrencias de una palabra en el texto.
// Ver más detalles en la letra del obligatorio.
	TipoRetorno hecho=OK;
	for(Posicion i = 1; i <= t->cantLineas; i++)
			hecho=BorrarOcurrenciasPalabraEnLineaT(t, i, palabraABorrar);
	return hecho;
}

TipoRetorno InsertarPalabraT(texto & t, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar){
// Inserta una palabra en una línea.
// Ver más detalles en la letra del obligatorio.
	if(posicionLinea>=1 && posicionLinea<=t->cantLineas) //Entra si existe la linea
		return InsertarPalabraL(t->primeraL, posicionLinea, posicionPalabra, palabraAIngresar);
	else
		return ERROR;
}

TipoRetorno BorrarPalabraT(texto & t, Posicion posicionLinea, Posicion posicionPalabra){
// Borra la palabra en la posición indicada.
// Ver más detalles en la letra del obligatorio.
	if(posicionLinea>=1 && posicionLinea<=t->cantLineas){ //Entra si existe la linea
		return BorrarPalabraL(t->primeraL, t->ultimaL, t->cantLineas, posicionLinea, posicionPalabra);
	}else 
		return ERROR;
}

TipoRetorno ImprimirTextoT(texto t){
// Imprime el texto por pantalla.
// Ver más detalles en la letra del obligatorio.
	TipoRetorno hecho=OK;
	if(t->primeraL!=NULL){
		for (Posicion x = 1; x <= t->cantLineas; x++){
			hecho=ImprimirLineaL(t->primeraL, x, t->cantLineas);
			cout << "\n";
		}
	}else
		cout << "Texto Vacio" << endl;
	return hecho;
}

TipoRetorno ImprimirLineaT(texto t, Posicion posicionLinea){
// Imprime la línea por pantalla.
// Ver más detalles en la letra del obligatorio.
	return ImprimirLineaL(t->primeraL, posicionLinea, t->cantLineas);
}

TipoRetorno BorrarOcurrenciasPalabraEnLineaT(texto & t, Posicion posicionLinea, Cadena palabraABorrar){
// Borra todas las ocurrencias de una palabra en la línea indicada.
// Ver más detalles en la letra del obligatorio.
	if(posicionLinea>=1 && posicionLinea<=t->cantLineas)
		return BorrarOcurrenciasPalabraEnLineaL(t->primeraL, posicionLinea, palabraABorrar);
	else
		return ERROR;
}

TipoRetorno ComprimirTextoT(texto & t){                                                             //   Opcional
// Comprime las palabras del texto. Para implementar esta operación no debe generarse un nuevo documento.
// Ver más detalles en la letra del obligatorio.
	t->cantLineas=ComprimirTextoL(t->primeraL, t->ultimaL, t->cantLineas);
	return OK;
}

int CopiarCantPalT(texto t, int posL){
//Copia la cantidad de lineas.
	return CopiarCantPalL(t->primeraL, posL);
}

int CopiarCantLinT(texto t){
//Copia la cantidad de lineas.
	return t->cantLineas;
}

Cadena CopiarPalT(texto t, int posL, int posP){
//Copia una cadena de caracteres y la retorna.
	return CopiarPalL(t->primeraL, posL, posP);
}