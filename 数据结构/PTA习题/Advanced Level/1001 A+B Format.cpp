#include <cstdio>
#include <cstring>
const int MAX = 10;
//看错题意，题干中输入的是两个int，自己把输入的内容当作char数组来处理。所以比参考代码复杂一点。然而这样处理也能work
int turn(char a[])
{
	int numA = 0;
	if (a[0] != '-')
		for (int i = 0; i < strlen(a); i++)
			numA = numA * 10 + (a[i] - '0');
	else
		for (int i = 1; i < strlen(a); i++)
			numA = numA * 10 - (a[i] - '0');
	return numA;
}

int main()
{
	char a[MAX], b[MAX], num[MAX];
	scanf("%s%s", a, b);
	int i = 0;
	int tmp;
	int numA = turn(a);
	int numB = turn(b);
	int ans = numA + numB;
	if (ans == 0)
		num[i++] = 0 + '0';
 	if (ans < 0)
	{
		printf("-");
		ans = -ans;
	}
	while (ans > 0)
	{
		tmp = ans % 10;
		ans = ans / 10;
		num[i++] = tmp + '0';
		if ((i + 1) % 4 == 0 && ans > 0)
			num[i++] = ',';
	}
	for (int k = i - 1; k >= 0; k--)
		printf("%c", num[k]);
	return 0;
}