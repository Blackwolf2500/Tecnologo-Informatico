#include "tabla.h"
#include "listaColumnas.h"
#include "define.h"
#include "listaFilas.h"
#include "fila.h"
#include "filaOrdenada.h"
#include "condicion.h"
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

struct nodo_tabla{
    FilaOrdenada ford;
    ListaColumnas columnas;
    ListaFilas inicioFila;
    ListaFilas finFila;
};

Tabla crearTabla(){
    Tabla t = new(nodo_tabla);
    t->ford = NULL;
    t->columnas= NULL;
    t->inicioFila = NULL;
    t->finFila = NULL;
    return t;
}

bool tablaIsEmpty(Tabla t){
    if (t->inicioFila == NULL)
        return true;
    else
        return false;    
}

bool existePKenTabla(Tabla t) {
// devuelve true si y solo si existe una columna con clasificacion primary key en la tabla  t
    return existePK(t->columnas);
}

int insertarListaColumna(Tabla &t, char * namecol, TipoClas clase, TipoDato tipo){ 
//agrega una lista de columnas lc a la tabla t al final y retorna la posicion de la columna
    t->columnas = insertarColumna(t->columnas, namecol, clase, tipo);
    int i = posicionColumna(t->columnas, namecol);
    return i;
}

bool noHayTuplas(Tabla t) {
    return esVaciaListaFila(t->inicioFila);
}

void agregaNuevaCol(Tabla &t, char * nombreCol, TipoDato td, TipoClas clas){
// inserta la columna en la tabla t y agrega en su posicion  datos EMPTY
    int i = insertarListaColumna(t, nombreCol, clas, td); // la inserta a la col y nos devuelve la posicion de la columna
    ListaFilas lf = t->inicioFila; // itero con lf
    while (!esVaciaListaFila(lf)){
        Fila f = primeraFila(lf);
        insertarDato(f, crearDatoEmpty(), i); // inserta EMPTY en la posicion de la columna nueva en cada fila
        lf = siguienteListaFila(lf);
    }
}

int posicionColumnaEnTabla(Tabla t, char * nombreCol){
// devuelve la posicion de la columna en la tabla t, si la columna no existe retorna 0
    return posicionColumna(t->columnas, nombreCol);
}

TipoRet eliminarListaColumna(Tabla &t, char * namecol){
// elimina lc de la tabla t
    TipoRet i = eliminarColumna(t->columnas, namecol);
    return i;
}

Tabla insertarFila(Tabla &t, Fila f){
//agrega una lista de filas al final de la tabla t
    ListaFilas filas = crearFilas(f); //aca creo la fila completa 
    if (t->inicioFila == NULL) {
        t->inicioFila = filas;
        t->finFila = filas;
    }
    else {
        agregar(t->finFila, filas);
        t->finFila = filas;
    }
    return t;
}

Tabla eliminarListaFila(Tabla &t){
// elimina todas las listas de filas de la tabla t
    ListaFilas aux = siguienteListaFila(t->inicioFila);
    while (!esVaciaListaFila(aux)){        
        destruirListaFilas(t->inicioFila);
        t->inicioFila = aux;
        aux = siguienteListaFila(aux);
    }
    return t;
}

TipoRet modificarColumnaTabla(Tabla &t, char * nombreColActual, char * namecol, TipoClas clas, TipoDato tipo){
// modifica la columna con nombre nombreActual en la tabla t
    return modificarCol(t->columnas, nombreColActual, namecol,clas, tipo);
}

int cantidadColumnasenTabla(Tabla t){
//Retorna la cantidad de columnas de la tabla t
    return cantidadColumnas(t->columnas);
}

TipoClas tipoClasificacionColumna(Tabla t, char* nombreCol) {
//Retorna el tipo de clasificacion de la columna de nombre nombreCol de la tabla t
//PRE: existe la columna nombreCol
    return tipoClaseColumna(t->columnas, nombreCol);
}

ListaFilas primerFiladeFilas(Tabla t) {
// devuelve el primer nodo de la lista de filas de la tabla t
    return t->inicioFila;
}

ListaColumnas primeraColumna(Tabla t) {
// devuelve el primer nodo de la lista de filas de la tabla t
    return t->columnas;
}

TipoDato tipoDatoTuplaenCol(Tabla t, int pos) {
// devuelve el tipo de dato de las tuplas en posicion pos
    return tipoDatoTupla(t->inicioFila, pos);
}

void conversionDato(Tabla &t, int pos){
// modifica el dato de las tuplas de la tabla t en posicion pos
// ej: si el dato es un string, lo modifica a integer, y viceversa
    modificarTD(t->inicioFila, pos);
}

void eliminarDatodeTabla(Tabla &t,  int pos) {
// elimina el dato de la tabla t que se encuentra en la posicion pos de cada fila
    cout << "entra al eliminar dato de tabla \n";   
    eliminarDatodeFila(t->inicioFila, pos);
}

TipoDato return_TipoDato(char * tipoCol){
// devuelve la clasificacion del tipo de dato pasado
	int i = atoi(tipoCol);
	if (i == 0 && strcmp(tipoCol, "0") != 0 )
		return TSTRING;
	else return TINTEGER;
}

bool modificarTuplaCond(Tabla &t, condicion c, char * nuevoDato){
// modifica las tuplas que cumplen con la condicion c
    char * nombreColumna = devuelveNomCol(c);
    TipoDato datoCol = tipoDatoCol(buscarcol(t->columnas, nombreColumna));
    TipoDato nuevo = return_TipoDato(nuevoDato);
    if( datoCol == nuevo) {
        int pos = posicionColumna(t->columnas, nombreColumna);// obtengo la posicion de la col
        ListaFilas iter = t->inicioFila;
        bool modifique;
        while (!esVaciaListaFila(iter)){
           modifique = modificarFila(iter, pos, c, nuevoDato);
        }
        return modifique;
    }else return false;
   
}


bool pasanPrimaryKey(Tabla t, char * columnas){ 
//devuelve true si en las columnas que le pasamos esta la pk, o si no existe pk
// de lo contratrio devuelve false
    if (existePK(t->columnas)){ //si hay PK
        int posPK = posicionPk(t->columnas); //obtengo la posicion de pk
        char * PK = nombreColPos(t->columnas, posPK); //obtengo el nombre de la columna con pk
        char *pch = strtok(columnas, ":");
        bool encontre = false;
		while ((pch != NULL ) && (!encontre)){
            if (strcmp(pch, PK) == 0)
                encontre = true;
            else{
                pch = strtok(NULL, ":");
            }    
        }
        return encontre;  
    }else
        return true;
}

void agregarTuplaVacia(Tabla &t, int cantCol){ 
//agrega una fila de datos vacia de cantCol elementos
    cout << "entro a agregarTuplaVacia \n";
    Fila f = crearTuplaVacia(cantCol);
    cout << "crea tupla vacia \n";
    ListaFilas lf = crearFilas(f);
    cout << "crea fila \n";
    if (!tablaIsEmpty(t)){ // si ya hay tuplas en la tabla
        cout << "Ya hay tuplas \n";
        agregar(t->finFila, lf); //agrega lf como siguiente al final
        cout << "Agrega tuplas vacias \n";
        t->finFila = lf; //actualiza el puntero al final de las listasFilas

    }else{ // si es la primer tupla que se ingresa 
        cout << "primera tupla \n";
        t->inicioFila = lf;
        t->finFila = lf;
    }    
}


TipoRet modificarTuplaFinal(Tabla &t, char * columnasTupla, char * valoresTupla){
// modifica la Lista de filas  que se encuentra al final segun su nombre de columna y valor de tupla
    ListaFilas lf = t->finFila; // fin fila ya esta completa con valores EMPTY
    cout << "columnasTupla: " << columnasTupla <<  "\n";
    char * copia = new char[strlen(columnasTupla)];
    strcpy(copia, columnasTupla); //hago una copia de las columnas que me dieron
    cout << "copia: " << copia <<  "\n";
    char * copiaCol = strtok(copia, ":"); // uso para chequear las columnas si existen
    cout << "copiaCol: " << copiaCol <<  "\n";
    int cant = 0;// cuento la cant de columnas pasadas
    while ((copiaCol != NULL)){ //veo si las columnas que me dieron existen en la tabla 
        if (!perteneceColumna(t->columnas, copiaCol)){ // si no existe columna en tabla
            cout << "Una de las columnas dada no existe en la tabla dada \n";
            return ERROR;
        }else{
            copiaCol = strtok(NULL, ":"); 
            cant ++;
            if (copiaCol != NULL)
                cout << "copiaCol: " << copiaCol <<  "\n";
        }   
    }
    cout << "termino primer while \n";
    char * colDadas = strtok(columnasTupla, ":"); // con esta chequeamos las columnas
    char * arr[cant];
    int i = 0;
    while (colDadas != NULL && i <= cant){ // si llega aca es pq todas las col pasadas pertenecen a la tabla
        arr[i] = colDadas; // guardo los nombres en un arreglo
        colDadas = strtok(NULL, ":");   //paso a los siguientes datos y columnas que me pasaron
        cout << "colDadas: " << arr[i] <<  "\n";
        i++;
    }
    char * valDados = strtok(valoresTupla, ":"); // con esta chequeamos los valores de la tupla
    cout << "valDados: " << valDados <<  "\n";
    int x = 0; // con esta me muevo en el arreglo
    while (valDados != NULL && x <= i){
        int posCol = posicionColumna(t->columnas, arr[x]); //obtengo la pos de la columna dada
        cout << "posCol: " << posCol <<  "\n";
        cout << "nombrecol: " << arr[x] << "\n";
        TipoDato tipoDatoColu = tipoDatoCol(buscarcol(t->columnas ,arr[x])); //obtengo tipo de dato de la columna dada
        cout << "dato col: " << tipoDatoColu <<  "\n";
        TipoRet inserto = insertarEnLF(lf, posCol, tipoDatoColu, valDados);  //inserto dato en la columna que me pasan
        cout << "resultado inserto: " << inserto <<  "\n";
        if (inserto == ERROR){ // si no se inserto es pq no corresponde el tipo de dato
            cout << "El dato no corresponde con el tipo de dato de la columna\n";
            return ERROR;
        }
        x++;
        cout << "x :" << x << "\n";
        valDados = strtok(NULL, ":"); // paso al siguiente valor que me pasaron
        if (valDados != NULL)
            cout << "valDados: " << valDados <<  "\n";
    }
    if (existePK(t->columnas)){ // si existe PK inserta en la fila Ordenada
        cout << "existe PK\n";
        int posPK = posicionPk(t->columnas); // devuelve la posicion de la pk
        cout << "posicionPK: " << posPK << "\n";
        Dato pk = copiaDato(primeraFila(t->finFila), posPK);
        t->ford =insertarFilaFO(t->ford, t->finFila, pk, posPK); // inserta la ultima fila en ford segun pk
    }
    return OK;   // si llegue aca es porque inserto todas ok 
}

void eliminarFilaCond(Tabla &t, condicion c){
// elimina la fila de datos completa
    // aca que estoy en la Tabla tengo acceso a las filas y a las col
    // aca es donde tengo que sacar cual es la columna para ya ver si existe o no
    // si la col existe ahi me meto en las filas
    int pos = posicionColumna(t->columnas, devuelveNomCol(c));// obtengo la posicion de la col
    ListaFilas aux = t->inicioFila;
    ListaFilas iter = t->inicioFila;
    while(!esVaciaListaFila(iter)){
        bool elimine = eliminarFila(iter, pos, c);
        if (elimine){
            int posPK = posicionPk(t->columnas); // me da la posicion de la pk
            if (iter == t->inicioFila){
                if (iter != t->finFila){
                    t->inicioFila = siguienteListaFila(iter);
                    eliminarFilaOrd(t->ford, iter , posPK); // con el fo, ListaFila y posicion de la pk 
                    elimNodoLF(iter);
                    iter = t->inicioFila;
                    aux = iter;
                }else{ //Queda vacia la lista
                    t->inicioFila = NULL;
                    t->finFila = NULL;
                    eliminarFilaOrd(t->ford, iter , posPK);
                    elimNodoLF(iter);
                }
            }else if(iter == t->finFila){
                t->finFila = aux;
                eliminarFilaOrd(t->ford, iter , posPK);
                eliminarNodoListaFilaFinal(aux, iter);
            }else{
                eliminarFilaOrd(t->ford, iter , posPK);
                eliminarNodoListaFilaMedio(aux, iter);
            }
        }else{   // si no lo elimine
            if (iter != t->inicioFila)
                aux = iter;                                 
            iter = siguienteListaFila(iter);            
        }
    }
}

void vaciarTabla(Tabla &t) {
// elimina todas las filas y lista de filas
    destruirFilaOrd(t->ford); // elimina la estructura ordenada si es que hay
    destruirListaFilas(t->inicioFila); // elimina las filas
} 

void imprimirTabla(Tabla t){
// imprime la tabla entera, primero la lista de columnas y luego la lista de filas
    if (!esVaciaListaCol(t->columnas)) {
        imprimirListaCol(t->columnas);
        if (!esVaciaListaFila(t->inicioFila))
            imprimirListaFilas(t->inicioFila);
    }
}

void imprimirNombresColumnas(Tabla t){
// imprime los nombres de las columnas
    imprimirNombresCol(t->columnas);
}

void imprimirInfoColumnas(Tabla t){
// imprime solo la informacion de las columnas
    if (!esVaciaListaCol(t->columnas)) 
        imprimirListaCol(t->columnas);
}

void imprimirTuplasOrd(Tabla t) {
// imprime las tuplas de forma ordenada separadas con :
    //imprimirTuplasOrdenadas(t->ford);
    imprimirListaFilas(t->inicioFila);
}

void destruirTabla(Tabla &t){
// destruye la tabla t
    destruirListaCol(t->columnas); // elimina todas las columnas
    destruirListaFilas(t->inicioFila); // elimina las filas
    destruirFilaOrd(t->ford); // elimina la estructura ordenada 
    delete(t);
}






