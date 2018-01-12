#include "stdio.h"
#include<malloc.h>
#include "Dijkstra.h"
void Dijkstra(AdjMGraph G, int v0, int distance[], int path[], DataType tables[])
{
	int n = G.Vertices.size;
	int *s = (int *)malloc(sizeof(int)*n);
	int minDis, i, j, u;
	for (i = 0; i<n; i++)
	{
		distance[i] = G.edge[v0][i];
		s[i] = 0;
		if (i != v0&& distance[i] < MaxWeight)
		{
			path[i] = v0;
			tables[i] = G.Vertices.list[i];
		}
		else
		{
			path[i] = -1;
			//tables[i]=-1;
		}
	}
	s[v0] = 1;
	for (i = 1; i < n; i++)
	{
		minDis = MaxWeight;
		for (j = 0; j < n; j++)
		{
			if (s[j] == 0 && distance[j] <minDis)
			{
				u = j;
				minDis = distance[j];
			}
		}
		if (minDis == MaxWeight)return;
		s[u] = 1;
		for (j = 0; j < n; j++)
		{
			if (s[j] == 0 && G.edge[u][j] < MaxWeight && distance[u] + G.edge[u][j] < distance[j])
			{
				distance[j] = distance[u] + G.edge[u][j];
				path[j] = u;
				tables[j] = tables[u];
			}
		}
	}
}