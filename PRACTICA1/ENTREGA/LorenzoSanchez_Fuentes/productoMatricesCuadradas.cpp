/**
 * Fichero de realiza las funciones del algoritmo productoMatricesCuadradas
 * Realizado por Jaime Lorenzo Sanchez
*/

// Biblioteca de producto de matrices cuadradas

#include "productoMatricesCuadradas.hpp"

// Biblioteca de funciones comunes

#include "funcionesComunes.hpp"

// Funcion productoMatricesCuadradas

void productoMatricesCuadradas(){

    // Orden minimo de las matrices

    int orden_min; 

    // Orden maximo de las matrices

    int orden_max; 
    
    // Vector de tiempos reales
    
    std::vector<double> tiemposReales; 
    
    // vector de numero de elementos

    std::vector<double> numeroElementos; 
    
    // Vector de coeficientes

    std::vector<double> a; 
    
    // El tamano del vector de coeficientes sera de 3

    a.resize(3); 
    
    // Vector de tiempos estimados

    std::vector<double> tiemposEstimados; 
    
    // Pedimos al usuario el orden minimo de las matrices
    
    std::cout << "Introduce el orden minimo de las matrices: ";
    
    cin >> orden_min;
    
    // El orden minimo debe ser superior a 1
    
    while(orden_min < 2){
        std::cout << "El orden minimo de las matrices debe ser superior a 1"<<std::endl;
        std::cout << "Introduce el orden minimo de las matrices: ";
        cin >> orden_min;
    }
    
    // Pedimos al usuario el orden maximo de las matrices
    
    std::cout << "Introduce el orden maximo de las matrices: ";
    
    cin >> orden_max;

    // El orden maximo debe ser superior al orden minimo
    
    while(orden_max < orden_min){
        std::cout << "El orden maximo de las matrices no puede ser inferior a " << orden_min << std::endl;
        std::cout << "Introduce el orden maximo de las matrices: ";
        cin >> orden_max;
    }

    // Calculamos el tiempo necesario para realizar el producto de las matrices
    
    tiemposProductoMatricesCuadradas(orden_min,orden_max,tiemposReales,numeroElementos);

    // Almacenamos en un fichero los tiempos reales del algoritmo

    escribeFicheroTiemposReales("datosReales.txt",numeroElementos, tiemposReales);

    // Llamamos a la funcion de ajuste polinomico

    ajustePolinomico(numeroElementos,tiemposReales,a);

    // Calculamos los tiempos estimados de la funcion de ajuste del polinomio

    calcularTiemposEstimadosPolinomico(numeroElementos,a,tiemposEstimados);

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


// Funcion de calculo del tiempo del producto de las matrices

void tiemposProductoMatricesCuadradas(int orden_min, int orden_max, vector <double> &tiemposReales, 
vector <double> &numeroElementos){

    int incremento; // Incremento del orden de las matrices

    float media = 0.0; // Tiempo medio del algoritmo
    
    Clock tiempo; // Clase reloj para el calculo del tiempo del producto de las matrices
    
    int orden_actual = orden_min; // Orden actual de las matrices
    
    // Pedimos al usuario el incremento del orden de las matrices
    
    std::cout << "Introduce el incremento del orden de las matrices: ";
    cin >> incremento;
    
    // El incremento debe ser superior a 0
    
    while(incremento < 1){
        std::cout << "El incremento del orden de las matrices debe ser superior a 0"<<std::endl;
        std::cout << "Introduce un nuevo incremento del orden de las matrices: ";
        cin >> incremento;
    }

    for(int i=orden_min; orden_actual < orden_max + 1; i++){
        std::vector < std::vector<double> > matriz1(orden_actual, std::vector <double>(orden_actual) ); // Matriz1
        std::vector < std::vector<double> > matriz2(orden_actual, std::vector <double>(orden_actual) ); // Matriz2
        std::vector < std::vector<double> > matriz3(orden_actual, std::vector <double> (orden_actual) ); // Matriz resultado
        
        // Recorremos las filas de las matrices
        
        for(int i=0; i < orden_actual; i++){
            // Recorremos las columnas de las matrices
            for(int j=0; j < orden_actual; j++){
                // Rellenamos la matriz1
                matriz1[i][j] = obtenerValorAleatorio(95,105);
                // Rellenamos la matriz2
            }
        }

        // Iniciar medicion de tiempo
        
        tiempo.restart();

        // Realizamos el producto de las matrices

        productoMatrices(matriz1, matriz2,matriz3, orden_actual);

        // Medimos el tiempo del algoritmo en la iteracion actual

        if(tiempo.isStarted()){
            // Detenemos el tiempo
            tiempo.stop();
        }

        // Actualizamos el tiempo medio de ejecucion del algoritmo

        media = media + tiempo.elapsed();

        // Almacenamos en el vector tiemposReales los tiempos del algoritmo

        tiemposReales.push_back(media);

        // Almacenamos en el vector numeroElementos el orden actual de las matrices

        numeroElementos.push_back(orden_actual);

        // Aplicamos el incremento del orden actual de las matrices

        orden_actual = orden_actual + incremento;

    }
}

// Funcion que rellena la matriz

float obtenerValorAleatorio(int minimo,int maximo){
    float valor = (minimo + rand() % (maximo-minimo) ); // Obtenemos el valor entero aleatorio
    valor = valor / 100; // Transformamos el valor entero a valor decimal
    return valor; // Retornamos el valor decimal
}

// Funcion que calcula el producto de 2 matrices cuadradas

void productoMatrices(std::vector < std::vector <double> > &matriz1, 
std::vector < std::vector <double> > &matriz2, std::vector < std::vector <double> > &matriz3, int n){
     
    // Filas de la matriz resultante

    for (int i = 0 ; i < n ; i++ ){
        // Columnas de la matriz resultante
        for (int k = 0 ; k < n ; k++ ){
            float temporal = 0.0;
            // Multiplicacion de los elementos de la matriz
            for (int j = 0 ; j < n ; j++ ){
                temporal = temporal + matriz1[i][j] * matriz2[j][k];
                matriz3[i][k] = temporal ;
            }
        }
    }
}

