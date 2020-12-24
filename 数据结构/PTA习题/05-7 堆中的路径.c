#include<stdio.h>
#define MAXN 1001
#define MINH -10001


int H[MAXN], size;

void Create()
{
	size = 0;
	H[0] = MINH;
}


void Insert(int X)
{
	int i;
	for (i = ++ size ; X < H[i/2] ; i /= 2)
		H[i] = H[i/2];
	H[i] = X;
}



int main()
{
	int N, M, Tmp, i, j;

	Create();
	scanf("%d%d", &N, &M);
	for( i = 0; i < N; i++ )  //之前居然在for语句后面打了';'真是服了自己
	{
		scanf("%d", &Tmp);
		Insert(Tmp);
	}
	
	for( i = 0; i < M; i++ )
	{
		scanf("%d", &j);
		printf("%d", H[j]);
		while( j > 1)
		{
			j /= 2;
			printf(" %d", H[j]);
		}
		printf("\n");
	}
	return 0;
}