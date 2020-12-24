ElementType Median3 ( ElementType A[], int Left, int Right )
{
	int Centre = ( Left + Right ) / 2;

	if ( A[Left] > A[Centre] )
		Swap ( &A[Left], &A[Centre] );
	if ( A[Left] > A[Right] )
		Swap ( &A[Left], &A[Right]);
	if ( A[Centre] > A[Right] )
		Swap ( &A[Centre], &A[Right] );

	Swap ( &A[Centre], &A[Right - 1] ); /* 将基准Pivot藏到右边*/
	/* 只需要考虑A[Left+1] … A[Right-2] */
	return A[Right - 1];
}


void Qsort ( ElementType A[], int Left, int Right )
{
	int Pivot, Cutoff, Low, High;

	if ( Right - Left > Cutoff )
	{
		Pivot = Median3 ( A, Left, Right );
		Low = Left;
		High = Right-1;

		while (1)
		{
			while ( A[++Low] < Pivot ) continue; /* 从 A[Left+1] 到 A[Right-2] */
			while ( A[--High] > Pivot ) continue;
			if ( Low < High )
				Swap ( &A[Low], &A[High] );
			else break;
		}

		Swap ( &A[Right - 1], &A[Low] );
		QuickSort ( A, Left, Low - 1 );
		QuickSort ( A, Low + 1, Right );
	}

	else
		InsertSort ( A+Left, Right-Left+1 );
}


void QuickSort ( ElementType A[], int N )
{
	Qsort ( A, 0, N - 1 );
}