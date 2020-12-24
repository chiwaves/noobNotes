#include <cstdio>
const int MAX1 = 1001;
const int MAX2 = 2001;	//发生数组越界的原因
const double eps = 1e-8;	//浮点数比较大小

int main()
{
	int num1, num2, e, count = 0;
	double k, A[MAX1] = {0}, C[MAX2] = {0};
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d%lf", &e, &k);
		A[e] = k;
	}
	scanf("%d", &num2);
	for (int i = 0; i < num2; i++)
	{
		scanf("%d%lf", &e, &k); 
		for (int j = 0; j < MAX1; j++)
			C[j+e] = C[j+e] + k * A[j];
	}
	for (int i = 0; i < MAX2; i++)
		if (C[i] > eps || C[i] < -eps)
			count++;
	printf("%d", count);
	for (int i = MAX2-1; i >= 0; i--)
		if (C[i] > eps || C[i] < -eps)
			printf(" %d %.1f", i, C[i]);
	return 0;
}