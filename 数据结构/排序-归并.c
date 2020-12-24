void Merge ( ElementType A[], ElementType TmpA[], int L, int R, int RightEnd )
{
	int LeftEnd, NumElements, Tmp;                       //概述：将两个已经有序数列，有序合并至另一个数列TmpA
	int i;

	LeftEnd = R - 1;
	Tmp = L;
	NumElements = RightEnd - L + 1;

	while ( L <= LeftEnd && R <= RightEnd )
	{
		if ( A[L] <= A[R] )
			TmpA[Tmp++] = A[L++];
		else
			TmpA[Tmp++] = A[R++];
	}

	while ( L <= LeftEnd )
		TmpA[Tmp++] = A[L++];
	while ( R <= RightEnd )
		TmpA[Tmp++] = A[R++];

	for ( i = 0; i < NumElements; i++, RightEnd-- )
		A[RightEnd] = TmpA[RightEnd]; 
}



/*-------------------------递归实现开始--------------------------*/

void MSort ( ElementType A[], ElementType TmpA, int L, int RightEnd )       //并归排序本体，递归实现
{
	int Centre;

	if ( L < RightEnd )
	{
		Centre = ( RightEnd + L ) / 2;
		MSort ( A, TmpA, L, Centre );
		MSort ( A, TmpA, Centre + 1, RightEnd );
		Merge ( A, TmpA, L, Centre + 1, RightEnd );
	}
}



void Merge_Sort ( ElementType A[], int N )                             //包装一下，拥有统一的函数接口
{
	ElementType * TmpA;
	TmpA = ( ElementType * ) malloc ( N * sizeof ( ElementType ) );

	if ( TmpA != NULL )
	{
		MSort ( A, TmpA, 0, N-1 );
		free ( TmpA );
	}
	else
		printf("noot enough room!\n");
}

/*------------------------递归实现结束------------------------*/



/*------------------------循环实现开始------------------------*/

void Merge_Pass ( ElementType A[], ElementType TmpA[], int N, int length )
{
	int i, j;

	for ( i = 0; i <= N-2*length; i += 2*length )
		Merge ( A, TmpA, i, i+length, i+2*length-1 );  //当i取到N-2*length时，RightEnd正好是N-1，不溢出，<=没毛病

	/*下面需要细分两种不同的处理方法，如果剩余的有一个长度多的，那就把前一组满长度和最后一组不满的归并了，
	  若一个长度都不满，就直接输入到TmpA数组中*/
	if ( i + length < N )
		Merge ( A, TmpA, i, i + length, N - 1 );
	else
		for ( j = i; j < N; j++ )
			TmpA[j] = A[j];
}



void Merge_Sort ( ElementType A[], int N )
{
	int length;
	ElementType * TmpA;

	length = 1;
	TmpA = ( ElementType * ) malloc ( N * sizeof ( ElementType ) );

	if ( TmpA != NULL )
	{
		while ( length < N )
		{
			Merge_Pass ( A, TmpA, N, length );
			length *= 2;
			Merge_Pass ( TmpA, A, N, length );
			length *= 2;
		}
		free ( TmpA );
	}
	else printf("noot enough room!\n");
}