void BubbleSort ( ElementType A[], int N )
{
	int p, i, flag;
	for ( p = N-1; p > 0; p-- )
	{
		flag = 0;
		for ( i = 0; i < p; i++ )
			if( A[i+1] < A[i] )
			{
				Swap ( &A[i+1], &A[i] );
				flag = 1;
			}
		if ( flag == 0 )
			break;
	}
}


//--------------------------------------------------------
void InsertSort( ElementType A[], int N )
{
	int p, i;
	ElementType tmp;
	for ( p = 1; p <= N-1; p++ )
	{
		tmp = A[p];
		for( i = p-1; i > 0 && tmp < A[i]; i-- )
			A[i+1] = A[i];
		A[i+1] = tmp;
	}
}


//------------------------------------------------------
void ShellSort( ElementType A[], int N )
{
	int Si, D, p, i;
	ElementType tmp;
	int Sed[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};

	for ( Si = 0; Sed[Si] >= N; Si++ )
		continue;
	for ( D = Sed[Si]; D > 0; D = Sed[++Si] )
	{
		for ( p = 0; p < N; p++ )
		{
			tmp = A[p];
			for( i = p; i-D >= 0 && tmp < A[i-D]; i= i-D )
				A[i] = A[i-D];
			A[i] = tmp;
		}
	}
}


//-----------------------------------------------------------------------------
void Merge( ElementType A[], ElementType TmpA[], int L, int R, int RightEnd )
{
	int tmp, N;
	N = RightEnd - L + 1;
	tmp = L;
	while ( L < R && R < RightEnd )
	{
		if ( A[L] <= A[R] )
			TmpA[tmp++] = A[L++];
		else
			TmpA[tmp++] = A[R++];
	}
	while ( L < R )
		TmpA[tmp++] = A[L++];
	while ( R < RightEnd )
		TmpA[tmp++] = A[R++];

	while ( N-- )
		A[RightEnd] = TmpA[RightEnd];
}

void MSort ( ElementType A[], ElementType TmpA[], int L, int RightEnd )
{
	if ( L < RightEnd )
	{
		MSort( A[], TmpA[], L, (L+RightEnd)/2);
		MSort( A[], TmpA[], (L+RightEnd)/2+1, RightEnd );
		Merge( A[], TmpA[], L, R, RightEnd);
	}
}

void MergeSort ( ElementType A[], int N )
{
	ElementType * TmpA;
	TmpA = ( ElementType* ) malloc ( N * sizeof (ElementType) );
	if ( TmpA != NULL )
	{
		MSort ( A, TmpA, 0, N-1 );
		free ( TmpA );
	}
	else
		printf("not enough room\n");
}

//---------------------------------------------------------------------------
ElementType Median3 ( ElementType A[], int L, int R )
{
	int C = (L+R)/2
	if ( A[L] < A[C] )
		Swap ( &A[L], &A[C] );
	if ( A[L] < A[R] )
		Swap ( &A[L], &A[R] );
	if ( A[C] < A[R] )
		Swap ( &A[C], &A[R] );
	Swap ( &A[C], &A[R-1] );
	return A[R-1];
}

void Qsort ( ElementType A[], int L, int R )
{
	int Pivot, Low, High, cutoff;
	if ( R-L+1 > cutoff )
	{
		Pivot = Median3 ( A, L, R);
		High = R-1;
		while(1)
		{
			while ( A[++Low] < Pivot );
			while ( A[--High] > Pivot );
			if ( Low < High )
				Swap ( &A[Low], &A[High] );
			else
				break;
		}
		Swap( &A[R-1], &A[Low] )
		Qsort ( A, Low+1, R );
		Qsort ( A, L, Low-1 );
	}
	else
		InsertSort ( A+L, R-L+1 );
}

void QuickSort ( ElementType A[], int N )
{
	Qsort ( A, 0, N-1 );
}

//----------------------------------------------------------
void HeapSort ( ElementType A[], int N )
{
	int i;
	for ( i = N/2-1; i >= 0; i-- )
		PrecDown ( A, i, N )
	for ( i = N-1; i > 0; i-- )
	{
		Swap ( &A[0], &A[i] );
		PrecDown ( A, 0, i );
	}
}

void PrecDown ( ElementType A[], int p, int N )
{
	int parrent, child;

	for ( parent = p; parent*2+1 < N; parrent = child )
	{
		child = parrent*2+1;
		if ( (child+1 < N) && (A[child+1] > A[child]) )
			child++;
		if ( A[child] > A[p] )
			A[parrent] = A[child];
		else
			break;
	}
	A[parrent] = A[p];
}


//----------------------------------------------------------------------------------
int Partition (ElemType A[], low, high)
{
	ElemType pivot = A[low];
	while (low < high)
	{
		while (low < high && A[high] >= pivot)
			high--;
		A[low] = A[high];
		while (low < high && A[low] <= pivot)
			low++;
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;
}

void QuickSort (ElemType A[], int low, int high)
{
	int pivotpos;
	if (low < high)
	{
		pivotpos = Partition (A, low, high);
		QuickSort (A, low, pivotpos-1);
		QuickSort (A, pivotpos+1, high);
	}
}



#define MaxVertexNum 100
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

typedef struct ArcNode
{
	Vertex AdjV;
	WeightType Weight;
	struct ArcNode *Next;
}ArcNode;

typedef struct VNode
{
	DataType Data;
	ArcNode *First;
}VNode, AdjList[MaxVertexNum];

typedef struct GNode
{
	int Nv;
	int Ne;
	AdjList G;
}GNode, *Graph;