#include <stdio.h>
int main()
{
	const int MAX = 1001;
	int i, k, e, a[MAX], count = 0;
	for (i = 0; i < MAX; i++)
		a[i] = 0;
	while (scanf("%d%d", &k, &e) != EOF)
		a[e] = k;
	a[0] = 0;
	for (i = 1; i < MAX; i++)
	{
		a[i-1] = i * a[i];
		a[i] = 0;
		if (a[i-1])
			count++;
	}
	if (count == 0)
		printf("0 0");
	else
		for (i = MAX-1; i >= 0; i--)
		{
			if (a[i])
			{
				printf("%d %d", a[i], i);
				if (--count)
					printf(" ");
			}
		}
	return 0;
}

/*第二种写法：
int main()
{
	const int min = -1001;
	int i, a[1010];
	for (i = 0; i < 1010; i++)
		a[i] = min;
	i = 0;
	while (scanf("%d", &a[i++]) != EOF)
		continue;
	i = 0;
	while (a[i] != min)
	{
		a[i] = a[i] * a[i+1];
		if (a[i+1])
			a[i+1] -= 1;
		i += 2;
	}
	printf("%d %d", a[0], a[1]);
	i = 2;
	while (a[i] != min && a[i] != 0)
	{
		printf(" %d %d", a[i], a[i+1]);
		i += 2;
	}
	return 0;
}
*/