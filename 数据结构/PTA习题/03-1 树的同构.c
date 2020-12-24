#include<stdio.h> 
#define Max 10
#define Null -1

struct TreeNode {
	char Data;
	int Left;
	int Right;
} T1[Max], T2[Max];



int MakeTree ( struct TreeNode T[] )
{
	int i, N;
	scanf ( "%d\n", &N );  
	/*有混合输入字符串和整数时scanf中的' '和'\n'要处理的很严格干净
	  用scanf输入整数时会忽略先导空白符，而输入字符时不会*/
	char left, right;
	int Root = Null;
	int check[Max];

	for ( i = 0; i < N; i++)
		check[i] = 0;

	for ( i = 0; i < N; i++ )
	{
		scanf ( "%c %c %c\n", &T[i].Data, &left, &right );
		if ( left != '-' )
		{
			T[i].Left = left - '0';
			check[T[i].Left] = 1;
		}
		else
			T[i].Left = Null;
		if ( right != '-')
		{
			T[i].Right = right - '0';
			check[T[i].Right] = 1;
		}
		else
			T[i].Right = Null;
		
		for ( i = 0 ; i < N ; i++ )
			if ( !check[i] )
				break;
		Root = i;
	}
	return Root;
}



int Iso ( int R1 , int R2 )
{
	if ( R1 == Null && R2 == Null )
		return 1;
		
	if ( ( R1 == Null && R2 != Null ) || ( R1 != Null && R2 ==Null ) )
		return 0;
		
	if ( T1[R1].Data != T2[R2].Data )
		return 0;
		
	if ( T1[R1].Left == Null && T2[R2].Left == Null )
		return ( Iso ( T1[R1].Right , T2[R2].Right ) );
		
	if ( T1[T1[R1].Left].Data == T2[T2[R2].Left].Data )
		return ( Iso ( T1[R1].Left , T2[R2].Left ) && Iso ( T2[R2].Right ,T2[R2].Right ) );
	else
		/*(T1[T1[R1].Left].Data != T2[T2[R2].Left].Data)，交换左右比较，
	       如果交换后还不相同，下一层迭代中的第三个if会验证*/
		return ( Iso ( T1[R1].Left , T2[R2].Right ) && Iso ( T1[R1].Right , T2[R2].Left ) );
}



int main ()
{
	int R1, R2;
	R1 = MakeTree ( T1 );
	R2 = MakeTree ( T2 );
	if ( Iso ( R1 , R2 ) )
		printf ( "Yes\n" );
	else
		printf ( "No\n" );
	return 0; 
}
