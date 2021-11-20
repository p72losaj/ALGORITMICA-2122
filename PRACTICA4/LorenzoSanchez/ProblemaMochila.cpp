/**
 * Funciones que realizan el algoritmo voraz para la resolucion del problema de la mochila
 * Realizado por Jaime Lorenzo Sanchez
 * */

#include "ProblemaMochila.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

void ProblemaMochila(){
    // Creamos un vector de materiales
    vector<Materiales> materiales;
    // Leemos el fichero de texto 
    leerFichero("materialesmochila.txt",materiales);
    // Ordenamos el vector de materiales de la mochila en funcion del volumen
    ordenarVector(materiales);
    std::cout << "#####################"<<endl;
    std::cout << "Mostrando el vector ordenado"<<endl;
    for(int i=0; i < materiales.size(); i++){
        std::cout << materiales[i].getEtiquetaMaterial()<<","<<materiales[i].getVolumenMaterial()<<","<<materiales[i].getPrecioMaterial()<<endl;
    }
    std::cout << "#####################"<<endl;
    // Volumen total de la mochila
    int volumenTotal;
    // Pedimos el volumen total de la mochila
    cout << "Introduce el volumen total de la mochila: ",
    cin >> volumenTotal;
    // El volumen total debe ser superior a 0
    while(volumenTotal < 1){
        cout << "El volumen total de la mochila debe ser superior a 0"<<endl;
        // Pedimos de nuevo el volumen total de la mochila
        cout << "Introduce el volumen total de la mochila: ",
        cin >> volumenTotal;
    }

    std::cout << "#####################"<<endl;

    // Creamos la matriz

    std::vector < std::vector<int> > C (materiales.size()+1,std::vector<int> (volumenTotal+1)); 

    crearMatriz(materiales,volumenTotal,C);

    cout << "Mostrando la matriz"<<endl;
    std::cout << "#####################"<<endl;
    // Mostramos la matriz

    for(int i=0; i < materiales.size(); i++){
        // para j de 1 a N hacer
        for(int j=0; j <= volumenTotal; j++){
            std::cout <<C[i][j] << " ";
        }
        std::cout << "" << endl;
    }
    std::cout << "#####################"<<endl;
    // Creamos un vector de enteros

    std::vector<int> uso;
    uso.resize(materiales.size()); // Tamano del vector
    // Obtenemos la solucion

    obtenerObjetos(volumenTotal,materiales,C,uso);

    // Imprimimos la solucion
    std::cout << "Mostrando la solucion" << std::endl;
    int precioFinal = 0;
    int resto = volumenTotal;
    for(int i=0; i < materiales.size(); i++){
        if(uso[i] == 1){
            // Uso total del volumen del material
            if(resto >= materiales[i].getVolumenMaterial()){
                // Usamos todo el volumen del material
                std::cout << "El material " << materiales[i].getEtiquetaMaterial() << " ha utilizado todo su volumen: " << materiales[i].getVolumenMaterial()<<endl;
                // Disminuimos la capacidad restante de la mochila
                resto -= materiales[i].getVolumenMaterial();
                precioFinal += (materiales[i].getPrecioMaterial()*materiales[i].getVolumenMaterial() ) ;
            }
            else{
                // Almacenamos en la mochila el volumen que queda disponible en la mochila
                std::cout << "El material " << materiales[i].getEtiquetaMaterial() << " ha utilizado un volumen parcial: " << resto<<endl;
                precioFinal += (materiales[i].getPrecioMaterial()*resto ) ;
                // La mochila no tiene volumen disponible
                resto = 0;
            }
        }
    }
    
    // Imprimimos el precio final de la mochila

    std:: cout << "El precio final de la mochila es: " << precioFinal << endl;
    
}

// Funcion que crea la matriz

void crearMatriz(std::vector<Materiales> &vector, int V, std::vector < std::vector <int> > &matriz){
    for(int i=0; i <= V; i++) matriz[0][i] = 0;
    for(int i=0; i <= vector.size(); i++) matriz[0][i] = 0;
    for(int i=1; i < vector.size(); i++){
        for(int j=0; j <= V; j++){
            if(j < vector[i].getVolumenMaterial()) matriz[i][j] = matriz [i-1][j];
            else{
                int valor1 = matriz[i-1][j];
                // D(i).precio ∗ D(i).volumen + C(i − 1, j −D(i).volumen
                int valor2 = (vector[i].getPrecioMaterial() * vector[i].getVolumenMaterial());
                valor2 = valor2 + matriz[i-1][j-vector[i].getVolumenMaterial()];
                if(valor1 > valor2) matriz[i][j] = valor1;
                else if(valor2 > valor1) matriz[i][j] = valor2;
            }
        }
    }
}

// Funcion que obtiene la solucion

void obtenerObjetos(int V,std::vector<Materiales> &vector,std::vector < std::vector <int> > &matriz,std::vector<int> &uso){
    int j = V; 
    for(int i = vector.size()-1; i > 0; i--){
        // No se usa el material
        if(matriz[i][j] == matriz[i-1][j]){
            uso[i] == 0;
        }
        // Usamos el objeto
        else{
            uso[i] = 1;            
            j = j - vector[i].getVolumenMaterial();
            
        }
    }
}

// Funcion de ordenacion del vector

void ordenarVector(vector<Materiales> &vector){sort(vector.begin(),vector.end(), Materiales::compararVolumenMateriales);}

// Funcion de lectura del fichero

void leerFichero(string nombre, vector<Materiales> &vector){
    // Creamos un material vacio
    Materiales material;
    // Creamos un fichero
    ifstream fichero;
    string etiqueta; // Etiqueta del material
    string volumen; // Volumen del material
    string precio; // Precio del material
    char delimitador = ' '; // Delimitador de los datos de cada linea
    fichero.open(nombre.c_str(),ios::in); // Abrimos el fichero de texto en formato lectura
    // Comprobamos si el fichero se ha abierto
    if(fichero.is_open()){
        // Leemos las lineas del fichero
        while(!fichero.eof()){
            // Obtenemos la etiqueta del material
            getline(fichero,etiqueta,delimitador);
            // Almacenamos la etiqueta del material
            material.setEtiquetaMaterial(stoi(etiqueta));
            // Obtenemos el volumen del material
            getline(fichero,volumen, delimitador);
            // Almacenamos el volumen del material
            material.setVolumenMaterial(stoi(volumen));
            // Obtenemos el precio por unidad de volumen del material
            getline(fichero,precio);
            // Almacenamos el precio por unidad de volumen del material
            material.setPrecioMaterial(stoi(precio));
            // Almacenamos los datos del material en el vector de materiales
            vector.push_back(material);
        }
    }
    // Caso de error: No se ha abierto el fichero
    else{
        cout<<"Se ha producido un error al abrir el fichero <" << nombre << "> en modo lectura" << endl;
    }
}