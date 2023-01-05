#include "diccionario.h"
#include "definiciones.h"
#include <string.h>
#include <iostream>

using namespace std;

struct nodo_dicc{
	Cadena palabra;
	dicc iz;
	dicc de;
};

dicc CrearDicc(){
//Crea el diccionario.
	return NULL;
}

TipoRetorno IngresarPalabraDiccionarioD(dicc & d, Cadena palabraAIngresar){
// Agrega una palabra al diccionario.
// Esta operación debe realizarse en a lo sumo O(log n) promedio.
	if(d==NULL){
		dicc aux=new(nodo_dicc);
		aux->palabra=new char[strlen(palabraAIngresar) + 1];
		strcpy(aux->palabra, palabraAIngresar);
		aux->iz = NULL;
		aux->de = NULL;
		d = aux;
		return OK;
	}else if(strcasecmp(d->palabra, palabraAIngresar) < 0)
			return IngresarPalabraDiccionarioD(d->de, palabraAIngresar);	
	else if(strcasecmp(d->palabra, palabraAIngresar) > 0)
			return IngresarPalabraDiccionarioD(d->iz, palabraAIngresar);
	else
		return ERROR;
}
	
void ImprimirDiccionarioD(dicc & d){
// Muestra las palabras del diccionario alfabéticamente.
// Esta operación debe realizarse en O(n) peor caso.
	if(d != NULL){
		ImprimirDiccionarioD(d->iz);
		cout << d->palabra << endl;
		ImprimirDiccionarioD(d->de);
	}
}

int profundidad(dicc d){
// Retorna la profundidad del diccionario.
	if (d == NULL)
		return 0;
	else
		return 1 + max(profundidad(d->iz), profundidad(d->de));

}

dicc max_iz(dicc d){
//Retorna la palabra lexicograficamente mas grande de la izquierda.
	if(d->de == NULL){
		dicc aux = d;
		d = d->iz;
		return aux;
	}else
		return max_iz(d->de);
}

dicc min_de(dicc d){
//Retorna la palabra lexicograficamente mas pequeña de la derecha.
	if (d->iz == NULL){
		dicc aux = d;
		d = d->de;
		return aux;
		
	}else
		return min_de(d->iz);
}

int max(int a, int b){
// Retorna el maximo de a y b.
	if(a > b)
		return a;
	else
		return b;
}

dicc BorrarPalabraDiccionarioD(dicc d, Cadena palabraABorrar){
// Borra una palabra del diccionario.
// Ver más detalles en la letra del obligatorio.
	if (d == NULL)
		return d;
	else if (strcmp(palabraABorrar, d->palabra) < 0){
		d->iz = BorrarPalabraDiccionarioD(d->iz, palabraABorrar);
		return d;
	}else if (strcmp(palabraABorrar, d->palabra) > 0){
		d->de = BorrarPalabraDiccionarioD(d->de, palabraABorrar);
		return d;
	}
	else{		// PalabraABorrar == d->palabra
		dicc aux;
		if ((d->iz == NULL) && (d->de == NULL)){  // es hoja
			delete d;
			return NULL;
		}else if (d->iz == NULL){
			aux = d->de;
			delete d;
			return aux;
		}else if (d->de == NULL){
			aux = d->iz;
			delete d;
			return aux;
		}else{
			if (profundidad(d->iz) > profundidad(d->de))
				aux = max_iz(d->iz);
			else
				aux = min_de(d->de);
			aux->iz = d->iz;
			aux->de = d->de;
			delete d;
			return aux;
		}
	}
}

bool pertenece(Cadena palabraABorrar, dicc d){
// Retorna true si la palabra pertenece a d, false en caso contrario.
	if (d == NULL)
		return false;
	else if (strcasecmp(palabraABorrar, d->palabra)==0)
		return true;
	else if (strcasecmp(palabraABorrar, d->palabra) < 0)
		return pertenece(palabraABorrar, d->iz);
	else
		return pertenece(palabraABorrar, d->de);
}

TipoRetorno DestruirDicc(dicc & d){
// Destruye el arbol.
TipoRetorno hecho=OK;
	if(d!=NULL){
		hecho=DestruirDicc(d->iz);
		hecho=DestruirDicc(d->de);
		delete d;
	}
	return hecho;
}
