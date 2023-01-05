#include <stdio.h>
#include "define.h"
#include "filaOrdenada.h"
#include "fila.h"



struct nodo_fila_ordenada{
    Fila f; //puntero a una fila
    FilaOrdenada izq;
    FilaOrdenada der;
};  