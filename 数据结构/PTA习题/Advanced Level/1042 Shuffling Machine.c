#include <stdio.h>
int main()
{
	const int max = 54;
	int k, i, j, start[max], end[max], pos[max], d;
	char c;
	char mp[] = {'S', 'H', 'C', 'D', 'J'};
	scanf("%d", &k);
	for (i = 0; i < max; i++)
	{
		scanf("%d", &pos[i]);
		pos[i]--;
		start[i] = i;
	}
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < max; j++)
			end[pos[j]] = start[j];
		for (j = 0; j < max; j++)
			start[j] = end[j];
	}
	for (i = 0; i < max; i++)
	{
		c = mp[end[i] / 13];
		d = end[i] % 13 + 1;
		printf("%c%d", c, d);
		if (i < max-1)
			printf(" ");
	}
	return 0;
}
