#include <stdio.h>


#define MD 5

int main(){
  
  //Declaramos nuestro arreglos 
  //Arreglos:
  //Monedas = Las diferentes monedas que poseemos.
  //Cantidad = La cantidad de monedas que tenemos de algún valor.
  //Contador = Las monedas ocupadas de algún valor.
  int Monedas[MD]= {100,25,10,5,1};
  int Cantidad[MD]= {0};
  int Contador[MD] = {0};
  int Cambio= 0;
  
  int r = 0;
  int necesarias = 0;

  //Le pedimos al usuario la cantidad de monedas que poseo de dicho valor.
  printf("Cantidad de monedad que poseo:\n");
  for(int i = 0 ; i <= MD - 1; i ++){
    printf("Cantidad de monedas $%d:", Monedas[i]);
    scanf("%d", &Cantidad[i]);
  }
  
  //Limpiamos pantalla
  system("clear");
  printf("\n");
  
  //Ciclo for "Monedas que poseemos":
  //Mostramos las monedas y la cantidad que tenemos de ellas
  printf("Total de monedad:\n");
  for(int i = 0; i <= MD - 1; i++){
    printf("$%d =", Monedas[i]);
    printf("%d monedas.\n", Cantidad[i]);
  }
  printf("\n");
  
  //Le pedimos al usuario cuanto cambio debemos devolver
  printf("Cantidad a devolve:");
  scanf("%d", &Cambio);
  
  //ciclo for "Calcular cantidad de monedas a ocupar":
  //Esta ciclo se encarga de hacer los calculos para saber cuantas monedas de algun valor
  //ocupamos para devolver el cambio
  for(int i=0; i<=MD-1; i++){
    necesarias = Cambio / Monedas[i];
    
    if (necesarias <= Cantidad[i]){
      
      r = Cambio / Monedas[i];
      Cambio -= r * Monedas[i];
    }
    
    Contador[i]= r;
  }
  
  //Ciclo for "Mostrar monedas ocupas":
  //Mostramos la cantidad de monedas ocupadas de dicha denominación para devolver el cambio.  
  for(int i=0; i <= MD-1; i++){
    printf("Cantidad de monedas ocupadas de %d = %d\n", Monedas[i], Contador[i]);
  }

  //Ciclo for "Nueva cantidad de monedas":
  //Mostramos la cantidad de monedas que poseemos despues de devolver el cambio
  printf("\nNuevo total de monedas\n");
  for(int i=0; i<= MD-1 ; i++){
    printf("$%d = %d Monedas\n",Monedas[i], Cantidad[i]- Contador[i]);  
  }
  
  
  //Condicional:
  //Nos mostrará un mensaje de éxito, si es que tenemos la cantidad de monedas suficientes
  //o de fracaso, si es que no contamos con las monedas suficientes.
  if(Cambio > 0){
  printf("\nNo hay suficientes monedas para devolver el cambio\n");
  
  }else{
  printf("\nCambio completado Correctamente!!\n");
  
  
  }



  return 0;
}
