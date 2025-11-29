#include <stdio.h>

int main() {
    int n;                      // Numero de objetos
    float capacidad;            // Capacidad de la mochila
    float totalValor = 0.0;     // Valor total máximo
    float pesoActual = 0.0;     // Peso acumulado

    printf("Ingrese la capacidad de la mochila: ");
    scanf("%f", &capacidad);

    printf("Ingrese el número de objetos: ");
    scanf("%d", &n);

    int objeto[n];
    float valor[n], peso[n], razon[n];

    // Pedir pesos y valores
    for (int i = 0; i < n; i++) {
        objeto[i] = i + 1;
        printf("\nObjeto %d\n", i + 1);
        printf("Peso: ");
        scanf("%f", &peso[i]);
        printf("Valor: ");
        scanf("%f", &valor[i]);
    }

    // Calcular razon valor/peso
    for (int i = 0; i < n; i++) {
        razon[i] = valor[i] / peso[i];
    }

    // Ordenar por razón (burbuja descendente)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (razon[i] < razon[j]) {
                // Intercambiar razón
                float temp = razon[i];
                razon[i] = razon[j];
                razon[j] = temp;

                // Intercambiar pesos
                temp = peso[i];
                peso[i] = peso[j];
                peso[j] = temp;

                // Intercambiar valores
                temp = valor[i];
                valor[i] = valor[j];
                valor[j] = temp;

                // Intercambiar número de objeto
                int t = objeto[i];
                objeto[i] = objeto[j];
                objeto[j] = t;
            }
        }
    }

    printf("\nObjetos ordenados por valor/peso:\n");
    printf("Obj\tValor\tPeso\tRazon\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%.2f\t%.2f\t%.2f\n", objeto[i], valor[i], peso[i], razon[i]);
    }

    printf("\nSelección de objetos:\n");

    for (int i = 0; i < n; i++) {
        if (pesoActual + peso[i] < capacidad) {
            pesoActual += peso[i];
            totalValor += valor[i];
            printf("Se toma el objeto %d completo (peso = %.2f)\n", objeto[i], peso[i]);
        } else {
            float resto = capacidad - pesoActual;
            totalValor += valor[i] * (resto / peso[i]);
            pesoActual += resto;
            printf("Se toma %.2f%% del objeto %d (peso = %.2f)\n", (resto / peso[i]) * 100, objeto[i], resto);
            break;
        }
    }

    printf("\nPeso total en la mochila: %.2f\n", pesoActual);
    printf("Valor total máximo posible: %.2f\n", totalValor);

    return 0;
}

