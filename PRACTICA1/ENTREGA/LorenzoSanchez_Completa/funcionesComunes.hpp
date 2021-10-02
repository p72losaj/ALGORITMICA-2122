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
 * @param n Variable n
 * @param t Variable t
 * @param expN Exponente de n
 * @param expT Exponente de T
 * @return Valor del sumatorio de la funcion polinomica
*/

double sumatorio(const vector<double> n, const vector <double> t, int expN, int expT);

/**
 * Funcion que calcula el coeficiente de determinacion de un algoritmo
 * @param tiemposReales Vector que almacena los tiempos reales de un algoritmo
 * @param tiemposEstimados  Vector que almacena los tiempos estimados de un algoritmo
 * @return Coeficiente de determinacion del algoritmo
*/

double calcularCoeficienteDeterminacion(const vector <double> &tiemposReales, 
const vector <double> &tiemposEstimados);


/**
 * Funcion que calcula el tiempo estimado de un polinomio de un tamano dado por el usuario
 * @param n Vector que almacena el numero de elementos del algoritmo
 * @param a Vector de incognitas de un polinomio
 * @return Tiempo estimado de resolucion de un polinomio
*/

double calcularTiempoEstimadoPolinomico(const vector<double> &n, vector <double> &a);

/**
 * Funcion que calcula la media de un vector
 * @param vector Vector de elementos
 * @return Valor medio del vector
*/

double media(std::vector<double> vector);

/**
 * Funcion que calcula la varianza de un vector
 * @param vector Vector de elementos
 * @param media Valor medio del vector
 * @return Varianza del vector 
*/


double varianza(std::vector<double> vector, double media);

/**
 * Funcion que calcula los tiempos estimados de un polinomio
 * @param numeroElementos Vector que almacena el numero de elementos de un algoritmo
 * @param a Vector de coeficientes de un polinomio
 * @param tiemposEstimados Vector que almacena los tiempos estimados de resolucion de un polinomio
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
 *  Funcion que escribe en un fichero los tiempos reales de un algoritmo
 *  @param nombre Nombre del fichero
 *  @param numeroElementos Vector que almacena el numero de elementos de un algoritmo
 *  @param tiemposReales Vector que almacena los tiempos reales de un algoritmo
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

#endif