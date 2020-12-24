#include <cstdio>
int main()
{
	int	n, b, s, g;
	scanf("%d", &n);
	b = n / 100;
	s = n % 100 / 10;
	g = n % 10;
	for (int i = 0; i < b; i++)
		printf("B");
	for (int i = 0; i < s; i++)
		printf("S");
	for (int i = 1; i <= g; i++)
		printf("%d", i);
	return 0;
}