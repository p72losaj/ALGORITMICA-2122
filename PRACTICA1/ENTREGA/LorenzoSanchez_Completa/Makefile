# Makefile para la creacion del fichero ejecutable y los ficheros objetos de la practica1 de Algoritmica

#FLAX

CXX = g++

CXXFLAGS: -std=c++11 -Wall -lrt

# Ejecutable

practica1.exe: MainProgram.o funcionesComunes.o ordenacionSeleccion.o ClaseTiempo.o sistemaEcuaciones.o productoMatricesCuadradas.o fibonacci.o
	$(CXX) $(CXXFLAGS) -o practica1.exe MainProgram.o funcionesComunes.o ordenacionSeleccion.o ClaseTiempo.o sistemaEcuaciones.o productoMatricesCuadradas.o fibonacci.o

# Creamos los ficheros objeto

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


# Limpieza de los ficheros

.PHONY: clean

clean:
	rm -rf *.o
	rm -rf *.txt
	rm -rf practica1.exe
