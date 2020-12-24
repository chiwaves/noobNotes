#include <stdio.h>
#define MAX 100005

struct ListNode {
	int Data;
	int Next;
} List[MAX];


int Reverse(int First, int K)
{
	int new, old, tmp, count = 1;

	new = First;
	old = List[new].Next;

	while ( count < K )
	{
		tmp = List[old].Next;
		List[old].Next = new;
		new = old;
		old = tmp;
		count++;
	}
	List[First].Next = old;

	return new;
}


void Input(int Num)
{
	int i, address, data, next;

	for ( i = 0; i < Num; ++i )
	{
		scanf("%d%d%d", &address, &data, &next);
		List[address].Data = data;
		List[address].Next = next;
	}
}


void Output(int Tango)
{
	int address, data, next;
	address = Tango;

	while ( address >= 0 )
	{
		data = List[address].Data;
		next = List[address].Next;
		if ( next >= 0 )
			printf("%05d %d %05d\n", address, data, next);
		else
			printf("%05d %d %d\n", address, data, next);
		address = List[address].Next;
	}
}


int main()
{
	int First, N, K, front, next, another;

	scanf("%d%d%d", &First, &N, &K);
	Input(N);

	if ( N % K || K == 1 )
		front = Reverse(First, K);
	else
	{
		front = Reverse(First, K);
		next = List[First].Next;
		another = Reverse(next, N - K);
		List[First].Next = another;
	}
	Output(front);
	return 0;
}