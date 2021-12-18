#include "reinas.hpp"
#include <cmath>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>

#include "ClaseTiempo.cpp"

using namespace std;

void reinasLasVegas(){
    srand(time(NULL));
    // Numero de reinas
    int n = 0;
    while(n<4){
        cout << "Introduce el numero de reinas: ";
        cin >> n;
        if(n < 4){
            cout << "El algoritmo n-reinas no tiene solucion para un numero de reinas inferior a 4"<<endl;
        }
    }
    Clock tiempo; 
    // Estructura de datos
    Tablero solucion;
    // Contador de numero de veces que se aplica el algoritmo
    int contador = 0;
    // Iniciamos el tiempo
    tiempo.restart();
    bool exito = false;
    while(exito != true){
        contador ++;
        exito = LasVegas(n,solucion);
    }
    // Detenemos el tiempo de ordenacion del vector
    if(tiempo.isStarted()){ tiempo.stop(); }
    // Se ha encontrado una solucion
    if(exito == true){
        cout << "Tiempo utilizado para calcular la solucion: " << tiempo.elapsed() << " microsegundos"<<endl;
        std::cout << "Solucion: [";
        for(int i=1; i < solucion.solucion.size();i++){cout << solucion.solucion[i]<<" ";}
        cout << "]" <<  endl;
        cout << "Numero de intentos: " << contador << endl;
    }
    else{cout << "No se ha encontrado solucion" << endl;}
}

bool LasVegas(int n,Tablero &solucion){
    int contador; 
    bool exito = false;
    // Inicializamos la solucion a 0
    std::vector<int> x(n+1);
    for(int i=1; i<= n; i++){x[i] = 0;}
    // Vector ok
    std::vector<int> ok(n+1);
    //Se han colocado k-1 reinas y se buscan todas las posiciones para la k-ésima
    for(int k=1; k <=n; k++){
        // Almacena todas las posiciones posibles la reina k en el vector ok
        contador = 0;
        for(int j=1; j <= n; j++){
            // probamos la reina k en la columna j
            x[k] = j;
            // Se puede colocar en la columna j
            if(Lugar(k,x) == true){
                contador = contador + 1;
                // Guardamos la posicion disponible
                ok[contador] = j;
            }
        }
        // no se ha encontrado posicion para la reina k.
        if(contador == 0){
            break;
        }
        // Se puede colocar la reina k y se selecciona una posición aleatoria
        int columna = ok[uniforme(1,contador)];
        x[k] = columna;
    }
    // No hay solucion
    if(contador == 0){
        exito = false;
    }
    // Hay solucion
    else{
        exito = true;
        solucion.identificadorTablero=1;
        solucion.solucion = x;
    }
    return exito;
}

int uniforme(int a, int b){
    return (a+rand()%b);
}

void SolucionReina(){
    // Numero de reinas
    int n = 0;
    while(n<4){
        cout << "Introduce el numero de reinas: ";
        cin >> n;
        if(n < 4){
            cout << "El algoritmo n-reinas no tiene solucion para un numero de reinas inferior a 4"<<endl;
        }
    }

    Clock tiempo; 

    // Estructura de datos de la solucion

    Tablero solucion;

    // Iniciamos el reloj de tiempo
            
    tiempo.restart();

    Reina(n,solucion);

    // Detenemos el tiempo de ordenacion del vector

    if(tiempo.isStarted()){ tiempo.stop(); }

    cout << "Tiempo utilizado para calcular la solucion: " << tiempo.elapsed() << " microsegundos"<<endl;

    std::cout << "Solucion: [";

    for(int i=1; i < solucion.solucion.size();i++){
        cout << solucion.solucion[i]<<" ";
    }

    cout << "]" <<  endl;
    

}

void Reina(int n,Tablero &solucion){
    // Creamos el vector de soluciones
    std::vector <int> x(n+1);    
    // Colocamos la primera reina en la columna central (c/2)
    x[1] = (n+1)/2;
    int k = 2;
    while( k > 0){
        x[k] = x[k] + 1;
        while( (x[k] <= n ) && (Lugar(k,x) == false) ){x[k] = x[k] + 1;}
        if( x[k] <= n){
            if( k == n){
                solucion.identificadorTablero = 1;
                // escribimos x(1),x(2),...,x(k)
                solucion.solucion = x;
                k = 0;
            }
            else{
                k = k + 1;
                x[k] = 0;
            }
        }
        else{k = k - 1;}
    }
}

void solucionesReinas(){
    // Numero de reinas
    int n = 0;
    while(n<4){
        cout << "Introduce el numero de reinas: ";
        cin >> n;
        if(n < 4){
            cout << "El algoritmo n-reinas no tiene solucion para un numero de reinas inferior a 4"<<endl;
        }
    }

    // Creamos un vector de soluciones

    std::vector<Tablero> soluciones;

    // Obtenemos las soluciones del algoritmo de n-reinas

    Reinas(n,soluciones);

    cout << "Mostrando soluciones para " << n << " reinas: "<<endl;

    for(int i=0; i < soluciones.size(); i++){
        cout << "Solucion " << soluciones[i].identificadorTablero << ": [";
        for(int j=1; j < soluciones[i].solucion.size();j++){
            cout << soluciones[i].solucion[j] << " ";
        }
        cout <<"]" << endl;

    }

    cout << "#################################" << endl; 
    
}

bool Lugar(int k,std::vector<int> x){
    for(int i=1; i <= (k-1); i++){
        if( (x[i] == x[k]) || (abs(x[i]-x[k]) == abs(i - k) ) ){
            return false;
        }
    }
    return true;
}


void Reinas(int n,std::vector<Tablero> &soluciones){
    // Numero de soluciones
    int contador = 0;
    // Creamos el vector de soluciones
    std::vector <int> x(n+1);    
    // Colocamos la primera reina en la columna 0 (fila 1)
    x[1] = 0;
    int k = 1;
    while( k > 0){
        x[k] = x[k] + 1;
        while( (x[k] <= n ) && (Lugar(k,x) == false) ){x[k] = x[k] + 1;}
        if( x[k] <= n){
            if( k == n){
                contador ++;
                Tablero tablero; // Solucion del tablero
                // escribimos x(1),x(2),...,x(k)
                tablero.identificadorTablero = contador;
                tablero.solucion = x;
                soluciones.push_back(tablero);
            }
            else{
                k = k + 1;
                x[k] = 0;
            }
        }
        else{k = k - 1;}
    }

}
