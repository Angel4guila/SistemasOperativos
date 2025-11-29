#include <stdlib.h>
#include <stdio.h>

void Pascal(int n){
    int C[n][n];

    
    for(int i = 0; i < n; i++){
        printf("1\t");
        C[i][i] = C[i][0] = 1;
        for(int k = 2; k <= i; k++){
            for(int j = 1; j < k; j++){
                C[k][j] = C[k-1][j-1] + C[k-1][j];
            }
        }
        if (i >= 2) {
            for(int j = 1; j < i; j++){
                printf("%d\t", C[i][j]);
            }
        }
        if (i > 0) printf("1\n");
        else printf("\n");
    }

    


}

int main(){
    int n=0;

    printf("Ingresa el coeficiente: ");
    scanf("%d", &n);
    Pascal(n);



    return 0;
}