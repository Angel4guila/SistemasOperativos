#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}


int mochilamaximoV(int *pesos, int *valores, int n, int capacidad, int *solucion) {
    //arreglo maximo valor
    int **maximoV = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        maximoV[i] = (int *)malloc((capacidad + 1) * sizeof(int));
    }

    // iniciamos nuestros valores en cero
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacidad; w++) {
            if (i == 0 || w == 0) {
                maximoV[i][w] = 0;
            } else if (pesos[i-1] <= w) {
                // Puedo incluir el objeto i-1: elijo el máximo entre:
                // 1. No tomarlo: maximoV[i-1][w]
                // 2. Tomarlo: valores[i-1] + maximoV[i-1][w - pesos[i-1]]
                maximoV[i][w] = max(
                    maximoV[i-1][w],                           // no tomar
                    valores[i-1] + maximoV[i-1][w - pesos[i-1]]  // tomar
                );
            } else {
                // si no cabe, no lo tomo
                maximoV[i][w] = maximoV[i-1][w];
            }
        }
    }

    // asiganmos el valor maximo que esta en n
    int valorMaximo = maximoV[n][capacidad];

    //checamos que objeto podemos tomar
    int w = capacidad;
    for (int i = n; i > 0; i--) {
        //si valor cambia, podemos tomar el objeto
        if (maximoV[i][w] != maximoV[i-1][w]) {
            solucion[i-1] = 1;  // tomar objeto i-1
            w -= pesos[i-1];     // teducir capacidad
        } else {
            solucion[i-1] = 0;  // no tomar objeto i-1
        }
    }

    // liberqmos memoria de la tabla maximoV
    for (int i = 0; i <= n; i++) {
        free(maximoV[i]);
    }
    free(maximoV);

    return valorMaximo;
}

int main() {
    int n;
    int capacidad;

    printf("========= MOCHILA 0/1 (Programación Dinámica) =========\n\n");
    printf("Ingrese la capacidad de la mochila: ");
    scanf("%d", &capacidad);

    printf("Ingrese el número de objetos: ");
    scanf("%d", &n);

    int *pesos = (int *)malloc(n * sizeof(int));
    int *valores = (int *)malloc(n * sizeof(int));
    int *solucion = (int *)malloc(n * sizeof(int));

    if (pesos == NULL || valores == NULL || solucion == NULL) {
        printf("Error al asignar memoria\n");
        free(pesos);
        free(valores);
        free(solucion);
        return 1;
    }

    // pedimos pesos y valores
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("Objeto %d\n", i + 1);
        printf("  Peso: ");
        scanf("%d", &pesos[i]);
        printf("  Valor: ");
        scanf("%d", &valores[i]);
    }

    int valorMaximo = mochilamaximoV(pesos, valores, n, capacidad, solucion);


    printf("\n========= SOLUCIÓN OPTIMA =========\n");
    printf("Valor maximo obtenido: %d\n", valorMaximo);
    printf("\nObjetos seleccionados:\n");
    
    int pesoTotal = 0;
    for (int i = 0; i < n; i++) {
        if (solucion[i] == 1) {
            printf("Objeto %d (Peso: %d, Valor: %d)\n", 
                   i + 1, pesos[i], valores[i]);
            pesoTotal += pesos[i];
        }
    }
    
    printf("\nPeso total usado: %d / %d\n", pesoTotal, capacidad);
    printf("Espacio restante: %d\n", capacidad - pesoTotal);

    printf("\nObjetos NO seleccionados:\n");
    for (int i = 0; i < n; i++) {
        if (solucion[i] == 0) {
            printf("Objeto %d (Peso: %d, Valor: %d)\n", 
            i + 1, pesos[i], valores[i]);
        }
    }

    // LIiberar memoria
    free(pesos);
    free(valores);
    free(solucion);

    return 0;
}