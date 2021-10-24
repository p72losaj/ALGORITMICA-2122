#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "QuickSort.eps"
set key right bottom
set xlabel "Numero de elementos"
set ylabel "Tiempo"
plot 'datosFinalesQuickSort.txt' using 1:2 t "Valor real" w l, 'datosFinalesQuickSort.txt' using 1:3 t "Valor estimado" w l
_end_
