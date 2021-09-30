# Makefile de la practica 1 de algoritmica

# Creamos el fichero ejecutable de la practica
practica1.exe: MainProgram.o ordenacionSeleccion.o ClaseTiempo.o sistemaEcuaciones.o productoMatricesCuadradas.o funcionesComunes.o fibonacci.o
	g++ -Wall -o practica1.exe MainProgram.o ordenacionSeleccion.o ClaseTiempo.o sistemaEcuaciones.o productoMatricesCuadradas.o fibonacci.o funcionesComunes.o -lrt

# Creamos el fichero objeto del programa principal

MainProgram.o: MainProgram.cpp
	g++ -c MainProgram.cpp

# Creamos el fichero objeto de fibbonnaci

fibonacci.o: fibonacci.cpp
	g++ -c fibonacci.cpp

# Creamos el fichero objeto del fichero de ordenacionSeleccion

ordenacionSeleccion.o: ordenacionSeleccion.cpp
	g++ -c ordenacionSeleccion.cpp

# Creamos el fichero objeto del fichero ClaseTiempo

ClaseTiempo.o: ClaseTiempo.cpp
	g++ -c ClaseTiempo.cpp

# Creamos el fichero objeto del sistema de ecuaciones

sistemaEcuaciones.o: sistemaEcuaciones.cpp
	g++ -c sistemaEcuaciones.cpp


# Creamos el fichero objeto productoMatricesCuadradas.o

productoMatricesCuadradas.o: productoMatricesCuadradas.cpp
	g++ -c productoMatricesCuadradas.cpp

# Creamos el fichero objeto 

.PHONY: clean

clean:
	rm -rf *.o