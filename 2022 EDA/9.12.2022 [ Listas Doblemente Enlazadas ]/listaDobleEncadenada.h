#ifndef LISTADOBLEENCADENADA_H
#define LISTADOBLEENCADENADA_H

typedef struct nodo_listaDE * listaDE;

listaDE Null();
//Inserta un la lista al vacio.
listaDE cons_DE(int x, listaDE l);
//Inserta un dato al inicio de la lista.
listaDE snoc_DE(int x, listaDE l);
//Inserta un dato al final de la lista.
listaDE insert_DE(int x, listaDE l);
//Inserta un dato ordenadamente dentro de la lista.
//Pre: la lista esta ordenada.
int cantidad(listaDE l);
//Retorna la cantidad de elementos en la lista.
int cant_ant(listaDE l);
//Tuneo de cantidad().
int cant_sig(listaDE l);
//Tuneo de cantidad().
listaDE eliminar_DE(int x,listaDE l);
//Elimina l de la lista.
listaDE imprimir(listaDE l);
//Imprime todos los elementos de l.
listaDE imprimir_inv(listaDE l);
//Imprime todos los elementos de l desde el ultimo al primero.
#endif