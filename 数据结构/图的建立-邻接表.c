#define MaxVertexNum 100
typedef int Vertex;
typedef int WeightType;
typedef char DataType;


 
typedef struct GNode * PtrToGNode;
struct GNode {
	int Nv;
	int Ne;
	AdjList G;       //数组G中的元素是结构Vnode 
}; 
typedef PtrToGNode LGraph;



typedef struct Vnode {
	PtrToAdjVNode FirstEdge;  //每个邻接点组成一个链表，FirstEdge指针指向第一个邻接点
	DataType Data;
} AdjList [ MaxVertexNum ];



typedef struct Node * PtrToAdjVNode {
	Vertex AdjV;            //该邻接点下标 
	WeightType Weight;      //该边的权重 
	PtrToAdjVNode Next;
}; 



LGraph CreateGraph ( int VertexNum )
{
	Vertex V;
	LGraph Graph;
	Graph = ( LGraph ) malloc ( sizeof ( struct GNode ) );
	Graph -> Nv = VertexNum;
	Graph -> Ne = 0;
	for ( V = 0 ; V < Graph -> Nv ; V ++ )
		Graph -> G [ V ].FirstEdge = NULL;
	return Graph;
} 



typedef struct ENode * PtrToENode;
struct ENode {
	Vertex V1 , V2;
	WeightType Weight;
};
typedef PtrToENode Edge;



void InsertEdge ( LGraph Graph , Edge E )
{
	NewNode = ( PtrToAdjVNode ) malloc ( sizeof ( struct Node ) );
	NewNode -> AdjV = E -> V2;
	NewNode -> Weight = E -> Weight;
	NewNode -> Next = Graph -> G[E -> V1].FirstEdge;
	Graph -> G[E -> V1].FirstEdge = NewNode;
}



LGraph BuildGraph ()
{
	LGraph Graph;
	Edge E;
	int Nv , i;
	Vertex V;
	
	scanf ( "%d" , &Nv );
	Graph = CreateGraph ( Nv );
	
	scanf ( "%d" , &Graph -> Ne );
	if ( Graph -> Ne != 0 )
	{
		E = ( Edge ) malloc ( sizeof ( struct ENode ) );
		for ( i = 0; i < Ne ; i ++ )
		{
			scanf ( "%d %d %d" , &E -> V1 , &E -> V2 , &E -> Weight );
			InsertEdge ( Graph , E );
		}
	}
	
	for ( V = 0 ; V < G -> Nv ; V++ )
		scanf ( "%c" , Graph -> G[ V ].Data );
	
	return Graph;
} 
