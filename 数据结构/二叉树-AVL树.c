typedef TreeNode * AVLTree
struct TreeNode {
	ElementType X;
	AVLTree Left;
	AVLTree Right;
};


int Max ( int a , int b )
{
	return a > b ? a : b;
}


int GetHeight ( AVLTree A )
{
	int HL , HR;
	if ( ! A )
		return 0;
	HL = GetHeight ( A -> Left );
	HR = GetHeight ( A -> Right );
	return ( Max ( HL , HR ) + 1 );
}


AVLTree LRotation ( AVLTree A )
{
	AVLTree B = A -> Left;
	A -> Left = B -> Right;
	B -> Right = A;
	return B;
}


AVLTree RRotation ( AVLTree A )
{
	AVLTree B = A -> Right;
	A -> Right = B -> Left;
	B -> Left = A;
	return B;
}


AVLTree LR ( AVLTree A )
{
	A -> Left = RRotation ( A -> Left );
	return LRotation ( A );
}


AVLTree RL ( AVLTree A )
{
	A -> Right = LRotation ( B );
	return RRotation ( A );
}


AVLTree Insert ( ElementType X , AVLTree A )
{
	if ( !A )
	{
		A = ( AVLTree ) malloc ( sizeof ( struct TreeNode ) );
		A -> Data = X;
		A -> Left = A -> Right = NULL;
	}
	
	else if ( X < A -> Data )
		A -> Left = Insert ( X , A -> Left );
		if ( GetHeight ( A -> Left ) - GetHeight ( A -> Right ) == 2 );
		{
			if ( X < A -> Left -> Data )
				A -> Left = LRotation ( A );
			else 
				A -> Left = LRRotation ( A );
		}
		
	else if ( X > A -> Data )
	{	
		A -> Right = Insert ( X , A -> Right );
		if ( GetHeight ( A -> Left ) - GetHeight ( A -> Right ) == -2 );
		{
			if ( X > A -> Left -> Data )
				A -> Right = RRotation ( A );
			else 
				A -> Right = RLRotation ( A );
		}
	}
	return A;
}
