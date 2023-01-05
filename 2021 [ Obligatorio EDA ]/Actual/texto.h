#ifndef TEXTO_H
#define TEXTO_H

// editor.h
// Modulo de especificacion de editor

#include "definiciones.h"

typedef struct nodo_texto* texto;

texto CrearTexto();
//Crea un texto nuevo vacio;

TipoRetorno InsertarLineaT(texto & t);
// Inserta una nueva línea vacía al final del texto.
// Este requerimiento debe ser resuelto en O(1) peor caso.

TipoRetorno InsertarLineaEnPosicionT(texto & t, Posicion posicionLinea);
// Inserta una nueva línea vacía en la posición indicada.

TipoRetorno BorrarLineaT(texto & t, Posicion posicionLinea);
// Borra la línea en la posición indicada.

TipoRetorno BorrarTodoT(texto & t);
// Borra todas las líneas del texto.

TipoRetorno BorrarOcurrenciasPalabraEnTextoT(texto & t, Cadena palabraABorrar);
// Borra todas las ocurrencias de una palabra en el texto.

TipoRetorno InsertarPalabraT(texto & t, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar);
// Inserta una palabra en una línea.

TipoRetorno BorrarPalabraT(texto & t, Posicion posicionLinea, Posicion posicionPalabra);
// Borra la palabra en la posición indicada.

TipoRetorno ImprimirTextoT(texto t);
// Imprime el texto por pantalla.

TipoRetorno ImprimirLineaT(texto t, Posicion posicionLinea);
// Imprime la línea por pantalla.

TipoRetorno BorrarOcurrenciasPalabraEnLineaT(texto & t, Posicion posicionLinea, Cadena palabraABorrar);
// Borra todas las ocurrencias de una palabra en la línea indicada.

TipoRetorno ComprimirTextoT(texto & t);
// Comprime las palabras del texto. Para implementar esta operación no debe generarse un nuevo documento.
// Ver más detalles en la letra del obligatorio.

int CopiarCantLinT(texto t);
//Copia la cantidad de lineas.

int CopiarCantPalT(texto t, int posL);
//Copia la cantidad de lineas.

Cadena CopiarPalT(texto t, int posL, int posP);
//Copia una cadena de caracteres y la retorna.

#endif
