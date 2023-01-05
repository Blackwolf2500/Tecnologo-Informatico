#ifndef DATO_H
#define DATO_H


typedef struct nodo_dato * Dato;

Dato crearDatoInt(int* i);
// inserta un tipo Integer

Dato crearDatoChar(char* c);
// inserta un tipo Character

void borrarDato( Dato d);
// borra el dato d

void imprimirDato(Dato d);
// Imprime el dato d


#endif