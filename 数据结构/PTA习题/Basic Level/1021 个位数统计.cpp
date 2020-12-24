#include <cstdio>
int main()
{
	char num[1000];
	int d[10] = {0}, k = 0;
	while (scanf("%c", &num[k++]) != EOF);
	for (int i = 0; i < k; i++)
		d[num[i]-'0']++;
	for (int i = 0; i < 10; i++)
		if (d[i])
			printf("%d:%d\n", i, d[i]);
	return 0;
}