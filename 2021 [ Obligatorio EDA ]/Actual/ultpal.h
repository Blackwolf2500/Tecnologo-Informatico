#ifndef ULTPAL_H
#define ULTPAL_H

#include "definiciones.h"

typedef struct nodo_ultPal* ultPal;

void GuardarUltimaPalabraU2(ultPal & primeraP, ultPal & ultimaP, Cadena palabraAIngresar, int cantPal);
//Guarda la palabra temporalmente.

void BorrarUltElem(ultPal & primeraP, ultPal & ultimaP);
//Borra la ultima palabra.

TipoRetorno ImprimirUltimasPalabrasU2(ultPal iter);
// Imprime las últimas MAX_CANT_ULTIMAS_PALABRAS palabras ingresadas al texto.
// Ver más detalles en la letra del obligatorio.

#endif
