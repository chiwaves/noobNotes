#include<stdio.h>
#define MAX 51


int main ()
{
	int p, i, N;
	int count[MAX];

	for ( p = 0; p < MAX; p++ )
		count[p] = 0;

/* 在内存中，输入的N放在count[51]的位置上，也就是说 &N == &count[51]。
   不明白为什么。若按题意，建立一个count[50]，N就放在count[50]上，输出错误 */
	scanf("%d", &N );         
	for ( p = 0; p < N; p++ )
	{
		scanf("%d", &i);
		count[i]++;
	}

	for ( i = 0; i < MAX; i++ )
		if ( count[i] )
			printf("%d:%d\n", i, count[i]);

	return 0;
}
