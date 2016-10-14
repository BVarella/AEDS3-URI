#include <stdio.h>
#include <stdlib.h>

typedef struct adj_list_node_t {
	int destination;
	struct adj_list_node_t* next;
} adj_list_node_t;

typedef struct adj_list_t {
	adj_list_node_t* head;
} adj_list_t;

typedef struct graph_t {
	int vertices;
	adj_list_t* array;
} graph_t;

graph_t* graph_create(int vertices){
	
	graph_t* graph = (graph_t *) malloc(sizeof(graph_t));
	graph->vertices = vertices;

	graph->array = (adj_list_t *) malloc(vertices * sizeof(adj_list_t));

	int i;
	for(i = 0; i < vertices; ++i){
		graph->array[i].head = NULL;
	}

	return graph;
}

void graph_destroy(graph_t* graph){
	
	if(graph){
		if(graph->array){
			int i;
			for (i = 0; i < graph->vertices; ++i){
				adj_list_node_t* current = graph->array[i].head;
				while(current){
					adj_list_node_t* tmp = current;
					current = current->next;
					free(tmp);
				}
			}
			free(graph->array);
		}
		free(graph);
	}
}

static adj_list_node_t* new_adj_list_node(int destination){

	adj_list_node_t* new_node = (adj_list_node_t *) malloc(sizeof(adj_list_node_t));
	new_node->destination = destination;
	new_node->next = NULL;

	return new_node;
}

void add_undirected_edge(graph_t* graph, int vertex_0, int vertex_1){

	adj_list_node_t* new_node = new_adj_list_node(vertex_1);
	new_node->next = graph->array[vertex_0].head;
	graph->array[vertex_0].head = new_node;

	new_node = new_adj_list_node(vertex_0);
	new_node->next = graph->array[vertex_1].head;
	graph->array[vertex_1].head = new_node;
}

void add_directed_edge(graph_t* graph, int source, int destination){

	adj_list_node_t* new_node = new_adj_list_node(destination);
	new_node->next = graph->array[source].head;
	graph->array[source].head = new_node;
}

void dfs_visit(graph_t* graph, int vertex, int* visited){

	visited[vertex] = 1;
	int i;
	for(i = 0; i < graph->vertices; ++i){
		if(!visited[i]){
			adj_list_node_t* current = graph->array[vertex].head;
			while(current){
				if(current->destination == i){
					dfs_visit(graph, i, visited);
				}
				current = current->next;
			}
		}
	}
}

int depth_first_search(graph_t* graph){

	int* visited = (int *) calloc(graph->vertices, sizeof(int));
	int i;
	for(i = 0; i < graph->vertices; ++i){
		if(visited[i] == 0){
			if(i != 0){
				free(visited);
				return 0;
			}
			dfs_visit(graph, i, visited);
		}
	}
	free(visited);
	return 1;
}

int main(){

	int num_edges, num_vertices;
	int src, dest, p;
	int i;

	while(1){
		
		scanf("%d %d", &num_vertices, &num_edges);
		if(num_edges == 0 && num_vertices == 0){
			break;
		}

		graph_t* graph = graph_create(num_vertices);
		graph_t* reverse_graph = graph_create(num_vertices);

		for(i = 0; i < num_edges; ++i){
			scanf("%d %d %d", &src, &dest, &p);
			if(p == 1){
				add_directed_edge(graph, src-1, dest-1);
				add_directed_edge(reverse_graph, dest-1, src-1);
			}
			else if(p == 2){
				add_undirected_edge(graph, src-1, dest-1);
				add_undirected_edge(reverse_graph, src-1, dest-1);
			}
		}

		if(depth_first_search(graph) == 0){
			printf("0\n");
		}
		else if(depth_first_search(reverse_graph) == 1){
			printf("1\n");
		}
		else printf("0\n");

		graph_destroy(graph);
		graph_destroy(reverse_graph);
	
	}
	
	return 0;
}