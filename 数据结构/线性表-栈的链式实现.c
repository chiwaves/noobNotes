typedef struct SNode * Stack       //��ʽջ��ʵ�� 
struct SNode{
	ElementType Data;
	stuct SNode * Next;
};



Stack StackCreat(void)              //����һ����ջͷ��� 
{
	Stack S = (Stack)malloc( sizeof(struct SNode) );
	S -> Next = Null;
	return S;
}



bool IsEmpty(Stack S)                //�ж϶�ջ�Ƿ�Ϊ�� 
{
	return (S -> Next == Null);
}




void Push(Stack S, ElementType X)         //ѹ����ջ 
{
	struct SNode * TmpCell;
	TmpCell = (struct SNode *)malloc( sizeof(struct SNode) );
	TmpCell -> Data = X;
	TmpCell -> Next = S -> Next;
	S -> Next = TmpCell;
 }
 
 
ElementType Pop(Stack S)                 //�����ջ 
{
	struct SNode * Top;
	ElementType TopData;
	
	if ( IsEmpty(S) )
	{
		printf("ջ�գ�\n");
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
