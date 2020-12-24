struct QNode{
	ElementType * Data;
	int front, rear;
	int Maxsize;
};
typedef struct QNode * Queue;




Queue QueueCreat( int Maxsize )
{
	Queue Q = (Queue) malloc ( sizeof (struct QNode) );
	Q -> Data = (ElementType *) malloc ( sizeof (ElementType) );
	Q -> front = Q -> rear = -1;
	Q -> Maxsize = Maxsize;
	return Q;
}




bool IsEmpty( Queue Q )
{
	return ( (Q -> front) % Q -> Maxsize == Q -> rear );
}

bool IsFull( Queue Q )
{
	return ( (Q -> front + 1) % Q -> Maxsize == Q -> rear );
}



bool Add(Queue Q, ElementType X)
{
	if ( IsFull(Q) )
    {
    	printf("队列已满！\n");
    	return false; 
	} 
	else
	{
		Q -> rear = (Q -> rear + 1) % Q -> Maxsize;
	    Q -> Data[Q -> rear] = X;
	    return true;
	}
}




ElementType Delete(Queue Q)
{
	if ( IsEmpty(Q) )
	{
		printf("队列已空！\n");
		return ERROR; 
	}
	else
	{
		Q -> front = (Q -> front +1) % Q -> Maxsize;
		return Q -> Data[Q -> front];
	}
}
