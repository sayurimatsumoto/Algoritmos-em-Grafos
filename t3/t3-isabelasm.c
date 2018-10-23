#include<stdio.h>
#include <stdlib.h>

typedef struct listaAdj {
	int *adj;
	int numAdj;
	int visit;	
}ListaAdj;

int buscaProfundidade(ListaAdj grafo[], int n, int u, int time);

int main(){
	int n, m, i, u, v, direcao;
	while(1){
		max = 0;
		scanf("%d %d", &n, &m);
		if(m == 0 && n == 0){
			return 0;
		}
		ListaAdj *grafo =  (ListaAdj *) malloc(sizeof(ListaAdj)*n);
		for(i = 0; i < n; i++){
			grafo[i].adj = (int *) malloc (sizeof(int)*(n-1));
			//grafo[i].pred = i;
			grafo[i].numAdj = 0;
			//grafo[i].dist = -1;
			grafo[i].visit = 0;
		}
		for(i = 0; i < m; i++){
			scanf("%d %d %d", &u, &v, &direcao);
			grafo[u].adj[grafo[u].numAdj] = v;
			grafo[u].numAdj++;
			if(direcao == 2){
				grafo[v].adj[grafo[v].numAdj] = u;
				grafo[v].numAdj++;	
			}

		}
		//for(i = 0 ; i < n; i++){
		//	if(grafo[i].visit == 0)
		buscaProfundidade(grafo, n, 0,0);		
		//}
		
		for(i = 0; i < n; i++){
			free(grafo[i].adj);
		}
		free(grafo);

	}
	return 0;
}
int buscaProfundidade(ListaAdj grafo[], int n, int u, int time){
	
	return 1;
}