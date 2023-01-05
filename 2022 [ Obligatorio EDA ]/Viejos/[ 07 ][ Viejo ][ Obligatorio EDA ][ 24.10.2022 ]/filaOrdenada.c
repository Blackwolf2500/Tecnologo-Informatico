#include <stdio.h>
#include <string.h>
#include "define.h"
#include "filaOrdenada.h"
#include "listaFilas.h"
#include "dato.h"


struct nodo_fila_ordenada{
    Dato pk; // dato de la clave 
    ListaFilas lf; //puntero a una ListaFilas de fila
    FilaOrdenada izq;
    FilaOrdenada der;
};  

FilaOrdenada crearFilaOrdenada(){
//crea una fila ordenada vacia
    return NULL;
}

FilaOrdenada insertarFila(FilaOrdenada & fo, ListaFilas lf, int pos){
// inserta la listaFila lf en la Fila Ordenada fo en orden segun el el dato que se encuentra en la posicion pos
	Dato pk = infoDato(primeraFila(lf), pos);
	TipoDato tipoPK = tipoDato(pk);
	if (tipoPK == TSTRING){ 
			char * pkChar = datoChar(pk);
			if (fo == NULL) {//si no hay nodo lo agrego al comienzo
				fo = new(nodo_fila_ordenada);
				fo->pk = crearDatoChar(pkChar);
				fo->lf = lf; //esto esta bien? porque no quiero crear, quiero que apunten alo mismo
        		fo->izq = NULL;
				fo->der = NULL;
			}else if (strcmp(datoChar(fo->pk), pkChar) > 0)  //si es >0 es pq fo->nombre > nombre de t
				fo-> izq = insertarFila(fo->izq, lf, pos);
			else if (strcmp(datoChar(fo->pk), pkChar) < 0) //si fo->nombre es menor 
				fo-> der = insertarFila(fo->der,lf, pos);
			return fo;
	}else { // es int
			if (fo == NULL) {//si no hay nodo lo agrego al comienzo
				fo = new(nodo_fila_ordenada);
				fo->pk = crearDatoInt(datoInt(pk));
				fo->lf = lf; //esto esta bien? porque no quiero crear, quiero que apunten alo mismo
				fo->izq = NULL;
				fo->der = NULL;
			}else if (datoInt(fo->pk) > datoInt(pk))  
				fo-> izq = insertarFila(fo->izq, lf, pos);
			else  
				fo-> der = insertarFila(fo->der,lf, pos);
			return fo;
	}
}

int max_(int a, int b){
// Retorna el maximo de a y b.
	if(a > b)
		return a;
	else
		return b;
}

FilaOrdenada max__izq(FilaOrdenada fo){
//auxiliar encuentra maximo de la izquierda
	if (fo->der == NULL){
		FilaOrdenada aux = fo;
		fo = fo->izq;
		return aux;
	}else
		return max__izq(fo->der);
}

FilaOrdenada min__der(FilaOrdenada fo){
//auxiliar encuentra minimo de la derecha
	if (fo->izq == NULL){
		FilaOrdenada aux = fo;
		fo = fo->der;
		return aux;
		
	}else
		return min__der(fo->izq);
}

int profundidad_(FilaOrdenada fo){
// Auxiliar: retorna la profundidad de la estructura FilaOrdenada
	if (fo == NULL)
		return 0;
	else
		return 1 + max_(profundidad_(fo->izq), profundidad_(fo->der));
}


void eliminarFilaOrd(FilaOrdenada &fo, ListaFilas lf, int posPK){
// elimina el elemento que contiene a la listaFila lf segun su pk
    if (fo != NULL) {
		Dato pk = infoDato(primeraFila(lf), posPK); // me da el Dato de la PK de lf
		TipoDato tipoPK = tipoDato(pk);
		if (tipoPK == TSTRING){ 
			char * pkChar = datoChar(pk);
			if (strcmp(datoChar(fo->pk), pkChar) > 0)  //si es >0 es pq fo->nombre > nombre de t
				eliminarFilaOrd(fo->izq, lf, posPK);
			else if (strcmp(datoChar(fo->pk), pkChar) < 0) //si fo->nombre es menor 
				eliminarFilaOrd(fo->der, lf, posPK);
			else{ // si estoy en el dato
				FilaOrdenada aux;
				if (fo->izq == NULL && fo->der == NULL){  // si es hoja
					delete(fo);
				}
				else if (fo->izq == NULL){
					aux = fo->der;
					delete(fo);
				}
				else if (fo->der == NULL){
					aux = fo->izq;
					delete(fo);
				}
				else{
					if (profundidad_(fo->izq) > profundidad_(fo->der))
						aux = max__izq(fo->izq);
					else
						aux = min__der(fo->der);
					aux->izq = fo->izq;
					aux->der = fo->der;
					delete(fo);
				}
			}
		}else { // es int
			if (datoInt(fo->pk) > datoInt(pk))  
				eliminarFilaOrd(fo->izq, lf, posPK);
			else if (datoInt(fo->pk) < datoInt(pk))
				eliminarFilaOrd(fo->der, lf, posPK);
			else { // estoy en el dato
				FilaOrdenada aux;
				if (fo->izq == NULL && fo->der == NULL){  // si es hoja
					delete(fo);
				}
				else if (fo->izq == NULL){
					aux = fo->der;
					delete(fo);
				}
				else if (fo->der == NULL){
					aux = fo->izq;
					delete(fo);
				}
				else{
					if (profundidad_(fo->izq) > profundidad_(fo->der))
						aux = max__izq(fo->izq);
					else
						aux = min__der(fo->der);
					aux->izq = fo->izq;
					aux->der = fo->der;
					delete(fo);
				}
			}
		}
	}		
}

void imprimirTuplasOrdenadas(FilaOrdenada fo) {
// imprime las tuplas de forma ordenada ascendente separadas por :
	if (fo != NULL){
        imprimirTuplasOrdenadas(fo->izq);
        imprimirListaFilas(fo->lf);
        imprimirTuplasOrdenadas(fo->der);
    }
}


void destruirFilaOrd(FilaOrdenada &fo){
// destruye toda la estructura de las filas ordenadas
    if (fo != NULL){
		destruirFilaOrd(fo->izq);
		destruirFilaOrd(fo->der);
        borrarDato(fo->pk);
		delete(fo);
	}
}
