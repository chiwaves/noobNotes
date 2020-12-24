void Visit ( Vertex V )
{
	printf ( "正在访问结点%d。\n" , V );
}


void DFS ( LGraph Graph , Vertex V , void (*Visit)(Vertex) )  //以结点V作为出发点遍历图，void (*Visit)(Vertex)这是什么操作？？？ 
{
	PtrToAdjVNode W;
	Visit ( V );
	Visited[V] = true; 
	
	for ( W = Graph -> G[V].FirstEdge ; W ; W = W -> Next )
		if ( !Visited[W -> AdjV] )
			DFS ( Graph , W -> AdjV , Visit );
} 



bool IsEdge ( MGraph Graph , Vertex V , Vertex W )
{
	return Graph -> G[V][W] < INFINITE ? true : false;
}



void BFS ( MGraph Graph , Vertex S )
{
	Queue Q;
	Vertex V , W;
	
	Q = CreateQueue ( MaxSize );
	Visit ( S );
	Visited [S] = true;
	Enqueue ( Q , S );
	
	while ( !IsEmpty ( Q ) )
	{
		V = Dequeue ( Q );
		Visit ( V ); 
		for ( W = 0 ; W < Graph -> Nv ; W ++ )
			if ( IsEdge ( Graph , V , W ) && !Visited[ W ] )
			{
				Visit ( W );
				Visited[W] = true;
				EnQueue ( Q , W );
			}
	}
	
}
