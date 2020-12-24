#include<stdio.h>
#define MAX 100005

void ShellSort ( int A[], int N )
{
	int D, Si, p, i, tmp;
	int Sedgewick[] = {146305, 64769, 36289, 16001, 8929, 3905, 2161, 929, 505, 209, 109, 41, 19, 5, 1, 0};

	for ( Si = 0; Sedgewick[Si] >= N; Si++ )
		continue;

	for ( D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si] )
		for ( p = D; p < N; p++ )
		{
			tmp = A[p];
			for ( i = p; i >= D && A[i - D] > tmp; i -= D )
				A[i] = A[i - D];
			A[i] = tmp;
		}
}



int main ()
{
	int i, N;
	int A[MAX], count[51];

	scanf ( "%d", &N );
	for ( i = 0; i < N; i++ )
	{
		scanf ( "%d", &A[i] );
		count[ A[i] ]++;
	}

	ShellSort ( A, N );

	printf("%d:%d\n", A[0], count[ A[0] ] );
	for ( i = 1; i < N; i++ )
		if( A[i] != A[i - 1] )
			printf("%d:%d\n", A[i], count[ A[i] ] );

	return 0;
}