/**
Funciones del algoritmo de ordenacion por QuickSort
Realizado por Jaime Lorenzo Sanchez
*/

#include "ordenacionQuickSort.hpp"
#include "funcionesComunes.hpp"

void ordenacionQuickSort(){
    int minimo; // Numero minimo de elementos del vector
    int maximo; // Numero maximo de elementos del vector
    int repeticiones; // Numero de repeticiones del algoritmo
    std::vector <double> tiemposReales; // Creamos un vector de tipo double que almacena los tiempos reales del algoritmo
    std::vector <double> numeroElementos; // Creamos un vector de tipo double que almacena los distintos valores del vector
    // Pedimos al usuario el numero minimo de elementos del vector
    std::cout << "Introduce el numero minimo de elementos del vector: ";
    cin >> minimo;
    // Pedimos al usuario el numero maximo de elementos del vector
    std:: cout << "Introduce el numero maximo de elementos del vector: ";
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
    tiemposOrdenacionQuickSort(minimo, maximo, repeticiones, tiemposReales, numeroElementos);
}

// Funcion de obtencion de los tiempos de ordenacion
void tiemposOrdenacionQuickSort(int nMin, int nMax, int repeticiones, vector <double> &tiemposReales, 
vector <double> &numeroElementos){
    Clock tiempo; // Para calcular el tiempo del algoritmo, utilizaremos la clase Clock
    int incremento; // Incremento de los valores del vector
    float media = 0.0; // Variable que calcular el tiempo medio del algoritmo
    // Pedimos al usuario el valor del incremento del vector
    std::cout << "Introduce el valor de incremento del vector: " ;
    cin >> incremento;
    // El incremento del vector sera positivo
    while(incremento <= 0){
        std::cout << "El valor de incremento introducido <" << incremento << "> no es valido" <<endl;
        std::cout << "Introduce el valor de incremento del vector: ";
        cin >> incremento;
    }
    // Creamos un vector vacio de tipo entero
    std::vector<int> vector;
    // Tamano actual del vector
    int tamActual = nMin;
    // para n de minimo a maximo + incremento
    while(tamActual < nMax + incremento){
        // Actualizacion del tamano actual del vector
        if(tamActual > nMax){
            tamActual = nMax;
        }
        // Ejecutamos el algoritmo durante el numero de repeticiones indicado por el usuario
        for(int i=0; i < repeticiones; i++){
            // Limpiamos el vector
            vector.clear();
            // Reservamos el tamano del vector
            vector.resize(tamActual);
            // Rellenamos el vector
            rellenarVector(vector);
            // Iniciar medicion de tiempo
            tiempo.restart();
            // Ordenamos el vector
            ordenacionVector(vector);
            bool ordenado = estaOrdenado(vector);
            if(ordenado == false){
                exit(-1);
            }
            // Medimos el tiempo del algoritmo en la iteracion actual
            if(tiempo.isStarted()){
                // Detenemos el tiempo
                tiempo.stop();
            }
            // Actualizamos el tiempo medio de ejecucion del algoritmo
            media = media + tiempo.elapsed();
        }
        // Calculamos el tiempo medio de todas las repeticiones
        media = media / repeticiones;
        // Almacenamos en el vector tiemposReales los tiempos medios de todas las repeticiones
        tiemposReales.push_back(media);
        // Almacenamos en el vector numeroElementos el tamano actual del vector
        numeroElementos.push_back(tamActual);
        // Aplicamos el incremento del tamano actual del vector
        tamActual = tamActual + incremento;
    }

}

// Funcion de ordenacion del vector

void ordenacionVector(vector <int> &v){

}


