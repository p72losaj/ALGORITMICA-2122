# Makefile de la practica 2 de algoritmica

# Creamos el fichero ejecutable de la practica

practica2.exe: MainProgram.o ClaseTiempo.o sistemaEcuaciones.o funcionesComunes.o
	g++ -Wall -o practica2.exe MainProgram.o ClaseTiempo.o sistemaEcuaciones.o funcionesComunes.o -lrt

# Creamos el fichero objeto del programa principal

MainProgram.o: MainProgram.cpp
	g++ -std=c++11 -c MainProgram.cpp

# Creamos el fichero objeto del fichero ClaseTiempo

ClaseTiempo.o: ClaseTiempo.cpp
	g++ -std=c++11 -c ClaseTiempo.cpp

# Creamos el fichero objeto del sistema de ecuaciones

sistemaEcuaciones.o: sistemaEcuaciones.cpp
	g++ -std=c++11 -c sistemaEcuaciones.cpp

# Creamos el fichero objeto 

funcionesComunes.o: funcionesComunes.cpp
	g++ -std=c++11 -c funcionesComunes.cpp

.PHONY: clean

clean:
	rm -rf *.o