#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode* Polynomial;
struct PolyNode {
	int coef;
	int expon;
	Polynomial Next;
};


void Attach(int c, int e, Polynomial* rear)   
/*方法2，通过返回rear来修改rear的指向，所有调用Attach函数的地方
  都改为 rear = Attach(...)，不用指针的指针，待验证*/ 
{
	Polynomial P = (Polynomial)malloc(sizeof ( struct PolyNode ));
	P->coef = c;
	P->expon = e;
	P->Next = NULL;
	(*rear)->Next = P;
	*rear = P;
}


Polynomial Input()
{
	int c, e, N;
	Polynomial P, Rear, temp;

	P = (Polynomial)malloc(sizeof ( struct PolyNode ));
	P->Next = NULL;
	Rear = P;
	
	scanf("%d", &N);
	while ( N-- )
	{
		scanf("%d%d", &c, &e);
		Attach(c, e, &Rear);
	}

	temp = P;
	P = P->Next;
	free(temp);
	return P;
}


void Output(Polynomial P)
{
	if ( !P )
		printf("0 0");
	while ( P )
	{
		printf( "%d %d", P->coef, P->expon );
		if ( P->Next )
			printf(" ");
		P = P->Next;
	}
	printf("\n");
}


Polynomial PolyAdd(Polynomial P1, Polynomial P2)
{
	Polynomial front, rear, temp;
	int sum;

	rear = (Polynomial)malloc(sizeof(struct PolyNode));
	front = rear;

	while ( P1 && P2 )
	{
		if ( P1->expon > P2->expon )
		{
			Attach(P1->coef, P1->expon, &rear);
			P1 = P1->Next;
		}
		else if ( P2->expon > P1->expon )
		{
			Attach(P2->coef, P2->expon, &rear);
			P2 = P2->Next;
		}
		else
		{
			sum = P1->coef + P2->coef;
			if ( sum )
				Attach(sum, P1 -> expon, &rear);
			P1 = P1->Next;
			P2 = P2->Next;
		}
	}

	while ( P1 ) //两种写法，分别是while和for。之前条件是P1->Next非零，死循环，应该是少录入一组呀
	{
		Attach(P1->coef, P1->expon, &rear);
		P1 = P1->Next;
	}
	for ( ; P2; P2 = P2->Next )
		Attach(P2->coef, P2->expon, &rear);

	rear->Next = NULL;
	temp = front;
	front = front->Next;
	free(temp);
	return front;
}


Polynomial PolyMulti(Polynomial P1, Polynomial P2)
{
	Polynomial P3, Tmp2, rear, temp;
	Polynomial P = NULL;
	
	if ( !P1 || !P2 )
		return NULL;
		
	P3 = (Polynomial)malloc(sizeof ( struct PolyNode ));
	P3->Next = NULL;
	rear = P3;
	while ( P1 )
	{
		Tmp2 = P2;
		while ( Tmp2 )
		{
			if ( P1->coef * Tmp2->coef )
				Attach(P1->coef * Tmp2->coef, P1->expon + Tmp2->expon, &rear);
			Tmp2 = Tmp2->Next;
		}
		rear->Next = NULL;
		temp = P3;
		P3 = P3->Next;
		free(temp);

		P = PolyAdd(P, P3);
		P1 = P1->Next;
		P3 = rear;
	}
	return P;
}


int main()
{
	Polynomial P1, P2, P;
	P1 = Input();
	P2 = Input();
	
	P = PolyMulti(P1, P2);
	Output(P);
	
	P = PolyAdd(P1, P2);
	Output(P);
	
	return 0;	
} 
