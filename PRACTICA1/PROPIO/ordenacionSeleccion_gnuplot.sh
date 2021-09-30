#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "OrdenacionSeleccion.eps"
set key right bottom
set xlabel "Etiqueta eje X"
set ylabel "Etiqueta Eje Y"
plot 'datosFinalesOrdenacionSeleccion.txt' using 1:2 t "Valor real" w l, 'datosFinalesOrdenacionSeleccion.txt' using 1:3 t "Valor estimado" w l
_end_
