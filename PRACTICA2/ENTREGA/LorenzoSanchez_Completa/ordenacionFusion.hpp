/**
 * Fichero con las declaraciones de las funciones propias del algoritmo de ordenacion fusion
 * Realizado por Jaime Lorenzo Sanchez
 * */

#ifndef  ORDENACIONFUSION_HPP
#define  ORDENACIONFUSION_HPP

// Incluimos la biblioteca de la funcion principal

#include "MainProgram.hpp"

/**
    * Funcion que obtiene los tiempos de ordenacion de un vector mediante el algoritmo Fusion
    * @param nMin Numero minimo de elementos del vector
    * @param nMax Numero maximo de elementos del vector
    * @param repeticiones Numero de repeticiones de ejecucion del algoritmo
    * @param tiemposReales Vector que almacena los tiempos reales de ejecucion del algoritmo
    * @param numeroElementos Vector que almacena distintos tamanos del vector
*/
void tiemposOrdenacionFusion(int nMin, int nMax, int repeticiones, vector <double> &tiemposReales, 
vector <double> &numeroElementos);

/**
 * Funcion que aplica el algoritmo de ordenar aplicando el metodo de fusion
 * @param v Vector a ordenar
 * */

void ordenarFusion(std::vector<int> &t);

/**
 * Funcion que ordena un vector por fusion, siendo el tamano del vector pequeno
 * @param v Vector a ordenar
 * */

void ordenar(std::vector<int> &t);

/**
 * Funcion que fusiona 3 vectores
 * @param u Vector a fusionar
 * @param v Vector a fusionar
 * @param t Vector a fusionar
 * */

void fusionar(std::vector<int> &u,std::vector<int> &v,std::vector<int> &t);

#endif