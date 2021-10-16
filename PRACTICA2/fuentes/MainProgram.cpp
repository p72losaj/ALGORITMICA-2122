/*
    Programa principal
    Realizado por Jaime Lorenzo Sanchez
*/

// Biblioteca MainProgram

#include "MainProgram.hpp"

/**
 * Funcion principal del programa
*/

int main(){
    
    // Inicializador de la semilla aleatoria
    
    srand(time(NULL)); 
    // Variable que gestiona la operacion que desee realizar el usuario

    int opcion = 1;
    /*
        Mostramos un menu con las siguientes opciones
        1- void ordenacionQuickSort()
        2- void ordenacionFusion()
    */
    while(opcion != 0){
        std::cout << "MENU DE OPERACIONES" << endl;
        std::cout << "1- void ordenacionQuickSort() " << endl;
        std::cout << "2- void ordenacionFusion() " << endl;
        std::cout << "0. Salir " << endl;
        std::cout << "Elige una opcion " << endl;
        cin >> opcion;
        switch(opcion){
        case 1:
            ordenacionQuickSort();
        break;
        case 2:
            //ordenacionFusion();
        break;
        }
    }

   
}