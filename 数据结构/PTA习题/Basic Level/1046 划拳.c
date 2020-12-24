#include <stdio.h>
int main()
{
	int n, i, ac, ad, bc, bd;
	int afail = 0, bfail = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &ac, &ad, &bc, &bd);
		if (bd == ac + bc && ad != ac + bc)
			afail++;
		if (bd != ac + bc && ad == ac + bc)
			bfail++;
	}
	printf("%d %d\n", afail, bfail);
	return 0;
}
