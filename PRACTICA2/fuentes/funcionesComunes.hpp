/**
 * Declaracion de las funciones comunes de los algoritmos
 * Realizado por Jaime Lorenzo Sanchez
 * */

#ifndef FUNCIONESCOMUNES_HPP
#define FUNCIONESCOMUNES_HPP

#include "MainProgram.hpp"

// Incluimos las funciones del fichero ClaseTiempo

#include "ClaseTiempo.cpp"

// Incluimos las funciones del sistema de ecuaciones

#include "sistemaEcuaciones.hpp"


/**
 * Funcion que calcula el valor del sumatorio de una funcion polinomica
*/

double sumatorio(const vector<double> n, const vector <double> t, int expN, int expT);

// Funcion que calcula el coeficiente de determinacion de un polinomio

double calcularCoeficienteDeterminacion(const vector <double> &tiemposReales, 
const vector <double> &tiemposEstimados);


/**
 * Funcion que calcula el tiempo estimado de un polinomio
 * */

double calcularTiempoEstimadoPolinomico(const vector<double> &n, vector <double> &a);

// Funcion que calcula la media de un vector

double media(std::vector<double> vector);

// Funcion que calcula la varianza de un vector

double varianza(std::vector<double> vector, double media);

/**
 * Funcion que calcula los tiempos estimados de un polinomio
 * 
*/

void calcularTiemposEstimadosPolinomico(const vector <double> &numeroElementos,
const vector <double> &a, vector <double> &tiemposEstimados);

/** 
 * Funcion de ajuste de un polinomio
 * @param numeroElementos Vector de numero de elementos
 * @param tiemposReales Vector de tiempos reales
 * @param a Vector de coeficientes
 * */

void ajustePolinomico(const vector <double> &numeroElementos, const vector
<double> &tiemposReales, vector <double> &a);


/**
 *  Funcion que escribe en un fichero los tiempos iniciales de un algoritmo
 *  @param nombre Nombre del fichero
 *  @param numeroElementos Vector que almacena el numero de elementos
 *  @param tiemposReales Vector que almacena los tiempos reales
*/

void escribeFicheroTiemposReales(string nombre,std::vector<double> &numeroElementos,
std::vector<double> &tiemposReales);


/**
 *  Funcion que escribe en un fichero los tiempos estimados de un algoritmo
 *  @param nombreFichero Nombre del fichero
 *  @param numeroElementos Vector que almacena los numeros de elementos
 *  @param tiemposReales Vector que almacena los tiempos reales del algoritmo
 *  @param tiemposEstimados Vector que almacena los tiempos estimados de un algoritmo
*/

void escribeFicheroTiemposEstimados(string nombreFichero, 
std::vector<double> &numeroElementos, std::vector<double> &tiemposReales, 
std::vector<double> &tiemposEstimados);

/**
    * Funcion que rellena un vector con valores aleatorios
    * @param v Vector a rellenar
*/
void rellenarVector(vector<int> &v);

/**
    * Funcion que comprueba si un vector esta ordenado de menor a mayor
    * @param v Vector de elementos
    * @return true Si el vector esta ordenado; false en caso contrario
*/

bool estaOrdenado(const vector <int> &v);

#endif