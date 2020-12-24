#include <cstdio>
const int MAX = 32;

int main()
{
	int n, b, k = 0, c[MAX], flag = 1;
	scanf("%d%d", &n, &b);
	do
	{
		c[k++] = n % b;
		n = n / b;
	}
	while (n);
	k--;
	for (int i = 0; i <= k/2; i++)
		if (c[i] != c[k-i])
			flag = 0;
	if (flag)
		printf("Yes\n");
	else
		printf("No\n");
	printf("%d", c[k]);
	for (int i = k-1; i >= 0; i--)
		printf(" %d", c[i]);
	return 0;
}