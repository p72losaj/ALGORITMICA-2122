/**
 * Funciones comunes de los 3 algoritmos
 * Realizado por Jaime Lorenzo Sanchez
 * */

// Biblioteca de funciones comunes

#include "funcionesComunes.hpp"

/*
    Creacion del fichero de tiempos de ordenacion de un vector
*/

void escribeFicheroTiemposReales(string nombre,std::vector<double> &numeroElementos,
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

// Funcion que crea el fichero de texto final de la funcion de OrdenacionSeleccion

void escribeFicheroTiemposEstimados(string nombreFichero, 
std::vector<double> &numeroElementos, std::vector<double> &tiemposReales, 
std::vector<double> &tiemposEstimados){
    // Creamos el fichero de texto

    std::ofstream fichero(nombreFichero);

    // Creamos las columnas del fichero de texto

    fichero << "Tamano Ejemplar  Tiempo Real    Tiempos Estimados"<<std::endl;

    // Rellenamos el fichero

    for(int i=0; i< tiemposReales.size(); i++){
        fichero << numeroElementos[i] << "    "<<tiemposReales[i]<< "  " << tiemposEstimados[i] << std::endl;
    }

    
    // Cerramos el fichero

    fichero.close();    
}

// Funcion sumatorio

double sumatorio(const vector<double> n, const vector <double> t, int expN, int expT){
    double res = 0.0;
    for(int i=0; i<n.size();i++){
        res = res + pow(n[i], expN) * pow(t[i], expT);
    }
    return res;
}

// Funcion rellenarVector

void rellenarVector(vector<int> &v){
    int valor;
    for(size_t i=0; i < v.size(); i++){
        valor = rand()%9999999;
        v[i] = valor;
    }
}

// Funcion estaOrdenado

bool estaOrdenado(const vector <int> &v){
    for(size_t i=0; i < v.size()-1; i++){
        if(v[i] > v[i+1]){
            return false;
        }
    }
    return true;
}

/**
    Funcion que ajusta un  polinomio de tipo: t(n) =a0 + a1*n + a2*n²
    @param numeroElementos Vector que almacena los numeros de elementos de un vector
    @param tiemposReales Vector que almacena los tiempos de ordenacion por seleccion de un vector
    @param a Vector que almacena los coeficientes del polinomio (a0, a1, a2)
*/

void ajustePolinomico(const vector <double> &numeroElementos, const vector <double> &tiemposReales, vector <double> &a){

    // t(n) =a0 + a1*n + a2*n²

    // Creamos la matriz A del sistema de ecuaciones

    std::vector< std::vector<double> > matrizA (3, std::vector <double>(3) ); // A = [a2,a1,a0]

    // Creamos la matriz B del sistema de ecuaciones

    std::vector< std::vector<double> > matrizB (3, std::vector <double>(1) ); // 

    // Creamos la matriz X ( solucion)

    std::vector <std::vector<double> > matrizX (3,std::vector <double> (1));

    // Recorremos filas de A
    for(int i=0; i < matrizA.size(); i++){
        // Recorremos columnas de A
        for(int j=0; j < matrizA.size(); j++){
            if(i==0 && j==0){
                matrizA[i][j] = numeroElementos.size();
            }
            else{
                matrizA[i][j] = sumatorio(numeroElementos, tiemposReales,i+j,0);
            }
        }
    }

    // Rellenamos la matriz B

    for(int i=0; i < matrizB.size(); i++){
       matrizB[i][0] = sumatorio(numeroElementos, tiemposReales,i,1);
    }

    // Resolvemos el sistema de ecucaciones
    
    resolverSistemaEcuaciones(matrizA, matrizB, matrizA.size(),matrizX);

    // Almacenamos en la matriz X las soluciones del sistema de ecuaciones

    for(int i=0; i<  matrizX.size(); i++){
        a[i] = matrizX [i][0];
    }

}

// Funcion que calcula los tiempos estimados de un polinomio

void calcularTiemposEstimadosPolinomico(const vector <double> &numeroElementos,
const vector <double> &a, vector <double> &tiemposEstimados){
    for(int i=0; i < numeroElementos.size();  i++){
        double valor = a[0] + a[1] * numeroElementos[i] + a[2] * pow(numeroElementos[i],2);
        tiemposEstimados.push_back(valor);
    }
}

// Tiempo estimado de un polinomio

double calcularTiempoEstimadoPolinomico(const vector<double> &n, vector <double> &a){
    double valor = 0.0;
    for(int i=0; i < n.size(); i++){
        // t(n) = a0+a1*n1 +a2*n2^2
        valor = valor + a[0] + a[1] * n[i] + a[2] * pow(n[i],2);
    }
    return valor;
}

// Coeficiente de determinacion del polinomio

double calcularCoeficienteDeterminacion(const vector <double> &tiemposReales, 
const vector <double> &tiemposEstimados){
    double varianza_real = 0.0, varianza_estimada = 0.0;
    double media_real = 0.0, media_estimada = 0.0;
    media_real = media(tiemposReales);
    media_estimada = media(tiemposReales);
    varianza_real = varianza(tiemposReales, media_real);
    varianza_estimada = varianza(tiemposEstimados, media_estimada);

    return varianza_estimada / varianza_real;
}

// Calculo de la varianza

double varianza(std::vector<double> vector, double media){
    double var = 0.0;
    for(int i=0; i < vector.size(); i++){
        var = var + pow((vector[i]-media),2);
    }
    var = var / vector.size();
    return var;
}

// Calculo de la media

double media(std::vector<double> vector){
    double suma = 0.0;
    for(int i=0; i < vector.size(); i++){
        suma = suma + vector[i];
    }
    suma = suma / vector.size();
    return suma;
}


