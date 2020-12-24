#include <cstdio>
const int MAX = 11;

int main()
{
	int n, score, max = -1, min = 101;
	char name[MAX], num[MAX], name1[MAX], num1[MAX], name2[MAX], num2[MAX];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s%s%d", name, num, &score);
		if (score > max)
		{
			for (int i = 0; i < MAX; i++)
			{
				name1[i] = name[i];
				num1[i] = num[i];
			}
			max = score;
		}
		if (score < min)
		{
			for (int i = 0; i < MAX; i++)
			{
				name2[i] = name[i];
				num2[i] = num[i];
			}
			min = score;
		}
	}
	printf("%s %s\n%s %s", name1, num1, name2, num2);
	return 0;
}