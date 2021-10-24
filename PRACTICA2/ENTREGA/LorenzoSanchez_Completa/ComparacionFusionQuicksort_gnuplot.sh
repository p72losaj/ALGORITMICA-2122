#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "ComparacionQuickSort_Fusion.eps"
set key right bottom
set xlabel "Numero de elementos"
set ylabel "Tiempo"
plot 'datosFinalesFusion.txt' using 1:2 t "Valor real Fusion" w l, 'datosFinalesFusion.txt' using 1:3 t "Valor estimado Fusion" w l,'datosFinalesQuickSort.txt' using 1:2 t "Valor real QuickSort" w l, 'datosFinalesQuickSort.txt' using 1:3 t "Valor estimado QuickSort" w l
_end_