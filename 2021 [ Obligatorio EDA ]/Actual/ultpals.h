#ifndef ULTPALS_H
#define ULTPALS_H

#include "definiciones.h"

typedef struct nodo_ultPalabras* ultPals;

ultPals CrearUltimasPalabras();
//crea la estructura de las ultimas palabras.

void GuardarUltimaPalabraU1(ultPals & u, Cadena palabraAIngresar);
//Guarda la palabra temporalmente.

TipoRetorno BorrarUltPals(ultPals & u);
//Borra la ultima palabra.

TipoRetorno ImprimirUltimasPalabrasU1(ultPals u);
// Imprime las últimas MAX_CANT_ULTIMAS_PALABRAS palabras ingresadas al texto.
// Ver más detalles en la letra del obligatorio.

#endif
