#include <cstdio>
int main()
{
	int n, sum = 0, bottom;
	char c;
	scanf("%d %c", &n, &c);
	int i = 1;
	while (sum <= (n-1)/2)
	{
		i = i + 2;
		sum = sum + i;
	}
	sum = sum - i;
	bottom = i - 2;
	for (int i = bottom; i > 0; i -= 2)
	{
		for (int j = 0; j < (bottom - i) / 2; j++)
			printf(" ");
		for (int j = 0; j < i; j++)
			printf("%c", c);
		printf("\n");
	}
	for (int i = 3; i <= bottom; i += 2)
	{
		for (int j = 0; j < (bottom - i) / 2; j++)
			printf(" ");
		for (int j = 0; j < i; j++)
			printf("%c", c);
		printf("\n");
	}
	printf("%d\n", n - 1 - 2 * sum);
	return 0;
}