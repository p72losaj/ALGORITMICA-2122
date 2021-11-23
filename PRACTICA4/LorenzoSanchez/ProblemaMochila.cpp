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
    if(materiales.size() == 0)   {
        return;
    }
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
    // Creamos la matriz
    std::vector < std::vector<int> > C (materiales.size()+1,std::vector<int> (volumenTotal+1)); 
    crearMatriz(materiales,volumenTotal,C);
    // Creamos un vector de enteros
    std::vector<int> uso;
    uso.resize(materiales.size()); // Tamano del vector
    // Obtenemos la solucion
    obtenerObjetos(volumenTotal,materiales,C,uso);
    int precioFinal = 0;
    int resto = volumenTotal;
    for(int i=0; i < materiales.size(); i++){
        if(uso[i] == 1){
            // Uso total del volumen del material
            if(resto >= materiales[i].getVolumenMaterial()){
                // Usamos todo el volumen del material
                std::cout << "\tEl material " << materiales[i].getEtiquetaMaterial() << " ha utilizado todo su volumen: " << materiales[i].getVolumenMaterial()<<endl;
                // Disminuimos la capacidad restante de la mochila
                resto -= materiales[i].getVolumenMaterial();
                precioFinal += (materiales[i].getPrecioMaterial()*materiales[i].getVolumenMaterial() ) ;
            }
        }
    }
    
    // Imprimimos el precio final de la mochila

    std:: cout << "El precio final de la mochila es: " << precioFinal << endl;
    
    cout << "#############################################" << endl;
}

// Funcion que crea la matriz

void crearMatriz(std::vector<Materiales> &vector, int V, std::vector < std::vector <int> > &matriz){
    for(int i=0; i <= V; i++) matriz[0][i] = 0;
    for(int i=0; i <= vector.size(); i++) matriz[i][0] = 0;
    for(int i=1; i <= vector.size(); i++){
        for(int j=0; j <= V; j++){
            if(j < vector[i-1].getVolumenMaterial()) matriz[i][j] = matriz [i-1][j];
            else{
                int valor1 = matriz[i-1][j];
                // D(i).precio ∗ D(i).volumen + C(i − 1, j −D(i).volumen
                int valor2 = (vector[i-1].getPrecioMaterial() * vector[i-1].getVolumenMaterial());
                valor2 = valor2 + matriz[i-1][j-vector[i-1].getVolumenMaterial()];
                if(valor1 > valor2) matriz[i][j] = valor1;
                else matriz[i][j] = valor2;
            }
        }
    }
}

// Funcion que obtiene la solucion

void obtenerObjetos(int V,std::vector<Materiales> &vector,std::vector < std::vector <int> > &matriz,std::vector<int> &uso){
    int j = V; 
    for(int i = vector.size(); i > 0; i--){
        // No se usa el material
        if(matriz[i][j] == matriz[i-1][j]){
            uso[i] = 0;
        }
        // Usamos el objeto
        else{
            uso[i-1] = 1;            
            j = j - vector[i].getVolumenMaterial();
        }
    }
}

// Funcion de ordenacion del vector

void ordenarVector(vector<Materiales> &vector){sort(vector.begin(),vector.end(), Materiales::compararVolumenMateriales);}

// Funcion de lectura del fichero


void leerFichero(string nombre, vector<Materiales> &vector){
    Materiales material; // Creamos un material vacio
    ifstream fichero; // Creamos un fichero
    int etiqueta = 0,volumen=0,precio=0;
    fichero.open(nombre.c_str(),ios::in); // Abrimos el fichero de texto en formato lectura
    // Comprobamos si el fichero se ha abierto
    if(fichero.is_open()){
        while(!fichero.eof()){ // Leemos las lineas del fichero
            // Obtenemos la etiqueta del material
            fichero >> etiqueta;
            material.setEtiquetaMaterial(etiqueta);
            // Obtenemos el volumen del material
            fichero >> volumen;
            material.setVolumenMaterial(volumen);
            // Obtenemos el precio por unidad de volumen del material
            fichero >> precio;
            material.setPrecioMaterial(precio);
            // Almacenamos los datos del material en el vector de materiales
            vector.push_back(material);
        }
    }
    // Caso de error: No se ha abierto el fichero
    else{
        cout<<"Se ha producido un error al abrir el fichero <" << nombre << "> en modo lectura" << endl;
    }
}