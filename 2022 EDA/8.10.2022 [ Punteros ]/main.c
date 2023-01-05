#include "iostream"

using namespace std;
void limpiar(){
    system("clear");
}

int main(){
    limpiar();
    
    int arr[10];
    for(int i = 0; i<10;i++){
        arr[i] = i;
    }
    
    for(int i = 0; i<10;i++){
        cout << "espacio[" << i << "] tiene: " << arr[i] << "\n";
    }
    
    /* CASTEO
    char a  = '@';
    cout << "char = " << a << "   int = " << (int)a << "\n";
    */
    
    /* EJEMPLO DE PUNTEROS
    int *a;
    a = new(int);
    *a = 3;
    int *b;
    b = new(int);
    *b = 7;
    cout << a << "->" << *a << "\n";
    cout << b << "->" << *b << "\n";
    a = b;
    cout <<"--------------"<<"\n";
    cout << a << "->" << *a << "\n";
    cout << b << "->" << *b << "\n";

    delete b;
    */
    return 1;
}