#ifndef DYNAR_ARRAY_H
#define DYNAR_ARRAY_H

typedef struct nodo_dynar * dynar;

dynar dynar_crear(int tam);
//crea arreglo
dynar dynar_ins(dynar d, char * cadena);
//setea la cadena d
//Pre: lego cadeba <= tamaño d
int dynar_tam(dynar d);
//retorna el tamaño
char * dynar_cad(dynar d);
//retorna cadena en d
dynar dynar_redimension(dynar d, int tam);
//redimenciona
dynar dynar_destruir(dynar d);
//rompe toti

#endif