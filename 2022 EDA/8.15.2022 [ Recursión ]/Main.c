#include "Recurcion.h"
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <unistd.h>

using namespace std;

int main(int argc, char * argv[]){
    if(strcmp(argv[1], "fact")==0){
        cout << atoi(argv[2]) << "! = "; cout << factorial(atoi(argv[2])) << endl;
    }else if (strcmp(argv[1],"mult")==0){
        cout << atoi(argv[2]) << "x" << atoi(argv[3]) << " = "; cout << multiplicacion(atoi(argv[2]), atoi(argv[3])) << endl;
    }else if(strcmp(argv[1],"suma")==0){
        unsigned int num = suma(atoi(argv[2]), atoi(argv[3]));
        cout << atoi(argv[2]) << "+" << atoi(argv[3]) << " = "; cout << num << endl;
    }else{
        cout << "Error esa opcion no existe";
    }
    return 1;
}