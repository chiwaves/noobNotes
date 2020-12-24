#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, m, i, last;
	scanf("%d%d", &n, &m);
	int *A = (int*)malloc(sizeof(int)*n);	//malloc函数一定别忘头文件stdlib.h
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);
	m = m % n;					//m的取值范围是 m >= 0，没说m要小于n，也没说m不能等于0
	if (m)
	{
		last = (n-m-1+n)%n;
		for (i = n-m; i != last; i = (i+1)%n)
			printf("%d ", A[i]);
		printf("%d\n", A[last]);
	}
	else
	{
		for (i = 0; i < n-1; i++)
			printf("%d ", A[i]);
		printf("%d\n", A[n-1]);
	}
	return 0;
}