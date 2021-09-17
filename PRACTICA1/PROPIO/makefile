practica1.exe: practica1.o algoritmos.o
	g++ -o practica1.exe practica1.o algoritmos.o

practica1.o: practica1.cpp
	g++ -c practica1.cpp

algoritmos.o: algoritmos.cpp
	g++ -c algoritmos.cpp

.PHONY: clean

clean:
	rm -rf practica1.o algoritmos.o