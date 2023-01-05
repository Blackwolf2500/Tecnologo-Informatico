#ifndef TABLAS_H
#define TABLAS_H

#include "define.h"
#include "tabla.h"


typedef struct nodo_Tablas * Tablas;

Tablas crearTablas();
// Crea una estructura Tablas vacío.

Tablas insertarTabla (Tablas & ts, char *nombreTabla, Tabla t);
// Inserta la tabla t en ts en orden alfabetico segun nombreTabla

Tablas eliminarTabla(Tablas & ts, char *nombreTabla);
//Elimina la tabla con nombre nombreTabla de ts

char * nombreTabla(Tablas ts);
// devuelve el nombre de la tabla t VER SI SIRVE

void imprimirNombreTablas(Tablas ts);
// imprime los nombres de las Tablas de ts

void imprimirTablas(Tablas ts, char * nombreTabla);
// imprime la tabla de nombre "nombreTabla" de ts

bool perteneceTabla(Tablas ts, char * nombreTabla);
// devuelve true si la tabla "nombreTabla" ya pertenece a ts

void destruirTablas(Tablas &ts);
// destruye el conjunto de tablas de la base de datos

/* a lo que se puede acceder en este modulo:
            ts->t
            ts->izq
            ts->der
            ts->nombre
*/

#endif