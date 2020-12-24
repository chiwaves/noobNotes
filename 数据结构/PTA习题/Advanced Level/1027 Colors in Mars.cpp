#include <cstdio>
/*方法二：也可以建一个数组char radix[13] = {'0', '1', '2', ... , '9', 'A', 'B', 'C'}*/
int main()
{
	int num, tmp;
	for (int i = 0; i < 3; i++)
	{
		char ans[2] = {'0', '0'};
		num = 0;
		scanf("%d", &tmp);
		while (tmp)
		{
			if (tmp % 13 < 10)
				ans[num++] = tmp % 13 + 48;
			else
				ans[num++] = tmp % 13 + 55;
			tmp = tmp / 13;
		}
		if (i == 0)
			printf("#");
		for (int j = 1; j >= 0; j--)
			printf("%c", ans[j]);
	}
	return 0;
}