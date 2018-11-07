#include<stdio.h>
#include <stdlib.h>

typedef struct listaAdj {
	int *adj;
	int numAdj;
	int myTime;
	int visit;
	int f;
}ListaAdj;
int buscaProfundidade(ListaAdj grafo[], int n, int u, int time, int *maior);
int main(){
	int n, m, i, u, v;
	while(1){
		int max = 0;
		scanf("%d %d", &n, &m);
		if(m == 0 && n == 0){
			return 0;
		}
		ListaAdj *grafo =  (ListaAdj *) calloc(n,sizeof(ListaAdj));
		for(i = 0; i < n; i++){
			grafo[i].adj = (int *) calloc (n+1,sizeof(int));
			grafo[i].numAdj = 0;
			grafo[i].visit = 0;
			grafo[i].f = 0;
			scanf("%d", &grafo[i].myTime);
		}
		for(i = 0; i < m; i++){
			scanf("%d %d", &u, &v);
			grafo[u].adj[grafo[u].numAdj] = v;
			grafo[u].numAdj++;

		}
		for(i = 0; i < n; i++){
			if(grafo[i].visit == 0){
				buscaProfundidade(grafo, n, i, 0, &max);
			}
		}
		/*for(i = 0; i < n; i++){
			printf("%d ", grafo[i].f);
		}*/
		printf("%d\n", max);
		for(i = 0; i < n; i++){
			free(grafo[i].adj);
		}
		free(grafo);
	}
	return 0;
}
int buscaProfundidade(ListaAdj grafo[], int n, int u, int time, int *maior){
	int v;
	grafo[u].visit = 1;
	//grafo[u].dist = time;
	time++;
	int max = grafo[u].myTime;
	for(int i = 0; i < grafo[u].numAdj ;i++){
		v = grafo[u].adj[i];
		if(grafo[v].visit == 0){
			//grafo[v].pred = u;
			time = buscaProfundidade(grafo, n, v, time, maior);
		}
		if(max < grafo[u].myTime + grafo[v].myTime){
			max = grafo[u].myTime + grafo[v].myTime;
		}

	}
	time++;
	grafo[u].visit = 2;
	grafo[u].f = time;
	grafo[u].myTime = max;
	if(*maior < max){
		*maior = max;
	}
	return time;
}
