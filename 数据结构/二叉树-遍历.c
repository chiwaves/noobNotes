typedef struct TreeNode * BinTree;
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
	int flag;
};




void InorderTraversal (BinTree BT)            //�������������
{
	BinTree T = BT;
	Stack S = CreatStack ();
	
	while (T || !IsEmpty(S))
	{
		while (T)
		{
			Push (S, T);
			T = T -> left;
		}
		
		if ( !IsEmpty(S) )
			T = Pop(S);
		printf("%d\n", T -> Data);
		T = T -> right;
	}
}





void PreorderTraversal (BinTree BT)           //��������������� 
{
	BinTree T = BT;
	Stack S = CreatStack();
	
	while (T || !IsEmpty(S))
	{
		while (T)
		{
			Push (S, T);
		    printf("%d\n", T -> Data);
		    T = T -> left;
		}
		
		T = Pop(S);
		T = T -> right;
	}
}




void PostorderTraversal (BinTree BT)           //�������ĺ������ 
{
	BinTree T = BT;
	Stack S = CreatStack();
	
	while (T || !IsEmpty(S))
	{
		while ( T && T -> flag == 0 )   //�ڽ�������һ�����flag�����ж��Ƿ���ʹ���0��ʾδ���ʹ���1��ʾ���ʹ������Ѿ����ʹ����ٴ������Ͳ��ٽ������ѭ�� 
		{
			Push (S, T);
			T -> flag = 1;               
		    T = T -> left;
		}
	
		T = Pop(S);
		if ( T -> right && T -> right -> flag == 0 )   //�����Ҷ�����δ���ʹ����ٴ�ѹ��ջ 
			Push ( S , T );
		else
			printf ( "%d" , T -> Data );
		T = T -> right;
	}
}




void PostorderTraversal (BinTree BT)           //�������ĺ������ �ο����д 
{
	BinTree T = BT;
	Stack S = CreatStack();
	
	while (T || !IsEmpty(S))
	{
		while ( T ) 
		{
			Push (S, T);               
		    T = T -> left;
		}
	
		T = Pop(S);
		if ( T -> flag == 0 )   //�����Ҷ�����δ���ʹ����ٴ�ѹ��ջ 
		{
			T -> flag = 1; 
			Push ( S , T );
		}
		else
			printf ( "%d" , T -> Data );
		T = T -> right;
	}
}





void PostorderTraversal (BinTree BT)           //��β¥ 
{
	BinTree T = BT;
	BinTree Y, K;
	Stack S = CreatStack();
	
	while (T || IsEmpty(S))
	{
		Push (S, T);
		T = T -> left;
	}
	
	T = Pop (S);
	Push (S, T);
	T = T -> right;
	
	if (T -> right == NULL)
	{
		Y = Pop(S);
		printf("%d\n", Y -> Data);
	}
	
	K = Pop(S);
	if (Y != K -> right)  Push (S, K);
	
	
	
	
	
	
	
	
	
	
}