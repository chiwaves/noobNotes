#include <stdio.h>
int main()
{
	int i, T;
	long A, B, C;
	scanf("%d", &T);
	for (i = 1; i <= T; i++)
	{
		scanf("%ld%ld%ld", &A, &B, &C);
		if (A + B > C)
			printf("Case#%d:true\n", i);
		else
			printf("Case#%d:false\n", i);
	}
	return 0;
}