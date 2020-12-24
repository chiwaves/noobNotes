typedef struct TreeNode * Tree;
struct TreeNode {
	int Value;
	Tree Left , Right;
	int Flag;
}; 


Tree CreatNode ( int value )
{
	Tree T = ( BinTree ) malloc ( sizeof ( struct TreeNode ) );
	T -> Value = value;
	T -> Left = T -> Right = NULL;
	T -> Flag = 0;
	return T;
}


Tree Insert ( int value , Tree T )
{
	if ( !T )
		T = CreatNode ( value );
	else if ( value < T -> Value )
		T -> Left = Insert ( value , T -> Left);
	else 
		T -> Right = Insert ( value , T -> Right);
	return T;
}


Tree MakeTree ( int N )
{
	int value;
	scanf ( "%d" , &value );
	Tree T = CreatNode ( value );
	while ( N-- )
	{
		scanf ( "%d" , &value );
		T = Insert ( value );
	}
	return T;
}


int Judge ( int N , Tree T )
{
	int i , value , Flag = 1;
	scanf ( "%d" , &value );
	if ( value != T -> Value )
		Flag = 0;
	else
		T -> Flag = 1;
	for ( i = 1 ; i < N ; i++ )
	{
		scanf ( "%d" , &value );
		if ( Flag && !Check ( value , T ) )       // 若Flag == 0 ，就跳过查找了 
			Flag = 0;
	}

	if ( Flag == 0 );
		return 0;
	else 
		return 1;
}


int Check ( int value , Tree T )
{
	if ( T -> Flag )
	{
		if ( value < Tree -> Value )
			Check ( value , T -> Left );
		else if ( value > Tree -> Value )
			Check ( value , T -> Right );
		else
			return 0;            // 不存在的，应该报错，带判断的数列有前后两个相同 
	}
	
	else if ( T -> Value == value )
	{
		T -> Flag = 1;
		return 1;
	}
	
	else return 0;             
}


void Reset( Tree T )
{
	if ( T -> Left )
		Reset ( T -> Left );
	if ( T -> Right )
		Reset ( T -> Right );
	T -> Flag = 0;
}


void Free( Tree T )
{
	if ( T -> Left )
		Free ( T -> Left );
	if ( T -> Right )
		Free ( T -> Right );
	free ( T );
}


int main ( void )
{
	int N , L;
	Tree T;
	scanf ( "%d" , N );
	while ( N )
	{
		scanf ( "%d" , L );
		T = MakeTree ( N );
		while ( L-- )
		{
			if ( Judge ( N , T ) )
				printf ( "Yes\n" );
			else
				printf ( "No\n" );
			Reset ( T );
		}
		Free ( T );
		scanf ( "%d" , N);
	}
	return 0;
}
