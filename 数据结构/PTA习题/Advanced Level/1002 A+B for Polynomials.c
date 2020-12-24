#include <stdio.h>
int main()
{
	const int max = 1001;
	int i, num1, num2, e, count;
	double k, a[max];
	for (i = 0; i < max; i++)
		a[i] = 0;
	scanf("%d", &num1);
	for (i = 0; i < num1; i++)
	{
		scanf("%d%lf", &e, &k);	//scanf输入double类型时用%lf
		a[e] = k;
	}
	scanf("%d", &num2);
	for (i = 0; i < num2; i++)
	{
		scanf("%d%lf", &e, &k);
		a[e] = a[e] + k;
	}
	for (i = 0, count = 0; i < max; i++)
		if (a[i])
			count++;
	printf("%d", count);
	for (i = max-1; i >= 0; i--)
		if (a[i])
			printf(" %d %.1f", i, a[i]);	//printf输出double类型时用%f，%lf表示long double
	return 0;
}