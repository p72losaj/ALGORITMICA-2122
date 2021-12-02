#ifndef REINAS_HPP
#define REINAS_HPP
#include <vector>

using namespace std;

struct Tablero{
    int identificadorTablero;
    std::vector<int> solucion;
};

void solucionesReinas();

// k representa el identificador de la maquina
// x representa las columnas de la matriz de n*n
bool Lugar(int k,std::vector<int> x);

void Reinas(int n,std::vector<Tablero> &soluciones);

void SolucionReina();

void Reina(int n,Tablero &solucion);

#endif