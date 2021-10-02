/**
 * Fichero que realiza las funciones exlusivas del algoritmo de ordenacion por seleccion
 * Realizado por Jaime Lorenzo Sanchez
*/

// Incluimos la biblioteca de ordenacionSeleccion

#include "ordenacionSeleccion.hpp"

// Biblioteca de funciones comunes

#include "funcionesComunes.hpp"


// Funcion ordenacionSeleccion

void ordenacionSeleccion(){

    // Numero minimo de elementos del vector

    int minimo; 
    
    // Numero maximo de elementos del vector

    int maximo; 

    // Numero de repeticiones del algoritmo

    int repeticiones; 

    // Vector que almacena los tiempos reales de un algoritmo

    std::vector <double> tiemposReales; 

    // Vector que almacena el numero de elementos de un algoritmo

    std::vector <double> numeroElementos; 

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

    // Pedimos al usuario el numero de repeticiones del algoritmo

    std:: cout << "Introduce el numero de repeticiones: ";

    cin >> repeticiones;

    // Obtenemos los tiempos de ordenacion de seleccion

    tiemposOrdenacionSeleccion(minimo, maximo, repeticiones, tiemposReales, numeroElementos);

    // Amacenamos en un fichero de texto el vector numeroElementos y el vector tiemposReales

    escribeFicheroTiemposReales("datosReales.txt",numeroElementos, tiemposReales);

    std::vector<double> a; // Vector de coeficientes

    a.resize(3); // El tamano del vector de coeficientes sera de 3

    // Llamamos a la funcion de ajuste polinomico

    ajustePolinomico(numeroElementos, tiemposReales, a);

    // Calculo de los tiempos estimados de la funcion de ajuste de un polinomio

    std::vector<double> tiemposEstimados; // Vector de tiempos estimados de la funcion de ajuste del polinomio

    calcularTiemposEstimadosPolinomico(numeroElementos,a,tiemposEstimados);
    
    // Calculamos el coeficiente de determinacion

    double coeficiente = calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);

    std::cout << "Coeficiente de determinacion: " << coeficiente << std::endl;

    // Almacenamos los tiempos reales y estimados en un fichero

    escribeFicheroTiemposEstimados("datosFinales.txt",numeroElementos, tiemposReales, tiemposEstimados);

    // Comprobamos si el usuario desea realizar una estimacion del tiempo del polinomio en funcion de un tamano dado
    
    std::cout << "Desea estimar (Y/N): ";

    string opcion;

    // Obtenemos la opcion elegida por el usuario

    cin>>opcion;

    int tamEjemplar = -1;

    // El usuario desea realizar una estimacion
    if(opcion == "Y"){
        // Pedimos el tamano del ejemplar del algoritmo hasta que el usuario no desee seguir realizando la estimacion
        while(tamEjemplar != 0){
            std::cout << "Introduce el valor 0 para finalizar"<<std::endl;
            std::cout << "Introduce un tamano del ejemplar" << std::endl;
            cin >> tamEjemplar; 
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

// Funcion que calcula los tiempos de ordenacion por seleccion de un algoritmo


void tiemposOrdenacionSeleccion(int nMin, int nMax, int repeticiones, vector <double> &tiemposReales, 
vector <double> &numeroElementos){

    // Anadimos la clase de tiempo para realizar el calculo del tiempo utilizado por el algoritmo

    Clock tiempo; 

    // Incremento de los valores del vector

    int incremento; 

    // Tiempo medio del algoritmo

    float media = 0.0; 

    // Pedimos al usuario el valor del incremento del vector

    std::cout << "Introduce el valor de incremento del vector: " ;

    cin >> incremento;

    // Comprobamos que el incremento del vector sea superior a 0

    while(incremento < 1){
       
        std::cout << "El incremento del vector debe ser superior a 0" <<endl;
        
        std::cout << "Introduce el valor de incremento del vector: ";

        cin >> incremento;
    }

    // Creamos un vector vacio de tipo entero

    std::vector<int> vector;

    // Tamano actual del vector

    int tamActual = nMin;

    while(tamActual < nMax + incremento){
        
        // Actualizacion del tamano actual del vector

        if(tamActual > nMax){ tamActual = nMax; }

        // Ejecutamos el algoritmo durante el numero de repeticiones indicado por el usuario

        for(int i=0; i < repeticiones; i++){
            
            // Limpiamos el vector
            
            vector.clear();
            
            // Reservamos el tamano del vector
            
            vector.resize(tamActual);
            
            // Rellenamos el vector
            
            rellenarVector(vector);
            
            // Iniciamos el reloj de tiempo
            
            tiempo.restart();

            // Ordenamos el vector usando el metodo de seleccion

            seleccion(vector);
            
            // Comprobamos si el vector esta ordenado

            bool ordenado = estaOrdenado(vector);
            
            // El vector no esta ordenado -> Finalizamos el programa

            if(ordenado == false){ exit(-1); }

            // Detenemos el tiempo de ordenacion del vector

            if(tiempo.isStarted()){ tiempo.stop(); }

            // Obtenemos el tiempo medio de ordenacion del vector

            media = media + tiempo.elapsed();

        }

        // Calculamos el tiempo medio de ordenacion del vector para todas las repeticiones

        media = media / repeticiones;

        // Almacenamos los tiempos medios reales de ordenacion del vector

        tiemposReales.push_back(media);

        // Almacenamos los distintos tamanos del vector

        numeroElementos.push_back(tamActual);

        // Aplicamos el incremento del tamano del vector

        tamActual = tamActual + incremento;
    }

}

// Funcion rellenarVector

void rellenarVector(vector<int> &v){
    
    // Creamos una variable de tipo entero que almacenara el valor aleatorio
    
    int valor;
    
    // Rellenamos el vector

    for(size_t i=0; i < v.size(); i++){

        // Obtenemos el valor aleatorio
        
        valor = rand()%9999999;

        // Almacenamos en el vector el valor aleatorio

        v[i] = valor;
    
    }
}

// Ordenacion por seleccion de un vector

void seleccion(vector <int> &v){
    
    // Recorremos los elementos del vector

    for(int i=0; i < v.size(); i++){
        // El valor minimo estara en la posicion 0 del vector
        
        int valorMinimo = i;

        // Comparamos el valor de la posicion minima con el resto de elementos del vector

        for(int j=i+1; j < v.size(); j++){
            
            // Comprobamos si hay que aplicar una sustitucion de los valores del vector

            if( v[valorMinimo] > v[j]){
                
                // La posicion del valor minimo del vector sera la posicion j

                valorMinimo = j;

            }
        }

        // Intercambiamos los valores para que el vector este ordenado de menor a mayor

        // Creamos una variable auxiliar que almacena el valor del vector en la posicion i

        int valorAuxiliar = v[i];

        // El valor en la posicion i del vector sera el valor minimo del vector

        v[i] = v[valorMinimo];

        // El valor minimo del vector sera el valor auxiliar

        v[valorMinimo] = valorAuxiliar;
    }

}

// Funcion que comprueba si un vector esta ordenado de menor a mayor

bool estaOrdenado(const vector <int> &v){

    // Recorremos los elementos del vector

    for(size_t i=0; i < v.size()-1; i++){
        
        // El vector no esta ordenado -> Retornamos false

        if(v[i] > v[i+1]){ return false; }
    }

    // Por defecto, retornamos true

    return true;
}