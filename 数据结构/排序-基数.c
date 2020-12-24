#define MaxDigit 4
#define Radix 10

/*桶元素结点*/
typedef struct Node * PtrToNode;
struct Node {
	int key;
	PtrToNode next;
};

/*桶头结点*/
struct HeadNode
{
	PtrToNode head, tail;
};
typedef struct HeadNode Bucket[Radix];  
//一个Bucket结构数组就是一个桶，数组中存了桶中元素组成的链表的表头



int GetDigit ( int D, int X )
{
	int d, i;

	for ( i = 1; i <= D; i++ )
	{
		d = X % Radix;
		X /= Radix;
	}
	return d;
}



/*基数排序 - 次位优先*/
void LSDRadixSort ( ElementType A[], int N )
{
	int D, Di, i;
	Bucket B;
	PtrToNode tmp, p, List = NULL;

	for ( i = 0; i < Radix; i++ )
		B[i].head = B[i].tail = NULL;  //初始化每个桶为空链表
	for ( i = 0; i < N; i++ )
	{
		tmp = ( PtrToNode ) malloc ( sizeof ( struct Node ) );
		tmp -> key = A[i];
		tmp -> next = List;  //这两步妙啊，不断地在表头处插入原始序列。不过，最后形成的是逆序
		List = tmp;
	}

	/*下面开始排序*/
	for ( D = 1; D <= MaxDigit; D++ )  //对于数据的每一位循环处理
		{
			p = List;
			while (p)
			{
				Di = GetDigit ( D, p->key );
				tmp = p;
				p = p->next;
				/*然后将tmp装桶，将其插入桶尾*/
				if ( B[Di].head == NULL )      //如果是桶中的第一个元素
					B[Di].head = B[Di].tail = tmp;
				else
				{
					B[Di].tail->next = tmp;
					B[Di].tail = tmp;
				}
			}
			/*下面是收集的过程，逆序收集到List表头，可得到顺序的链表*/
			List = NULL;
			for ( Di = Radix - 1; Di >= 0; Di-- )
			{
				B[Di].tail->next = List;
				List = B[Di].head;
				B[Di].head = B[Di].tail = NULL;  //将桶清空
			}
		}
	/*将List导入A[]并释放空间*/
	for ( i = 0; i < N; i++ )
	{
		tmp = List;
		A[i] = List->key;
		List = List->next;
		free ( tmp );
	}
}