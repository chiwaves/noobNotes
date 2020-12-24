typedef Vertex ElementType;  //默认元素可以用非负整数表示
typedef Vertex SetName;      //默认用根结点的下标作为集合名称
typedef ElementType SetType[MaxVertexNum];  //假设集合元素下标从0开始



void InitializeVSet ( SetType S, int N )
{
	ElementType X;
	for ( X = 0; X < N; X++ )
		S[X] = -1;
}



void Union ( SetType S, SetName Root1, SetName Root2 )
{
	if ( S[Root2] < S[Root1] )  //S[Root]都为负数，越小说明集合中元素越多，此处是2集合比较大，将1并入2
	{
		S[Root2] += S[Root1];
		S[Root1] = Root2;       //将Root1的Parent赋值为Root2
	}
	else
	{
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	}
}



SetName Find ( SetType S, ElementType X )
{
	if ( S[X] < 0 )  return X;
	else return S[X] = Find ( S, S[X] );   //路径压缩
}



bool CheckCycle ( SetType VSet, Vertex V1, Vertex V2)
{
	Vertex Root1, Root2;

	Root1 = Find ( VSet, V1 );
	Root2 = Find ( VSet, V2 );

	if ( Root1 == Root1 )
		return false;
	else
	{
		Union ( VSet, Root1, Root2 );
		return true;
	}
}
/*-------------------- 并查集定义结束 --------------------*/
 


/*-------------------- 边的最小堆定义 --------------------*/

void PercDown ( Edge ESet, int p, int N )  //改编自代码4.24中的PercDown，有挺多细节的改动以适应不同情况
{
	int Parent, Child;
	struct ENode X;   //ESet数组中的元素是边结构，而不是边结构指针，所以不是Edge X

	X = ESet[p];
	/*由于此处是从ESet[0]开始储存元素，原版代码4.24中是从Data[1]开始，所以Parent * 2 + 1才是Parent的左儿子*/
	for ( Parent = p; ( Parent * 2 + 1 ) < N; Parent = Child )
	{
		Child = Parent * 2 + 1;
		if ( ( Child != N - 1 ) && ( ESet[Child].Weight > ESet[Child + 1].Weight ) )
			Child++;
		if ( X.Weight <= ESet[Child].Weight )
			break;
		else
			ESet[Parent] = ESet[Child];
	}
	ESet[Parent] = X;
}



/*将图的边存入数组ESet，并将其初始化为最小堆*/
void InitializeESet ( LGraph Graph, Edge ESet )
{
	Vertex V;
	PtrtoAdjVNode W;
	int ECount = 0;

	for ( V = 0; V < Graph -> Nv; V++ )
		for ( W = Graph -> G[V].FirstEdge; W; W = W -> NextEdge )
			if ( V < W -> AdjV )   //为避免重复录入无向图的边，只收录V1 < V2的边
			{
				ESet[ECount].V1 = V;
				ESet[ECount].V2 = W -> AdjV;
				ESet[ECount++].Weight = W -> Weight;
			}

	for ( ECount = Graph -> Ne / 2; ECount > 0; ECount-- )   //将ESet调整为最小堆
		PercDown ( ESet, ECount, Graph -> Ne );
}



/* 给定当前堆的大小CurrentSize，将当前最小边位置弹出(放到末尾并无视)，并调整最小堆 */
int GetEdge ( Edge ESet, int CurrentSize )
{
	Swap ( &ESet[0], &ESet[CurrentSize - 1] );  
	//将最小边与当前堆的堆末尾的边交换位置，这样搞，返回的CurrentSize - 1既是堆的规模，又是最小边的位置，很巧妙
	PercDown ( ESet, 0, CurrentSize - 1 )
/*	原本的堆末放到堆顶，但堆顶的左右儿子都符合最小堆的有序性，所以从堆顶开始下滤
	现在堆的规模是CurrentSize - 1，之后都是交换过来的曾经的堆顶(已经被无视了，不算在堆内)	*/
	return CurrentSize - 1;
}
/* 学完堆排序后的更新，这里用了堆排序的方法。但是有个疑问，这里先构建了最小堆，然后依次将堆顶最小元素放到堆末尾并隔离开，
在这里和直接将堆顶最小元素弹出有什么区别？可以在Kruskal函数中用判断是否堆空，来代替用返回值CurrentSize-1判断是否边集合是
否空了。难道仅仅是为了保留ESet中的数据吗，可能在使用时，Kruskal函数仅仅作为一小部分，其它部分还可以重复利用ESet数组 */

/*-------------------- 最小堆定义结束 --------------------*/




int Kruskal ( LGraph Graph, LGraph MST )
{
	WeightType TotalWeight = 0;
	int ECount = 0, NextEdge;
	SetType VSet;   //顶点数组
	Edge ESet;      //边数组，数组中元素为struct ENode，等价写法有，*ENode ESet; 或 ENode ESet[];

	InitializeVSet ( VSet, Graph -> Nv );  //初始化并查集，使每个顶点为一个独立的集合
	ESet = ( Edge ) malloc ( sizeof ( struct ENode ) );
	InitializeESet ( Graph, ESet );
	MST = CreateGraph ( Graph -> Nv );

	NextEdge = Graph -> Ne;  //原始边集合规模
	while ( ECount < Graph -> Nv -1 )  //当收集的边数量不能构成最小生成树时
	{
		NextEdge = GetEdge ( ESet, NextEdge ); //NextEdge为边集合中最小边位置
		if ( NextEdge < 0 )  //边集合已空
			break;
		if ( CheckCycle ( VSet, ESet[NextEdge].V1, ESet[NextEdge].V2 ) == true )
		{
			InsertEdge ( MST, ESet + NextEdge );  //必须不是*(ESet+NextEdge)，InsertEdge函数参数为指向struct ENode的指针，数组ESet中存的是struct ENode
			TotalWeight += ESet[NextEdge].Weight;
			ECount++;
		}
	}
	if ( ECount < Graph -> Nv -1 )
		TotalWeight = ERROR;   //设置错误标记，表示生成树不存在

	return TotalWeight;
}