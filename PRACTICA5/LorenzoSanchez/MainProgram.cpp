// Funcion principal
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n = 0; // Numero de reinas
    while(n < 2){
        cout << "Introduce el numero de reinas: ";
        cin >> n;
        if(n  < 2){
            cout << "Introduce al menos 2 reinas"<<endl;
        }
    }
    std::vector<std::vector<int>> matriz; // Creamos una matriz vacia
    matriz.resize(n+1,vector<int>(n+1)); // Creamos una matriz de n+1filas,n+1 columnas
    int opcion = -1;
    while(opcion != 0){
        cout << "############################"
        cout << "MENU DE OPCIONES OBLIGATORIAS"<<endl;
        cout << "1. METODO BACKTRACKING PARA OBTENER SOLUCIONES"<<endl;
        cout << "2. METODO BACKTRACKING PARA OBTENER UNA SOLUCION"<<endl;
        cout << "3. ALGORITMO LAS VEGAS" << endl;
        cout << "############################"
        cout << "Introduce una opcion: " << endl;
        cin >> opcion;
    }
    return 0;
}