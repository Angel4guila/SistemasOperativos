#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


void CrearyGenerar(int numeros){
    FILE *archivo;
    if(numeros == 1000){
        archivo = fopen("milnumeros.txt", "w");
    }else if(numeros==10000){
        archivo = fopen("diezmilnumeros.txt", "w");
    }else if(numeros==100000){
        archivo = fopen("cienmilnumeros.txt", "w");
    }else if(numeros==1000000){
        archivo = fopen("millonnumeros.txt", "w");
    }else if(numeros==2000000){
        archivo = fopen("dosmillonesnumeros.txt", "w");
    }
    
    if (archivo != NULL){
        printf("Archivo correctamente creado\n");
    }else{
        printf("El archivo no se pudo crear\n");
    }


    if(numeros > 0){
        for(int i=0; i < numeros; i++){
            int numero = rand();
            fprintf(archivo, "%d\n", numero);   
            
        } 
        printf("Numeros generados correctamente\n");
        fclose(archivo);
    }else{
        printf("No fue posible generar los numeros\n");
    }

    
    

};//Fin de crearygenerar


int main(){

    srand(time(NULL));
    int *A = NULL;
    int n = 0;
    int numeros = 0;

    printf("==============Creacion de numeros===============\n");
    printf("Cantidades Recomendadas:\n");
    printf("1. 1000 numeros\n");
    printf("2. 10,000 numeros\n");          
    printf("3. 100,000 numeros\n");
    printf("4. 1,000,000 numeros\n");
    printf("5. 2,000,000 numeros\n");
    printf("Opcion: ");
    scanf("%d", &n );

    if(n == 1){
        numeros = 1000;
    }else if(n == 2){
        numeros = 10000;    
    }else if(n == 3){
        numeros = 100000;
    }else if(n == 4){
        numeros = 1000000;
    }else if(n == 5){
        numeros = 2000000;  
    }else{
        printf("Opcion invalida\n");    
    }

    CrearyGenerar(numeros);
    A = (int *)malloc(numeros * sizeof(int));

    if(A == NULL){
        printf("Error, no hay memoria suficiente\n");
        return 0;
    }

    return 0;
}