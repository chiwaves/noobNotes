#include<stdio.h>
#define MAX 100000


void ShellSort ( int A[], int N )
{
	int Si, D, P, i;
	int tmp;
	int Sedgewick[] = { 145305, 64769, 36289, 16001, 8929, 3905, 2161, 929, 505, 209, 109, 41, 19, 5, 1, 0 };

	for ( Si = 0; Sedgewick[Si] >= N; Si++ )
		continue;

	for ( D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si] )
		for ( P = D; P < N; P++ )
		{
			tmp = A[P];
			for ( i = P; i >= D && tmp < A[i - D]; i -= D )
				A[i] = A[i - D];
			A[i] = tmp;
		}
}



int main ()
{
	int N, i;

	scanf ( "%d", &N );
	int A[N];

	for ( i = 0; i < N; i++ )
		scanf ( "%ld", &A[i] );

	ShellSort ( A, N );

	for ( i = 0; i < N; i++ )
	{
		if ( i != 0 )
			printf(" ");
		printf("%d", A[i] );
	}

	return 0;
}