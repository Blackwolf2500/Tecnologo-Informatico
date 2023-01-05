// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// racional.c
// Modulo Implementacion Racional.



#include "racional.h"

struct racional{
	int num;
	int den;
};

racional crear(){
	racional r;
	r = new(nodo_racional);
	return r;
}

racional setNumerador(racional r, int n){
// Setea el numerador de r.
	r->num = n;
	return r;
}

racional setDenominador(racional r, int d){
// Setea el denominador de r.
// Pre: d != 0
	r->den = d;
	return r;
}

int getNumerador(racional r){
// Retorna el numerador de r.
	return r->num;
}

int getDenominador(racional r){
// Retorna el denominador de r.
	return r->den;
}

racional suma(racional r1, racional r2){
// Retorna la suma de r1 y r2.
	racional ret = crear();
	ret->num = r1->num*r2->den + r2->num*r1->den;
	ret->den = r1->den * r2->den;
	return ret;
}

racional mult(racional r1, racional r2){
// Retorna el producto de r1 y r2.
	racional ret = crear();
	ret->num = r1->num * r2->num;
	ret->den = r1->den * r2->den;
	return ret;
}


racional div(racional r1, racional r2){
// Retorna el cociente de r1 y r2.
// Pre: r2 != 0.
	racional ret = crear();
	ret->num = r1->den * r2->num;
	ret->den = r1->num * r2->den;
	return ret;
}

racional borrar(racional r){
	delete r;
}



