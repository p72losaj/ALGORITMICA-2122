#include "algoritmos.hpp"

// Funcion que rellena un vector con valores aleatorios en el rango [0, 9999999]

void rellenarVector(std::vector<int> &v){
    int valor;
    for(size_t i=0; i < v.size(); i++){
        valor = rand()%9999999;
        v[i] = valor;
    }
}

// Algoritmo de ordenacion por seleccion del vector

void seleccion(vector <int> &v){
     for (auto it = v.begin(); it != v.end(); ++it) {
        std::swap(*it, *std::min_element(it, v.end()));
    }
}

// Funcion que comprueba si un vector esta ordenado de menor a mayor

bool estaOrdenado(const vector <int> &v){
    for(size_t i=0; i < v.size()-1; i++){
        if(v[i] > v[i+1]){
            return false;
        }
    }
    return true;
}