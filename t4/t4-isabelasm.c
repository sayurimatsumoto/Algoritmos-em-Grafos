#include<stdio.h>
#include <stdlib.h>

typedef struct listaAdj {
	int *adj;
	int numAdj;
	int myTime;
}ListaAdj;

int main(){
	int n, m, i, u, v;
	while(1){
		max = 0;
		scanf("%d %d", &n, &m);
		if(m == 0 && n == 0){
			return 0;
		}
		ListaAdj *grafo =  (ListaAdj *) calloc(n,sizeof(ListaAdj));
		for(i = 0; i < n; i++){
			grafo[i].adj = (int *) calloc (n+1,sizeof(int));
			grafo[i].numAdj = 0;
			scanf("%d", &grafo[i].myTime);
		}
		for(i = 0; i < m; i++){
			scanf("%d %d", &u, &v, &direcao);
			grafo[u].adj[grafo[u].numAdj] = v;
			grafo[u].numAdj++;

		}
		for(i = 0; i < n; i++){
			free(grafo[i].adj);
		}
		free(grafo);
	}
	return 0;
}
