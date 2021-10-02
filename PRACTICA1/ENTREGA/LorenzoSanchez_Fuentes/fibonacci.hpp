/**
 * Declaracion de las funciones de Fibonacci
 * Realizado por Jaime Lorenzo Sanchez
 * */

#ifndef FIBONACCI_HPP
#define FIBONACCI_HPP

// Biblioteca principal
#include "MainProgram.hpp"

/**
 * Funcion que calcula los tiempos de calculo del termino n de la sucesion de Fibbonnaci
 * @param minimo Termino minimo de la sucesion de Fibbonnaci
 * @param maximo Termino maximo de la sucesion de Fibbonnaci
 * @param tiemposReales Vector que almacena los tiempos reales de la sucesion de Fibbonnaci
 * @param numeroElementos Vector que almacena los distintos terminos n de la sucesion de Fibbonnaci
 * */

void tiemposFibbonnaci (int minimo, int maximo, std::vector<double> &tiemposReales, std::vector<double> &numeroElementos);

/**
 * Funcion que calcula el termino n de la sucesion de Fibbonnaci de modo recursivo
 * @param i Valor a calcular su termino n de la sucesion de Fibbonnaci
 * @return Termino n de la sucesion de Fibbonnaci
*/

int fibbonnaciRecursivo(int valor);

/**
 * Funcion que obteniene la curva de ajuste del polinomio curva t(n) = a0 + a1*2^n
 * @param n Vector del numero de elementos
 * @param tiemposReales Vector de tiempos reales del algoritmo
 * @param a Vector de coeficientes
*/

void ajusteExponencial(const vector <double> &n, const vector <double> &tiemposReales, vector <double> &a);

/**
 * Funcion que calcula los tiempos estimados de una funcion exponencial
 * @param n Vector que almacena el numero de elementos del algoritmo
 * @param a Vector que almacena los coeficientes de la curva t(n) = a0 + a1*2^n
 * @param tiemposEstimados Vector que almacena los tiempos estimados
*/

void calcularTiemposEstimadosExponencial(const vector <double> &n, 
const vector <double> &a, vector <double> &tiemposEstimados);

/**
 * Funcion que calcula el tiempo estimado de una funcion exponencial
 * @param numeroElementos Vector que almacena el numero de elemenots de la funcion exponencial
 * @param a Vector de coeficientes de la funcion exponencial
*/

double calcularTiempoEstimadoExponencial(const vector <double> &numeroElementos, const vector <double> &a);

#endif
