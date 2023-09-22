#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMAÑO 10


int NumeroAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}


void mostrarYContarRepetidos(int vector[], int tamaño) {
    int i, j, repetidos = 0;

    printf("Vector: ");
    for (i = 0; i < tamaño; i++) {
        printf("%d ", vector[i]);
        for (j = 0; j < i; j++) {
            if (vector[i] == vector[j]) {
                repetidos++;
                break;
            }
        }
    }
    printf("\nDatos repetidos: %d\n", repetidos);
}

int main() {
    int vector1[TAMAÑO];
    int vector2[TAMAÑO];
    int i;
    
    srand(time(NULL));

    for (i = 0; i < TAMAÑO; i++) {
        vector1[i] = NumeroAleatorio(20, 35);
        vector2[i] = NumeroAleatorio(20, 35);
    }

    int opcion;
    do {
        printf("\nMenu:\n");
        printf("1. Mostrar vectores y contar datos repetidos en cada uno\n");
        printf("2. Mostrar vectores sin datos repetidos\n");
        printf("3. Mostrar la unión de ambos vectores\n");
        printf("4. Mostrar la intersección de ambos vectores\n");
        printf("5. Mostrar la resta de A - B\n");
        printf("6. Mostrar la resta de B - A\n");
        printf("0. Salir\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("\nVector 1:\n");
                mostrarYContarRepetidos(vector1, TAMAÑO);

                printf("\nVector 2:\n");
                mostrarYContarRepetidos(vector2, TAMAÑO);
                break;

            case 2:
                printf("\nVector 1 (sin repetidos):\n");
                for (i = 0; i < TAMAÑO; i++) {
                    for (int j = 0; j < i; j++) {
                        if (vector1[i] == vector1[j]) {
                            break;
                        }
                        if (j == i - 1) {
                            printf("%d ", vector1[i]);
                        }
                    }
                }
                printf("\n");

                printf("\nVector 2 (sin repetidos):\n");
                for (i = 0; i < TAMAÑO; i++) {
                    for (int j = 0; j < i; j++) {
                        if (vector2[i] == vector2[j]) {
                            break;
                        }
                        if (j == i - 1) {
                            printf("%d ", vector2[i]);
                        }
                    }
                }
                printf("\n");
                break;

            case 3:
                printf("\nUnión de ambos vectores:\n");
                for (i = 0; i < TAMAÑO; i++) {
                    printf("%d ", vector1[i]);
                }
                for (i = 0; i < TAMAÑO; i++) {
                    for (int j = 0; j < i; j++) {
                        if (vector2[i] == vector2[j]) {
                            break;
                        }
                        if (j == i - 1) {
                            printf("%d ", vector2[i]);
                        }
                    }
                }
                printf("\n");
                break;

            case 4:
                printf("\nIntersección de ambos vectores:\n");
                for (i = 0; i < TAMAÑO; i++) {
                    for (int j = 0; j < TAMAÑO; j++) {
                        if (vector1[i] == vector2[j]) {
                            printf("%d ", vector1[i]);
                            break;
                        }
                    }
                }
                printf("\n");
                break;

            case 5:
                printf("\nResta de A - B:\n");
                for (i = 0; i < TAMAÑO; i++) {
                    int esRepetido = 0;
                    for (int j = 0; j < TAMAÑO; j++) {
                        if (vector1[i] == vector2[j]) {
                            esRepetido = 1;
                            break;
                        }
                    }
                    if (!esRepetido) {
                        printf("%d ", vector1[i]);
                    }
                }
                printf("\n");
                break;

            case 6:
                printf("\nResta de B - A:\n");
                for (i = 0; i < TAMAÑO; i++) {
                    int esRepetido = 0;
                    for (int j = 0; j < TAMAÑO; j++) {
                        if (vector2[i] == vector1[j]) {
                            esRepetido = 1;
                            break;
                        }
                    }
                    if (!esRepetido) {
                        printf("%d ", vector2[i]);
                    }
                }
                printf("\n");
                break;

            case 0:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }
    } while (opcion != 0);

    return 0;
}
