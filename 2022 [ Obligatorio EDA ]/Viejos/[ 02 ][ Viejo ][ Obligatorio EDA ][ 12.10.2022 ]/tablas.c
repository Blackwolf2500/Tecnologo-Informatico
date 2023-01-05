#include "tablas.h"
#include "tabla.h"
#include <stdio.h>
#include <string.h>
#include "define.h"
#include <iostream>

using namespace std;

//Nuestro conjunto de Tablas se almacenan en un ABB (los menores
// van a la izq y los mayores a la derecha - orden alfabetico por nombre)
struct nodo_Tablas{
    char * nombre;
    Tabla t;
    Tablas izq;
    Tablas der;
};

Tablas crearTablas(){
// Crea una estructura Tablas vacío.
    return NULL; 
}

Tablas insertarTabla (Tablas & ts, char *nombreTabla, Tabla tab){
// Inserta la tabla t en ts en orden alfabetico segun nombreTabla
    if (ts == NULL) {//si no hay ninguna tabla la agrego al comienzo
        ts = new (nodo_Tablas); 
        ts->nombre = new char[MAX_COMANDO];
        strcpy(ts->nombre, nombreTabla);
        ts->t = crearTabla();
        ts->t = tab; 
        ts->izq = NULL;
		ts->der = NULL;
    }
    else if (strcmp(ts->nombre, nombreTabla) > 0)  //si es >0 es pq ts->nombre > nombre de t
        ts-> izq = insertarTabla(ts->izq, nombreTabla, tab);
    else if (strcmp(ts->nombre, nombreTabla) < 0) //si ts->nombre es menor 
        ts-> der = insertarTabla(ts->der,nombreTabla, tab);
    else // si es igual 
        cout << "Imposible Crear Tabla, ya hay una tabla con el mismo nombre" << "\n";
    return ts;
}


int profundidad(Tabla ts);
Tablas max_izq(Tablas ts);
Tablas min_der(Tablas ts);



Tablas eliminarTabla(Tablas & ts, char *nombreTabla){
//Elimina la tabla con nombre nombreTabla de ts
    if (ts == NULL) 
        return ts;
    else if (strcmp(ts->nombre, nombreTabla) > 0)
        ts-> izq = eliminarTabla(ts->izq, nombreTabla);
    else if (strcmp(ts->nombre, nombreTabla) < 0)
        ts-> der = eliminarTabla(ts->der, nombreTabla);
    else {
        Tablas aux;
        if (ts->izq == NULL && ts->der == NULL){  // si es hoja
			delete ts;
			return NULL;
		}
		else if (ts->izq == NULL){
			aux = ts->der;
			delete ts;
			return aux;
		}
		else if (ts->der == NULL){
			aux = ts->izq;
			delete ts;
			return aux;
		}
		else{
			if (profundidad(ts->izq) > profundidad(ts->der))
				aux = max_izq(ts->izq);
			else
				aux = min_der(ts->der);
			aux->izq = ts->izq;
			aux->der = ts->der;
			delete ts;
			return aux;
		}
	}
}

Tablas max_izq(Tablas ts){
//auxiliar encuentra maximo de la izquierda
	if (ts->der == NULL){
		Tablas aux = ts;
		ts = ts->izq;
		return aux;
	}else
		return max_izq(ts->der);
}

Tablas min_der(Tablas ts){
//auxiliar encuentra minimo de la derecha
	if (ts->izq == NULL){
		Tablas aux = ts;
		ts = ts->der;
		return aux;
		
	}else
		return min_der(ts->izq);
}

int profundidad(Tabla ts){
// Auxiliar: retorna la profundidad de la estructura tablas
	if (ts == NULL)
		return 0;
	else
		return 1 + max(profundidad(ts->izq), profundidad(ts->der));
}

char * nombreTabla(Tablas ts){
// devuelve el nombre de la tabla t VER SI SIRVE
    return ts->nombre;
}

void imprimirNombreTablas(Tablas ts){
// imprime los nombres de las Tablas de ts en orden alfabetico
    if (ts != NULL){
        imprimirNombreTablas(ts->izq);
        cout << ts->nombre << "\n";
        imprimirNombreTablas(ts->der);
    }
}

void imprimirTablas(Tablas ts, char * nombreTabla){
// imprime la tabla de nombre "nombreTabla" de ts
     if (ts == NULL)
		cout << "No se puede imprimir la tabla: " << nombreTabla << " ya que no existe en la base de datos\n";
	else if (strcmp(ts->nombre, nombreTabla) == 0) // si encontramos al nombre imprime
           imprimirTabla(ts->t);
	else if (strcmp(ts->nombre, nombreTabla) < 0)
		return imprimirTablas(ts->izq, nombreTabla);
	else
		return imprimirTablas(ts->der, nombreTabla);
}

bool perteneceTabla(Tablas ts, char * nombreTabla){
// devuelve true si la tabla "nombreTabla" ya pertenece a ts
    if (ts == NULL)
		return false;
	else if (strcmp(ts->nombre, nombreTabla) == 0) // si encontramos al nombre
		return true;
	else if (strcmp(ts->nombre, nombreTabla) < 0)
		return perteneceTabla(ts->izq, nombreTabla);
	else
		return perteneceTabla(ts->der, nombreTabla);
}


void destruirTablas(Tablas &ts) { // OJO ACA MAL, DEBE ELIMINAR TODO, NO SE SI ELIMINA LAS TABLAS
// destruye el conjunto de tablas de la base de datos
	if (ts != NULL){
		ts->izq = destruir(ts->izq);
		ts->der = destruir(ts->der);
		delete ts;
	}
}

