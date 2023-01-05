#ifndef TABLA_H
#define TABLA_H
#include "listaColumnas.h"
#include "listaFilas.h"


typedef struct nodo_tabla * Tabla;


Tabla crearTabla();
/*crea una tabla vacia
punteros: t->inicioFila
            t->finFila
            t->inicioCol
            t->finCol
todos a NULL */

Tabla insertarListaColumna(Tabla &t, ListaColumnas lc);
//agrega una lista de columnas a la tabla t al final

Tabla eliminarListaColumna(Tabla &t, ListaColumnas lc);
// elimina lc de la tabla t

Tabla insertarListaFila(Tabla &t, ListaFilas f);
//agrega una lista de fila a la tabla t al final

Tabla eliminarListaFila(Tabla &t, ListaFilas f);
// elimina f de la tabla t

void imprimirTabla(Tabla t);
// imprime la tabla entera, primero la lista de columnas y luego la lista de filas

void destruirTabla(Tabla t);
// destruye la tabla t

#endif