/**
 * Fichero que realiza la funcion principal del programa
 * Realizado por Jaime Lorenzo Sanchez
 * */

#include "reinas.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    int opcion = -1;
    while(opcion != 0){
        cout<<"Mostrando funcionalidades " << std::endl;
        cout << "0. SALIR" << endl;
        cout << "1. Obtener soluciones n-reinas" << std::endl;
        cout << "2. Obtener una solucion n-reinas que coloca la primera reina de la primera fila en la columna cental" << endl;
        cout << "3. Algoritmo de Las Vegas para n-reinas: Muestra una solucion, el numero de intentos y el tiempo consumido"<<endl;
        cout << "##################################################################"<<endl;
        cout << "Introduce una opcion: ";
        cin >> opcion;
        if(opcion == 1){solucionesReinas();}
        else if(opcion == 2){SolucionReina();}
        else if(opcion == 3){reinasLasVegas();}
    }

    return 1;
}