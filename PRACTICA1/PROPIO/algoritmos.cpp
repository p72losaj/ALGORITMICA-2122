/*
    Fichero con la instrucciones de los algoritmos
    Realizado por Jaime Lorenzo Sanchez
*/

#include "algoritmos.hpp"

#include "ClaseTiempo.cpp"

/**
        Funcion que implementa el metodo de ordenacion por seleccion y calcula el tiempo empleado
        por el algoritmo
*/

void tiemposOrdenacionSeleccion(int nMin, int nMax, int repeticiones, vector <double> &tiemposReales, 
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
            seleccion(vector);
            
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
	
	// AjustePolinomico(vector nElementos, vector tReales, vector polinomio)
	// estimarTiempos( vector nElementos, vector polinomio, vector &tEstimados);
		// Para cualquier prediccion introducir n y despues:  tEstimado = a0 + a1*n + a2*n2
	// guardar en fichero de texto vector nElementos, vector tReales, vector tEstimados
}

void ajustePolinomico(const vector <double> &numeroElementos, const vector <double> &tiemposReales, vector <double> &a){
    // t(n) =a0 + a1*n + a2*n²

    // Creamos la columna A del sistema de ecuaciones

    // Creamos la columna B del sistema de ecuaciones

    // Creamos la columna X ( solucion)

    

    // Realizamos una copia del vector de numeroElementos

    std::vector <double> copia = numeroElementos;

    // 

}

void tiemposProductoMatricesCuadradas(int orden_min, int orden_max, vector <double> &tiemposReales, 
vector <double> &numeroElementos){

    int incremento; // Incremento del orden de las matrices

    // Inicializamos la clase de reloj

    Clock tiempo;

    // El orden de las matrices sera el orden minimo
    int orden_actual = orden_min;

    // Obtenemos el incremento del orden

    std::cout << "Introduce el incremento del orden de las matrices: ";

    cin >> incremento;

    // El incremento debe ser >0

    while(incremento < 1){
        std::cout << "El incremento del orden de las matrices debe ser superior a 0"<<std::endl;
        std::cout << "Introduce un nuevo incremento del orden de las matrices: ";
        cin >> incremento;
    }

    for(int i=orden_min; orden_actual < orden_max+1; i++) {

        // Creamos las matrices

        std::vector < std::vector<double> > matriz1(orden_actual, std::vector <double>(orden_actual) ); // Matriz1
        std::vector < std::vector<double> > matriz2(orden_actual, std::vector <double>(orden_actual) ); // Matriz2
        std::vector < std::vector<double> > matriz3(orden_actual, std::vector <double> (orden_actual) ); // Matriz resultado

        // Rellenamos las matrices con valores aleatorios en el rango [0.95,1.05]

        for(int i=0; i < orden_actual; i++){
            for(int j=0; j < orden_actual; j++){
                matriz1[i][j] = ValorAleatorio(95,105);
                matriz2[i][j] = ValorAleatorio(95,105);
            }
        }

        // Iniciamos el tiempo

        tiempo.restart();

        // Realizamos el producto de las matrices

        matriz3 = producto(matriz1, matriz2, orden_actual);

        // Incrementamos el orden actual de las matrices
        orden_actual = orden_actual + incremento;
    }
    
}

void fibonacciRecursivo();

