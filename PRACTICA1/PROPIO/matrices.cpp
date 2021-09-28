#include "algoritmos.hpp"

float ValorAleatorio(int inicio,int fin){
    float valor = (inicio + rand() % (fin-inicio));
    valor = valor / 100;
    return valor;
}

std::vector < std::vector <double> > producto(std::vector < std::vector <double> > matriz1, 
std::vector < std::vector <double> > matriz2, int n){
    // Creamos una matriz resultado vacia
    std::vector < std::vector <double> > res;
    
    // Necesitamos hacer esto por cada columna de la segunda matriz (matriz2)

    for (int a = 0; a < n; a++) {

        // Dentro recorremos las filas de la primera (matriz1)

        for (int i = 0; i < n; i++) {
            
            int suma = 0;

            // Y cada columna de la primera (matriz1)
            
            for (int j = 0; j < n; j++) {
            
                // Multiplicamos y sumamos resultado
            
                suma += matriz1[i][j] * matriz2[j][a];
            
            }

            // Lo acomodamos dentro del producto
            res[i][a] = suma;
        }
    }

    // retornamos la matriz resultado
    return res;
}