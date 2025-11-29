/* Algoritmo de Dijkstra --- Analisis y Disenio de Algoritmos */

#include <stdio.h>

#define tam 100
#define infinito 2000000

float matrizC[tam][tam];
int p[tam];
float d[tam];

void leeCostos(int n){
	int i, j;
	
	printf("Dame los costos de cada camino\n");
	printf("Si no hay camino o es el mismo nodo, escribe -1\n");
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			printf("Costo del camino %d a %d: ", i+1, j+1);
			scanf("%f", &matrizC[i][j]);
			if (matrizC[i][j] == -1)
				matrizC[i][j] = infinito;
		}
		printf("\n");
	}
	
	printf("\nLa matriz de costos es:\n");
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
		
		        if(matrizC[i][j] >= infinito-1){
		           printf("INF \t");
		          
		        
		        }else{
			  printf("%5.2f\t", matrizC[i][j]);
			}
			
		}
		printf("\n");
	}
} // fin leeCostos

void mostrarCamino(int p[], int destino, int origen){
    if (destino == origen){
        printf("%d", destino + 1);
        return;
    }
    if (p[destino] == -1){
        printf("Sin camino");
        return;
    }
    mostrarCamino(p, p[destino], origen);
    printf(" -> %d", destino + 1);
}


void dijkstra(int nodoi, int n){
	int S[tam]; // Conjunto S booleano
	float min;
	int i, v, w;
	
	nodoi--; // Le restamos 1 porque el usuario empieza desde 1 a leer
	// Inicializamos conjuntos
	for (i=0; i<n; i++){
		S[i] = 0;
		d[i] = matrizC[nodoi][i];
		if(i == nodoi)
                  p[i] = -1;  // Marca que es el origen
                else
                  p[i] = nodoi;
          }
	S[nodoi] = 1;
	
	// Algoritmo voraz de Dijkstra
	for (i=1; i<=n-1; i++){
		min = infinito;
		for (v=0; v<n; v++)
			// Elige un vertice w minimo en V-S
			if (!S[v])
				if (d[v]<min){
					min = d[v];
					w = v;
				}
		//printf("w = %d\n", w);
		S[w] = 1;  // Agrega w a S 
		for (v=0; v<n; v++)
			if (!S[v])
				if (d[w]+matrizC[w][v] < d[v]){
					d[v] = d[w]+matrizC[w][v];
					p[v] = w;
				}
	}
	
	// Impresion de prueba
	printf("\nVector D:\n");
	for (i=0; i<n; i++){
	        if(d[i] >= infinito-1){
	        printf("INF \t");
	        }else{
		printf("%5.2f\t", d[i]);
		}
	}
	printf("\nVector P:\n");
	for (i=0; i<n; i++)
		printf("%d\t", p[i] + 1);
	printf("\n");
	
	printf("\n\nCaminos mas cortos desde el nodo %d:\n", nodoi+1);
    for (i=0; i<n; i++){
        if(i != nodoi){
        
            if (d[i] >= infinito){
              printf("Hacia nodo %d (costo INF): ", i+1);
            }else {
              printf("Hacia nodo %d (costo %.2f): ", i+1, d[i]);
            }
            
            if(d[i] >= infinito-1){
                printf("Sin camino\n");
            }else{
                mostrarCamino(p, i, nodoi);
                printf("\n");
            }
        }
    }
	
	
	
} // fin dijkstra


int main(){
	int nodoi;
	int n=0;
	int llenado = 0;
	int op;
	
	
	
	do {
	
	printf("\n===== MENU DIJKSTRA =====\n");
	printf("Programa voraz de caminos mas cortos por Dijkstra\n");
	printf("Elige una de las opciones para iniciar el programa\n\n");
	printf("1. Determinar la cantidad de nodos\n");
	printf("2. Empezar a llenar mi matriz de caminos\n");
	printf("3. Seleccionar nodo inicial\n");
	printf("4. Borrar todos lo datos\n");
	printf("5. Salir\n\n");
	printf("Opcion: ");
	scanf("%d", &op);
	
	switch(op){
	  case 1: 
	      printf("Dame el numero de nodos del grafo\n");
	      printf("Cantidad: ");
	      scanf("%d", &n);
	    break;
	  case 2:
	    if(n<=0){
	      printf("primero debe dar el numero de nodos\n");
	    
	    }else{
	      leeCostos(n);
	      llenado = 1;
	    }
	    break;
	    
	  case 3:
	      if(!llenado){
	        printf("No es posible seleccionar un nodo, asegurate de llenar primero la matriz");
	      
	      }else{
	        printf("Ingresa el nodo donde empezaremos:\n");
	        scanf("%d", &nodoi);
	        dijkstra(nodoi, n);	      
	      }
	      
	    break;
	    
          case 4:         
              n = 0;
              llenado = 0;
              printf("Todos los elementos se borraron correctamente");
              
            break;
	  case 5:
	  
	      printf("gracias por no usar \n");
	    
	    break;
	  
	  default:
	      printf("Opción inválida, intenta de nuevo.\n");
	    break;
          
	}
	
	}while(op !=5 );
	
	return 0;
}
