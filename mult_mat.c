#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// Función para medir tiempo
void get_walltime(double *wcTime) {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    *wcTime = (tp.tv_sec + tp.tv_usec / 1000000.0);
}

// Función para inicializar matrices con valores aleatorios
void inicializar_matriz(int **matriz, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matriz[i][j] = rand() % 10;
}

// Función para multiplicar matrices según el orden de bucles
void multiplicar_matrices(int **A, int **B, int **C, int n, int orden) {
    // Limpiar matriz C
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = 0;

    double S, E;
    get_walltime(&S);

    switch (orden) {
        case 0: // ijk
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    for (int k = 0; k < n; k++)
                        C[i][j] += A[i][k] * B[k][j];
            break;
        case 1: // ikj
            for (int i = 0; i < n; i++)
                for (int k = 0; k < n; k++)
                    for (int j = 0; j < n; j++)
                        C[i][j] += A[i][k] * B[k][j];
            break;
        case 2: // jik
            for (int j = 0; j < n; j++)
                for (int i = 0; i < n; i++)
                    for (int k = 0; k < n; k++)
                        C[i][j] += A[i][k] * B[k][j];
            break;
        case 3: // jki
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    for (int i = 0; i < n; i++)
                        C[i][j] += A[i][k] * B[k][j];
            break;
        case 4: // kij
            for (int k = 0; k < n; k++)
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        C[i][j] += A[i][k] * B[k][j];
            break;
        case 5: // kji
            for (int k = 0; k < n; k++)
                for (int j = 0; j < n; j++)
                    for (int i = 0; i < n; i++)
                        C[i][j] += A[i][k] * B[k][j];
            break;
    }

    get_walltime(&E);
    printf("Tiempo orden %d: %f s\n", orden, (E - S));
}

int main() {
    int tamanos[] = {1000, 5000, 10000}; // Tamaños de matrices a probar

    for (int t = 0; t < 3; t++) {
        int n = tamanos[t];
        printf("\n=== Multiplicacion de matrices %dx%d ===\n", n, n);

        // Reservar memoria
        int **A = (int **)malloc(n * sizeof(int *));
        int **B = (int **)malloc(n * sizeof(int *));
        int **C = (int **)malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++) {
            A[i] = (int *)malloc(n * sizeof(int));
            B[i] = (int *)malloc(n * sizeof(int));
            C[i] = (int *)malloc(n * sizeof(int));
        }

        // Inicializar matrices
        inicializar_matriz(A, n);
        inicializar_matriz(B, n);

        // Probar todas las combinaciones
        for (int orden = 0; orden < 6; orden++)
            multiplicar_matrices(A, B, C, n, orden);

        // Liberar memoria
        for (int i = 0; i < n; i++) {
            free(A[i]);
            free(B[i]);
            free(C[i]);
        }
        free(A);
        free(B);
        free(C);
    }

    return 0;
}
