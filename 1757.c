#include <stdio.h>

#define INF 2147483647;

int MAX = 100;

int minKey(int key[], int mstSet[], int V){

	int min = INF;
	int min_index;
	int v;
	
	for (v = 0; v < V; ++v)
		if (mstSet[v] == 0 && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

void cost(int parent[], int n, int graph[MAX][MAX]){
	
	int result = 0;

	int i;
	for (i = 1; i < n; ++i){
		if (graph[i][parent[i]] == 2)
			++result;
	}

	printf("%d\n", result);

}

void prim(int graph[MAX][MAX], int V){
	
	int parent[V];
	int key[V];
	int mstSet[V];
	int i, count, u, v;

	for (i = 0; i < V; ++i){
		key[i] = INF;
		mstSet[i] = 0;
	}

	key[0] = 0;
	parent[0] = -1;

	for (count = 0; count < V-1; ++count){

		u = minKey(key, mstSet, V);

		mstSet[u] = 1;

		for (v = 0; v < V; ++v)
			if (graph[u][v] && mstSet[v] == 0 && graph[u][v] <  key[v])
				parent[v]  = u, key[v] = graph[u][v];
	}

	cost(parent, V, graph);
}

int main(){

	int numTestes, numCidades, numVisiveis, a, b;
	int i, j, k;
	int graph[MAX][MAX];

	scanf("%d", &numTestes);
	for(i = 0; i < numTestes; ++i){
		
		for(j = 0; j < MAX; ++j){
			for(k = 0; k < MAX; ++k){
				if(j == k)
					graph[j][k] = 0;
				else graph[j][k] = 1;
			}
		}

		scanf("%d %d", &numCidades, &numVisiveis);
		for(j = 0; j < numVisiveis; ++j){
			scanf("%d %d", &a, &b);
			graph[a][b] = 2;
			graph[b][a] = 2;
		}

	prim(graph, numCidades);

	}

	return 0;
}