#include<stdio.h>
#include <stdlib.h>

typedef struct listaAdj {
	int *adj;
	int numAdj;
	int visit;
	int dist;
	int f;	
}ListaAdj;

int buscaProfundidade(ListaAdj grafo[], int n, int u, int time);

int main(){
	int n, m, i, u, v, direcao, flag, max = 0;
	while(1){
		max = 0;
		scanf("%d %d", &n, &m);
		if(m == 0 && n == 0){
			return 0;
		}
		ListaAdj *grafo =  (ListaAdj *) calloc(n+1,sizeof(ListaAdj));
		ListaAdj *grafoT  =  (ListaAdj *) calloc(n+1,sizeof(ListaAdj));	
		for(i = 0; i <= n; i++){
			grafo[i].adj = (int *) calloc (n+1,sizeof(int));
			grafoT[i].adj = (int *) calloc (n+1,sizeof(int));
			grafo[i].numAdj = 0;
			grafoT[i].numAdj = 0;
			grafo[i].dist = -1;
			grafoT[i].dist = -1;
			grafo[i].visit = 0;
			grafoT[i].visit = 0;
		}
		for(i = 0; i < m; i++){
			scanf("%d %d %d", &u, &v, &direcao);
			grafo[u].adj[grafo[u].numAdj] = v;
			grafo[u].numAdj++;
			grafoT[v].adj[grafoT[v].numAdj] = u;
			grafoT[v].numAdj++;

			if(direcao == 2){
				grafo[v].adj[grafo[v].numAdj] = u;
				grafo[v].numAdj++;
				grafoT[u].adj[grafoT[u].numAdj] = v;
				grafoT[u].numAdj++;	
			}
		}
		/*for(i = 1; i <= n; i++){
			printf("\n%d = ",i);
			for(int j = 0; j < grafo[i].numAdj; j++){
				printf("%d ", grafo[i].adj[j]);
			}
		}*/
		buscaProfundidade(grafo, n, 1,0);
		flag = 1;
		max = 0;		
		for(i = 1; i <= n; i++){
			if(grafo[i].visit == 0){
				flag = 0;
			}
			if(grafo[i].f > max){
				max = grafo[i].f;
				v = i;
			}
		}
		if(flag==0){
			printf("0\n");
		}else{
			buscaProfundidade(grafoT, n, v,0);
			for(i = 1; i <= n; i++){
				if(grafoT[i].visit == 0){
					flag = 0;
					break;
				}
			}
			if(flag==0){
				printf("0\n");
			}else{
				printf("1\n");
			}
		}
		for(i = 0; i <= n; i++){
			free(grafo[i].adj);
			free(grafoT[i].adj);
		}
		free(grafo);
		free(grafoT);

	}
	return 0;
}
int buscaProfundidade(ListaAdj grafo[], int n, int u, int time){
	int v;
	grafo[u].visit = 1;
	grafo[u].dist = time;
	time++;
	for(int i = 0; i < grafo[u].numAdj ;i++){
		v = grafo[u].adj[i];
		if(grafo[v].visit == 0){
			//grafo[v].pred = u;
			time = buscaProfundidade(grafo, n, v, time);
		}
	}
	time++;
	grafo[u].visit = 2;
	grafo[u].f = time;
	//printf("%d f = %d ",u,grafo[u].f);
	return time;
}
