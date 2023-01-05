// Estructuras de Datos y Algoritmos - Obligatorio 2021
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// editor.c
// Modulo de implementacion de editor.
#include "ultPal.h"
#include "ultPals.h"
#include "diccionario.h"
#include "palabras.h"
#include "lineas.h"
#include "texto.h"
#include "editor.h"
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

struct nodo_editor{
	texto t;
	dicc d;
	ultPals u;
	// crear el resto de las estructuras que se incluyan en el editor
};

editor CrearEditor(){
// Crea la estructura editor.
	editor e = new(nodo_editor);
	e->t=CrearTexto();
	e->d=CrearDicc();
	e->u=CrearUltimasPalabras();
// crear el resto de las estructuras que se incluyan en el editor
	return e;
}

TipoRetorno InsertarLinea(editor & e){
// Inserta una nueva línea vacía al final del texto.
// Este requerimiento debe ser resuelto en O(1) peor caso.
// Ver más detalles en la letra del obligatorio.
	return InsertarLineaT(e->t);
}

TipoRetorno InsertarLineaEnPosicion(editor & e, Posicion posicionLinea){
// Inserta una nueva línea vacía en la posición indicada.
// Ver más detalles en la letra del obligatorio.
	return InsertarLineaEnPosicionT(e->t, posicionLinea);
}

TipoRetorno BorrarLinea(editor & e, Posicion posicionLinea){
// Borra la línea en la posición indicada.
// Ver más detalles en la letra del obligatorio.
	return BorrarLineaT(e->t, posicionLinea);
}

TipoRetorno BorrarTodo(editor & e){
// Borra todas las líneas del texto.
// Ver más detalles en la letra del obligatorio.
	return BorrarTodoT(e->t);
}

TipoRetorno BorrarOcurrenciasPalabraEnTexto(editor & e, Cadena palabraABorrar){
// Borra todas las ocurrencias de una palabra en el texto.
// Ver más detalles en la letra del obligatorio.
	return BorrarOcurrenciasPalabraEnTextoT(e->t, palabraABorrar);
}

TipoRetorno ImprimirTexto(editor & e){
// Imprime el texto por pantalla.
// Ver más detalles en la letra del obligatorio.
	return ImprimirTextoT(e->t);
}

TipoRetorno ComprimirTexto(editor & e){
// Comprime las palabras del texto. Para implementar esta operación no debe generarse un nuevo documento.
// Ver más detalles en la letra del obligatorio.
	return ComprimirTextoT(e->t);
}

TipoRetorno InsertarPalabra(editor & e, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar){
// Inserta una palabra en una línea.
// Ver más detalles en la letra del obligatorio.
	TipoRetorno hecho;
	hecho=InsertarPalabraT(e->t, posicionLinea, posicionPalabra, palabraAIngresar);
	if(hecho==OK)
		GuardarUltimaPalabraU1(e->u, palabraAIngresar);
	return hecho;
}

TipoRetorno BorrarPalabra(editor & e, Posicion posicionLinea, Posicion posicionPalabra){
// Borra la palabra en la posición indicada.
// Ver más detalles en la letra del obligatorio.
	return BorrarPalabraT(e->t, posicionLinea, posicionPalabra);
}

TipoRetorno BorrarOcurrenciasPalabraEnLinea(editor & e, Posicion posicionLinea, Cadena palabraABorrar){
// Borra todas las ocurrencias de una palabra en la línea indicada.
// Ver más detalles en la letra del obligatorio.
	return BorrarOcurrenciasPalabraEnLineaT(e->t, posicionLinea, palabraABorrar);
}

TipoRetorno ImprimirLinea(editor & e, Posicion posicionLinea){
// Imprime la línea por pantalla.
// Ver más detalles en la letra del obligatorio.
	return ImprimirLineaT(e->t, posicionLinea);
}

TipoRetorno IngresarPalabraDiccionario(editor & e, Cadena palabraAIngresar){
// Agrega una palabra al diccionario.
// Esta operación debe realizarse en a lo sumo O(log n) promedio.
// Ver más detalles en la letra del obligatorio.
	return IngresarPalabraDiccionarioD(e->d, palabraAIngresar);
}

TipoRetorno BorrarPalabraDiccionario(editor & e, Cadena palabraABorrar){
// Borra una palabra del diccionario.
// Ver más detalles en la letra del obligatorio.
	if(pertenece(palabraABorrar, e->d)){
		e->d=BorrarPalabraDiccionarioD(e->d, palabraABorrar);
		return OK;
	}else 
		return ERROR;
}

TipoRetorno ImprimirDiccionario(editor & e){
// Muestra las palabras del diccionario alfabéticamente.
// Esta operación debe realizarse en O(n) peor caso.
// Ver más detalles en la letra del obligatorio.
	if(e->d==NULL)
		cout << "diccionario vacio\n" << endl;
	else
		ImprimirDiccionarioD(e->d);
	return OK;
}

TipoRetorno ImprimirTextoIncorrecto(editor & e){
// Muestra las palabras del texto que no se encuentran en el diccionario.
// Ver más detalles en la letra del obligatorio.
	int cantLin = CopiarCantLinT(e->t);
	for(int i=1; i<=cantLin; i++){
		cout << i << ":" << "	";
		int cantPal = CopiarCantPalT(e->t, i);
		int posP=1;
		while(posP<=cantPal){
			Cadena aux=new char[strlen(CopiarPalT(e->t, i, posP)) + 1];
			strcpy(aux, CopiarPalT(e->t, i, posP));
			if(!pertenece(aux, e->d))
				cout << aux << "	";
			posP+=1;
		}
		cout << endl;
	}
	return OK;
}

TipoRetorno ImprimirUltimasPalabras(editor & e){
// Imprime las últimas MAX_CANT_ULTIMAS_PALABRAS palabras ingresadas al texto.
// Ver más detalles en la letra del obligatorio.
	return ImprimirUltimasPalabrasU1(e->u);
}

TipoRetorno DestruirEditor(editor & e){  
// Destruye la estructura editor y libera la memoria asociada.
	TipoRetorno hecho;
	hecho=BorrarTodoT(e->t);
	if(hecho==OK){
		hecho=DestruirDicc(e->d);
		hecho=BorrarUltPals(e->u);
		if(hecho==OK)
			delete e;
		return hecho;
	}else
		return hecho;
}
