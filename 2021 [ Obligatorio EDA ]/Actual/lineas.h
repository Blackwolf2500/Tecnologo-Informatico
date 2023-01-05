#ifndef LINEAS_H
#define LINEAS_H

#include "definiciones.h"

typedef struct nodo_linea* linea;

TipoRetorno InsertarLineaL(linea & primeraL, linea & ultimaL);
// Inserta una nueva línea vacía al final del texto.
// Este requerimiento debe ser resuelto en O(1) peor caso.
// Ver más detalles en la letra del obligatorio.

TipoRetorno InsertarLineaEnPosicionL(linea & primeraL, linea & ultimaL, Posicion posicionLinea, int cantLineas);
// Inserta una nueva línea vacía en la posición indicada.
// Ver más detalles en la letra del obligatorio.

TipoRetorno BorrarLineaL(linea & primeraL, linea & ultimaL, Posicion posicionLinea, int cantLineas);
// Borra la línea en la posición indicada.
// Ver más detalles en la letra del obligatorio.

TipoRetorno BorrarPalabraL(linea & primeraL, linea & ultimaL, int cantLineas, Posicion posicionLinea, Posicion posicionPalabra);
// Borra la palabra en la posición indicada.
// Ver más detalles en la letra del obligatorio.

bool haypalabra(linea l);
//Retorna true si hay palabras y false en caso contrario.

TipoRetorno BorrarOcurrenciasPalabraEnLineaL(linea & ln, Posicion posicionLinea, Cadena palabraABorrar);
// Borra todas las ocurrencias de una palabra en la línea indicada.
// Ver más detalles en la letra del obligatorio.

TipoRetorno InsertarPalabraL(linea & primeraL, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar);
// Inserta una palabra en una línea.
// Ver más detalles en la letra del obligatorio.

TipoRetorno ImprimirLineaL(linea primeraL, Posicion posicionLinea, int cantLineas);
// Imprime la línea por pantalla.
// Ver más detalles en la letra del obligatorio.

int ComprimirTextoL(linea & primeraL, linea & ultimaL, int cantLineas);
// Comprime las palabras del texto. Para implementar esta operación no debe generarse un nuevo documento.
// Ver más detalles en la letra del obligatorio.

int CopiarCantPalL(linea l, int posL);
//Copia la cantidad de palabras.

Cadena CopiarPalL(linea l, int posL, int posP);
//Copia una cadena de caracteres y la retorna.

#endif
