struct Node{
	ElementType Data;
	struct * Node Next;
};

struct QNode{
	struct * Node front, rear;
};

typedef struct * QNode Queue;




Queue QueueCreat()
{
	Queue Q = ( Queue ) malloc ( sizeof (QNode) );
	Q -> front = Q -> rear = NULL;
	return Q;
}




bool IsEmpty( Queue Q )
	return ( Q -> front == NULL );




void Add(Queue Q, ElementType X)
{
	struct Node * TmpCell;
	TmpCell = (struct Node * )malloc( sizeof (struct Node) );
	TmpCell -> Data = X;
	TmpCell -> Next = NULL;
	
	if ( IsEmpty(Q) )
		Q -> front = Q -> rear = TmpCell;
	else
	{
		Q -> rear -> Next = TmpCell; 
		Q -> rear = TmpCell;
	}
}




ElementType Delete(Queue Q)
{
	struct * Node FrontCell;
	ElementType FrontElem;
	if ( IsEmpty(Q) )
	{
		printf("¶ÓÁÐ¿Õ£¡\n");
		return NULL;
	}
	
	FrontCell = Q -> front
	if (Q -> front == Q -> rear)
		Q -> front = Q -> rear = NULL;
	else
	    Q -> front = FrontCell -> Next;
	
	FrontElem = FrontCell -> Data;
	free(FrontCell);
	return FrontElem;
}
