#include "listaCircular.h"
#include <iostream>

using namespace std;

struct nodo_listaC{
    int dato;
    listaC sig;
};

listaC cons(int x,listaC l){
//Agregar un elemento x al inicio de la lista.
    listaC aux = new(nodo_listaC);
    aux->dato = x;
    if(l == NULL){
        aux->sig = aux;
    }else{
        listaC iter = l;
        while(iter->sig != l){
            iter = iter->sig;
        }
        iter->sig = aux;
        aux->sig = l;
    }
    return aux;
}

listaC snoc(int x,listaC l){
//Agregar un elemento x al final de la lista.
    listaC aux = new(nodo_listaC);
    aux->dato = x;
    if(l == NULL){
        aux->sig = aux;
        return aux;
    }else{
        listaC iter = l;
        while(iter->sig != l){
            iter = iter->sig;
        }
        iter->sig = aux;
        aux->sig = l;
        return l;
    }
}

void imprimirIter(listaC l){
//Imprimir los elementos de la lista, separados por guiones.
    listaC iter = l;
    while(iter->sig != l){
        cout << "[ " << iter->dato << " ] - ";
        iter = iter->sig;
    }
    return l;
}

void imprimirRecu(listaC l){
//Imprimir los elementos de la lista, separados por guiones.
    if(l != NULL){
        imprimir_auxRecurciva(l, l);
    }
}

void imprimir_auxRecurciva(listaC l, listaC ini){
    if(l->sig == ini){
        cout << "[ " << l->dato << " ]";
    }else{
        cout << "[ " << l->dato << " ] - ";
        imprimir_auxRecurciva(l->sig, ini);
    }
}

listaC eliminar(int x,listaC l){
//Eliminar un elemento x.
    if(l == NULL){
        return l;
    }else{
        bool borre = false;
        listaC ini = l, ant;
        do{
            if(!borre){
                ant = l;
                l = l->sig;
            }else{ borre = flase; }
            if(l->dato == x){
                ant->sig = l->sig;
                if(l == ini){
                    ini = ini->sig;
                }
                if(ant == l){
                    delete l;
                    l = NULL;
                    ini = NULL;
                }else{
                    delete l;
                    l = ant->sig;
                    borre = true;
                }
            }
        }while(l != ini);
        return ini;
    }
}

listaC eliminarL(listaC l){
//Eliminar la lista completa.
    listaC ini = l, ant = l;
    if(l != NULL){
        l = l->sig;
        while(l->sig != ini){
            ant = l;
            l = l->sig;
            delete ant;
        }
        delete ini;
        l = NULL;
    }
    return l;
}

bool buscarIter(int x,listaC l){
//Buscar si existe un elemento x.
    listaC ini = l;
    bool existe = false;
    while((l->sig != ini) && (existe)){
        if(l->dato == x){
            existe = true;
        }else{
            l=l->sig;
        }
    }
    return existe;
}

bool buscarRecu(int x,listaC l){
//Buscar si existe un elemento x.
    if(l != NULL){
        return pertenece(x,l,l);
    }else{ return false; }
}

bool pertenece(int x, listaC l, listaC ini){
    if(l->dato == x){
        return true;
    }else if(l->sig == ini){
        return false;
    }else{
        return pertenece(x, l->sig, ini);
    }
}

int contadorIter(int x, listaC l){
//Contar las ocurrencias del elemento x en la lista.
    listaC ini = l;
    int cantidad = 0;
    while(l->sig != ini){
        if(l->dato == x){
            cantidad++;
        }
        l=l->sig;
    }
    return cantidad;
}

int contadorRecu(int x, listaC l){
//Contar las ocurrencias del elemento x en la lista.
  if(l != NULL){
      return cantidadX(x,l,l);
  }else{
      return 0;
  }
}

int cantidadX(int x, listaC l, listaC ini){
    if(l->dato == x){
        if(l->sig == ini){
            return 1;
        }else{
            return 1 + cantidadX(x, l->sig, ini);
        }
    }else{
        if(l->sig == ini){
            return 0;
        }else{
            return 0 + cantidadX(x, l->sig, ini);
        }
    }
}

listaC insertar(int x, listaC l){
//Insertar un elemento en forma ordenada (asumiendo que la lista ya está ordenada).
    listaC aux = new(nodo_listaC);
    aux->dato = x;
    if(l == NULL){
        l = aux;
    }else{
        listaC ini = l;ant = l;
        while(ant->sig != l){
            ant=ant->sig;       
        }
        if(ant == l){
            aux->sig = l;
            l->sig = aux;
            if(aux->dato < l->dato){
                ini = aux;
            }
        }else{
            while((l->sig != ini)&&(l->dato < x)){
                ant = l;
                l = l->sig;
            }
            if(l->dato > x){
            ant->sig = aux;
            aux->sig = l;
            }else{
                l->sig = aux;
                aux->sig = ini;
            }
        }
    }
    return ini;
}

int max(listaC l){
//Devolver el máximo de la lista.
//Asumir que la lista no es vacía.
    listaC ini = l;
    int maximo = 0;
    if(l == NULL){
        return 0;
    }else{
        while(l->sig != ini){
            if(maximo < l->dato){
                maximo = l->dato;
            }
            l = l->sig;
        }
        return ini;
    }
}