#include<stdio.h>
#include <stdlib.h>


typedef struct no{
	int num;
	int custo;
}No;
typedef struct listaAdj {
	No *adj;
	int numAdj;
	int custo;
	int dist;
	int s;
}ListaAdj;

int dijkstra(ListaAdj grafo[], int *minCusto, int n);
int menorDist(ListaAdj grafo[], int n);

int main(){
	int n, m, k, i, u, v, custo;

	scanf("%d %d %d", &n, &m, &k);
	
	ListaAdj *grafo =  (ListaAdj *) malloc(n * sizeof(ListaAdj));

	int minCusto[n];

	for(i = 0; i < n; i++){
		grafo[i].adj = (No *) malloc (n+1 * sizeof(No));
		grafo[i].numAdj = 0;
		if(i < k){
			grafo[i].dist = 0;
			grafo[i].s = 1;
			minCusto[i] = i;
		}else{
			grafo[i].dist = -1;
			grafo[i].s = 1;
			minCusto[i] = -1;
		}
	}	

	for(i = 0; i < m; i++){
		// de u a v
		scanf("%d %d %d", &u, &v, &custo);
		grafo[u].adj[grafo[u].numAdj].num = v;
		grafo[u].numAdj++;
		grafo[u].adj[grafo[u].numAdj].custo = custo;
		// de v a u
		grafo[v].adj[grafo[v].numAdj].num = u;
		grafo[v].numAdj++;
		grafo[v].adj[grafo[v].numAdj].custo = custo;
	}

	dijkstra(grafo, minCusto, n);

	for(i = k; i < n; i++){
		if(i == k ){
			printf("%d", minCusto[i]);
		}else{
			printf(" %d", minCusto[i]);
		}
	}
	printf("\n");
	
	return 0;
}

int dijkstra(ListaAdj grafo[], int *minCusto, int n){
	int i, v;
	int u = menorDist(grafo, n);
	while(u != -1){
		//printf("AAAAAAAAAAAA\n");
		for(i = 0; i < grafo[u].numAdj; i++){
			v = grafo[u].adj[i].num;
			if(grafo[v].s == 1){
				if(grafo[v].dist == -1){
					grafo[v].dist = grafo[u].dist + grafo[u].adj[v].custo;
					minCusto[v] = minCusto[u];

				}else if(grafo[v].dist > grafo[u].dist + grafo[u].adj[v].custo){
					grafo[v].dist = grafo[u].dist + grafo[u].adj[v].custo;
					minCusto[v] = minCusto[u];

				}else if(grafo[v].dist == grafo[u].dist + grafo[u].adj[v].custo && minCusto[v] > minCusto[u]){
						minCusto[v] = minCusto[u];
				}
			}
		}
		u = menorDist(grafo, n);
	}
}
int menorDist(ListaAdj grafo[], int n){
	int i, min = -1;

	for(i = 0; i < n; i++){
		if(min == -1){
			if(grafo[i].s && grafo[i].dist != -1){
				min = i;
			}
		}else if(grafo[i].s && grafo[i].dist != -1 && grafo[i].dist < grafo[min].dist){
			min = i;
		}
	}
	if(min != -1){
		grafo[min].s = 0;
	}
	return min;
}