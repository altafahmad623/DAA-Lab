#include <limits.h> 
#include <stdbool.h> 
#include <stdio.h> 
int V=5;
int minKey(int key[], bool mstSet[]) //function to find the minimum key value frm the set of vertices
{ 
	int min = INT_MAX, min_index; 
	int v,i;
	for (v = 0; v < V; v++) 
		if (mstSet[v] == false && key[v] < min) 
			min = key[v], min_index = v; 

	return min_index; 
} 
int printMST(int parent[], int graph[V][V]) // function to print the constructed MST
{ 
	printf("Edge \tWeight\n");
	int i; 
	for (i = 1; i < V; i++) 
		printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]); 
} 
void primMST(int graph[V][V]) 
{ 
	int parent[V]; //stores the constructed MST
	int key[V]; 	
	bool mstSet[V];// To represent set of vertices not yet included in MST 
	int i,count,v; 
	for (i = 0; i < V; i++) 	// Initialize all keys as INFINITE 
		key[i] = INT_MAX, mstSet[i] = false; 
	key[0] = 0; 
	parent[0] = -1; // First node is always root of MST 
	for ( count = 0; count < V - 1; count++) 	// The MST will have V vertices 
	{  
		int u = minKey(key, mstSet); // Pick the minimum key vertex from the set of vertices not yet included in MST 
		mstSet[u] = true; 		// Add the picked vertex to the MST Set 
		for ( v = 0; v < V; v++) 
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) // graph[u][v] is non zero only for adjacent vertices of m mstSet[v] is false for vertices not yet included in MST 
				parent[v] = u, key[v] = graph[u][v]; 
	} 
	printMST(parent, graph); 
} 
int main() 
{ 
	printf("Enter the value of size\n");		
	scanf("%d",&V);
	int i,j;			
	int graph[V][V];
	printf("Enter The values of the weights of edges (or the adjacency matrix)\n");					
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			if(i==j)
				graph[i][j]=0;
			else
			{	
				printf("Enter the weight of edge connecting %d and %d\n",i+1,j+1);
				scanf("%d",&graph[i][j]);
			}	
		}	
	}					
	primMST(graph); 
	return 0; 
} 

