bool Judge( ElementType A[], int Parent )
{
	int LChild, RChild;
	LChild = Parent*2+1;
	RChild = LChild+1;

	if ( A[LChild] < A[Parent] && A[RChild] < A[Parent] )
		return false;
	else
		return ( Judge( A[], LChild ) && Judge( A[], RChild ) );
}


bool Judge( ElementType A[], int N )
{
	int Parent, Child;
	int Last = (N-1)/2;

	if ( N%2 == 0)
	{
		for ()
	}
}