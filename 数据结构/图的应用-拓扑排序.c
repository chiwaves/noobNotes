bool TopSort ( LGraph Graph, TopOrder[] )
{
	int Indegree[MaxVertex], cnt = 0;  //数组Indegree为各个结点的入度值
	Vertex V;
	PtrToAdjVNode W;
	Queue Q = CreateQueue ( Graph -> Nv )

	//初始化数组Indegree[]
	for ( V = 0; V < Graph -> Nv; V++ )
		Indegree[V] = 0;

	//遍历图，得到每个结点的入度值
	for ( V = 0; V < Graph -> Nv; V++ )
		for ( W = Graph -> G[V].FirstEdge; W; W = W -> Next )
			Indegree[W -> AdjV]++;

	//将所有入度为0的顶点入列
	for ( V = 0; V < Graph -> Nv; V++ )
		if ( Indegree[V] == 0 )
			EnQueue ( Q, V );

	//拓扑排序
	while ( !IsEmpty ( Q ) )
	{
		V = DeQueue ( Q );
		TopOrder[cnt++] = V;

		for ( W = Graph -> G[V].FirstEdge; W; W++ )
			if ( --Indegree[W -> AdjV] == 0 )
				EnQueue ( Q, W -> AdjV );
	}

	if ( cnt < Graph -> Nv )   //有回路
		return false;
	else
		return true;
}