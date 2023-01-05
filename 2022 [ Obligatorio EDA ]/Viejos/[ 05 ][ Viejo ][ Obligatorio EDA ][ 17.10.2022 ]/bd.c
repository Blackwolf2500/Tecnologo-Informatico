// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// bd.c
// Modulo de Implementación de Base de Datos.

#include "bd.h"
#include "tablas.h"
#include "tabla.h"
#include "fila.h"
#include "columna.h"

#include <iostream>
#include <string.h>

using namespace std;

struct nodo_bd
{
	Tablas ts; // nodo que apunta al arbol de tablas
};

bd createBD()
{
	// Crea la base de datos vacía.
	bd bd = new (nodo_bd);
	bd->ts = crearTablas();
	return bd;
}

TipoRet createTable(bd &bd, char *nombreTabla){
	// Crea una nueva tabla vacía (sin columnas ni tuplas) en la base de datos
	// con nombre nombreTabla, siempre que no exista ya una tabla con dicho nombre.
	if (!perteneceTabla(bd->ts, nombreTabla)){// si no hay una tabla con el mismo nombre, inserta
		Tabla t = crearTabla();				   // crea una tabla vacia
		t = insertarTabla(bd->ts, nombreTabla, t); // inserta en las tablas base de datos una tabla vacia con nombreTabla
		return OK;
	}
	else {
		cour << "No se pudo crear la tabla ya que ya existe una con el mismo nombre /n";
		return ERROR;
	}
}

TipoRet dropTable(bd &bd, char *nombreTabla){
// Elimina de la base de datos la tabla de nombre nombreTabla, y las tuplas
// que la misma posee, si nombreTabla existe.
	Tabla aborrar = tablaSleccionada(bd->ts, nombreTabla);
	if(agregaCol != NULL) {
		destruirTabla(aborrar);				// destruye tabla
		eliminarTabla(bd->ts, nombreTabla); // elimina tabla del abb tablas
		return OK;
	}
	else return ERROR;
}

TipoClas returnClasificador(char *clasificadorCol){
// Devuelve el TipoClas correspondiente segun el string ingresado
	if (strcasecmp( "NOT_EMPTY" , clasificadorCol) == 0)
		return NOT_EMPTY;
	else if (strcasecmp( "PRIMARY_KEY" , clasificadorCol) == 0)
		return PRIMARY_KEY;
	else return ANY;
}

TipoDato returnTipoDato(char * tipoCol){
// devuelve la clasificacion del tipo de dato pasado
	int i = atoi(tipoCol);
	if (i == 0 && tipoCol != "0")
		return TSTRING;
	else return TINTEGER;
}

TipoRet addCol(bd &bd, char *nombreTabla, char * NombreCol, char *tipoCol, char *calificadorCol){
// Agrega a la tabla de nombre nombreTabla, si ésta existe, una nueva columna al final de nombre nombreCol,
// si ésta no existe. Si la tabla tiene tuplas el nuevo campo tendrá el valor EMPTY en cada tupla. Por lo
// tanto, en el caso de que la tabla tenga tuplas, no es válido que se agregue un calificador distinto de ANY.
// Tampoco es válido que calificadorCol sea PRIMARY KEY si existe ya una columna con dicho calificador en la
// tabla nombreTabla.
	Tabla agregaCol = tablaSleccionada(bd->ts, nombreTabla); // va a devolver NULL si no existe
	if(agregaCol != NULL) { // si existe la tabla
		TipoClas clas = returnClasificador(clasificadorCol);
		if(!esVaciaListaFila(primerFiladeFilas(agregaCol)) && clas != ANY){// si ya hay filas en la tabla TIENE que ser ANY
			cout << "La tabla " << nombreTabla << " tiene al menos una tupla y se debe agregar con calificador ANY\n";
			return ERROR;
		}
		else{ // si no hay tuplas puede haber otro calificador
			if (clas == PRIMARY_KEY && existePKenTabla(agregaCol)){ // si lo que me dan es PK y ya existe uno
				cout << "No es posible ingresar otra primary key \n";
				return ERROR; // ya hay una pk
			}
			else {
				TipoDato tipo = returnTipoDato(tipoCol);
				int x = posicionColumna(primeraColumna(agregaCol), NombreCol); // si devuelve 0 es porque la columna no existe
				if( x == 0) { // puedo agregarla, ya se que no existe
					int i = insertarListaColumna(agregaCol, NombreCol, clas, tipo); // la inserta y nos devuelve la posicion de la columna
					ListaFilas lf = primerFiladeFilas(agregaCol);
					while (!esVaciaListaFila(lf)){
						insertarDato(primeraFila(lf), "EMPTY", i); // inserta EMPTY en la posicion de la columna nueva en cada fila
						lf = siguienteListaFila(lf);
					}
				return OK; // agrego columna
				}
			}
		}
	}
	else {
		cout << "No existe la tabla " << nombreTabla << "\n":
		return ERROR; // si la tabla no existe
	}
}

TipoRet dropCol(bd &bd, char *nombreTabla, char *NombreCol){
// Elimina de la tabla de nombre nombreTabla, si ésta existe, la columna de nombre
// nombreCol, si ésta existe. Si la tabla tiene tuplas, entonces se eliminará de éstas
// el campo correspondiente a la columna eliminada. Si la tabla posee una única columna
// de nombre nombreColentonces quedará como tabla vacía. Si la columna a eliminar es la
// PRIMARY KEY, la operación resultará inválida, salvo que ésta sea la única columna de
// la tabla, en cuyo caso quedará como tabla vacía, como se describió previamente.
	Tabla eliminaCol = tablaSleccionada(bd->ts, nombreTabla); // selecciono la tabla  solicitada
	if( eliminaCol != NULL ){ // si existe la tabla
		if (cantidadColumnasenTabla(eliminaCol) > 1 && tipoClasificacionColumna(eliminaCol, NombreCol) == PRIMARY_KEY)
			return ERROR; //si hay mas de 1 columna y piden elim una pk, no puede hacerse
		else{
			int x = posicionColumna(primeraColumna(eliminaCol), NombreCol);
			TipoRet i = eliminarListaColumna(eliminaCol, NombreCol); // s existe se elimina
			if (i == ERROR) // si la columna no existe en la tabla
				return ERROR;
			else { // la columna existe y se elimino, faltan las tuplas
				if(!esVaciaListaFila(primerFiladeFilas(eliminaCol))) { // si la tabla tiene tuplas
					eliminarDatodeTabla(eliminaCol, x);
					return OK;
				}
			}
		}		
	}
	else {
		cout << "No existe la tabla " << nombreTabla << "\n":
		return ERROR; // no existe la tabla
	}
}

TipoRet alterCol(bd &bd, char *nombreTabla, char *nombreCol, char *tipoCol, char *calificadorCol, char *nombreColNuevo){
// Modifica de la tabla de nombre nombreTabla, si ésta existe, la columna de nombre nombreCol,
// si ésta existe, quedando ésta columna con el nuevo tipo de datos tipoColNuevo, calificador
// calificadorColNuevo y nombre nombreColNuevo, si éste último no es el nombre de otra columna
// de la tabla. Si la tabla tiene tuplas, los valores de la columna modificada deberán satisfacer
// las nuevas características (tipo de dato y calificador). El tipo de datos sólo puede cambiar de
// integer a string y en este caso se deberá realizar la conversión de tipo de la columna especificada
// en todas las tuplas de la tabla.
	Tabla modificar = tablaSleccionada(bd->ts, nombreTabla); // selecciono la tabla  solicitada
	if( modificar != NULL ){ // si existe la tabla
		int pos = posicionColumna(primeraColumna(modificar), nombrecol);
		TipoDato datoNuevaCol = tipoDatoCol(tipoCol);
		TipoClas califNuevaCol = tipoClasCol(calificadorCol);
		TipoRet mod = modificarColumnaTabla(modificar, nombreCol, nombreColNuevo, datoNuevaCol, califNuevaCol);
		if (mod == OK){// si se modifico la col ok, ahora hay que chequear las tipo dato tuplas
			TipoDato td = tipoDatoTuplaenCol(modificar, pos);  // me dice el tipo de dato de las tuplas en esa posicion
			if (td == datoNuevaCol)
				return OK;
			else {
				conversionDato(modificar, pos); // modifica el dato en cada fila de la tabla en la posicion pos
			}
		}
		else return ERROR;
	}
	return OK;
}

TipoRet insertInto(bd &bd, char *nombreTabla, char *columnasTupla, char *valoresTupla)
{
	// cout << " - insertInto " << nombreTabla << " " << columnasTupla << " " << valoresTupla<< endl;;
	//  Inserta en la tabla de nombre nombreTabla, si ésta existe, una tupla con los valores
	// dados en valoresTupla para las columnas indicadas en columnasTupla, si los nombres de las
	// columnas existen, los valores son del tipo adecuado y satisfacen los calificadores correspondientes
	// a cada columna. Si no se indican todas las columnas se inserta EMPTY en las otras. Por lo tanto,
	// la operación se permite sólo si las columnas que no se indican tienen el calificador ANY. Los nombres
	// de las columnas en columnasTupla y los valores de valoresTupla se separan con el uso del caracter
	// dos puntos (:) y deben corresponderse uno a uno. Esto es, el nombre de columna i en columnasTupla con
	// el valor en la posición i de valoresTupla. Si la tupla a insertar pertenece a la tabla,
	// la operación no tendrá efecto.
	
	// ACA HAY QUE HACER LO DE DIVIDIR POR LOS DOS PUNTOS Y CREAR UNA FILA DE TUPLAS
	// Y VER A QUE COL CORRESPONDE
	
	return NO_IMPLEMENTADA;
}

TipoRet deleteFrom(bd &bd, char *nombreTabla, char *condicionEliminar)
{
// Elimina de la tabla de nombre nombreTabla, si éste existe, todas las tuplas que cumplen
// la condición condiciónEliminar. En caso de que la condición sea “”, se eliminan todas
// las tuplas de la tabla. Si ninguna tupla cumple la condición, la operación no tendrá
// efecto. El formato de las condiciones es: columna operador valor (sin espacios en blanco
// intermedios). Los operadores a utilizar son: = “igual”, ! “Distinto”, > “Mayor” , < “Menor”.
	Tabla eliminarT = tablaSleccionada(bd->ts, nombreTabla);
	if( eliminarT != NULL ){
		eliminarTupla(eliminarT, condicionEliminar); // dentro de tabla
		return OK;
	}
	return ERROR;
}

TipoRet update(bd &bd, char *nombreTabla, char *condicionModificar, char *columnaModificar, char *valorModificar)
{
	// cout << " - update " << nombreTabla << " " << condicionModificar << " " << columnaModificar << " " << valorModificar << endl;
	return NO_IMPLEMENTADA;
}

TipoRet selectWhere(bd &bd, char *nomTabla1, char *condicion, char *nomTabla2)
{
	// cout << " - selectWhere " << nomTabla1 << " " << condicion << " " << nomTabla2 << endl;
	return NO_IMPLEMENTADA;
}

TipoRet select(bd &bd, char *nomTabla1, char *nomColumnas, char *nomTabla2)
{
	// cout << " - select " << nomTabla1 << " " << nomColumnas << " " << nomTabla2 << endl;
	return NO_IMPLEMENTADA;
}

TipoRet join(bd &bd, char *nomTabla1, char *nomTabla2, char *nomTabla3)
{
	// cout << " - join " << nomTabla1 << " " << nomTabla2 << " " << nomTabla3 << endl;
	return NO_IMPLEMENTADA;
}

TipoRet union_(bd &bd, char *nombreTabla1, char *nombreTabla2, char *nombreTabla3)
{
	// cout << " - union_ " << nombreTabla1 << " " << nombreTabla2 << " " << nombreTabla3 << endl;
	return NO_IMPLEMENTADA;
}

TipoRet intersec(bd &bd, char *nombreTabla1, char *nombreTabla2, char *nombreTabla3)
{
	// cout << " - intersec " << nombreTabla1 << " " << nombreTabla2 << " " << nombreTabla3 << endl;
	return NO_IMPLEMENTADA;
}

TipoRet minus_(bd &bd, char *nombreTabla1, char *nombreTabla2, char *nombreTabla3)
{
	// cout << " - minus_ " << nombreTabla1 << " " << nombreTabla2 << " " << nombreTabla3 << endl;
	return NO_IMPLEMENTADA;
}

TipoRet printdatatable(bd bd, char *NombreTabla)
{
	// cout << " - printdatatable " << NombreTabla << endl;
	return NO_IMPLEMENTADA;
}

TipoRet printTables(bd bd)
{
	// cout << " - printTables " << endl;
	return NO_IMPLEMENTADA;
}

TipoRet printMetadata(bd bd, char *nombreTabla)
{
	// cout << " - printMetadata " << nombreTabla << endl;
	return NO_IMPLEMENTADA;
}

TipoRet undo(bd &bd)
{
	// cout << " - undo" << endl;
	return NO_IMPLEMENTADA;
}

TipoRet redo(bd &bd)
{
	// cout << " - redo" << endl;
	return NO_IMPLEMENTADA;
}

bd destroyBD(bd &bd)
{
	//
	return NULL;
}
