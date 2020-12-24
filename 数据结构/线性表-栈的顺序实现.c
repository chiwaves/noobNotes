typedef int Postion;           //˳��ջ��ʵ�� 
typedef struct SNode
{
	ElementType * Data;
	Postion Top;
	int MaxSize;
 };
 
typedef SNode * Stack;



Stack CreatStack(int MaxSize)    //˳��ջ�Ĵ��� 
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
	S -> Data = (ElementType *)malloc(MaxSize * sizeof(ElementType) );
	S -> Top = -1;
	S -> MaxSize = MaxSize;
	return S;
}




bool IsFull(Stack S)             //�ж�˳��ջ�Ƿ��Ѿ����� 
{
	return (S -> Top == S -> MaxSize - 1);
 } 
 
 


bool IsEmpty(Stack S)            //�ж�˳��ջ�Ƿ�Ϊ�� 
{
	return (S -> Top == -1);
 }
 
 
 

bool Push (Stack S, ElementType X)     //ѹ��ջ 
{
	if ( IsFull(S) )
	{
	    Printf("ջ����\n");
	    return false;
    }
	else
	{
	    S -> Data[++S -> Top] = X;
	    return true;
    }
 }
 
 
 
ElementType Pop (Stack S)                  //����ջ 
{
    if ( IsEmpty(S) )
    {
        printf("ջ�գ�\n");
		return ERROR;
   }
	else
	    return S -> Data[(S -> Top)--];
} 
