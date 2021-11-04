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

using namespace std;

void ProblemaCambio(){
    SolucionParcialCambio s; // creamos una solucionParcial
    std::vector<Divisa> vector; // Creamos un vector de divisas

    std::vector<SolucionParcialCambio> solucion; // Creamos un vector de cambios
    // Leemos el fichero de texto SistemaMonetario.txt
    leerFichero("sistemamonetario.txt",vector);
    // Ordenamos el vector
    ordenarVector(vector);
    int n; // Valor para el cambio
    std::cout << "Mostrando los datos del fichero sistemamonetario.txt ordenados" << std::endl;
    for(int i=0; i < vector.size(); i++){
        std::cout << vector[i].getValorDivisa()<<";"<<vector[i].getTipoDivisa()<<std::endl;
    }
    std::cout << "Introduce el valor de n: ";
    cin >> n;
    while (n < 1){
        std::cout << "El valor introducido es inferior a 1"<<std::endl;
        std::cout << "Introduce el valor de n: ";
        cin >> n;
    }
    
    int suma = 0; // Suma parcial
    int cantidad = 0; // Numero de cantidades de la moneda o del billete
    int i = 0; // Posicion del vector de divisa
    std::cout << "Realizando cambio" << std::endl;
    int resto = n;
    while(resto>0){
        int x = vector[i].getValorDivisa(); // Obtenemos el valor de la divisa en la posicion i del vector
        while(suma + x <= resto){
            cantidad ++;
            suma += x; 
        }
        resto -= cantidad * x;
        s.setValorSolucionParcial(x);
        s.setCantidadSolucionParcial(cantidad);
        // Anadimos la solucion parcial al vector de soluciones
        solucion.push_back(s);
        i++;
        cantidad = 0; // El numero de cantidades es 0
        suma = 0;
    }
    int cantidadTotal = 0; // Numero total de monedas
    // Imprimimos la solucion
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
            // Obtenemos el numero de monedas de 2 centimos
            else if(vector[i].getValorDivisa() == 2){
                std::cout << "Numero de monedas de 2 centimos: " << solucion[i].getCantidadSolucionParcial() << std::endl;
            }
            // Obtenemos el numero de monedas de 1 centimo
            else if(vector[i].getValorDivisa() == 1){
                std::cout << "Numero de monedas de 1 centim: " << solucion[i].getCantidadSolucionParcial() << std::endl;
            }
            // std::cout << "Valor de la divisa en centimos: " << vector[i].getValorDivisa() << "; Tipo de la divisa: " << vector[i].getTipoDivisa() + ";Cantidad: " << solucion[i].getCantidadSolucionParcial() << std::endl;
            cantidadTotal += solucion[i].getCantidadSolucionParcial();
        }        
    }
    // Mostramos el numero total de monedas
    std::cout << "Numero total de monedas: " << cantidadTotal << std::endl;
}

void ordenarVector(vector<Divisa> &vector){
   sort(vector.begin(),vector.end(), Divisa::compararValorDivisa);
}

void leerFichero(string nombre, vector<Divisa> &vector){
    Divisa divisa; // Clase divisa
    ifstream fichero;
    string valor,tipo;
    char delimitador = ' '; // Delimitador de los datos de cada linea
    fichero.open(nombre.c_str(),ios::in); // Abrimos el fichero de texto en formato lectura
    // Comprobamos si el fichero se ha abierto
    if(fichero.is_open()){
        // Leemos todas las lineas del fichero
        while(!fichero.eof()){
            // Obtenemos el valor de la divisa almacenada en el fichero
            getline(fichero,valor,delimitador);
            // Almacenamos el valor de la divisa
            divisa.setValorDivisa(stoi(valor));
            // Obtenemos el tipo de la divisa almacenada en el fichero
            getline(fichero,tipo);
            // Almacenamos el tipo de la divisa
            divisa.setTipoDivisa(tipo);
            vector.push_back(divisa); // Anadimos la divisa al vector
        }
    }
    // fichero no abierto
    else{
        cout << "El fichero" << nombre << " no existe o no tiene permisos para abrirlo" << std::endl;
    }
}