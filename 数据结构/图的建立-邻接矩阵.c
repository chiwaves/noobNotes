#define MaxVertexNum 100
#define INFINITE 65535
typedef int Vertex;                //��ȻVertex����������������int��������Ϊ�����ר�� 
typedef int WeightType;
typedef char DataType;



typedef struct GNode * PtrToGNode;
struct GNode {
	int Nv;
	int Ne;
	WeightType G [ MaxVertexNum ][ MaxVertexNum ];
	DataType Data [ MaxVertexNum ];
}; 
typedef PtrToGNode MGraph; 



MGraph CreateGraph ( int VertexNum )         //��ʼ��һ��ͼ����VertexNum�����㣬û�б�
{
	Vertex V , W;
	MGraph Graph;
	Graph = ( MGraph ) malloc ( sizeof ( struct GNode ) );
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
	Graph -> G [ E -> V2 ][ E -> V1 ] = E -> Weight;   //����ͼ�Ļ���Ҫ�ٲ�һ������� 
} 



MGraph BuildGraph ()
{
	MGraph G;
	Edge E;
	int Nv , i;
	Vertex V;
	
	scanf ( "%d" , &Nv );
	G = CreateGraph ( Nv );
	
	scanf ( "%d" , &( G -> Ne ) );
	if ( G -> Ne != 0 )
	{
		E = ( Edge ) malloc ( sizeof ( struct ENode ) );
		for ( i = 0 ; i < G -> Ne ; i ++ )
		{
			scanf ( "%d %d %d" , &E -> V1 , &E -> V2 , &E -> Weight );
			InsertEdge ( G , E );
		}
	}
	
	for ( V = 0 ; V < G -> Nv ; V ++ )
		scanf ( "%c" , &( G -> Data [ V ] ) );    //����Ҫ��&�𣿣���������һ�������������� �б�Ҫ��ϰһ��Cָ��Ļ����� 
	
	return G;
} 




//ͼ�ļ��װ汾����ģ�黯�����������Ҫ���ڽӾ��󻻳��ڽӱ��Ҫȫ����д����ģ�黯�������дBuildGraph����֮ǰ�Ĳ��� 
 
int Graph[Max][Max] , Nv , Ne;

void BuildGraph ()
{
	int i , j , V1 , V2 , W;
	 
	scanf ( "%d" , &Nv );
	for ( i = 0 ; i < Nv ; i ++ )
		for ( j = 0 ; j < Nv ; j++ )
			Graph [i][j] = 0;           //��INFINITE 
	scanf ( "%d" , &Ne );
	for ( i = 0 ; i < Ne ; i ++ )
	{
		scanf ( "%d%d%d" , &V1 , &V2 , &W );
		Graph [V1][V2] = W;
		Graph [V2][V1] = W;
	}
} 

