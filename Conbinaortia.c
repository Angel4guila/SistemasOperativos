#include <stdio.h>
#include <stdlib.h>

unsigned long long generaFactorial(int n, unsigned long long* fact){
	if(n == 1){
		fact[0] = 1;	return 1;
	}
	if(fact[n-1] == 0)	fact[n-1] = (unsigned long long) n * generaFactorial(n-1, fact);

	return fact[n-1];
}

int main(){
	int n, r;

	printf("Ingrese el número total de elementos : ");
	scanf("%d", &n);

	printf("Ingrese el número de elementos a elegir: ");
	scanf("%d", &r);

	//Validaciones
	if(n <= 0 || r < 0 || r > n){
		printf("Error: n debe ser positivo, n >= r >= 0 \n");
		return 0;
	}

	if(r == 0 || n == r){
		printf("La combinatoria de %d en %d es: 1", n, r);
		return 0;
	}

	//Inicio algoritmo
	unsigned long long* fact = (unsigned long long*) calloc(n, sizeof(unsigned long long));
	if(fact == NULL){
		printf("Error: No se pudo asignar memoria\n");
		return 1;
	}

	generaFactorial(n, fact);

	unsigned long long nFact = fact[n-1];
	unsigned long long rFact = fact[r-1];
	unsigned long long n_rFact = fact[(n-r)-1];

    printf("==========Resolucion==========\n");
    printf("Formula:\n");
    printf("n!/r!(n-r)!\n\n");
    printf("Valores:\n");
    printf("n = %d\t", n);
    printf("%d!= %llu \n", n, nFact);
    printf("r = %d\t", r);
    printf("%d!= %llu\n\n", r, rFact);

    printf("Desarrollo:\n");
    printf("(%d-%d)!= %llu\n",n, r, n_rFact);

    unsigned long long comb = nFact/(rFact * n_rFact);
    printf("%d!/%d!(%d-%d)!= %llu\n\n", n,r,n,r, comb);
    printf("Resultado:\n");
    printf("%d C %d = %llu\n", n,r,comb);

	free(fact);
}
