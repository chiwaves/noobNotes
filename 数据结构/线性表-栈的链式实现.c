typedef struct SNode * Stack       //链式栈的实现 
struct SNode{
	ElementType Data;
	stuct SNode * Next;
};



Stack StackCreat(void)              //创建一个堆栈头结点 
{
	Stack S = (Stack)malloc( sizeof(struct SNode) );
	S -> Next = Null;
	return S;
}



bool IsEmpty(Stack S)                //判断堆栈是否为空 
{
	return (S -> Next == Null);
}




void Push(Stack S, ElementType X)         //压结入栈 
{
	struct SNode * TmpCell;
	TmpCell = (struct SNode *)malloc( sizeof(struct SNode) );
	TmpCell -> Data = X;
	TmpCell -> Next = S -> Next;
	S -> Next = TmpCell;
 }
 
 
ElementType Pop(Stack S)                 //弹结出栈 
{
	struct SNode * Top;
	ElementType TopData;
	
	if ( IsEmpty(S) )
	{
		printf("栈空！\n");
		return NULL;
	}
	else
	{
		Top = S -> Next;
		S -> Next = Top -> Next;
		TopData = Top -> Data;
		free(Top);
		return TopData;
	}
}
