#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "definiciones.h"

typedef struct nodo_dicc * dicc;

dicc CrearDicc();
//Crea el diccionario.

TipoRetorno IngresarPalabraDiccionarioD(dicc & d, Cadena palabraAIngresar);
// Agrega una palabra al diccionario.
// Esta operación debe realizarse en a lo sumo O(log n) promedio.

void ImprimirDiccionarioD(dicc & d);
// Muestra las palabras del diccionario alfabéticamente.
// Esta operación debe realizarse en O(n) peor caso.

int profundidad(dicc d);
// Retorna la profundidad del diccionario.

dicc max_iz(dicc d);
//Retorna la palabra lexicograficamente mas grande de la izquierda.

dicc min_de(dicc d);
//Retorna la palabra lexicograficamente mas pequeña de la derecha.

int max(int a, int b);
// Retorna el maximo de a y b.

dicc BorrarPalabraDiccionarioD(dicc d, Cadena palabraABorrar);
// Borra una palabra del diccionario.
// Ver más detalles en la letra del obligatorio.

bool pertenece(Cadena palabraABorrar, dicc d);
// Retorna true si la palabra pertenece a d, false en caso contrario.

TipoRetorno DestruirDicc(dicc & d);
// Destruye el arbol.
#endif
