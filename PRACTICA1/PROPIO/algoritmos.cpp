/*
    Fichero que realiza las funciones del programa principal
    Realizado por Jaime Lorenzo Sanchez
*/

#include "algoritmos.hpp"

void ordenacionSeleccion(){

    int elementosMinimoVector, elementosMaximoVector;

    // Obtenemos el valor minimo de numero de elementos del vector

    std::cout << "Introduce el numero minimo de elemento del vector: ";

    cin >> elementosMinimoVector;

    // Obtenemos el numero maximo de elementos del vector

    std:: cout << "Introduce el numero maximo del elemento del vector: ";

    cin >> elementosMaximoVector;

    // Comprobamos si el numero maximo introducido es mayor al numero minimo de elementos del vector

    while(elementosMinimoVector > elementosMaximoVector){
        std:: cout << "Introduce un numero de elementos maximo del vector superior a " << elementosMinimoVector << ":";
        cin >> elementosMaximoVector;
    }

    // Creamos un vector vacio

}