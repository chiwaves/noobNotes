#include <stdio.h>
int main()
{
	int n, i, num, A1, A2, A3, A5, count2, count4;
	double A4;
	A1 = A2 = A3 = A5 = count2 = count4 = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if (num % 5 == 0 && num % 2 == 0)
			A1 += num;
		if (num % 5 == 1)
		{
			if (count2 % 2 == 0)
				A2 += num;
			else
				A2 -= num;
			count2++;
		}
		if (num % 5 == 2)
			A3++;
		if (num % 5 == 3)
		{
			A4 += num;
			count4++;
		}
		if (num % 5 == 4 && num > A5)
			A5 = num;
	}
	A4 = A4 / count4;
	if (A1)
		printf("%d ", A1);
	else
		printf("N ");
	if (count2)
		printf("%d ", A2);
	else
		printf("N ");
	if (A3)
		printf("%d ", A3);
	else
		printf("N ");
	if (count4)
		printf("%.1f ", A4);
	else
		printf("N ");
	if (A5)
		printf("%d", A5);
	else
		printf("N");
	return 0;
}