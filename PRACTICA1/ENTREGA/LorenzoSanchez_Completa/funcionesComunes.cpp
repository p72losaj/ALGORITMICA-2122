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

    fichero << "Numero Elementos\tMedia de tiempos reales"<<std::endl;

    // Rellenamos el fichero

    for(int i=0; i< tiemposReales.size(); i++){
        fichero << numeroElementos[i] << "\t"<<tiemposReales[i]<<std::endl;
    }

    // Cerramos el fichero

    fichero.close();
}

// Funcion que crea el fichero de tiempos estimados

void escribeFicheroTiemposEstimados(string nombreFichero, 
std::vector<double> &numeroElementos, std::vector<double> &tiemposReales, 
std::vector<double> &tiemposEstimados){

    // Creamos el fichero de texto

    std::ofstream fichero(nombreFichero);

    // Creamos las columnas del fichero de texto

    fichero << "Tamano Ejemplar\tTiempo Real\tTiempos Estimados"<<std::endl;

    // Rellenamos el fichero

    for(int i=0; i< tiemposReales.size(); i++){
        fichero << numeroElementos[i] << "    "<<tiemposReales[i]<< "  " << tiemposEstimados[i] << std::endl;
    }

    
    // Cerramos el fichero

    fichero.close();    
}

// Funcion sumatorio

double sumatorio(const vector<double> n, const vector <double> t, int expN, int expT){
    double suma = 0.0;
    for(int i=0; i<n.size();i++){
        // Suma de las variables n con sus exponentes expN
        double sumaN = pow(n[i], expN);
        // Suma de las variables t con sus exponentes expT
        double sumaT = pow(t[i], expT);
        // Realizamos el sumatorio general de un polinomio
        suma = suma + sumaN * sumaT;
    }
    // Retornamos el valor del sumatorio
    return suma;
}

/**
    Funcion que ajusta un  polinomio de tipo: t(n) =a0 + a1*n + a2*n²
    @param numeroElementos Vector que almacena los numeros de elementos de un vector
    @param tiemposReales Vector que almacena los tiempos de ordenacion por seleccion de un vector
    @param a Vector que almacena los coeficientes del polinomio (a0, a1, a2)
*/

void ajustePolinomico(const vector <double> &numeroElementos, const vector <double> &tiemposReales, vector <double> &a){

    // t(n) =a0 + a1*n + a2*n²

    // Creamos la matriz A del sistema de ecuaciones ( la matriz sera de 3x3 )

    std::vector< std::vector<double> > matrizA (3, std::vector <double>(3) ); // A = [a2,a1,a0]

    // Creamos la matriz B del sistema de ecuaciones ( la matriz sera de 3x1 )

    std::vector< std::vector<double> > matrizB (3, std::vector <double>(1) ); // 

    // Creamos la matriz solucion ( la matriz sera de 3x1 )

    std::vector <std::vector<double> > matrizX (3,std::vector <double> (1));

    // Recorremos filas de A

    for(int i=0; i < matrizA.size(); i++){
        
        // Recorremos columnas de A
        
        for(int j=0; j < matrizA.size(); j++){
            
            // En la posicion A[0][0] almacenamos el numero de elementos del algoritmo

            if(i==0 && j==0){ matrizA[i][j] = numeroElementos.size(); }

            // Rellenamos la matriz A aplicando la funcion de sumatorio de un polinomio

            else{ matrizA[i][j] = sumatorio(numeroElementos, tiemposReales,i+j,0);}

        }
    }

    // Recorremos las filas de la matriz B

    for(int i=0; i < matrizB.size(); i++){
    
        // Rellenamos los elementos de la matriz B aplicando la funcion de sumatorio de un polinomio

        matrizB[i][0] = sumatorio(numeroElementos, tiemposReales,i,1);

    }

    // Resolvemos el sistema de ecucaciones
    
    resolverSistemaEcuaciones(matrizA, matrizB, matrizA.size(),matrizX);

    // Recorremos las filas de la matriz solucion del sistema de ecuaciones

    for(int i=0; i<  matrizX.size(); i++){

        // Almacenamos en el vector de coeficientes las soluciones del sistema de ecuaciones

        a[i] = matrizX [i][0];
    }

}

// Funcion que calcula los tiempos estimados de un polinomio

void calcularTiemposEstimadosPolinomico(const vector <double> &numeroElementos,
const vector <double> &a, vector <double> &tiemposEstimados){
    
    // Recorremos los elementos del algoritmo
    
    for(int i=0; i < numeroElementos.size();  i++){
        // Obtenemos el valor estimado de cada elemento del algoritmo

        double valor = a[0] + a[1] * numeroElementos[i] + a[2] * pow(numeroElementos[i],2);

        // Almacenamos el valor estimado

        tiemposEstimados.push_back(valor);
    }
}

// Tiempo estimado de un polinomio de un tamano dado por el usuario

double calcularTiempoEstimadoPolinomico(const vector<double> &n, vector <double> &a){
    
    // Creamos una variable para el calculo del tiempo estimado del polinomio
    
    double valor = 0.0;

    // Recorremos el numero de elementos del algoritmo

    for(int i=0; i < n.size(); i++){
        // t(n) = a0+a1*n1 +a2*n2^2

        // Obtenemos el tiempo estimado del polinomio en milisegundos

        valor = valor + a[0] + a[1] * n[i] + a[2] * pow(n[i],2);
    }

    // Retornamos el tiempo estimado del polinomio

    return valor;
}

// Coeficiente de determinacion del polinomio

double calcularCoeficienteDeterminacion(const vector <double> &tiemposReales, 
const vector <double> &tiemposEstimados){

    // Varianza real del polinomio

    double varianza_real = 0.0; 
    
    // Varianza estimada del polinomio

    double varianza_estimada = 0.0;

    // Media real del polinomio

    double media_real = 0.0;
    
    // Media estimada del polinomio

    double media_estimada = 0.0;

    // Calculamos la media real del polinomio

    media_real = media(tiemposReales);

    // Calculamos la media estimada del polinomio

    media_estimada = media(tiemposReales);

    // Calculamos la varianza real del polinomio

    varianza_real = varianza(tiemposReales, media_real);

    // Calculamos la varianza estimada del polinomio

    varianza_estimada = varianza(tiemposEstimados, media_estimada);

    // Retornamos el coeficiente de determinacion del polinomio

    return varianza_estimada / varianza_real;
}

// Funcion que calcula la varianza de un vector

double varianza(std::vector<double> vector, double media){

    // Sumatorio de la ecuacion de la varianza

    double sumatorio = 0.0;

    // Recorremos los elementos del vector

    for(int i=0; i < vector.size(); i++){
        
        // Calculamos el valor sumatorio de la ecuacion de la varianza

        sumatorio = sumatorio + pow((vector[i]-media),2);

    }

    // Calculamos la varianza del vector

    double var = sumatorio / vector.size();

    // Retornamos la varianza del vector

    return var;
}

// Funcion que calcula la media de los elementos de un vector

double media(std::vector<double> vector){
    // Sumatorio de la media de los elementos del vector

    double suma = 0.0;

    // Recorremos los elementos del vector

    for(int i=0; i < vector.size(); i++){
        // Calculamos la suma de los elementos del vector
        suma = suma + vector[i];
    }
    // Calculamos la media de los elementos del vector

    double media = suma / vector.size();

    // Retornamos el valor medio de los elementos del vector

    return media;
}


