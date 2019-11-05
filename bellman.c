#include <stdio.h>
#include <stdlib.h>
#define INFINITY 99999
struct Edge 
{
	int u;	//start vertex of the edge
	int v;	//end vertex of the edge
	int w;	//weight of the edge (u,v)
};

struct Graph //Graph - it consists of edges
{
	int V;	//total number of vertices in the graph
	int E;	//total number of edges in the graph
	struct Edge *edge;	//array of edges
};
void bellmanford(struct Graph *g, int source);
void display(int arr[], int size);
int main() 
{
	struct Graph *g = (struct Graph*)malloc(sizeof(struct Graph));
	int a,b,i,j;
	printf("Enter the number of vertices\n");
	scanf("%d",&a);
	g->V = a;	//total vertices - 4
	printf("Enter the number of edges\n");
	scanf("%d",&b);	
	g->E = b;	//total edges - 5
	g->edge = (struct Edge*)malloc(g->E * sizeof(struct Edge));
	printf("Enter the u, v and weights of each edge\n");
	for(i=0;i<b;i++)
	{
		
		printf("Enter u for %d ",i);
		scanf("%d",&j);
		g->edge[i].u=j;
		printf("Enter v for %d ",i);
		scanf("%d",&j);
		g->edge[i].v=j;
		printf("Enter w for %d ",i);
		scanf("%d",&j);
		g->edge[i].w=j;		
	}
	bellmanford(g, 0);		//0 is the source vertex
	
	return 0;
}
void bellmanford(struct Graph *g, int source) {
	//variables
	int i, j, u, v, w;
	//total vertex in the graph g
	int tV = g->V;
	
	//total edge in the graph g
	int tE = g->E;
	
	//distance array
	//size equal to the number of vertices of the graph g
	int d[tV];
	
	//predecessor array
	//size equal to the number of vertices of the graph g
	int p[tV];
	
	//step 1: fill the distance array and predecessor array
	for (i = 0; i < tV; i++) {
		d[i] = INFINITY;
		p[i] = 0;
	}
	
	//mark the source vertex
	d[source] = 0;
	
	//step 2: relax edges |V| - 1 times
	for(i = 1; i <= tV-1; i++) {
		for(j = 0; j < tE; j++) {
			//get the edge data
			u = g->edge[j].u;
			v = g->edge[j].v;
			w = g->edge[j].w;
			
			if(d[u] != INFINITY && d[v] > d[u] + w) {
				d[v] = d[u] + w;
				p[v] = u;
			}
		}
	}
	
	//step 3: detect negative cycle
	//if value changes then we have a negative cycle in the graph
	//and we cannot find the shortest distances
	for(i = 0; i < tE; i++) {
		u = g->edge[i].u;
		v = g->edge[i].v;
		w = g->edge[i].w;
		if(d[u] != INFINITY && d[v] > d[u] + w) {
			printf("Negative weight cycle detected!\n");
			return;
		}
	}
	
	//No negative weight cycle found!
	//print the distance and predecessor array
	printf("Distance array: ");
	display(d, tV);
	printf("Predecessor array: ");
	display(p, tV);
}
void display(int arr[], int size) {
	int i;
	for(i = 0; i < size; i ++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
