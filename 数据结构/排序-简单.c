void Swap( ElementType * a, ElementType * b )
{
	ElementType Tmp = *a;
	*a = *b;
	*b = Tmp;
}


/*-------------------------冒泡排序开始--------------------------*/
void Bubble_Sort( ElementType A[], int N )
{
	int P, i, Flag;

	for ( P = N-1; P >= 0; P-- )
	{
		Flag = 0;
		for ( i = 0; i < P; i++ )
		{
			if ( A[i] > A[i+1] )
			{
				Swap(&A[i], &A[i+1]);
				Flag = 1;
			}
		}
		if ( Flag = 0 )
			break;
	}
}


/*-------------------------插入排序开始--------------------------*/
void InsertSort( ElementType A[], int N )
{
	int p, i;
	ElementType Tmp;

	for ( p = 1; p < N; p++ )
	{
		Tmp = A[p];
		for ( i = p; i > 0 && A[i - 1] > Tmp; i-- )  //p之前已经排好序了
			A[i] = A[i - 1];   //依次往后挪一格
		A[i] = Tmp;
	}
}


/*-------------------------希尔排序开始--------------------------*/
void ShellSort( ElementType A[], int N )
{
	int Si, D, P, i;
	ElementType Tmp;
	int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};

	for ( Si = 0; Sedgewick[Si] >= N; Si++ )
		continue;     //找到不超过待排序列长度的初始增量Sedgewick[Si]

	for ( D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si] )
		for ( P = D; P < N; P++ )
		{
			Tmp = A[P];
			for ( i = P; i >= D && A[i - D] > Tmp; i -= D )
				A[i] = A[i - D];
			A[i] = Tmp;
		}
}


/*---------------------------堆排序开始----------------------------*/
void PercDown( ElementType A[], int p, int N )
{
	int Child, Parent;
	ElementType Tmp = A[p];

	for ( Parent = p; Parent*2+1 < N; Parent = Child )
	{
		Child = Parent*2+1;
		if ( ( Child+1 < N ) && ( A[Child] < A[Child+1] ) )  //Child+1 <= N-1说明Parent有右儿子，等价于Child != N-1
			Child++;
		if ( Tmp > A[Child] )
			break;
		else
			A[Parent] = A[Child];
	}
	A[Parent] = Tmp;
}


void HeapSort( ElementType A[], int N )
{
	int i;
	for ( i = N/2-1; i >= 0; i-- )  //这里A中元素下标从0开始到N-1结束，所以i=N/2-1
		PercDown( A, i, N );
	for ( i = N-1; i > 0; i-- )
	{
		Swap( &A[0], &A[i] );
		PercDown( A, 0, i );
	}
}