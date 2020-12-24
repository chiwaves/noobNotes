#include <stdio.h>  //本身最小堆就不唯一，输入后排序的方法不合题意，基本不会判断正确
#include <stdlib.h>
#define MINDATA -10001

typedef int ElementType;
typedef struct HNode * MinHeap;

struct HNode {
	ElementType * Element;
	int size;
	int Capicity;
}; 


MinHeap CreatHeap(int Maxsize)
{
	MinHeap H = (MinHeap) malloc (sizeof (struct HNode));
	H -> Element = (ElementType*) malloc ((Maxsize + 1) * sizeof (ElementType));
	H -> size = 0;
	H -> Capicity = Maxsize;
	H -> Element[0] = MINDATA;
	return H;
}


void PercDown(MinHeap H, int p)
{
	int Parent, Child;
	ElementType temp = H->Element[p];
	
	for(Parent = p; Parent*2 <= H->size; Parent = Child)
	{
		Child = Parent*2;
		if (Child != H->size && H->Element[Child] > H->Element[Child+1])
			Child++;
		if (temp <= H->Element[Child])
			break;
		else
			H->Element[Parent] = H->Element[Child];
	}
	H->Element[Parent] = temp;
}


MinHeap BuildMinHeap(int M)
{
	int i;
	MinHeap H = CreatHeap(M);
	for ( i = 1; i <= M; i++ )
	{
		scanf( "%d", &H->Element[i] );
		H->size++;
	}
	for ( i = H->size/2; i; i-- )
		PercDown( H, i );
	return H;
}


void PrintRomote(MinHeap H, int N)
{
	int i, flag;
	while ( N -- )
	{
		flag = 0;
		scanf("%d", &i);
		while ( i > 0 )
		{
			if (flag)
				printf(" ");
			flag = 1;
			printf("%d", H->Element[i]);
			i = i/2;
		}
		printf("\n");
	}
}


int main()
{
	int N, M;
	MinHeap H;
	scanf ("%d%d", &N, &M);
	H = BuildMinHeap(N);
	PrintRomote(H, M);
	return 0;
}