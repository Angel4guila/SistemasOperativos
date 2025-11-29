#include <stdio.h>
#include <stdlib.h>

int main(){

    int diferentesM = 0;
    int cantidad = 0;
    int necesarias = 0;
    int Cambio = 0;
    int r = 0;

    printf("Cantidad de monedas diferentes:");
    scanf("%d",&diferentesM);

    printf("%d",diferentesM);

    int *Monedas = (int *)malloc(diferentesM* sizeof(int));
    int *Cantidad = (int *)malloc(diferentesM* sizeof(int));
    int *Contador = (int *)malloc(diferentesM* sizeof(int));

    if(Monedas == NULL || Cantidad == NULL || Contador == NULL){
        printf("Error al asignar memoria");

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

    for(int i=0; i<diferentesM; i++){
        r = 0;
        necesarias = Cambio / Monedas[i];

   
        if (necesarias <= Cantidad[i]){
            r = Cambio / Monedas[i];
            Cambio -= r * Monedas[i];
        }
        
        Contador[i]= r;
    }
  
   
    for(int i=0; i < diferentesM; i++){
        printf("Cantidad de monedas ocupadas de %d = %d\n", Monedas[i], Contador[i]);
    }

  
    printf("\n=========Nuevo total de monedas=========\n");
    printf("Valores\t|Cantidad\n");
    for(int i=0; i< diferentesM ; i++){
        printf("$%d\t|%d Monedas\n",Monedas[i], Cantidad[i]- Contador[i]);  
    }
  
  
  
    if(Cambio > 0){
        printf("\nNo hay suficientes monedas para devolver el cambio\n");
    }else{
        printf("\nCambio completado Correctamente!!\n");
    }

    
    //LIberar memoria
    free(Monedas);
    free(Cantidad);
    free(Contador);
    return 0;

}