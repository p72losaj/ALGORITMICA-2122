/*
    Declaracion de las funciones del fichero practica1.hpp
    Realizado por Jaime Lorenzo Sanchez
*/

#ifndef  PRACTICA1_HPP
#define PRACTICA1_HPP


#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

// Prototipo de las funciones de tiempo de los algoritmos

void ordenacionSeleccion(); // Funcion que implementa el algoritmo de ordenacion por seleccion

void productoMatricesCuadradas(); // Funcion que implementa el producto de 2 matrices cuadradas de orden n

void fibonacciRecursivo(); // Funcion que implementa el algoritmo de Fibonacci de modo recursivo

// Protipo de las funciones de ordenacion por seleccion

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

// Funciones polinomicas

/**
    Funcion que ajusta un  polinomio de tipo: t(n) =a0 + a1*n + a2*n²
    @param numeroElementos Vector que almacena los numeros de elementos de un vector
    @param tiemposReales Vector que almacena los tiempos de ordenacion por seleccion de un vector
    @param a Vector que almacena los coeficientes del polinomio (a0, a1, a2)
*/

void ajustePolinomico(const vector <double> &numeroElementos, const vector <double> &tiemposReales, vector <double> &a);

/**
    Funcion que calcula los tiempos estimados de ajuste de un polinomio
    @param numeroElementos Vector que almacena los numeros de elementos de un vector
    @param a Vector que almacena los coeficientes del polinomio (a0, a1, a2)
    @param tiemposEstimados Vector que almacena los tiempos estimados de ajuste del polinomio
*/
void calcularTiemposEstimadosPolinomico(const vector <double> &numeroElementos, const vector <double> &a, 
vector <double> &tiemposEstimados);

// Funciones matrices

/**
    Funcion que obtiene los tiempos de producto de 2 matrices cuadradas
    @param orden_min Orden minimo de las matrices
    @param orden_max Orden maximo de las matrices
    @param tiemposReales Vector que almacena los tiempos de ejecución del algoritmo
    @param numeroElementos Vector que almacena los numeros de elementos del vector
*/

void tiemposProductoMatricesCuadradas(int orden_min, int orden_max, vector <double> &tiemposReales, 
vector <double> &numeroElementos);

/**
    Funcion que obtiene la matriz solucion al producto de 2 matrices
    @param matriz1 Matriz a multiplicar
    @param matriz2 Matriz a multiplicar
    @param n Orden de ambas matrices
    @return Matriz resultado del producto
*/

std::vector < std::vector <double> > producto(std::vector < std::vector <double> > matriz1, 
std::vector < std::vector <double> > matriz2, int n);

// Funciones auxiliares

/**
    Funcion que escribe en un fichero de texto los tiempos de ordenacion por seleccion de un  vector
    @param nombreFichero Nombre del fichero de texto
    @param numeroElementos Vector que almacena los numeros de elementos de un vector
    @param tiemposReales Vector que almacena los tiempos de ordenacion por seleccion de un vector
*/

void escribeFicheroOrdenacionSeleccion(string nombreFichero, std::vector<double> &numeroElementos,
std::vector<double> &tiemposReales);

/**
    Funcion que obtiene un valor en el rango [min, max]
    @param inicio Valor de tipo flotante que indica el minimo valor del rango aleatorio
    @param fin Valor de tipo flotante que indica el maximo valor del rango aleatorio
*/

float ValorAleatorio(int inicio,int fin);

#endif