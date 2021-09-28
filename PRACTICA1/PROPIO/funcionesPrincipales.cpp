#include "algoritmos.hpp"
#include "funcionesauxiliares.cpp"

/**
    Funcion que implementa el metodo de ordenacion por seleccion de un vector
*/

void ordenacionSeleccion(){

    int minimo; // Numero minimo de elementos del vector
    
    int maximo; // Numero maximo de elementos del vector

    int repeticiones; // Numero de repeticiones del algoritmo

    std::vector <double> tiemposReales; // Creamos un vector de tipo double que almacena los tiempos reales del algoritmo

    std::vector <double> numeroElementos; // Creamos un vector de tipo double que almacena los distintos valores del vector

    // Pedimos al usuario el numero minimo de elementos del vector

    std::cout << "Introduce el numero minimo de elemento del vector: ";

    cin >> minimo;

    // Pedimos al usuario el numero maximo de elementos del vector

    std:: cout << "Introduce el numero maximo del elemento del vector: ";

    cin >> maximo;

    // Comprobamos si el numero maximo introducido es mayor al numero minimo de elementos del vector

    while(minimo > maximo){
        std:: cout << "Introduce un numero de elementos maximo del vector superior a " << minimo << ":";
        cin >> maximo;
    }

    // Pedimos al usuario el numero de repeticiones

    std:: cout << "Introduce el numero de repeticiones: ";

    cin >> repeticiones;

    // Obtenemos los tiempos de ordenacion de seleccion

    tiemposOrdenacionSeleccion(minimo, maximo, repeticiones, tiemposReales, numeroElementos);

    // Amacenamos en un fichero de texto el vector numeroElementos y el vector tiemposReales

    escribeFicheroOrdenacionSeleccion("tiempoReales.txt",numeroElementos, tiemposReales);

    std::vector<double> a; // Vector de coeficientes

    a.resize(3); // El tamano del vector de coeficientes sera de 3

    // Llamamos a la funcion de ajuste polinomico

    ajustePolinomico(numeroElementos, tiemposReales, a);

    // Calculo de los tiempos estimados de la funcion de ajuste de un polinomio

    // Obtencion del coeficiente de determinacion del ajuste

    /**
     Guardamos los tiempos de estimacion en el fichero de texto datosFinales.txt
            Columna1: tamano del ejemplar
            Columna2: tiempo real
            columna3: tiempo estimado
     */


}

/**
    Funcion que realiza el producto de 2 matrices cuadradas
*/

void productoMatricesCuadradas(){

    int orden_min; // Orden minimo de las matrices cuadradas

    int orden_max; // Orden maximo de las matrices cuadradas
    
    std::cout << "Introduce el orden minimo de las matrices cuadradas: ";

    cin >> orden_min;

    // El orden minimo tiene que ser superior a 1

    while(orden_min < 2){
        std::cout << "El orden minimo de la matriz cuadrada debe ser superior a 1" << std::endl;
        std::cout << "Introduce un orden minimo de la matriz: ";
        cin >> orden_min;
    }

    std::cout << "Introduce el orden maximo de las matrices cuadradas: ";

    cin >> orden_max;

    // el orden maximo debe ser superior al orden minimo

    while(orden_min > orden_max){
        std::cout << "El orden minimo <" << orden_min << "> es mayor al orden maximo" << std::endl;
        std::cout << "Introduce un orden maximo de las matrices superior al orden minimo: ";
        cin >> orden_max;
    }

    std::vector <double> tiemposReales; // Creamos un vector de tipo double que almacena los tiempos reales del algoritmo

    std::vector <double> numeroElementos; // Creamos un vector de tipo double que almacena los distintos valores del vector

    tiemposProductoMatricesCuadradas(orden_min,orden_max,tiemposReales, numeroElementos);






}
