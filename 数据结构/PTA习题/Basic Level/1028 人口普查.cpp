#include <cstdio>
const int MAX = 100001;
struct Info
{
	char name[6];
	int yy;
	int mm;
	int dd;
}tmp, young, old;

int main()
{
	int n, count = 0, mg, max = 18140905, min = 20140907;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s%d/%d/%d", tmp.name, &tmp.yy, &tmp.mm, &tmp.dd);
		mg = tmp.yy*10000 + tmp.mm*100 + tmp.dd;
		if (18140906 <= mg && mg <= 20140906)
		{
			count++;
			if (mg < min)
			{
				old = tmp;
				min = mg;
			}
			if (mg > max)
			{
				young = tmp;
				max = mg;
			}
		}
	}
	if (count)
		printf("%d %s %s", count, old.name, young.name);
	else
		printf("%d", count);
	return 0;
}