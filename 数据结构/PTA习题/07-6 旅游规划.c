#include<stdio.h>
#include<stdlib.h>


#define MAXV 666
#define INFINITE 1000

typedef struct
{
	int Dist[MAXV][MAXV];
	int Cost[MAXV][MAXV];
	int Visited[MAXV];
	int MinDist[MAXV];
	int MinCost[MAXV];
	int VertexNum, EdgeNum;
} Graph;



void InitializeG ( Graph * G )
{
	int i, j;
	for ( i = 0; i < MAXV; i++ )
		{
			for ( j = 0; j < MAXV; j++ )
				G -> Dist[i][j] = G->Cost[i][j] = INFINITE;
			G->Visited[i] = 0;
			G->MinDist[i] = G->MinCost[j] = INFINITE;
		}
}



void ReadG ( Graph * G, int * S, int * D )
{
	int i, V1, V2;

	scanf ( "%d %d %d %d", &G->VertexNum, &G->EdgeNum, S, D );
	for ( i = 0; i < G->EdgeNum; i++ )
	{
		scanf ( "%d %d", &V1, &V2 );
		scanf ( "%d %d", &G->Dist[V1][V2], &G->Cost[V1][V2] );
		G->Dist[V2][V1] = G->Dist[V1][V2];
		G->Cost[V2][V1] = G->Cost[V1][V2];
	}
}



void Dijkstra ( Graph * G, int S )
{
	int V, W;
	int minD = INFINITE;

	G->MinDist[S] = G->MinCost[S] = 0;
	G->Visited[S] = 1;
	for ( V = 0; V < G->VertexNum; V++ )
	{
		G->MinDist[V] = G->Dist[S][V];
		G->MinCost[V] = G->Cost[S][V];
	}


	for ( V = 0; V < G->VertexNum - 1; V++ )
	{
		for ( W = 0; W < G->VertexNum; W++ )
			if ( ( G->Visited[W] == 0 ) && ( G->MinDist[W] < minD ) )
				minD = G->MinDist[W];

		if ( minD < INFINITE )
			G->Visited[W] = 1;
		else
			break;

		for ( W = 0; W < G->VertexNum; W++ )
		{
			if ( !G->Visited[W] )
				if ( G->MinDist[W] > G->MinDist[V] + G->Dist[V][W] )
				{
					G->MinDist[W] = G->MinDist[V] + G->Dist[V][W];
					G->MinCost[W] = G->MinCost[V] + G->Cost[V][W];
				}
				else if ( ( G->MinDist[W] == G->MinDist[V] + G->Dist[V][W] )
				&& ( G->MinCost[W] > G->MinCost[V] + G->Cost[V][W] ) )
					G->MinCost[W] = G->MinCost[V] + G->Cost[V][W];
		}
	}
}



int main ()
{
	int S, D;
	Graph * G = malloc ( sizeof ( Graph ) );
	
	InitializeG ( G );
	ReadG ( G, &S, &D );
	Dijkstra ( G, S );
	printf ( "%d %d\n", G->MinDist[D], G->MinCost[D] );

	return 0;
}