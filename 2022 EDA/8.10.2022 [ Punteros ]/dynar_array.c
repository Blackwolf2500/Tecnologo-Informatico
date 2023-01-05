#include "dynar_array.h"
#include <string.h>

struct nodo_dynar{
    char * cadena;
    unsigned int tam;
};

dynar dynar_crear(int tam){
//crea arreglo
    dynar aux = new(nodo_dynar);
    aux->tam = tam;
    aux->cadena = new char[tam];
    return aux;
}

dynar dynar_ins(dynar d, char * cadena){
//setea la cadena d
//Pre: lego cadeba <= tamaño d
    strcpy(d->cadena, cadena);  // copia la cadeba en la direccion (d)
    return d;
}

int dynar_tam(dynar d){
//retorna el tamaño
    return d->tam;
}

char * dynar_cad(dynar d){
//retorna cadena en d
    return d->cadena;
}

dynar dynar_redimension(dynar d, int tam){
//redimenciona
    char * aux = new char[d->tam];// crea aux con el nuevo tamaño
    if(d->tam + tam < d->tam){ //tamaño es mas chico que el tamaño asignado
        for(int i=0;i<tam;i++){ //recorre el tamaño
            aux[i] = d->cadena[i];// en cada lugar copia la cadena
        }
    }else{
        for(int i=0;i<d->tam;i++){ //recorre el tamaño nuevo
            aux[i] = d->cadena[i];// en cada lugar copia la cadena
        }
    }
    d->tam += tam; // es lo mismo que: "d->tam = d->tam + tam;"
    delete [] d->cadena;
    d->cadena = aux;
    return d;
}

dynar dynar_destruir(dynar d){
//Rompe toti
    delete [] d->cadena;
    delete d;
    return d;
}