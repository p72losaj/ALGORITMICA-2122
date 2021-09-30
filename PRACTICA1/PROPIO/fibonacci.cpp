/**
 * Funciones para la realizacion del algoritmo de Fibonacci de modo recursivo
 * Realizado por Jaime Lorenzo Sanchez
 * 
*/


// Biblioteca de la funcion

#include "fibonacci.hpp"

// Biblioteca de las funciones comunes

#include "funcionesComunes.hpp"

// Algoritmo de Fibonacci

void fibonacciRecursivo(){
    
    int minimo; // Termino n minimo
    int maximo; // Termino n maximo
    std::vector<double> tiemposReales; // Vector de tiempos reales
    std::vector<double> numeroElementos; // vector numeroElementos
    std::vector<double> a; // Vector de coeficientes
    a.resize(2); // El tamano del vector de coeficientes sera de 2 (a1,a0)
    std::vector<double> tiemposEstimados; // Vector de tiempos estimados de la funcion de ajuste del polinomio
    
    // Pedimos al usuario el termino minimo

    std::cout << "Introduce el termino n minimo: ";

    std::cin >> minimo;

    // El valor minimo debe ser superior a 0

    while(minimo < 1){
        std::cout << "Termino indicado debe ser superior a 0" << std::endl;
        std::cout << "Introduce el termino n: ";
        std::cin >> minimo;
    }

    // Pedimos al usuario el termina maximo

    std::cout << "Introduce el termino n maximo: ";

    std::cin >> maximo;

    // El termino maximo debe ser superior al termino minimo

    while(maximo < minimo){
        std::cout << "Termino n indicado es inferior a : " << minimo << std::endl;
        std::cout << "Introduce el termino n maximo: ";
        std::cin >> maximo;
    }

    // Calculamos el tiempo necesario para realizar el calculo de la sucession de Fibbonacci
    
    tiemposFibbonnaci (minimo,maximo,tiemposReales,numeroElementos);

    // Almacenamos en un fichero los tiempos de producto de las matrices

    escribeFicheroTiemposReales("datosRealesFibbonnaci.txt",numeroElementos, tiemposReales);

    // Llamamos a la funcion de ajuste exponencial

    ajusteExponencial(numeroElementos, tiemposReales, a);


}

// Funcion de calculo de los tiempos de Fibbonnaci

void tiemposFibbonnaci (int minimo, int maximo, std::vector<double> &tiemposReales, std::vector<double> &numeroElementos){
    int incremento; // Incremento del termino n de la sucesion
    float media = 0.0; // Tiempo medio del algoritmo
    Clock tiempo; // Clase reloj para el calculo del tiempo del producto de las matrices
    int actual = minimo; // Termino actual del termino n de la sucesion

    // Pedimos al usuario el incremento del termino n
    
    std::cout << "Introduce el incremento del termino n: ";

    cin >> incremento;
    
    // El incremento debe ser superior a 0
    
    while(incremento < 1){
        std::cout << "El incremento del termino n debe ser superior a 0"<<std::endl;
        std::cout << "Introduce el incremento del termino n: ";
        cin >> incremento;
    }

    // Aplicamos el algoritmo para cada termino n

    for(int i=actual; actual < maximo + 1; i++){

        // Iniciar medicion de tiempo
        
        tiempo.restart();

        // Calculamos el termino n-esimo de fibbonnaci

        int termino = fibbonnaciRecursivo(i);

        // Medimos el tiempo del algoritmo en la iteracion actual

        if(tiempo.isStarted()){
            // Detenemos el tiempo
            tiempo.stop();
        }

        // Actualizamos el tiempo medio de ejecucion del algoritmo

        media = media + tiempo.elapsed();

        // Almacenamos en el vector tiemposReales los tiempos reales del algoritmo

        tiemposReales.push_back(media);

        // Almacenamos en el vector numeroElementos el termino n actual

        numeroElementos.push_back(actual);

        // Aplicamos el incremento 

        actual = actual + incremento;

    }

}

// Calculamos el termino n de la sucesion de Fibbonnaci

int fibbonnaciRecursivo(int valor){
    int termino = 1;
    // Si el valor dado es 1 o 2, el termino n de la sucesion de Fibbonnaci es 1
    if(valor==1 || valor==2){
        return termino;
    }
    else{
        // fibbonnaciRecursivo(n) = fibbonnaciRecursivo(n-1) + fibbonnaciRecursivo(n-2)
        termino = fibbonnaciRecursivo(valor-1) + fibbonnaciRecursivo(valor-2);
    }
    return termino;
}

// Funcion de obtencion de curva de ajuste

void ajusteExponencial(const vector <double> &n, const vector <double> &tiemposReales, vector <double> &a){
    // curva t(n) = a0 + a1*2^n
    
    // Creamos la matriz A del sistema de ecuaciones

    std::vector< std::vector<double> > matrizA (3, std::vector <double>(2) ); // A = [a1,a0]

    // Creamos la matriz B del sistema de ecuaciones

    std::vector< std::vector<double> > matrizB (2, std::vector <double>(1) ); // 

    // Creamos la matriz X ( solucion)

    std::vector <std::vector<double> > matrizX (3,std::vector <double> (1));

    
}