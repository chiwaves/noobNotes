#define INFINITE 65535
#define ERROR -1

void Unweighted( LGraph Graph, WeightType dist[], Vertex path[], Vertex S )   //邻接表储存 - 无权图的单源
{
	Queue Q;
	Vertex V;
	PtrToAdjVNode W;

	Q = CreateQueue( MaxSize );
	dist[S] = 0;
	Enqueue( S, Q );

	while ( !IsEmpty( Q ) )
	{
		V = Dequeue( Q );
		for ( W = G -> G[V].FirstEdge; W; W = W->Next )
			if ( dist[W] == INFINITE )
			{
				dist[W] = dist[V]+1;
				path[W] = V;
				Enqueue( W, Q );
			}
	}
}


Vertex FindMinDist( MGraph Graph, WeightType dist[], bool collected[] ) //邻接矩阵储存 - 有权图的单源最短路径 - 狄克斯特拉算法
{
	Vertex V, MinV;
	int MinDist = INFINITE;

	for ( int V = 0; V < Graph->Nv; V++ )
		if ( collected[V] == false && dist[V] < MinDist )
		{
			MinDist = dist[V];
			MinV = V;
		}

	if ( MinDist < INFINITE )
		return MinV;
	else
		return ERROR;
}


bool Dijkstra( MGraph Graph, WeightType dist[], Vertex path[], Vertex S )
{
	int collected[MaxVertexNum];
	Vertex V, W;

	for ( V = 0; V < Graph->Nv; V++ )
	{
		dist[V] = Graph->G[S][V];
		collected[V] = false;
		if ( dist[V] < INFINITE )
			path[V] = S;
		else
			path[V] = -1;
	}

	dist[S] = 0;
	collected[S] = true;

	while (1)
	{
		V = FindMinDist( Graph, dist, collected );  //V是未收录顶点中dist最小者
		if ( V == ERROR )   //若V已经全部收录完毕了，则跳出循环
			break;
		collected[V] = true;
		for ( W = 0; W < Graph->Nv; W++ )
			if ( collected[W] == false && Graph->G[V][W] < INFINITE )
			{
				if ( Graph->G[V][W] < 0 )  //有负边，无法正确处理，返回错误标记
					return false;
				if ( dist[V] + Graph->G[V][W] < dist[W] )
				{
					dist[W] = dist [V] + Graph->G[V][W];
					path[W] = V;
				}
			}		
	}
	return true;
}





bool Floyd( MGraph Graph, WeightType D[][MaxVertexNum], Vertex path[][MaxVertexNum] )   //邻接矩阵 - 有权图的多源最短路径
{
	Vertex i, j, k;

	for ( i = 0; i < Graph->Nv ; i++ )
		for ( j = 0; j < Graph->Nv; j++ )
		{
			D[i][j] = Graph->G[i][j];
			path[i][j] = -1;
		}

	for ( k = 0; k < Graph->Nv; k++ )
		for ( i = 0; i < Graph->Nv; i++ )
			for ( j = 0; j < Graph->Nv; j++ )
				if ( D[i][j] > D[i][k] + D[k][j] )
				{
					D[i][j] = D[i][k] + D[k][j];
					if ( i==j && D[i][j] < 0 )  //发现负值圈
						return false;           //不能正确解决，返回错误标记
					path[i][j] = k;
				}
	return true;
}