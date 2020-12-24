#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 100
#define INFINITE 65535
typedef int Vertex;  
typedef int WeightType;
WeightType dist[][MaxVertexNum];


typedef struct GNode * PtrToGNode;
struct GNode {
	int Nv;
	int Ne;
	Vertex MinAnimal;
	WeightType MinLength;
	WeightType G [ MaxVertexNum ][ MaxVertexNum ];
};
typedef PtrToGNode MGraph; 



MGraph CreateGraph ( int VertexNum ) 
{
	Vertex V , W;
	MGraph Graph;
	Graph = ( MGraph ) malloc ( sizeof (struct GNode) );
	Graph -> Nv = VertexNum;
	Graph -> Ne = 0;
	for ( V = 0 ; V < Graph -> Nv ; V ++ )
		for ( W = 0 ; W < Graph -> Nv ; W ++ )
			Graph -> G [ V ][ W ] = INFINITE;
	return Graph;
}



typedef struct ENode * PtrToENode;
struct ENode {
	Vertex V1 , V2;
	WeightType Weight;
}; 
typedef PtrToENode Edge;



void InsertEdge ( MGraph Graph , Edge E )
{
	Graph -> G [ E -> V1 ][ E -> V2 ] = E -> Weight;
	Graph -> G [ E -> V2 ][ E -> V1 ] = E -> Weight;
} 



MGraph BuildGraph ( int Nv, int Ne )
{
	MGraph G;
	Edge E;
	int i;
	
	G = CreateGraph ( Nv );
	G -> Ne = Ne;

	if ( G -> Ne != 0 )
	{
		E = ( Edge ) malloc ( sizeof ( struct ENode ) );
		for ( i = 0 ; i < G -> Ne ; i ++ )
		{
			scanf ( "%d %d %d" , &E -> V1 , &E -> V2 , &E -> Weight );
			InsertEdge ( G , E );
		}
	}	
	return G;
} 



void Floyd ( MGraph Graph, WeightType D[][MaxVertexNum] )
{
	Vertex i, j, k;

	for ( i = 0; i < Graph -> Nv ; i++ )
		for ( j = 0; j < Graph -> Nv; j++ )
			D[i][j] = Graph -> G[i][j];

	for ( k = 0; k < Graph -> Nv; k++ )
		for ( i = 0; i < Graph -> Nv; i++ )
			for ( j = 0; j < Graph -> Nv; j++ )
				if ( D[i][j] > D[i][k] + D[k][j] )
					D[i][j] = D[i][k] + D[k][j];
}



void FindAnimal ( MGraph Graph )
{
	int i, j;
	WeightType temp = 0;
	Graph -> MinLength = INFINITE;

	Floyd ( Graph,  dist[][MaxVertexNum] );
	for ( i = 0; i < Graph -> Nv; i++ )
	{
		for ( j = 0; j < Graph -> Nv; j++ )
			if ( dist[i][j] > temp )
				temp = dist[i][j];
		if ( temp < Graph -> MinLength )
		{
			Graph -> MinLength = temp;
			Graph -> MinAnimal = i;
		}
	}
}



int main ()
{
	int N, M;
	MGraph Graph;
	scanf ( "%d%d", &N, &M );
	Graph = BuildGraph ( N, M );
	FindAnimal ( Graph );
	printf ( "%d %d", Graph -> MinAnimal, Graph -> MinLength );
}