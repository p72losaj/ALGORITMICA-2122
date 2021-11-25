# Version minima de cmake 

cmake_minimum_required(VERSION 3.16.3)

# Nombre de proyecto y version 

project(PRACTICA1 VERSION 2.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Generamos el ejecutable

add_executable(practica1.exe MainProgram.cpp funcionesComunes.cpp fibonacci.cpp ordenacionSeleccion.cpp productoMatricesCuadradas.cpp sistemaEcuaciones.cpp)
