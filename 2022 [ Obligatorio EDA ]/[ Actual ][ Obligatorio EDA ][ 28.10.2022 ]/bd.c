// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// bd.c
// Modulo de Implementación de Base de Datos. HOLA PRUEBA ASIII
//a ver

#include "bd.h"
#include "tablas.h"
#include "tabla.h"
#include "condicion.h"
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
		insertarTabla(bd->ts, nombreTabla, crearTabla()); // inserta en las tablas base de datos una tabla vacia con nombreTabla
		return OK;
	}
	else {
		cout << "Imposible Crear Tabla, ya hay una tabla con el mismo nombre" << "\n";
		return ERROR;
	}
}

TipoRet dropTable(bd &bd, char *nombreTabla){
// Elimina de la base de datos la tabla de nombre nombreTabla, y las tuplas
// que la misma posee, si nombreTabla existe.
	Tabla aborrar = tablaSleccionada(bd->ts, nombreTabla);
	if(aborrar != NULL) {
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

TipoDato returnTipoDato_(char * tipoCol){
// devuelve la clasificacion del tipo de dato pasado
	int i = atoi(tipoCol);
	if (i == 0 && strcmp(tipoCol, "0") != 0 )
		return TSTRING;
	else return TINTEGER;
}

TipoDato returnTDCol( char * tipo){
	if (strcasecmp("INTEGER", tipo) == 0)
		return TINTEGER;
	else return TSTRING;
}

TipoRet addCol(bd &bd, char *nombreTabla, char * NombreCol, char *tipoCol, char *calificadorCol){
// Agrega a la tabla de nombre nombreTabla, si ésta existe, una nueva columna al final de nombre nombreCol,
// si ésta no existe. Si la tabla tiene tuplas el nuevo campo tendrá el valor EMPTY en cada tupla. Por lo
// tanto, en el caso de que la tabla tenga tuplas, no es válido que se agregue un calificador distinto de ANY.
// Tampoco es válido que calificadorCol sea PRIMARY KEY si existe ya una columna con dicho calificador en la
// tabla nombreTabla.
	Tabla agregaCol = tablaSleccionada(bd->ts, nombreTabla); // va a devolver NULL si no existe
	if(agregaCol != NULL) { // si existe la tabla
		cout << "Existe la tabla \n";
		TipoClas clas = returnClasificador(calificadorCol);
		cout << "el clasificador es:" << clas << "\n";
		if(!noHayTuplas(agregaCol) && clas != ANY){// si ya hay filas en la tabla TIENE que ser ANY
			cout << "La tabla " << nombreTabla << " tiene al menos una tupla y se debe agregar con calificador ANY\n";
			return ERROR;
		}
		else{ // si no hay tuplas puede haber otro calificador
			if (clas == PRIMARY_KEY && existePKenTabla(agregaCol)){ // si lo que me dan es PK y ya existe uno
				cout << "No es posible ingresar otra primary key \n";
				return ERROR; // ya hay una pk
			}
			else {
				TipoDato tipo = returnTDCol(tipoCol); // retorna TINTEGER o TSTRING
				cout << "el tipo es:" << tipo << "\n";
				int x = posicionColumnaEnTabla(agregaCol, NombreCol); // si devuelve 0 es porque la columna no existe
				cout << "la posicion es:" << x << "\n";
				if( x == 0) { // puedo agregarla, ya se que no existe
					cout << "x es igual a cero \n";
					agregaNuevaCol(agregaCol, NombreCol , tipo ,clas);
					cout << "agrego col\n";
					return OK; // agrego columna
				} else return ERROR;
			}
		}
	}
	else {
		cout << "No existe la tabla " << nombreTabla << "\n";
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
		cout << "La tabla existe \n";
		if (cantidadColumnasenTabla(eliminaCol) > 1 && tipoClasificacionColumna(eliminaCol, NombreCol) == PRIMARY_KEY){
			cout << "no cumple las normas para eliminar\n";
			return ERROR; //si hay mas de 1 columna y piden elim una pk, no puede hacers
		}else{
			cout << "Se puede eliminar\n";
			ListaColumnas c = primeraColumna(eliminaCol);
			int x = posicionColumna(c, NombreCol);
			cout << "posicion col a eliminar: " << x << "\n";
			TipoRet i = eliminarListaColumna(eliminaCol, NombreCol); // s existe se elimina
			cout << "se elimino \n";
			if (i == ERROR) // si la columna no existe en la tabla
				return ERROR;
			else { // la columna existe y se elimino, faltan las tuplas
				cout << "vamos a las tuplas\n";
				if(!esVaciaListaFila(primerFiladeFilas(eliminaCol))) { // si la tabla tiene tuplas
					cout << "entro al if\n";
					eliminarDatodeTabla(eliminaCol, x);
					cout << "elimine las tuplas\n";
					return OK;
				}else return ERROR;
			}
		}		
	}
	else {
		cout << "No existe la tabla " << nombreTabla << "\n";
		return ERROR; // no existe la tabla
	}
}

TipoDato NuevoTipoDato(char * nombreTipoDato){  
    if ((strcasecmp(nombreTipoDato, "INTEGER") == 0)){
        return TINTEGER;
    }else   
        return TSTRING;
}

TipoClas NuevoTipoClas(char * nombreTipoDato){
    if ((strcasecmp(nombreTipoDato, "NOT_EMPTY") == 0)){
        return NOT_EMPTY;
    }else if ((strcasecmp(nombreTipoDato, "ANY") == 0))
        return ANY;
    else
        return PRIMARY_KEY;
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
		cout << "La tabla existe\n";
		ListaColumnas lc = primeraColumna(modificar);
		if (perteneceColumna(lc, nombreCol)){//evaluo si existe la columna
			cout << "La columna existe\n";
			int pos = posicionColumna(lc, nombreCol); // obtengo la posicion de la columna
			cout << "posicion col: " << pos << "\n";
			TipoDato NuevoDatoCol = NuevoTipoDato(tipoCol);//obtengo el tipo de dato que me dan
			TipoClas NuevoCalifCol = NuevoTipoClas(calificadorCol);//obtengo el tipo de clasificador que me dan
			TipoRet mod = modificarColumnaTabla(modificar, nombreCol, nombreColNuevo, NuevoCalifCol, NuevoDatoCol);
			if (mod == OK){// si se modifico la col ok, ahora hay que chequear las tipo dato tuplas
				TipoDato td = tipoDatoTuplaenCol(modificar, pos);  // me dice el tipo de dato de las tuplas en esa posicion
				if (td == NuevoDatoCol)
					return OK;
				else {
					conversionDato(modificar, pos); // modifica el dato en cada fila de la tabla en la posicion pos
					return OK;
				}
			}
			else {
				cout << "No se modifico la col \n";
				return ERROR;
			}
		}else{
			cout << "No existe la columna " << nombreCol << "\n";
			return ERROR; // no existe la columna
		}
	}else{
		cout << "No existe la tabla " << nombreTabla << "\n";
		return ERROR; // no existe la tabla
	}
}

TipoRet insertInto(bd &bd, char *nombreTabla, char *columnasTupla, char *valoresTupla){
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
	Tabla aInsertar = tablaSleccionada(bd->ts, nombreTabla);
	cout << "Selecciona la tabla \n";
	if(aInsertar != NULL){ // si existe la tabla
		cout << "Existe la tabla \n";
		ListaColumnas lc = primeraColumna(aInsertar);
		cout << "me da lc \n";
		char * copia = new char[strlen(columnasTupla)];
    	strcpy(copia, columnasTupla);
		if (pasanPrimaryKey(aInsertar, copia)){ //compruebo que me pasen la primary key en caso que exista en la tabla
			cout << "luego de pasan PK  \n";
			int cantCol = cantidadColumnas(lc);	//obtengo la cantidad de columnas de la tabla
			cout << "cantidad columnas: " << cantCol << "\n";
			agregarTuplaVacia(aInsertar, cantCol); //agrega en la tabla una tupla de cantidad cantCol con valores EMPTY
			cout << "agrego la tupla \n";
			TipoRet modifique = modificarTuplaFinal(aInsertar, columnasTupla, valoresTupla);
			if ( modifique == ERROR) 
				return ERROR;
			else				
				return OK;					
		}else return ERROR;	
	}else{
		cout << "No existe la tabla " << nombreTabla << "\n";
		return ERROR; // no existe la tabla
	}
}

TipoRet deleteFrom(bd &bd, char *nombreTabla, char *condicionEliminar){
// Elimina de la tabla de nombre nombreTabla, si éste existe, todas las tuplas que cumplen
// la condición condiciónEliminar. En caso de que la condición sea “”, se eliminan todas
// las tuplas de la tabla. Si ninguna tupla cumple la condición, la operación no tendrá
// efecto. El formato de las condiciones es: columna operador valor (sin espacios en blanco
// intermedios). Los operadores a utilizar son: = “igual”, ! “Distinto”, > “Mayor” , < “Menor”.
	Tabla eliminarT = tablaSleccionada(bd->ts, nombreTabla);
	if( eliminarT != NULL ){ // si existe la tabla
		if (strcmp(condicionEliminar, "") == 0) {
			vaciarTabla(eliminarT); // elimina todas las tuplas
			return OK;
		}
		else {
			condicion c = crearCondicion(condicionEliminar, primeraColumna(eliminarT));
			if (c == NULL)
				return ERROR;
			eliminarFilaCond(eliminarT, c);
			return OK;
		}
	}else{
		cout << "No existe la tabla " << nombreTabla << "\n";
		return ERROR;
	}
}

TipoRet update(bd &bd, char *nombreTabla, char *condicionModificar, char *columnaModificar, char *valorModificar){
// Modifica en la tabla de nombre nombreTabla, si éste existe, el valor de las tuplas en la
// columna de nombre columnaModificar, si éste existe, que cumplen la condición condiciónModificar.
// En la columna especificada de las tuplas que cumplen la condición se asigna el valor valorModificar,
// siempre que este valor sea del tipo adecuado y satisfaga el calificador de la columna especificada.
// La condición respeta el formato descrito para condiciones.
	Tabla updteTupla = tablaSleccionada(bd->ts, nombreTabla);
	if( updteTupla != NULL ){ // si existe la tabla
		ListaColumnas lc = primeraColumna(updteTupla);
		if (perteneceColumna(lc, columnaModificar)){ // si existe la columna en la tabla
			condicion c = crearCondicion(condicionModificar, lc);
			if(c == NULL)
				return ERROR;
			if(strcasecmp(devuelveNomCol(c), columnaModificar)){ // si la columna es la misma que en la condicion
				bool mod = modificarTuplaCond(updteTupla, c, valorModificar);
				if (mod)
					return OK;
				else return ERROR;
			}else return ERROR;
		}
		else{
			cout << "No existe la columna " << columnaModificar << "\n";
			return ERROR; // no existe la columna
		}
	}else{
		cout << "No existe la tabla " << nombreTabla << "\n";
		return ERROR;
	}
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

TipoRet printdatatable(bd bd, char *NombreTabla){
// Imprime las tuplas de la tabla de nombre nombreTabla, si ésta existe. Los nombres y los valores
// de las columnas se expresan en el formato columna1:columna2: … :columnan. Las tuplas se muestran
// ordenadas ascendentemente por la PRIMARY KEY. Primero se imprime el nombre de la tabla, luego los
// nombres de las columnas, separados con (:), y por último las tuplas, cuyos campos se separan
// también con (:).
	Tabla imprimirTuplasTabla = tablaSleccionada(bd->ts, NombreTabla);
	if( imprimirTuplasTabla != NULL ){ // si existe la tabla
		cout << NombreTabla << endl; // primero imprime el nombre de la tabla
		imprimirNombresColumnas(imprimirTuplasTabla); // imprime los nombres de las columnas separados por :
		imprimirTuplasOrd(imprimirTuplasTabla);// imprime las tuplas ordenadas separadas por :
		cout << "\n";
		return OK;
	}
	else{
		cout << "No existe la tabla " << NombreTabla << "\n";
		return ERROR;
	}
}

TipoRet printTables(bd bd){
// Imprime los nombres de las tablas de la base de datos del sistema, ordenados alfabéticamente de menor a mayor.
	if(!esVaciaTablas(bd->ts)){
		imprimirNombreTablas(bd->ts);
		return OK;
	}
	else{
		cout << "La base de datos no tiene elementos \n";
		return ERROR;
	}
}

TipoRet printMetadata(bd bd, char *nombreTabla){
// Imprime el esquema de la tabla de nombre nombreTabla, si éste existe. Es decir, imprime el nombre
// de la Tabla, los nombres de sus columnas en el orden correspondiente, indicando para cada columna su
// tipo de datos y calificador si lo tuviera.
	Tabla impTabla = tablaSleccionada(bd->ts, nombreTabla);
	if( impTabla != NULL ){ // si existe la tabla
		cout << nombreTabla << endl; // primero imprime el nombre de la tabla
		imprimirInfoColumnas(impTabla);
		cout << "\n";
		return OK;
	}
	else{
		cout << "No existe la tabla " << nombreTabla << "\n";
		return ERROR;
	}
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

bd destroyBD(bd &bd){
// Destruye bd y libera la memoria asociada.
	destruirTablas(bd->ts);
	return NULL;
}
