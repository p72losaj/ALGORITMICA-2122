/**
 * Declaracion de las funcionalidades para la realizacion del problema de la mochila
 * Realizado por Jaime Lorenzo Sanchez
 * */

#ifndef PROBLEMAMOCHILA_HPP
#define PROBLEMAMOCHILA_HPP

#include <string>
#include <vector>

using namespace std;

// Clase de los materiales

class Materiales{
    private:
        int etiqueta; // Etiqueta del material
        int volumen; // Volumen del material
        int precio; // Precio por unidad de volumen
        int volumenUsado; // Volumen utilizado del material
    public:
    // Funcion que obtiene la etiqueta del material
    int getEtiquetaMaterial(){ return this->etiqueta;}
    // Funcion que modifica la etiqueta del material
    void setEtiquetaMaterial(int etiqueta2){ this->etiqueta = etiqueta2;}
    // Funcion que obtiene el volumen del material
    int getVolumenMaterial(){ return this->volumen;}
    // Funcion que modifica el volumen del material
    void setVolumenMaterial(int volumen2){ this->volumen = volumen2;}
    // Funcion que obtiene el precio por unidad de volumen del material
    int getPrecioMaterial(){ return this->precio; }
    // Funcion que modifica el precio por unidad de volumen del material
    void setPrecioMaterial(int precio2){ this->precio = precio2;}
    // Funcion que obtiene el volumen utilizado por el material
    int getVolumenUtilizadoMaterial(){ return this->volumenUsado;}
    // Funcion que modifica el volumen utilizado por un material
    void setVolumenUtilizado(int uso2){ this->volumenUsado = uso2;}
    // Funcion que compara el volumen de 2 materiales
    static bool compararVolumenMateriales(Materiales &a, Materiales &b){return a.precio > b.precio; }
}typedef Materiales;


// Declaracion de la funcion que lee la informacion del fichero de texto

void leerFichero(string nombre, vector<Materiales> &vector);

// Declaracion de la funcion que ordena el vector en funcion del volumen del material

void ordenarVector(vector<Materiales> &vector);

#endif