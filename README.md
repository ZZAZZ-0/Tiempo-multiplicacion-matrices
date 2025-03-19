Equipo Sistemas Distribuidos:
- Bote Sánchez Cristian
- Celis Hernandez Ronnie
- Chagoya Gonzalez Leonardo
- Martínez Martínez Alberto
- Pulido Vazquez Rodrigo
---------------------------------------------------------------------------------------------------------------------------------------
Comparación de Orden de Bucle en Multiplicación de Matrices

Este programa en C mide el tiempo de ejecución de la multiplicación de matrices cuadradas utilizando diferentes órdenes de iteración en los bucles anidados. Se evalúan los siguientes órdenes:
 - ijk
 - ikj
 - jik
 - jki
 - kij
 - kji
El objetivo es analizar el impacto del orden de acceso a los datos en la caché y su efecto en el rendimiento.
---------------------------------------------------------------------------------------------------------------------------------------
* Contenido
- mult_mat.c - Programa principal
---------------------------------------------------------------------------------------------------------------------------------------
* Características
 - Inicialización de matrices con valores aleatorios.
 - Implementación de seis variantes de multiplicación de matrices.
 - Medición del tiempo de ejecución usando gettimeofday().
 - Pruebas con tamaños de matrices de 1000x1000, 5000x5000 y 10000x10000.
