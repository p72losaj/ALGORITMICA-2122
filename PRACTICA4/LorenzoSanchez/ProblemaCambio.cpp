/**
 * Fichero que realiza las funcionalidades del problema del cambio
 * Realizado por Jaime Lorenzo Sanchez
 * */

// Incluimos la biblioteca Moneda.hpp

#include "ProblemaCambio.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

const int infinito = numeric_limits<int>::max(); //Máximo valor que puede almacenar un Int.

using namespace std;

void ProblemaCambio(){
    SolucionParcialCambio s; // creamos una solucionParcial
    std::vector<Divisa> vector; // Creamos un vector de divisas
    std::vector<SolucionParcialCambio> solucion; // Creamos un vector de cambios
    // Leemos el fichero de texto SistemaMonetario.txt
    leerFichero("sistemamonetario.txt",vector);
    // Ordenamos el vector
    ordenarVector(vector);
    if(vector.size() == 0){
        return;
    }
    int N; // Valor para el cambio
    std::cout << "Introduce el valor de n: ";
    cin >> N;
    while (N < 0){
        std::cout << "El valor introducido es inferior a 0"<<std::endl;
        std::cout << "Introduce el valor de n: ";
        cin >> N;
    }

    // Creamos una matriz 
    std::vector < std::vector<int> > C (vector.size(),std::vector<int> (N+1)); 
    cambio2(vector,N,C);
    // Obtenemos las soluciones

    seleccionarMonedas(N,vector,C,solucion);

    // Mostramos el cambio

    int cantidadTotal = 0; // cantidad total de monedas/billetes utilizados

    std::cout << "Mostrando el cambio" <<std::endl;

    for(int i=0; i < solucion.size(); i++){
        if(solucion[i].getCantidadSolucionParcial() != 0){
            // Obtenemos el numero de billetes de 500 euros
            if(vector[i].getValorDivisa() ==  50000){
                std::cout << "Numero de billetes de 500 euros: " << solucion[i].getCantidadSolucionParcial() << std::endl;
            }
            // Obtenemos el numero de billetes de 200 euros
            else if(vector[i].getValorDivisa() == 20000){
                std::cout << "Numero de billetes de 200 euros: " << solucion[i].getCantidadSolucionParcial() << std::endl;
            }
            // Obtenemos el numero de billetes de 100 euros
            else if(vector[i].getValorDivisa() == 10000){
                std::cout << "Numero de billetes de 100 euros: " << solucion[i].getCantidadSolucionParcial() << std::endl;
            }
            // Obtenemos el numero de billetes de 50 euros
            else if(vector[i].getValorDivisa() == 5000){
                std::cout << "Numero de billetes de 50 euros: " << solucion[i].getCantidadSolucionParcial() << std::endl;
            }
            // Obtenemos el numero de billetes de 20 euros
            else if(vector[i].getValorDivisa() == 2000){
                std::cout << "Numero de billetes de 20 euros: " << solucion[i].getCantidadSolucionParcial() << std::endl;
            }
            // Obtenemos el numero de billetes de 10 euros
            else if(vector[i].getValorDivisa() == 1000){
                std::cout << "Numero de billetes de 10 euros: " << solucion[i].getCantidadSolucionParcial() << std::endl;
            }
            // Obtenemos el numero de billetes de 5 euros
            else if(vector[i].getValorDivisa() == 500){
                std::cout << "Numero de billetes de 5 euros: " << solucion[i].getCantidadSolucionParcial() << std::endl;
            }
            // Obtenemos el numero de monedas de 2 euros
            else if(vector[i].getValorDivisa() == 200){
                std::cout << "Numero de monedas de 2 euros: " << solucion[i].getCantidadSolucionParcial() << std::endl;
            }
            // Obtenemos el numero de monedas de 1 euro
            else if(vector[i].getValorDivisa() == 100){
                std::cout << "Numero de monedas de 1 euro: " << solucion[i].getCantidadSolucionParcial() << std::endl;
            }
            // Obtenemos el numero de monedas de 50 centimos
            else if(vector[i].getValorDivisa() == 50){
                std::cout << "Numero de monedas de 50 centimos: " << solucion[i].getCantidadSolucionParcial() << std::endl;
            }
            else if(vector[i].getValorDivisa() == 40){
                cout << "Numero de monedas de 40 centimos: " << solucion[i].getCantidadSolucionParcial()<<endl;
            }
            // Obtenemos el numero de monedas de 20 centimos
            else if(vector[i].getValorDivisa() == 20){
                std::cout << "Numero de monedas de 20 centimos: " << solucion[i].getCantidadSolucionParcial() << std::endl;
            }
            // Obtenemos el numero de monedas de 10 centimos
            else if(vector[i].getValorDivisa() == 10){
                std::cout << "Numero de monedas de 10 centimos: " << solucion[i].getCantidadSolucionParcial() << std::endl;
            }
            // Obtenemos el numero de monedas de 5 centimos
            else if(vector[i].getValorDivisa() == 5){
                std::cout << "Numero de monedas de 5 centimos: " << solucion[i].getCantidadSolucionParcial() << std::endl;
            }
            // Obtenemos el numero de monedas de 4 centimos
            else if(vector[i].getValorDivisa() == 4){
                cout << "Numero de monedas de 4 centimos: " << solucion[i].getCantidadSolucionParcial()<<endl;
            }
            // Obtenemos el numero de monedas de 2 centimos
            else if(vector[i].getValorDivisa() == 2){
                std::cout << "Numero de monedas de 2 centimos: " << solucion[i].getCantidadSolucionParcial() << std::endl;
            }
            // Obtenemos el numero de monedas de 1 centimo
            else if(vector[i].getValorDivisa() == 1){
                std::cout << "Numero de monedas de 1 centim: " << solucion[i].getCantidadSolucionParcial() << std::endl;
            }
            cantidadTotal += solucion[i].getCantidadSolucionParcial();
        }        
    }
    // Mostramos el numero total de monedas
    std::cout << "Numero total de monedas: " << cantidadTotal << std::endl;

}

void ordenarVector(vector<Divisa> &vector){sort(vector.begin(),vector.end(), Divisa::compararValorDivisa);}

void leerFichero(string nombre, vector<Divisa> &vector){
    Divisa divisa; // Clase divisa
    ifstream fichero;
    fichero.open(nombre.c_str(),ios::in);
    string tipo;
    int valor = 0;
    if(fichero.is_open()){
        while(!fichero.eof()){
        fichero >> valor;
        divisa.setValorDivisa(valor);
        fichero >> tipo;
        divisa.setTipoDivisa(tipo);
        vector.push_back(divisa);
        }
    }
    else{
        cout << "Fichero" << nombre << " no encontrado" << endl;   
    }
}

void seleccionarMonedas(int N, std::vector<Divisa> &vector,std::vector < std::vector <int> > &matriz, std::vector<SolucionParcialCambio> &solucion){
    // Obtenemos los valores de las monedas/billetas y la cantidad de monedas inicial de cada moneda/billete
    for(int i=0; i < vector.size(); i++){
        SolucionParcialCambio s; // Creamos una posible solucion vacia
        s.setValorSolucionParcial(vector[i].getValorDivisa());
        s.setCantidadSolucionParcial(0);
        solucion.push_back(s);
    }

    int i= matriz.size()-1;
    int j = matriz[i].size()-1;
    
    while(j != 0){
        if( (i != 0) && ( matriz[i][j] == matriz[i-1][j] ) ){
            i = i-1;
        }
        else{
            if( ( j - vector[i].getValorDivisa() ) < 0){i = i-1;}
            // Aumentamos en 1 el numero de monedas del tipo de moneda
            solucion[i].setCantidadSolucionParcial(solucion[i].getCantidadSolucionParcial() + 1);
            // Pasamos a ver el elemento matriz[i][j-vector(i)]
            j = j - vector[i].getValorDivisa();
        }
    }
    
}

void cambio2(std::vector<Divisa> &vector, int N, std::vector < std::vector <int> > &matriz){
    
    for(int i=0; i < vector.size()-1; i++){
        matriz[i][0] = 0;
    }

    for(int i = 1; i < vector.size(); i++){
        for(int j=1; j <= N; j++){
            if( (i==1) && (j < vector[i-1].getValorDivisa())){
                matriz[i][j] = infinito;
            }
            else{
                if(i==1){
                    matriz[i][j] = 1 + (matriz[i][j-vector[i].getValorDivisa()]);
                }
                else{
                    if(j < vector[i].getValorDivisa()){
                        matriz[i][j] = matriz[i-1][j];
                    }
                    else{
                        int valor1 = matriz[i-1][j];
                        int valor2 = 1 +  matriz[i][j-vector[i].getValorDivisa()];
                        if(valor1 < valor2 ) matriz[i][j] = valor1;
                        else if(valor2 < valor1) matriz[i][j] = valor2;
                    }
                }
            }
        }
    }
}