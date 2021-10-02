/*
    Declaracion de las funciones de ordenacionSeleccion
    Realizado por Jaime Lorenzo Sanchez
*/

#ifndef  ORDENACIONSELECCION_HPP
#define  ORDENACIONSELECCION_HPP

#include "MainProgram.hpp"

/**
    Funcion que rellena un vector con numeros aleatorios en el rango [0, 9999999]
    @param v Vector a rellenar
*/

void rellenarVector(vector<int> &v);

/**
    Funcion que ordena un vector mediante seleccion
    @param v Vector a ordenar
*/

void seleccion(vector <int> &v);

/**
    Funcion que comprueba si el vector esta ordenado
    @param v Vector a comprobar si esta ordenado
    @return true si el vector esta ordenado, false en caso contrario
*/

bool estaOrdenado(const vector <int> &v);

/**
    Funcion que obtiene los tiempos de ordenacion por seleccion de un vector
    @param nmin Numero minimo de elementos del vector
    @param nmax Numero maximo de elementos del vector
    @param repeticiones Numero de repeticiones del algoritmo de ordenacion por seleccion del vector
    @param tiemposReales Vector que almacena los tiempos de ejecución del algoritmo
    @param numeroElementos Vector que almacena los numeros de elementos del vector
*/

void tiemposOrdenacionSeleccion(int nMin, int nMax, int repeticiones, vector <double> &tiemposReales, 
vector <double> &numeroElementos);



#endif