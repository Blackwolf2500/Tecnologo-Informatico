#include "sorting.h"

void bubble_sort (int arr[], int tope, int & comparaciones){
// Ordena arr utilizando el algoritmo Bubble Sort.
	int aux;
	for (int i = 0; i < tope ; i++){
		for (int j = 0; j < tope - i; j++){
			if ((j + 1) < tope){
				comparaciones++;
				if (arr[j] > arr[j + 1]){
					aux = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = aux;
				}
			}
		}
	}
}

void cocktail_sort (int arr[], int tope, int & comparaciones){
// Ordena arr utilizando el algoritmo Cocktail Sort.
	int primero  = 0, ultimo  = tope-1, aux;
	while(primero < ultimo){
		for (int j = primero; j < ultimo; j++){
			comparaciones++;
			if (arr[j] > arr[j+1]){
				aux = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = aux;
			}
		}
		ultimo--;
		for (int k = ultimo; k > primero; k--){
			comparaciones++;
			if (arr[k] < arr[k-1]){
				aux = arr[k];
				arr[k] = arr[k-1];
				arr[k-1] = aux;
			}
		}
		primero++;
	}
}

void selection_sort (int arr[], int tope, int & comparaciones){
// Ordena arr utilizando el algoritmo Selection Sort.
	int min_lugar, min_valor;
	for(int i = 0; i < tope ; i++){
		min_lugar = i;
		min_valor = arr[i];
		for(int x = i; x < tope ; x++){
			comparaciones++;
			if(arr[x]<min_valor){
				min_lugar = x;
				min_valor = arr[x];
			}
		}
		arr[min_lugar] = arr[i];
		arr[i] = min_valor;
	}
}

void insertion_sort (int arr[], int tope, int & comparaciones){
// Ordena arr utilizando el algoritmo Insertion Sort.
	if(tope > 1){
		for(int i = 1;i < tope;i++){
			int j = i - 1;
			int key = arr[i];
			comparaciones++;
			while(j >= 0 && arr[j] > key){
				comparaciones++;
				arr[j+1] = arr [j];
				j--;
			}
			arr[j+1] = key;
		}
	}
}

void merge (int arr1[], int tope1, int arr2[], int tope2, int & comparaciones){
// Intercala ordenadamente (de menor a mayor) 2 arreglos.
	int y = 0;
	int swap, y1;
	for (int x = 0; x < tope1; x++){
		comparaciones++;
		if ((arr1[x] > arr2[y])){
			swap = arr1[x];
			arr1[x] = arr2[y];
			arr2[y] = swap;
			y1 = y;
			while ((y1 < tope2 - 1) && (arr2[y1] > arr2[y1 + 1])){
				swap = arr2[y1];
				arr2[y1] = arr2[y1 + 1];
				arr2[y1 + 1] = swap;
				y1++;
			}
		}
	}
}

void merge_sort (int arr[], int tope, int & comparaciones){
// Ordena arr utilizando el algoritmo Merge Sort.
	if (tope > 1){
		int part = tope / 2;
		if (tope - part > 1)
				merge_sort (arr, tope - part, comparaciones);
		if (part > 1)
			merge_sort (&arr[tope - part], part, comparaciones);
		merge (arr, tope - part, &arr[tope - part], part, comparaciones);
	}
}

void quick_sort (int arr[], int tope, int & comparaciones){
// Ordena arr utilizando el algoritmo Quick Sort.
	int primero = 0, ultimo = tope -1;
	int i, j, pivot, temp;
	comparaciones++;
	if(primero < ultimo){
		pivot = primero;
		i = primero;
		j = ultimo;
		comparaciones++;
		while(i < j){
			while((arr[i] <= arr[pivot]) && (i < ultimo))
				i++;
			while(arr[j] > arr[pivot])
				j--;
			if(i<j){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		temp = arr[pivot];
		arr[pivot] = arr[j];
		arr[j] = temp;
		quick_sort(arr, j, comparaciones);
		quick_sort(&arr[j+1], ultimo -j, comparaciones);
	}
}

void shell_sort (int arr[], int tope, int & comparaciones){
// Ordena arr utilizando el algoritmo Shell Sort.
	for(int medio = tope /2; medio > 0; medio /= 2){
		for(int i = medio; i < tope; i++){
			comparaciones ++;
			int temp = arr[i];
			int j;
			for(j = i; j >= medio && arr[j -medio] > temp; j -= medio){
				arr[j] = arr[j -medio];
				comparaciones ++;
			}
			arr[j] = temp;
		}
	}
}