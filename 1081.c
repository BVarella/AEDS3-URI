#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

void dfs_visit(int graph[MAX_VERTICES][MAX_VERTICES], int num_vertices, int i, int *visited, int spaces){
	int j, k;
	visited[i] = 1;
	for(j = 0; j < num_vertices; ++j){
		if(graph[i][j] == 1){
			if(!visited[j]){
				for(k = 0; k < spaces; ++k){
					printf(" ");
				}
				printf("%d-%d pathR(G,%d)\n", i, j, j);
				dfs_visit(graph, num_vertices, j, visited, spaces+2);
			}
			else{
				for(k = 0; k < spaces; ++k){
					printf(" ");
				}
				printf("%d-%d\n", i, j);
			}
		}
	}
}

void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int num_vertices){
	int *visited = (int *) calloc(num_vertices, sizeof(int));
	int i, j;
	for(i = 0; i < num_vertices; ++i){
		int connected = 0;
		if(visited[i] == 0){
			for(j = 0; j < num_vertices; ++j){
				if(graph[i][j] == 1){
					connected = 1;
					break;
				}
			}
			if(connected == 1) printf("\n");
			dfs_visit(graph, num_vertices, i, visited, 2);
		}
	}
	free(visited);
}

int main(){

	int num_tests;
	int num_vertices, num_edges;
	int graph[MAX_VERTICES][MAX_VERTICES];
	int source, dest;
	int i, j, k;

	scanf("%d", &num_tests);
	for(i = 0; i < num_tests; ++i){

		printf("Caso %d:", i+1);
		
		for(j = 0; j < MAX_VERTICES; ++j){
			for(k = 0; k < MAX_VERTICES; ++k){
				graph[j][k] = 0;
			}
		}

		scanf("%d %d", &num_vertices, &num_edges);
		for(j = 0; j < num_edges; ++j){
			scanf("%d %d", &source, &dest);
			graph[source][dest] = 1;
		}

		dfs(graph, num_vertices);
		printf("\n");
	}

	return 0;
}
