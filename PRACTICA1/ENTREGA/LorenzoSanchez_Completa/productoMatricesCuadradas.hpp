/**
 * Declaracion de las funciones de producto de matrices cuadradas
 * Realizado por Jaime Lorenzo Sanchez
 * */

#ifndef  PRODUCTOMATRICESCUADRADAS_HPP
#define  PRODUCTOMATRICESCUADRADAS_HPP

#include "MainProgram.hpp"

/**
 * Funcion que calcula el tiempo de un algoritmo de realizar el producto de 2 matrices cuadradas
 * @param orden_min Orden minimo de las matrices
 * @param orden_max Orden maximo de las matrices
 * @param tiemposReales Vector que almacena los tiempos reales de calculo del producto de las matrices
 * @param numeroElementos Vector que almacena los distintos elementos de las matrices
*/

void tiemposProductoMatricesCuadradas(int orden_min, int orden_max, vector <double> &tiemposReales, 
vector <double> &numeroElementos);

/**
 * Funcion que rellena una matriz con valores aleatorios utilizando un rango de valores
 * @param minimo Valor minimo del rango de valores aleatorios
 * @param maximo Valor maximo del rango de valores aleatorios
 * @return Valor aleatorio obtenido
*/

float obtenerValorAleatorio(int minimo,int maximo);

/**
 * Funcion que calcula el producto de 2 matrices cuadradas
 * @param matriz1 Matriz a multiplicar
 * @param matriz2 Matriz a multiplicar
 * @param matriz3 Matriz resultado
 * @param n Orden de las matrices
*/

void productoMatrices(std::vector < std::vector <double> > &matriz1, 
std::vector < std::vector <double> > &matriz2, std::vector < std::vector <double> > &matriz3, int n);


#endif