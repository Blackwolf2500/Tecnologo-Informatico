#include <iostream>
#include "racional.h"

using namespace std;


void imprimir(racional r){
	cout << getNumerador(r) << "/" << getDenominador(r);
}

int main(){
	racional r1, r2, sum, mul, divi;
	r1 = setNumerador(r1, 1);
	r1 = setDenominador(r1, 2);

	r2 = setNumerador(r2, 1);
	r2 = setDenominador(r2, 2);
	
	sum = suma(r1,r2);
	mul = mult(r1,r2);
	divi = div(r1,r2);

	cout << " - ";
	imprimir(r1);	
	cout << " + ";
	imprimir(r2);
	cout << " = ";
	imprimir(sum);
	cout << "\n";
	
	cout << " - ";
	imprimir(r1);	
	cout << " * ";
	imprimir(r2);
	cout << " = ";
	imprimir(mul);
	cout << "\n";
	
	cout << " - ";
	imprimir(r1);	
	cout << " / ";
	imprimir(r2);
	cout << " = ";
	imprimir(divi);
	cout << "\n";

	return 1;
}

