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
 * @param i Valor
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

#endif
