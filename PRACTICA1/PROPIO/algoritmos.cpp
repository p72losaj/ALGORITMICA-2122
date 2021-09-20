/*
    Fichero con la instrucciones de los algoritmos
    Realizado por Jaime Lorenzo Sanchez
*/

#include "algoritmos.hpp"

void ordenacionSeleccion(){

    int elementosMinimoVector, elementosMaximoVector, incrementoVector;

    // Pedimos al usuario el valor del incremento del vector

    std::cout << "Introduce el valor de incremento del vector" << endl;

    cin >> incrementoVector;

    // el incremento del vector sera positivo

    while(incrementoVector < 0){
       
        std::cout << "El valor de incremento introducido <" << incrementoVector << "> no es correcto" <<endl;
        
        std::cout << "Introduce el valor de incremento del vector" << endl;

        cin >> incrementoVector;
    }

    // Pedimos al usuario el numero minimo de elementos del vector

    std::cout << "Introduce el numero minimo de elemento del vector: ";

    cin >> elementosMinimoVector;

    // Pedimos al usuario el numero maximo de elementos del vector

    std:: cout << "Introduce el numero maximo del elemento del vector: ";

    cin >> elementosMaximoVector;

    // Comprobamos si el numero maximo introducido es mayor al numero minimo de elementos del vector

    while(elementosMinimoVector > elementosMaximoVector){
        std:: cout << "Introduce un numero de elementos maximo del vector superior a " << elementosMinimoVector << ":";
        cin >> elementosMaximoVector;
    }

    // Recorremos desde el valor minimo al valor maximo

    

	// para n de minimo a maximo inc incremento
		// reservarVector(tamano n)
		// rellenarVector
		// Iniciar medicion de tiempo
		// ordenarVector
		// medir tiempo
		// introducir en el vector respectivo el tiempo real y el valor n
	// fin_para
	// AjustePolinomico(vector nElementos, vector tReales, vector polinomio)
	// estimarTiempos( vector nElementos, vector polinomio, vector &tEstimados);
		// Para cualquier prediccion introducir n y despues:  tEstimado = a0 + a1*n + a2*n2
	// guardar en fichero de texto vector nElementos, vector tReales, vector tEstimados



    // Creamos un vector vacio

}

void productoMatricesCuadradas(){

}

void fibonacciRecursivo();