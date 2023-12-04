#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 9

int minDistance(int dist[], bool sptSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;
	return min_index;
}

void printSolution(int dist[])
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i =0; i < V; i++)
		printf("%d \t\t\t\t %d\n", i, dist[i]);
}

void printpath(int pathfinder[])
{
	printf("Path is: ");
	int x, i, y;
	for (i = 0; i < 9; i++)
	{
		x = 0;
		y = 0;
		while (y == 0)
		{
			if (pathfinder[x] == i)
			{
				printf("%d ", x);
				y = 1;
			}
			else x++;
		}
	}
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V];
	bool sptSet[V];
	int pathfinder[V] = {V-1,V-1,V-1,V-1,V-1,V-1,V-1,V-1,V-1};

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;
	dist[src] = 0;

	int x = 0;
	for (int count = 0; count < V-1; count++)
	{
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		pathfinder[u] = x;
		x++;

		for (int v =0; v < V; v++)
		{
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
		}
	}
	printSolution(dist);
	printpath(pathfinder);
}


int main()
{
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0);

    return 0;
}

// i)   I implememnted the code for including the path as well.
// ii)  Yes, this idea will work for directed graphs as well since the adjancency matrix will be updated accordingly and it will not
//      the algorithm. Whenever there is an edge from u to v the weight of the edge will be there as the entry in the matrix. If there 
//      is no edge the entry will be 0.
// iii) The time complexity can be improved by using a min heap to extract the minimum distance vertex. The time complexity then
//      becomes O((nlog(n)). This is so because now extracting the minimum distance vertex doesn't take O(n) time but rather O(log(n)).
