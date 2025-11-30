#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int calcularCambio(int *Monedas, int *Cantidad, int diferentesM, int Cambio, int *resultado){
    int *minimoM= (int *)malloc((Cambio+1) * sizeof(int));
    int *monedasUsadas= (int *)malloc((Cambio+1) *sizeof(int));

    if (minimoM == NULL || monedasUsadas == NULL){
        printf("No se pudo asignar memoria");
        return -1;
    }

    minimoM[0]= 0;
    monedasUsadas[0] = -1;
    //primer chequeo
    for(int i= 1; i <= Cambio; i++){
        minimoM[i] = INT_MAX;
        monedasUsadas[i] = -1;
    }

    //llenamos minimoM[]
    for (int i = 1; i <= Cambio; i++) {
        // probamos cada moneda
        for (int j = 0; j < diferentesM; j++) {
            // mucho ojo
            //si la moneda en la posicion j es menor a la cantidad que representa i, y que 
            //aparte exixte forma de dar el cambio entro
            if (Monedas[j] <= i && minimoM[i - Monedas[j]] != INT_MAX) {
                // checamos si podemos encontrar una mejor solución
                if (minimoM[i - Monedas[j]] + 1 < minimoM[i]) {
                    minimoM[i] = minimoM[i - Monedas[j]] + 1;
                    monedasUsadas[i] = j; // gardamos indice de la moneda
                }
            }
        }
    }

    //vemos si es posible dar cambio
    if(minimoM[Cambio] == INT_MAX){ 
        free(minimoM);
        free(monedasUsadas);
        return -1;
        // recordar que cuando no se puede dar una un valor con las monedas que tenemos ponemos que es
        //INT_MAX, y al ser cambio igual a INT_MAX, eso quiere decir que no hubo manera de dar el camibio
        //y es por eso que de una vez liberamos la memoria
    }

    //iniciamos el arreglo de resultado con todos en cero para despues
    //poner la cantidad de monedas que se van a ocupar
    int cambioActual = Cambio;
    for (int i = 0; i < diferentesM ; i++){
        resultado[i]=0;

    }

    while (cambioActual > 0) {
        int idx = monedasUsadas[cambioActual];
        if (idx == -1) break;
        
        // checamos si tenemos
        if (resultado[idx] < Cantidad[idx]) {
            resultado[idx]++;
            cambioActual -= Monedas[idx];
        } else {
            //si no hay las suficientes nos piramos
            free(minimoM);
            free(monedasUsadas);
            return -1;
        }
    }
    
    int totalMonedas = minimoM[Cambio];
    free(minimoM);
    free(monedasUsadas);
    
    return totalMonedas;




}




int main(){

    int diferentesM = 0;
    int Cambio = 0;
   

    printf("Cantidad de monedas diferentes:");
    scanf("%d",&diferentesM);

    printf("%d",diferentesM);

    int *Monedas = (int *)malloc(diferentesM* sizeof(int));
    int *Cantidad = (int *)malloc(diferentesM* sizeof(int));
    int *Contador = (int *)malloc(diferentesM* sizeof(int));

    if(Monedas == NULL || Cantidad == NULL || Contador == NULL){
        printf("Error al asignar memoria");
        free(Monedas);
        free(Cantidad);
        free(Contador);

        return 1;

    }

    printf("\n=========Valores de las monedas=========\n");
    for(int i=0; i < diferentesM; i++){
        printf("Moneda #%d: ",i+1);
        scanf("%d", &Monedas[i]);
    }

    printf("=========Cantidad de Monedas=========\n");
    for(int j=0; j < diferentesM ; j++){
        printf("Cantidad de $%d: ", Monedas[j]);
        scanf("%d", &Cantidad[j] );
    }

    //Limpiamos pantalla
    printf("\033[2J\033[1;1H");

    
    printf("=========Total de monedas=========\n");
    printf("Valores\t|Cantidad\n");
    for(int i = 0; i < diferentesM;i++){
        printf("$%d\t|%d Monedas\n", Monedas[i], Cantidad[i]);

    }

    printf("\nCantidad a devolver: ");
    scanf("%d", &Cambio);

    int totalMonedas = calcularCambio(Monedas, Cantidad, diferentesM, Cambio, Contador);


    if (totalMonedas == -1) {
        printf("\nNo hay suficientes monedas para devolver el cambio\n");
    } else {
        printf("\nCambio completado correctamente!\n");
        printf("Total de monedas usadas: %d\n\n", totalMonedas);
        
        printf("=========Monedas utilizadas=========\n");
        printf("Valores\t|Cantidad\n");
        for (int i = 0; i < diferentesM; i++) {
            if (Contador[i] > 0) {
                printf("$%d\t|%d Monedas\n", Monedas[i], Contador[i]);
            }
        }
    }

    printf("\n=========Nuevo total de monedas=========\n");
    printf("Valores\t|Cantidad\n");
    for(int i=0; i<= diferentesM -1 ; i++){
        printf("$%d\t|%d Monedas\n",Monedas[i], Cantidad[i]- Contador[i]);  
    }
  
  
 

    
    //LIberar memoria
    free(Monedas);
    free(Cantidad);
    free(Contador);
    return 0;

}
