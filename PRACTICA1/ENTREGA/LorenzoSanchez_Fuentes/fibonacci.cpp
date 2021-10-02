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
    
    // Termino n minimo de la sucesion de Fibbonnaci

    int minimo; 

    // Termino n maximo de la sucesion de Fibbonnaci

    int maximo; 

    // Vector que almacena los tiempos reales del algoritmo

    std::vector<double> tiemposReales; 
    
    // Vector que almacena los distintos numeros de elementos del algoritmo
    
    std::vector<double> numeroElementos; 

    // Vector de coeficientes
    
    std::vector<double> a; 

    // El tamano del vector de coeficientes sera de 2 (a1,a0)

    a.resize(2); 
    
    // Vector que almacena los tiempos estimados del algoritmo

    std::vector<double> tiemposEstimados; 
    
    // Pedimos al usuario el termino minimo de la sucesion de Fibbonnaci

    std::cout << "Introduce el termino n minimo: ";

    std::cin >> minimo;

    // El termino minimo debe ser superior a 0

    while(minimo < 1){

        std::cout << "Termino indicado debe ser superior a 0" << std::endl;
        
        std::cout << "Introduce el termino n: ";
        
        std::cin >> minimo;
    }

    // Pedimos al usuario el termino maximo

    std::cout << "Introduce el termino n maximo de la sucesion de Fibbonnaci: ";

    std::cin >> maximo;

    // El termino maximo debe ser superior al termino minimo

    while(maximo < minimo){

        
        std::cout << "Termino maximo indicado es inferior a : " << minimo << std::endl;
        
        std::cout << "Introduce el termino n maximo: ";
        
        std::cin >> maximo;
    }

    // Calculamos el tiempo necesario para realizar el calculo de la sucession de Fibbonacci
    
    tiemposFibbonnaci (minimo,maximo,tiemposReales,numeroElementos);

    // Almacenamos en un fichero los tiempos de producto de las matrices

    escribeFicheroTiemposReales("datosReales.txt",numeroElementos, tiemposReales);

    // Llamamos a la funcion de ajuste exponencial

    ajusteExponencial(numeroElementos, tiemposReales, a);

    // Calculamos los tiempos estimados de la funcion de ajuste
    
    calcularTiemposEstimadosExponencial(numeroElementos,a,tiemposEstimados);

    // Calculamos el coeficiente de determinacion

    double coeficiente = calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);

    std::cout << "Coeficiente de determinacion: " << coeficiente << std::endl;

    // Almacenamos los tiempos reales y estimados en un fichero

    escribeFicheroTiemposEstimados("datosFinales.txt",numeroElementos, tiemposReales, tiemposEstimados);

    // Comprobamos si el usuario desea realizar una estimacion del tiempo del polinomio en funcion de un tamano dado
    
    std::cout << "Desea estimar (Y/N): ";

    string opcion;

    // Obtenemos la eleccion del usuario con respecto a la estimacion

    cin>>opcion;

    int tamEjemplar = -1;

    // El usuario desea realizar una estimacion

    if(opcion == "Y"){

        while(tamEjemplar != 0){
        
            // Pedimos al usuario el tamano del ejemplar

            std::cout << "Introduce el valor 0 para finalizar"<<std::endl;
        
            std::cout << "Introduce un tamano del ejemplar" << std::endl;

            // Almacenamos el tamano del ejemplar

            cin >> tamEjemplar;

            // Creamos un vector de tamanoElementos nuevo con un solo valor

            std::vector <double> tamanoElementos(1);
            
           if(tamEjemplar != 0){
                double valor = 0.0;
                tamanoElementos[0] = tamEjemplar;
                // Calculamos el tiempo estimado del polinomio en milisegundos
                valor = calcularTiempoEstimadoPolinomico(tamanoElementos, a);
                // Transformamos el numero de milisegundos en dias
                valor = valor * 0.001 * 0.0000115741; 
                std::cout << "Tiempo estimado: " << valor << " dias" << std::endl;
            }
            
        }
        
    }

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
    
    if(valor < 2){
        return valor;
    }

    else{
        // fibbonnaciRecursivo(n) = fibbonnaciRecursivo(n-1) + fibbonnaciRecursivo(n-2)
        return fibbonnaciRecursivo(valor-1) + fibbonnaciRecursivo(valor-2);
    }
}

// Funcion de obtencion de curva de ajuste

void ajusteExponencial(const vector <double> &n, const vector <double> &tiemposReales, vector <double> &a){
    // curva t(n) = a0 + a1*2^n
    // curva t(n) = a0 + a1*Z
    
    // Creamos la matriz A del sistema de ecuaciones

    std::vector< std::vector<double> > matrizA (2, std::vector <double>(2) ); // A = [a1,a0]

    // Creamos la matriz B del sistema de ecuaciones

    std::vector< std::vector<double> > matrizB (2, std::vector <double>(1) ); // 

    // Creamos la matriz X ( solucion)

    std::vector <std::vector<double> > matrizX (2,std::vector <double> (1));

    std::vector <double> Z = n;

    for(int i=0; i < n.size(); i++){
        Z[i] = pow(2,n[i]);
    }

    // Recorremos filas de A

    for(int i=0; i < matrizA.size(); i++){
        
        // Recorremos columnas de A
        
        for(int j=0; j < matrizA.size(); j++){
            
            // En la posicion A[0][0] almacenamos el numero de elementos del algoritmo

            if(i==0 && j==0){ matrizA[i][j] = n.size(); }

            // Rellenamos la matriz A aplicando la funcion de sumatorio de un polinomio

            else{ matrizA[i][j] = sumatorio(Z,Z,i+j,0);}

        }
    }

    // Recorremos las filas de la matriz B

    for(int i=0; i < matrizB.size(); i++){
    
        // Rellenamos los elementos de la matriz B aplicando la funcion de sumatorio de un polinomio

        matrizB[i][0] = sumatorio(Z, tiemposReales,i,1);

    }
    
    // Resolvemos el sistema de ecucaciones
    
    resolverSistemaEcuaciones(matrizA, matrizB, matrizA.size(),matrizX);

    // Recorremos las filas de la matriz solucion del sistema de ecuaciones

    for(int i=0; i<  matrizX.size(); i++){

        // Almacenamos en el vector de coeficientes las soluciones del sistema de ecuaciones

        a[i] = matrizX [i][0];
    } 
}

// Funcion que calcula los tiempos estimados de una funcion de ajuste exponencial

void calcularTiemposEstimadosExponencial(const vector <double> &n, 
const vector <double> &a, vector <double> &tiemposEstimados){
    
    // Recorremos los elementos del vector n

    double valor = 0.0;

    for(int i=0; i < n.size(); i++){
        // Obtenemos el valor estimado de cada elemento del algoritmo

        // t(n) = a0 + a1 * 2^n

        valor = a[0] + a[1] * pow(2,n[i]);

        // Almacenamos el valor estimado

        tiemposEstimados.push_back(valor);
    }
}

// Funcion que calcula el tiempo estimado de una funcion exponencial

double calcularTiempoEstimadoExponencial(const vector <double> &numeroElementos, const vector <double> &a){

    // Valor del tiempo estimado
    
    double valor = 0.0;
    
    // Recorremos el numero de elementos del algoritmo

    for(int i=0; i < numeroElementos.size(); i++){
        // Obtenemos el valor estimado de cada elemento del algoritmo

        // t(n) = a0 + a1 * 2^n
        
        valor = valor + a[0] + a[1] * pow(2,numeroElementos[i]);
    }

    // Retornamos el tiempo estimado del polinomio

    return valor;
    
}