#include <cstdio>
const int GtoS = 17;
const int StoK = 29;

int main()
{
	int a1, b1, c1, a2, b2, c2, a3, b3, c3;
	scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
	c3 = c1 + c2;
	b3 = b1 + b2;
	a3 = a1 + a2;
	if (c3 >= StoK)
		b3++;
	if (b3 >= GtoS)
		a3++;
	printf("%d.%d.%d\n", a3, b3 % GtoS, c3 % StoK);
	return 0;
}