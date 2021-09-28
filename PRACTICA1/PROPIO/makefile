practica1.exe: practica1.o funcionesPrincipales.o algoritmos.o ClaseTiempo.o vector.o matrices.o funcionesauxiliares.o sistemaEcuaciones.o
	g++ -Wall -o practica1.exe practica1.o funcionesPrincipales.o algoritmos.o vector.o matrices.o ClaseTiempo.o -lrt

practica1.o: practica1.cpp
	g++ -c practica1.cpp

algoritmos.o: algoritmos.cpp
	g++ -c algoritmos.cpp

funcionesPrincipales.o: funcionesPrincipales.cpp	
	g++ -c funcionesPrincipales.cpp

ClaseTiempo.o: ClaseTiempo.cpp
	g++ -c ClaseTiempo.cpp

vector.o: vector.cpp	
	g++ -c vector.cpp

matrices.o: matrices.cpp
	g++ -c matrices.cpp

funcionesauxiliares.o: funcionesauxiliares.cpp
	g++ -c funcionesauxiliares.cpp

sistemaEcuaciones.o: sistemaEcuaciones.cpp
	g++ -c sistemaEcuaciones.cpp

.PHONY: clean

clean:
	rm -rf *.o