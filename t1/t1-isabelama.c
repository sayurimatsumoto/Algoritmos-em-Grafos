#include<stdio.h>
typedef struct listaAdj {
	int color;
	int adjacentes[2001];
	int numAdj;
	int visitado;	
}ListaAdj;

int isBipartite(ListaAdj grafo[], int numAlunos);

int main(){

	int numAlunos, numPares;
	int i = 0, u, v, j;
	while(1){
		scanf("%d %d", &numAlunos, &numPares);
		if(numAlunos == 0 && numPares == 0){
			return 0;
		}
		ListaAdj grafo[numAlunos+1];

		for(i = 0; i <= numAlunos; i++){
			grafo[i].color = 0;
			grafo[i].numAdj = 0;
			grafo[i].visitado = 0;
		}
		for(i = 0; i < numPares; i++){
			scanf("%d %d", &u, &v);
			grafo[u].adjacentes[grafo[u].numAdj] = v;
			grafo[u].numAdj++;
		}
		
		if(isBipartite(grafo, numAlunos)){
			printf("SIM\n");
		}else{
			printf("NAO\n");
		}
		
	}

	return 0;
}
int isBipartite(ListaAdj grafo[], int numAlunos){
	int u, j, v;
	int pred[numAlunos+1];
	for(u = 1; u <= numAlunos; u++){
		for(j = 0; j < grafo[u].numAdj; j++){
			v = grafo[u].adjacentes[j];
			if(grafo[v].visitado == 0){
				grafo[v].visitado++;
				pred[v] = u;
				if(grafo[pred[v]].color == 0){
					grafo[v].color = 1;
				}else{
					grafo[v].color = 0;
				}
			}else{
				if(grafo[v].color == grafo[u].color){
					return 0;
				}
			}
		}
		grafo[u].visitado = 2;	
	}
	return 1;
}
