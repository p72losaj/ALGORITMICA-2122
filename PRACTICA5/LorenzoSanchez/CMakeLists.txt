# Version minima de cmake 

# cmake_minimum_required(VERSION 3.16.3)

cmake_minimum_required(VERSION 3.13.4)

# Nombre de proyecto y version 

project(PRACTICA5 VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Generamos el ejecutable

add_executable(practica5.exe MainProgram.cpp reinas.cpp)
