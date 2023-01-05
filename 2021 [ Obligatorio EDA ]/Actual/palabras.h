#ifndef PALABRAS_H
#define PALABRAS_H

#include "definiciones.h"

typedef struct nodo_palabra* palabra;

TipoRetorno InsertarPalabraP(palabra & primeraP, palabra & ultimaP, Posicion posicionPalabra, Cadena palabraAIngresar, int cantPal);
// Inserta una palabra en una línea.
// Ver más detalles en la letra del obligatorio.

TipoRetorno BorrarPalabraP(palabra & primeraP, palabra & ultimaP, Posicion posicionPalabra, int cantPal);
// Borra la palabra en la posición indicada.
// Ver más detalles en la letra del obligatorio.

TipoRetorno BorrarOcurrenciasPalabraEnPalabra(palabra & primeraP, palabra & ultimaP, Cadena palabraABorrar, int & cantPal);
// Borra todas las ocurrencias de una palabra.

TipoRetorno imprimirPalabrasDeLineaP(palabra primeraP, int cantPal);
//Imprime todas las palabras de una linea dada.

Cadena CopiarPalP(palabra NodPal, int posP);
//Copia una cadena de caracteres y la retorna.

#endif
