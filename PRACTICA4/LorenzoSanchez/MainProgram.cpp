/**
 * Fichero que realiza la funcion principal del programa
 * Realizado por Jaime Lorenzo Sanchez
 * */

// Biblioteca principal

#include "MainProgram.hpp"
#include <iostream>

using namespace std;

int main(){
    int opcion = 3;
    while(opcion != 0){
        cout<<"Mostrando funcionalidades disponibles del usuario" << std::endl;
        cout << "0. SALIR" << endl;
        cout << "1. ProblemaCambio()" << std::endl;
        cout << "2. ProblemaMochila()" << endl;
        cout << "##################################################################"<<endl;
        cout << "Introduce una opcion: ";
        cin >> opcion;
        if(opcion == 1){ProblemaCambio();}
        else if(opcion == 2){ProblemaMochila();}
    }

    return 1;
}