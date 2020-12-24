void Bubble_Sort( ElementType A[], int N )
{
	int P, Q, i, Flag;

	for ( P = N-1, Q = 0; Q < P; P--, Q++ )
	{
		Flag = 0;
		for ( i = 0; i < P; i++ )
			if ( A[i] > A[i+1] )
			{
				Swap(&A[i], &A[i+1]);
				Flag = 1;
			}

		for ( i = N-1; i > Q; i-- )
			if ( A[i] < A[i-1] )
			{
				Swap(&A[i], &A[i-1]);
				Flag = 1;
			}

		if ( Flag = 0 )
			break;
	}
}


void QuickJO( ElementType A[], int Low, int High )
{
	ElementType Pivot = A[Low];

	while ( Low < High )
	{
		while ( Low < High && !A[High]%2 ) 
			High--;
		A[Low] = A[High];
		while ( Low < High && A[Low]%2 ) 
			Low++;
		A[High] = A[Low];
	}
	A[Low] = Pivot;
}