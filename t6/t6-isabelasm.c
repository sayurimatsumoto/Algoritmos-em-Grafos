#include<stdio.h>
#include <stdlib.h>
#include <math.h>

char floyd_warshall(double **matriz, int n);
int main(){
	int n, i, j;
	char arbitragem;
	while(1){

		scanf("%d", &n);

		if(!n){
			return 0;
		}

		double **matrizAdj;
		matrizAdj = (double **) malloc (n * sizeof(double*));

		for(i = 0; i < n; i++){
			matrizAdj[i] = (double *) malloc (n * sizeof(double));	
		}

		double aux;
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				scanf("%lf", &aux);
				matrizAdj[i][j] = -log(aux);
			}
		}
		arbitragem = floyd_warshall(matrizAdj, n);
		printf("%c\n", arbitragem);

		for(i = 0; i < n; i++){
			free(matrizAdj[i]);	
		}
		free(matrizAdj);

	}
	return 0;
}
char floyd_warshall(double **matriz, int n){
	int i, j, k;

	for(k = 0; k < n; k++){
		for(i = 0; i < n; i++){
			for(j = 0 ; j < n; j++){
				if(matriz[i][j] > matriz[i][k] + matriz[k][j]){
					matriz[i][j] = matriz[i][k] + matriz[k][j];
				}
			}
		}
	}

	for(i = 0; i < n; i++){
		if(matriz[i][i] < 0){
			return 'S';
		}
	}

	return 'N';
}