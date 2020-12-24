int Visited [MaxVertexNum];


InitializeVisited ( int Nv )
{
	Vertex V;
	for ( V = 0 ; V < Nv ; V++ )
		Visited[V] = false;
}




int BFS ( LGraph Graph, Vertex V )
{
	Queue Q;
	Vertex last, next;      //last为正在出入队的这一层的尾巴，next为下一层的尾巴
	PtrToAdjVNode W;
	int count = 1, level = 0;
	
	Q = CreateQueue ( MaxSize );
	Visited [V] = true;
	Enqueue ( Q, V );
	last = V;
	
	while ( !IsEmpty ( Q ) && level <= 6 )
	{
		V = Dequeue ( Q );
		for ( W = Graph -> G[V].FirstEdge; W; W = W->Next )
			if ( !Visited[W->AdjV] )
			{
				Visited [W->AdjV] = true;
				Enqueue ( Q, W );
				count++;
				next = W->AdjV;
			}
		
		if ( last == V )   //V是刚出队的元素，last是这层的队尾。如果这层的队尾出队了
		{
			level++;
			last = next;   //最后刷新的next成为了下一层(将要开始出入队的那层)的队尾
		}
	} 
	DestroyQueue ( Q );
	return count;
}



void Six_Degree_of_Separation ( LGraph Graph )
{
	Vertex V;
	int count;
	InitializeVisited ( Graph->Nv );
	for ( V = 0; V < Graph->Nv; V++ )
	{
		count = BFS ( Graph , V );
		printf ("顶点%d的六度覆盖比例为%.2f%%\n", V, 100.0 * count / Graph->Nv);
	}
}
