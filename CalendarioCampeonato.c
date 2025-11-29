#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// E= equipo
void completarTabla(int C[][MAX], int EInferior, int ESuperior, int diaInferior, int diaSuperior, int Einicial){
    for(int j = diaInferior ; j <= diaSuperior; j++)
        C[EInferior][j] = Einicial + j - diaInferior;

    for(int i = EInferior+1 ; i <= ESuperior; i++ ) {
        C[i][diaInferior]= C[i-1][diaSuperior] ;

        for(int j = diaInferior+1; j <= diaSuperior; j++){
            C[i][j]= C[i-1][j-1];

        }
    }
}

void formarTabla(int C[][MAX], int primero, int ultimo){
    int medio = 0;

    if (ultimo - primero == 1){
        C[primero][1]= ultimo;
        C[ultimo][1] = primero;
    }else{
        medio = (primero + ultimo)/ 2;
        formarTabla(C, primero, medio);
        formarTabla(C,medio+1,ultimo);

        completarTabla(C,primero, medio,medio-primero+1,ultimo-primero,medio);

        completarTabla(C,medio+1, ultimo, medio-primero+1,ultimo-primero,primero);

    }



}

void Calendario(int C[][MAX], int participantes){
    formarTabla(C, 1, participantes);

}

void imprimir(int C[][MAX] ,int n ){
    printf("Calendario de partidos:\n");
    printf("Equipo:\t");

    for(int j = 1; j < n ; j++){
        printf("Dia %d\t ", j);
    }
    printf("\n");

    for(int i= 1; i <= n ; i++){
        printf("%d\t", i);
        for(int j = 1; j < n; j++)
        printf("%d\t",C[i][j]);
        printf("\n");
    }
    


}


 

int main (){

    int participantes = 0;
    int C[MAX][MAX] = {0};
    
    printf("Recordar que los integrantes deben ser potenccia de:\n ");
    printf("Ingresar la cantidad de participantes en el torneo:");
    scanf("%d", &participantes);

    if((participantes & (participantes-1)) != 0 || participantes < 2){
        printf("Error: El número debe ser potencia de 2 (2, 4, 8, 16...)\n");
        return 1;
    }

    Calendario(C, participantes);

    imprimir(C, participantes);

    
    return 0;
} 

