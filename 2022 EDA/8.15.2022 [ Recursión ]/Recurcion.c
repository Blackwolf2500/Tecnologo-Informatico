#include "Recurcion.h"
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <unistd.h>

using namespace std;

unsigned int factorial(unsigned int n){
// Retorna el factorial de n
    if(n == 0){
        return  1;
    }else{
         system("clear");
        return n * factorial(n -1);
    }
}

unsigned int suma(unsigned int a, unsigned int b){
//Retorna la suma de a y b implementado de manera recursiva.
    sleep(1);
    if(b==0){
        cout << "PI" << endl;
        system("clear");
        return a;
    }else{
         system("clear");
        cout << "PB" << endl;
        return suma(a+1, b-1);
    }
}

unsigned int multiplicacion(unsigned int a, unsigned int b){
// Retorna el producto de a y b
    if((a==0)||(b==0)){
        return 0;
    }else if(a==1){
         system("clear");
        return b;
    }else if(b==1){
         system("clear");
        return a;
    }else{
         system("clear");
        return a + multiplicacion(a, b-1);
    }
}