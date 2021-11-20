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
    std::cout << "Mostrando el vector de materiales ordenado de mayor a menor por el precio del material"<<endl;
    for(int i=0; i < materiales.size(); i++){
        cout << "Etiqueta: " << materiales[i].getEtiquetaMaterial() << ";Volumen: " << materiales[i].getVolumenMaterial() << ";Precio/UnidadVolumen: " << materiales[i].getPrecioMaterial()<<endl;
    }
    // Aplicamos el algoritmo voraz de la mochila

    // Numero de materiales que se introduciran en la mochila
    int n = materiales.size();
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
    // Almacenamos en una variable el volumen de la mochila
    int resto = volumenTotal;
    // Inicialmente no se ha utilizado ningun material
    for(int i=0; i < materiales.size(); i++){
        materiales[i].setVolumenUtilizado(0);
    }
    bool materialDisponible = true;
    while(resto != 0 || materialDisponible == false){
        // Precio del material maximo
        int precioMaximo = 0;
        // Posicion del material maximo
        int materialMaximo = 0;
        // Material no disponible
        materialDisponible = false;
        // Recorremos el vector de materiales
        for(int i=0; i < materiales.size(); i++){
            // Material no utilizado
            if(materiales[i].getVolumenUtilizadoMaterial() == 0 ){
                // El material esta disponible
                materialDisponible = true;
                // Comprobamos si el precio del material es superior al precio maximo
                if(materiales[i].getPrecioMaterial() > precioMaximo){
                    // El precio del material maximo sera el precio del material
                    precioMaximo = materiales[i].getPrecioMaterial();
                    // Obtenemos la posicion del material maximo
                    materialMaximo = i;
                }
            }
        }
        // Comprobamos si el material de maximo coste cabe en la mochila
        if(materialDisponible == true){
            // El volumen restante de la mochila es superior al volumen del material maximo
            if(resto >= materiales[materialMaximo].getVolumenMaterial()){
                // Usamos todo el volumen del material
                materiales[materialMaximo].setVolumenUtilizado(materiales[materialMaximo].getVolumenMaterial());
                // Disminuimos la capacidad restante de la mochila
                resto -= materiales[materialMaximo].getVolumenUtilizadoMaterial();
            }
            else{
                // Almacenamos en la mochila el volumen que queda disponible en la mochila
                materiales[materialMaximo].setVolumenUtilizado(resto);
                // La mochila no tiene volumen disponible
                resto = 0;
            }
        }
    }
    int precioFinal = 0; // Precio final de la mochila
    cout << "Mostrando el volumen empleado de los materiales" << endl;
    // Recorremos la lista de materiales
    for(int i=0; i < materiales.size(); i++){
        // El material forma parte de la solucion
        if(materiales[i].getVolumenUtilizadoMaterial() != 0){
            // Actualizamos el precio final de la mochila

            // Precio final = precio final + (precioMaterial/volumen * volumenUtilizado)

            precioFinal += (materiales[i].getPrecioMaterial()*materiales[i].getVolumenUtilizadoMaterial() ) ;

            // Se ha empleado todo el volumen del material
            if(materiales[i].getVolumenUtilizadoMaterial() == materiales[i].getVolumenMaterial()){
                cout << "El material de etiqueta <" << materiales[i].getEtiquetaMaterial() 
                << "> ha utilizado todo su volumen. Ha utilizado un volumen <" 
                << materiales[i].getVolumenUtilizadoMaterial() 
                << "> de su volumen total <" << materiales[i].getVolumenMaterial() << ">" << endl;
            }
            // Se ha empleado un volumen parcial del material
            else{
                cout << "El material de etiqueta <" << materiales[i].getEtiquetaMaterial()
                << "> ha utilizado un volumen parcial de su volumen total. Ha utilizado un volumen <"
                << materiales[i].getVolumenUtilizadoMaterial() << "> de su volumen total <"
                << materiales[i].getVolumenMaterial() << ">" << endl;
            }
        }
    }
    // Mostramos el precio final de la mochila
    cout << "El precio final de la mochila ha sido: " << precioFinal << endl;
}

// Funcion de ordenacion del vector

void ordenarVector(vector<Materiales> &vector){
    sort(vector.begin(),vector.end(), Materiales::compararVolumenMateriales);
}

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