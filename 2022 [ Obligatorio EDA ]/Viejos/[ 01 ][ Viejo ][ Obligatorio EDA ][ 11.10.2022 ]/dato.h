#ifndef DATO_H
#define DATO_H


typedef struct nodo_dato * Dato;

Dato crearDato(int i);
//Crea el dato de tipo integer

Dato crearDato(char * c);
//Crea el dato de tipo cadena de caracteres

void borrarDato( Dato d);
// borra el dato d

void imprimirDato(Dato d);
// Imprime el dato d


#endif