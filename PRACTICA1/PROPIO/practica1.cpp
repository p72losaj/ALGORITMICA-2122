/*
    Programa principal
    Realizado por Jaime Lorenzo Sanchez
*/

#include "algoritmos.hpp"

int main(){
    srand(time(NULL)); // Inicializador de la semilla aleatoria
    int opcion = 1;
    /*
        Mostramos un menu con las siguientes opciones
        1- void ordenacionSeleccion();
        2- void productoMatricesCuadradas(); 
        3- void fibonacciRecursivo();
    */
    while(opcion != 0){
        std::cout << "MENU DE OPERACIONES" << endl;
        std::cout << "1- void ordenacionSeleccion(); " << endl;
        std::cout << "2- void productoMatricesCuadradas(); " << endl;
        std::cout << "3- void fibonacciRecursivo(); " << endl;
        std::cout << "0. Salir " << endl;
        std::cout << "Elige una opcion " << endl;
        cin >> opcion;
        switch(opcion){
        case 1:
            ordenacionSeleccion();
        break;
        
        }
    }

   
}