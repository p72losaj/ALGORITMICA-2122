/**
Declaracion de las funciones de ordenacion QuickSort
Realizado por Jaime Lorenzo Sanchez
*/


#ifndef  ORDENACIONQUICKSORT_HPP
#define  ORDENACIONQUICKSORT_HPP

// Incluimos la biblioteca de la funcion principal

#include "MainProgram.hpp"

/**
    * Funcion que obtiene los tiempos de ordenacion de un vector mediante el algoritmo QuickSort
    * @param nMin Numero minimo de elementos del vector
    * @param nMax Numero maximo de elementos del vector
    * @param repeticiones Numero de repeticiones de ejecucion del algoritmo
    * @param tiemposReales Vector que almacena los tiempos reales de ejecucion del algoritmo
    * @param numeroElementos Vector que almacena distintos tamanos del vector
*/
void tiemposOrdenacionQuickSort(int nMin, int nMax, int repeticiones, vector <double> &tiemposReales, 
vector <double> &numeroElementos);

/**
    Funcion que realiza la ordenacion del vector
    @param iz Primer elemento del vector
    @param de Ultimo elemento del vector
    @param n Numero de elementos del vector
    @param v Vector a ordenar
*/

void Quicksort(int iz, int de, int n, vector <int> &v);

#endif