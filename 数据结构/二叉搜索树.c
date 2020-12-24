Postion Find (ElementType X, BinTree BST)
{
	if (!BST)
	    return NULL;
	if (X < BST -> Data)
	    return Find (X, BST -> Left);
	else if (X > BST -> Data)
	    return Find (X, BST -> Right);
	else 
	    return BST;
}




Position IterFind (ElementType X, BinTree BST)
{
	while (!BST)
	{
		if (X < BST -> Data)
		    BST = BST -> Left;
		else if (X > BST -> Data)
		    BST = BST -> Right;
		else
		    return BST;
	}
	return NULL;
}




Position FindMin (BinTree BST)
{
	if (!BST)
	    return NULL;
	else if (!BST -> Left)
	    return BST;
	else
	    return FindMin (BinTree -> Left);
}




Position FindMax (BinTree BST)
{
	while (!BST)
		BST = BST -> Right;
	return BST;
}





BinTree Insert (ElementType X, BinTree BST)
{
	if (!BST)
	{
		BST = (BinTree)malloc( sizeof(struct TreeNode) );
		BST -> Data = X;
		BST -> Left = BST -> Right = NULL;
	}
	else if (X < BST -> Data)
	    BST -> Left = Insert (X, BST -> Left);
	else if (X > BST -> Data)
	    BST -> Right = Insert (X, BST -> Right);
//  else X已存在，什么都不做 
	return BST;
}




BinTree Delete (ElementType X, BinTree BST)
{
	Position Tmp;
	
	if (!BST)
	    return NULL;
	    
	if (X < BST -> Data)
	    BST -> Left = Delete (X, BST -> Left);
	else if (X > BST -> Data)
	    BST -> Right = Delete (X, BST -> Right);
	else
	    if (BST -> Left && BST -> Right)
	    {
	    	Tmp = FindMax (BST -> Left);
	    	BST -> Data = Tmp -> Data;
	    	BST -> Left = Delete (X, BST -> Left) 
		}
	    else if (!BST -> Left)
	    {
	    	Tmp = BST;
	    	BST = BST -> Right;
	    	free (Tmp);
		}
		else if (!BST -> Right)
		{
			Tmp = BST;
			BST = BST -> Left;
			free (Tmp);
		}
	return BST;
}























