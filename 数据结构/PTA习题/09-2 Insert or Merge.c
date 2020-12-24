#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 101

void InsertSort( int A[], int P, int N )
{
	int i, Tmp;

	Tmp = A[P];
	for ( i = P; i >= 1 && Tmp < A[i-1]; i-- )
		A[i] = A[i-1];
	A[i] = Tmp;
}



void Merge ( int A[], int TmpA[], int L, int R, int RightEnd )
{
	int LeftEnd, NumElements, Tmp;
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



void Merge_Pass ( int A[], int TmpA[], int N, int length )
{
	int i, j;

	for ( i = 0; i <= N-2*length; i += 2*length )
		Merge ( A, TmpA, i, i + length, i+2*length-1 );
	if ( i + length < N )
		Merge ( A, TmpA, i, i + length, N-1 );
	else
		for ( j = i; j < N; j++ )
			TmpA[j] = A[j];
}



void MergeSort ( int A[], int length, int N )
{
	int i; 
	int * TmpA;
	TmpA = ( int * ) malloc ( N * sizeof ( int ) );

	Merge_Pass ( A, TmpA, N, length );

	for ( i = 0; i < N; i++ )
		A[i] = TmpA[i];

	free ( TmpA );
}



int IsInsert( int A[], int B[], int N )
{
	int i = 1, Tmp;

	while ( i < N && B[i-1] <= B[i] )
		i++;
	Tmp = i;

	for ( ; i < N; i++ )
		if ( A[i] != B[i] )
			return 0;
	return Tmp;
}



int IsMerge( int B[], int N )
{
	int l, i;

	for ( l = 2; l < N; l *= 2 )         //这里的等号感觉也取不到，遂修改
		for ( i = 1; i*l < N; i += 2 )   //这里参考的浪漫逆风同学写的。他的条件是i < N/l，我认为不妥，但测试点可通过。。。
			if ( B[i*l-1] > B[i*l] )
				return l;
	return l;     
	/*这里return什么值都不影响最后结果，因为如果走到这一步说明排序完毕了，
	  但这就无法确定到底用的是归并还是插入，不可能给这种测试点*/
}

/*自己创的检测并归到第几步的函数，很啰嗦，几经修改好歹正确了
int IsMerge( int B[], int N )
{
	int l, length, i, flag = 1;

	for ( l = 2; l < N && flag; l *= 2 )
	{
		i = l;
		while ( i < N && flag )
			if ( B[i-1] <= B[i] )
				i = i+2*l;
			else
				flag = 0;
		length = l;
	}
	return length;
}   */



int main()
{
	int N, i, P;
	int A[MAX], B[MAX];

	scanf("%d", &N);
	for ( i = 0; i < N; i++ )
		scanf("%d", &A[i]);
	for ( i = 0; i < N; i++ )
		scanf("%d", &B[i] );

	if ( P = IsInsert( A, B, N ) )  //这里开始检测是否是插排，若是，插排到第几步
	{
		printf("Insertion Sort\n");
		InsertSort( B, P, N );
	}
	else
	{
		printf("Merge Sort\n");
		P = IsMerge( B, N );        //这里确定是归并，归并到第几步  
		MergeSort( B, P, N );
	}

	for ( i = 0; i < N; i++ )
	{
		if ( i )
			printf(" ");
		printf("%d", B[i]);
	}
	return 0;
}