#ifndef LISTA_H
#define LISTA_H

typedef struct nodo_lista * lista;
typedef nodo_listagral * listagral;

lista Null();
// Crea la lista vacía.
lista Cons(int x, lista l);
// Inserta el elemento x al principio de la lista l.
bool IsEmpty(lista l);
// Retorna true si l es vacía, false en caso contrario.
int Head(lista l);
// Retorna el primer elemento de la lista.
// Pre: l no vacía.
lista Tail(lista l);
// Retorna la lista sin su primer elemento.
// Pre: l no vacía.
bool IsElement(int x, lista l);
// Retorna true si x pertenece a l, false en caso contrario.
lista Remove(int x, lista l);
// Retorna la lista fruto de eliminar x en l.
// l no comparte memoria con la lista resultado.
int Length(lista l);
// Retorna la cantidad de elementos de la lista.
lista Snoc(int x, lista l);
// Retorna la lista fruto de insertar el elemento x al final de la lista l.
// l no comparte memoria con la lista resultado.
lista Append(lista l, lista p);
// Retorna la lista fruto de agregar la lista p al final de la lista l.
// l y p no comparten memoria con la lista resultado.
lista Insert(int x, lista l, bool inserte);
// Retorna la lista fruto de insertar ordenadamente el elemento x en la lista ordenada l.
// l no comparte memoria con la lista resultado.
int Last(lista l);
// Retorna el último elemento.
// Pre: l no vacía.
int HowMany(int x, lista l);
// Cuenta las ocurrencias del natural x en la lista l
int Max(lista l);
// Retorna el máximo elemento de l.
// Pre: l no vacía.
bool IsSorted(lista l);
// Retorna true si l está ordenada, false en caso contrario.
lista Change(int x, int y, lista l);
// Retorna una nueva lista fruto de cambiar x por y en l.
// l no comparte memoria con la lista resultado.
lista InsBefore(int x, int y, lista l);
// Retorna una nueva lista fruto de insertar x antes de y en l.
// l no comparte memoria con la lista resultado
lista InsAround(int x, int y, lista l);
// Retorna una nueva lista fruto de insertar x antes y después de y en l.
// l no comparte memoria con la lista resultado.
bool Equals(lista l, lista p);
// Retorna true si las listas l y p son iguales (mismos elementos en el mismo orden)
// false en caso contrario.
void Show(lista l);
// Muestra los elementos de la lista l.

/*<--       Lista General       -->*/

listagral NullLG();
// Crea la lista general vacía.
listagral ConsLG(listagral lg, lista l);
// Inserta la lista elemento l al principio de la lista general lg.
bool IsEmptyLG(listagral lg);
// Verifica si la lista general está vacía.
lista HeadLG(listagral lg);
// Retorna la primer lista elemento.
// Pre: lg no vacía.
listagral TailLG(listagral lg);
// Retorna lg sin su primer elemento.
// Pre: lg no vacía.
int LengthLG(listagral lg);
// Retorna la cantidad de naturales de la lista general lg.
void ShowLG(listagral lg);
// Muestra la lista general separando los naturales y listas de naturales por comas y
// encerrando cada lista de naturales entre paréntesis.
#endif