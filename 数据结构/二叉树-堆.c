#define MAXDATA 1000
#define ERROR -1

typedef struct HNode* Heap;
struct HNode 
{
	ElementType * Data;      // Data[] Êý×é 
	int size;
	int Capacity;
}; 
typedef Heap MaxHeap;


/*-------------------------创建堆--------------------------*/

MaxHeap CreatHeap( int Maxsize )
{
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
	H->Data = (ElementType* )malloc((Maxsize+1)*sizeof(ElementType));
	H->size = 0;
	H->Capacity = Maxsize;
	H->Data[0] = MAXDATA;
	return H;
}


/*-------------------------判断堆满--------------------------*/

bool IsFull( MaxHeap H )
{
	return ( H->size == H->Capacity );
}


/*-------------------------将元素X插入最大堆--------------------------*/

bool Insert( ElementType X, MaxHeap H )
{
	int i;
	if ( IsFull( H ) )
	{
		printf ("¶ÑÒÑÂú\n");
		return false;
	}
	
	for ( i = ++H->size; X > H->Data[i/2]; i /= 2)
		H->Data[i] = H->Data[i/2];
	H->Data[i] = X;
	return true;
}


/*-------------------------判断堆空--------------------------*/

bool IsEmpty( MaxHeap H )
{
	return ( H->size == 0 );
}


/*-------------------------取出最大的元素，并删除节点--------------------------*/

ElementType Delete( MaxHeap H )
{
	int Parent, Child;
	ElementType temp, Max;
	
	if ( IsEmpty( H ) )
		return ERROR;
	
	Max = H->Data[1];
	temp = H->Data[H->size--];
	
	for ( Parent = 1; 2*Parent <= H->size; Parent = Child )
	{
		Child = Parent*2;
		if ( ( Child != H->size ) && ( H->Data[Child] < H->Data[Child+1] ) )
			Child++;
		if ( temp >= Data[Child] )
			break;
		else
			H->Data[Parent] = H->Data[Child];
	}
	
	H->Data[Parent] = temp;
	return Max;
}


/*-------------------------建造最大堆，先随机生成数组，从最后一棵有左儿子的子树开始执行向下过滤，直到树根--------------------------*/

void PercDown( MaxHeap H, int Parent)
{
	int Child;
	ElementType temp = H->Data[Parent];
	
	for ( ; Parent*2 <= H->size; Parent = Child )
	{
		Child = Parent*2;
		if ( ( Child != H->size ) && ( H->Data[Child] < H->Data[Child+1] ) )
			Child++;
		if ( temp >= Data[Child] )
			break;
		else
			H->Data[Parent] = H->Data[Child];
	}
	
	H->Data[Parent] = temp;
}


void BuildHeap( MaxHeap H )
{
	int i;
	for ( i = H->size/2; i; i-- )
		PercDown( H, i );
}



/*-------------------------哈夫曼树--------------------------*/

typedef struct TreeNode* HuffmanTree;       // ¹þ·òÂüÊ÷£¬Ê÷µÄÃ¿¸ö½áµã´æ´¢ÔÚ¶ÑµÄData[]Êý×éÖÐ 
struct TreeNode
{
	int weight;
	HuffmanTree Left, Right;
};


HuffmanTree BuildHuffman( MinHeap H )
{
	int i;
	HuffmanTree T;
	for ( i = 1; i < H->size; i++ )
	{
		T = (HuffmanTree)malloc(sizeof(struct TreeNode));
		T -> Left = Delete( H );
		T -> Right = Delete( H );
		T -> Weight = T->Left->Weight + T->Right->Weight;
		Insert( T, H );
	} 
	T = Delete( H );
	return T;
}