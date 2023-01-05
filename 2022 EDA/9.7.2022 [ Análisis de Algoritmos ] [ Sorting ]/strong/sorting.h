#ifndef SORTING_H
#define SORTING_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

void bubble_sort (int arr[], int tope, int & comparaciones);
// Ordena arr utilizando el algoritmo Bubble Sort.

void cocktail_sort (int arr[], int tope, int & comparaciones);
// Ordena arr utilizando el algoritmo Cocktail Sort.

void selection_sort (int arr[], int tope, int & comparaciones);
// Ordena arr utilizando el algoritmo Selection Sort.

void insertion_sort (int arr[], int tope, int & comparaciones);
// Ordena arr utilizando el algoritmo Insertion Sort.

void merge_sort (int arr[], int tope, int & comparaciones);
// Ordena arr utilizando el algoritmo Merge Sort.

void quick_sort (int arr[], int tope, int & comparaciones);
// Ordena arr utilizando el algoritmo Quick Sort.

void shell_sort (int arr[], int tope, int & comparaciones);
// Ordena arr utilizando el algoritmo Shell Sort.

#endif