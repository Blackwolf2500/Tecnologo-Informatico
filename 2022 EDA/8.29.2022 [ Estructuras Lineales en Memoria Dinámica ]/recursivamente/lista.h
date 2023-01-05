#ifndef LISTA_H
#define LISTA_H

typedef struct nodo_lista * lista;

bool IsElement(int x, lista l);
// Retorna true si x pertenece a l, false en caso contrario.
int Length(lista l);
// Retorna la cantidad de elementos de la lista
int Last(lista l);
// Retorna el último elemento de l.
// Pre: l no es vacía.
int Max(lista l);
// Retorna el máximo elemento de l.
// Pre: l no es vacía.
float Average(lista l);
// Retorna si la lista no es vacía el promedio de sus elementos.
// Pre: l no es vacía.
lista Insert(int x, lista l);
// Inserta ordenadamente el elemento x en la lista ordenada l.
lista Snoc(int x, lista l);
// Inserta el elemento x al final de la lista l.
lista Remove(int x, lista l);
// Elimina todas las ocurrencias de x en la lista l
bool Equals(lista l, lista p);
// Verifica si las listas l y p son iguales (mismos elementos en el mismo orden).
lista Take(int i, lista l);
// Retorna la lista resultado de tomar los primeros i elementos.
// l no comparte memoria con la lista resultado.
lista Drop(int u, lista l);
// Retorna la lista resultado de no tomar los primeros u elementos.
// l no comparte memoria con la lista resultado.
lista Merge(lista l, lista p);
// Genera una lista fruto de intercalar ordenadamente las listas
// l y p que vienen ordenadas.
// l y p no comparten memoria con la lista resultado.
lista Append(lista l, lista p);
// Agrega la lista p al final de la lista l.
// l y p no comparten memoria con la lista resultado.

#endif