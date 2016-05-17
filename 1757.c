// A C / C++ program for Prim's Minimum Spanning Tree (MST) algorithm. 
// The program is for adjacency matrix representation of the graph
 
#include <stdio.h>
//#include <limits.h>
//#include <stdbool.h>
 
// Number of vertices in the graph
int MAX = 100;
#define INF 2147483647;

// A utility function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST
int minKey(int key[], int mstSet[], int V)
{
   // Initialize min value
   int min = INF;
   int min_index;
 	int v;
   for (v = 0; v < V; v++)
	 if (mstSet[v] == 0 && key[v] < min)
		 min = key[v], min_index = v;
 
   return min_index;
}
 
// A utility function to print the constructed MST stored in parent[]
void printMST(int parent[], int n, int graph[MAX][MAX])
{
	int result = 0;
   //printf("Edge   Weight\n");
	int i;
   for (i = 1; i < n; i++){
	  //printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
   		if (graph[i][parent[i]] == 2)
   			++result;
   }
   printf("%d\n", result);

}
 
// Function to construct and print MST for a graph represented using adjacency
// matrix representation
void primMST(int graph[MAX][MAX], int V)
{
	 int parent[V]; // Array to store constructed MST
	 int key[V];   // Key values used to pick minimum weight edge in cut
	 int mstSet[V];  // To represent set of vertices not yet included in MST
 
	 // Initialize all keys as INFINITE
	 int i;
	 for (i = 0; i < V; i++){
		key[i] = INF;
		mstSet[i] = 0;
	}
 
	 // Always include first 1st vertex in MST.
	 key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
	 parent[0] = -1; // First node is always root of MST 
 
	 // The MST will have V vertices
	 int count;
	 for (count = 0; count < V-1; count++)
	 {
		// Pick thd minimum key vertex from the set of vertices
		// not yet included in MST
		int u = minKey(key, mstSet, V);
 
		// Add the picked vertex to the MST Set
		mstSet[u] = 1;
 
		// Update key value and parent index of the adjacent vertices of
		// the picked vertex. Consider only those vertices which are not yet
		// included in MST
		int v;
		for (v = 0; v < V; v++)
 
		   // graph[u][v] is non zero only for adjacent vertices of m
		   // mstSet[v] is false for vertices not yet included in MST
		   // Update the key only if graph[u][v] is smaller than key[v]
		  if (graph[u][v] && mstSet[v] == 0 && graph[u][v] <  key[v])
			 parent[v]  = u, key[v] = graph[u][v];
	 }
 
	 // print the constructed MST
	 printMST(parent, V, graph);
}
 
 
// driver program to test above function
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

	// Print the solution
	primMST(graph, numCidades);

	}
 

 
	return 0;
}