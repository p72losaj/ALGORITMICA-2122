/**
 * Definicion de las clases y funcionalidades necesarias para la realizacion del problema del cambio
 * Realizado por Jaime Lorenzo Sanchez
 * */

#ifndef PROBLEMACAMBIO_HPP
#define PROBLEMACAMBIO_HPP


#include <string>
#include <vector>
using namespace std;

// Clase Divisa
class Divisa{
    private:
        int valor; // Valor de la moneda o del billete
        string tipo; // Tipo de la divisa
    public:
    // Funcion que obtiene el valor de la moneda o del billete
    int getValorDivisa(){ return this->valor; }
    // Funcion que modifica el valor de la moneda o del billete
    void setValorDivisa(int valor2){ this->valor = valor2; }
    // Funcion que obtiene el tipo de la moneda o del billete
    string getTipoDivisa(){return this->tipo;}
    // Funcion que modifica el tipo de la moneda o del billete
    void setTipoDivisa(string tipo2){this->tipo = tipo2;}
    // Funcion que compara el valor de 2 divisas
    static bool compararValorDivisa(Divisa &a, Divisa &b){return a.valor > b.valor; }
} typedef Divisa;

// Clase solucion parcial

class SolucionParcialCambio{
    private:
    int valor; // Valor de la moneda o billete de la posible solucion
    int cantidad; // Cantidad de monedas o billetes de la posible solucion
    public: 
    // Funcion que obtiene el valor de la moneda o del billete
    int getValorSolucionParcial(){ return this->valor;}
    // Funcion que modifica el valor de la moneda o del billete
    void setValorSolucionParcial(int valor2){this->valor = valor2;}
    // Funcion que obtiene la cantidad de billetes o monedas de la posible solucion
    int getCantidadSolucionParcial(){ return this->cantidad;}
    // funcion que modifica la cantidad de billetes o monedas de la posible solucion
    void setCantidadSolucionParcial(int cantidad2){this->cantidad = cantidad2;}
} typedef SolucionParcialCambio;

/**
 * Funcion que ordena un vector
 * @param vector Vector a ordenar
 * */

void ordenarVector(vector<Divisa> &vector);

/**
 * Funcion que lee la informacion del fichero SistemaMonetario.txt
 * @param nombre Nombre del fichero
 * */

void leerFichero(string nombre, vector<Divisa> &vector);

#endif