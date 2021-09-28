#include "algoritmos.hpp"

/*
    Funcion que crea un fichero donde se almacenan los tiempos de ordenacion de un vector usando el metodo
    de seleccion
*/

void escribeFicheroOrdenacionSeleccion(string nombre,std::vector<double> &numeroElementos,
std::vector<double> &tiemposReales){

    // Creamos el fichero de texto

    std::ofstream fichero(nombre);

    // Creamos las columnas del fichero de texto

    fichero << "Numero Elementos       Media de tiempos reales"<<std::endl;

    // Rellenamos el fichero

    for(int i=0; i< tiemposReales.size(); i++){
        fichero << numeroElementos[i] << "    "<<tiemposReales[i]<<std::endl;
    }

    // Cerramos el fichero

    fichero.close();
}