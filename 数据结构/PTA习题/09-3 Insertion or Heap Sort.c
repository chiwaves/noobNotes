#include<stdio.h>
#include<stdbool.h>
#define MAX 101

void InsertSort ( int A[], int p, int N )
{
	int i, tmp;

	tmp = A[p];
	for ( i = p; i >= 1 && A[i - 1] > tmp; i-- )
		A[i] = A[i - 1];
	A[i] = tmp;
}



void Swap( int*a, int*b )
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}



void PercDown( int A[], int p, int N )
{
	int Child, Parent, Tmp;
	Tmp = A[p];

	for ( Parent = p; Parent*2+1 < N; Parent = Child )
	{
		Child = Parent*2+1;
		if ( (Child+1 < N) && (A[Child+1] > A[Child]) )
			Child++;
		if ( Tmp > A[Child] )
			break;
		else
			A[Parent] = A[Child];
	}
	A[Parent] = Tmp;
}



bool IsSame( int A[], int B[], int N )
{
	int i;

	for ( i = 0; i < N; i++ )
		if ( A[i] != B[i] )
			return false;
	return true;
}



int NextStep( int A1[], int A2[], int B[], int N )
{
	int i;

/*一开始这里的i初始赋值为0，测试点[2]未通过猜测测试数据类似
3 
2 3 1 
2 3 1
结果应该为 1 2 3，但若i初始为0，相当于跳过第一次插排。打印完后是从B[1]插排，
输出还是 2 3 1，但若i初始为1，则打印完从B[2]开始插排得 1 2 3*/
	for ( i = 1; i < N; i++ )  
	{
		InsertSort( A1, i, N );
		if ( IsSame( A1, B, N ) )
		{
			printf("Insertion Sort\n");
			InsertSort( B, i+1, N );
			return 0;
		}
	}

	for ( i = N/2-1; i >= 0; i-- )
		PercDown( A2, i, N );
	for ( i = N-1; i > 0; i-- )
	{
		Swap( &A2[0], &A2[i] );
		PercDown( A2, 0, i );
		if ( IsSame( A2, B, N ) )
		{
			printf("Heap Sort\n");
			Swap( &B[0], &B[--i] );
			PercDown( B, 0, i );
			return 0;
		}
	}
}



int main()
{
	int N, i;
	int A1[MAX], A2[MAX], B[MAX];

	scanf("%d", &N);
	for ( i = 0; i < N; i++ )
	{
		scanf("%d", &A1[i]);
		A2[i] = A1[i];
	}
	for ( i = 0; i < N; i++ )
		scanf("%d", &B[i]);

	NextStep( A1, A2, B, N );

	for ( i = 0; i < N; i++ )
	{
		if (i)
			printf(" ");
		printf("%d", B[i] );
	}

	return 0;
}
