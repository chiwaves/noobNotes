typedef struct TreeNode * BinTree;
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
	int flag;
};




void InorderTraversal (BinTree BT)            //二叉树中序遍历
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





void PreorderTraversal (BinTree BT)           //二叉树的先序遍历 
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




void PostorderTraversal (BinTree BT)           //二叉树的后序遍历 
{
	BinTree T = BT;
	Stack S = CreatStack();
	
	while (T || !IsEmpty(S))
	{
		while ( T && T -> flag == 0 )   //在结点里加了一个标记flag用于判断是否访问过，0表示未访问过，1表示访问过。若已经访问过，再次遇到就不再进入这个循环 
		{
			Push (S, T);
			T -> flag = 1;               
		    T = T -> left;
		}
	
		T = Pop(S);
		if ( T -> right && T -> right -> flag == 0 )   //若有右儿子且未访问过，再次压入栈 
			Push ( S , T );
		else
			printf ( "%d" , T -> Data );
		T = T -> right;
	}
}




void PostorderTraversal (BinTree BT)           //二叉树的后序遍历 参考后改写 
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
		if ( T -> flag == 0 )   //若有右儿子且未访问过，再次压入栈 
		{
			T -> flag = 1; 
			Push ( S , T );
		}
		else
			printf ( "%d" , T -> Data );
		T = T -> right;
	}
}





void PostorderTraversal (BinTree BT)           //烂尾楼 
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