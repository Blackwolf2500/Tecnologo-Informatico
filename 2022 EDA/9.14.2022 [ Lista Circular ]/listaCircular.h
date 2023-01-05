#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

typedef struct nodo_listaC * listaC;

listaC cons(int x,listaC l);
//Agregar un elemento x al inicio de la lista.
listaC snoc(int x,listaC l);
//Agregar un elemento x al final de la lista.
void imprimirIter(listaC l);
//Imprimir los elementos de la lista, separados por guiones.
void imprimirRecu(listaC l);
//Imprimir los elementos de la lista, separados por guiones.
listaC eliminar(int x,listaC l);
//Eliminar un elemento x.
listaC eliminarL(listaC l);
//Eliminar la lista completa.
bool buscarIter(int x,listaC l);
//Buscar si existe un elemento x.
bool buscarRecu(int x,listaC l);
//Buscar si existe un elemento x.
int contadorIter(int x, listaC l);
//Contar las ocurrencias del elemento x en la lista.
int contadorRecu(int x, listaC l);
//Contar las ocurrencias del elemento x en la lista.
listaC insertar(int x, listaC l);
//Insertar un elemento en forma ordenada (asumiendo que la lista ya está ordenada).
int max(listaC l);
//Devolver el máximo de la lista.
//Asumir que la lista no es vacía.

#endif