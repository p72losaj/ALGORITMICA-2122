/**
 * Fichero con la implementacion de las funciones necesarias para implementar el algoritmo de ordenacion fusion
 * Realizado por Jaime Lorenzo Sanchez
*/

// Incluimos la biblioteca de las funciones comunes

#include "funcionesComunes.hpp"

// Incluimos la biblioteca de las funciones del algoritmo de ordenacion fusion

#include "ordenacionFusion.hpp"

// Funcion de ordenacionFusion

void ordenacionFusion(){
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
    tiemposOrdenacionFusion(minimo, maximo, repeticiones, tiemposReales, numeroElementos);
    // Amacenamos en un fichero de texto el vector numeroElementos y el vector tiemposReales
    escribeFicheroTiemposReales("datosRealesFusion.txt",numeroElementos, tiemposReales);
    std::vector<double> a; // Vector de coeficientes
    a.resize(2); // El tamano del vector de coeficientes sera de 2
    // Llamamos a la funcion de ajuste polinomico
    ajustePolinomico(numeroElementos, tiemposReales, a);
    // Calculo de los tiempos estimados de la funcion de ajuste de un polinomio
    std::vector<double> tiemposEstimados; // Vector de tiempos estimados de la funcion de ajuste del polinomio
    calcularTiemposEstimadosPolinomico(numeroElementos,a,tiemposEstimados);
    // Calculamos el coeficiente de determinacion
    double coeficiente = calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);
    std::cout << "Coeficiente de determinacion: " << coeficiente << std::endl;
    // Almacenamos los tiempos reales y estimados en un fichero
    escribeFicheroTiemposEstimados("datosFinalesFusion.txt",numeroElementos, tiemposReales, tiemposEstimados);
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

// Funcion que obtiene los tiempos de ordenacion fusion de un vector

void tiemposOrdenacionFusion(int nMin, int nMax, int repeticiones, vector <double> &tiemposReales, 
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
            // Aplicamos el algoritmo de ordenacion por fusion
            ordenarFusion(vector);
            bool ordenado = estaOrdenado(vector);
            if(ordenado == false){
                std::cout << "Vector no ordenado"<<std::endl;
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

// Funcion de ordenar fusion

void ordenarFusion(std::vector<int> &t){
    // Consideramos como tamano pequeno del vector a un valor inferior a 10
    if(t.size() < 10){
        ordenar(t); // Ordenamos el vector usando un metodo no sofisticado
    }
    // El tamano del vector no es pequeno
    else{
        int aux = t.size()/2; // Tamano medio del vector
        std::vector<int> u(aux+1); // Creamos un vector u de tamano (n/2 + 1)
        std::vector<int> v(t.size() - aux + 1); // Creamos un vector v de tamano (n - n/2 + 1)
        // Rellenamos el vector u
        for(int i=0; i < aux; i++){
            u[i] = t[i];// Rellenamos el vector u con los elementos del vector t hasta (n/2)
        }
        // Rellenamos el vector v
        for(int i=aux; i < t.size(); i++ ){
            v[i-aux] = t[i];
        }
        ordenarFusion(u); // Ordenamos por fusion el vector u
        ordenarFusion(v);// Ordenamos por fusion el vector v
        fusionar(u,v,t);// Fusionamos los 3 vectores
    }
}

// Funcion que fusiona 3 vectores

void fusionar(std::vector<int> &u,std::vector<int> &v,std::vector<int> &t){
    int i = 0,j=0;
    u[u.size()-1] = 10000000;
    v[v.size()-1] = 10000000;
    
    // Recorremos el vector t
    for(int k=0; k < t.size(); k++){ 
        // Anadimos en el vector t los valores del vector u
        if(u[i] < v[j] ) {
            t[k] = u[i];
            i = i+1;
        }
        // Anadimos en el vector t los valores del vector v
        else{
            t[k] = v[j];
            j = j+1;
        }
    }
    
}

// Funcion que ordena un vector por fusion, siendo el tamano del vector pequeno

void ordenar(std::vector<int> &t){
    
    for(int i=0; i < t.size(); i++){
        int posicionActual = i;
        while((posicionActual > 0) && (t[posicionActual] < t[posicionActual-1])){
            int aux = t[posicionActual];
            t[posicionActual] = t[posicionActual-1];
            t[posicionActual-1] = aux;
            posicionActual = posicionActual-1;
        }
    }

}