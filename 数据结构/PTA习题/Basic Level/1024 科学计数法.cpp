#include <cstdio>
const int MAX = 10000;

int main()
{
	int e = 0, k = 0;
	char num[MAX];
	scanf("%s", num);
	if (num[0] == '-')
		printf("-");
	while (num[e] != 'E')
		e++;
	for (int i = e + 2; num[i] != '\0'; i++)
		k = k*10 + (num[i] - '0');
	if (num[e + 1] == '+')
	{
		printf("%c", num[1]);
		if (3 + k < e)						//这里可以简化，参考代码
		{
			for (int i = 3; i < 3 + k; i++)
				printf("%c", num[i]);
			printf(".");
			for (int i = 3 + k; num[i] != 'E'; i++)
				printf("%c", num[i]);
		}
		else if (3 + k > e)
		{
			for (int i = 3; i < e; i++)
				printf("%c", num[i]);
			for (int i = 0; i < k + 3 - e; i++)
				printf("0");
		}
		else
			for (int i = 3; i < 3 + k; i++)
				printf("%c", num[i]);
	}
	else
	{
		if (k == 0)
			for (int i = 1; num[i] != 'E'; i++)
				printf("%c", num[i]);
		else
		{
			printf("0.");
			for (int i = 0; i < k - 1; i++)
				printf("0");
			printf("%c", num[1]);
			for (int i = 3; num[i] != 'E'; i++)
				printf("%c", num[i]);
		}
	}
	return 0;
}