#define INFINITE 65535
#define ERROR -1

Vertex FindMinDist ( MGraph Graph, WeightType dist[] )
{
	Vertex V, MinV;
	WeightType MinDist = INFINITE;

	for ( V = 0; V < Graph -> Nv; V++ )
	{
		if ( dist[V] != 0 && dist[V] < MinDist )
		{
			MinDist = dist[V];
			MinV = V;
		}
	}
	if ( MinDist < INFINITE )
		return MinV;
	else
		return ERROR;
}



int Prim ( MGraph Graph, LGraph MST )
{
	WeightType dist[MaxVertexNum], TotalWeight;
	Vertex parent[MaxVertexNum], V, W;
	int VCount;
	Edge E;

	/*初始化*/
	for ( V = 0; V < Graph -> Nv; V++ )
	{
		dist[V] = Graph[0][V];
		parent[V] = 0;
	}
	TotalWeight = 0;
	VCount = 0;

	/*创建图MST*/
	MST = CreatGraph ( Graph -> Nv );
	E = ( Edge ) malloc ( sizeof ( struct ENode ) );

	dist[0] = 0;
	VCount++;
	parent[0] = -1;

	/*类Dijkstra部分*/
	while (1)
	{
		V = FindMinDist ( Graph, dist )
		if ( V = ERROR )
			break;

		/*将V和它相应的边收录进MST*/
		E -> V1 = parent[V];
		E -> V2 = V;
		E -> Weight = dist[V];
		Insert ( MST, E );
		TotalWeight += dist[V];
		dist[V] = 0;
		VCount++;

		for ( W = 0; W < Graph -> Nv; W++ )
			if ( dist[W] != 0 && Graph[V][W] < INFINITE )
				if ( dist[V] + Graph -> G[V][W] < dist[W] )
				{
					dist[W] = dist[V] + Graph -> G[V][W];
					parent[W] = V;
				}

		if ( VCount < Graph -> Nv )
			TotalWeight = ERROR;
		return TotalWeight;
	}
}