#include <cstdio>
int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char M[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int main()
{
	int n, sum, z, w = 0, flag = 0;
	char id[20];
	for (int i = 0; i < 17; i++)
		w = w + weight[i];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		scanf("%s", id);
		for (int j = 0; j < 17; j++)
			sum = sum + (id[j] - '0') * weight[j];
		z = sum % 11;
		if (id[17] != M[z])
		{
			puts(id);
			flag = 1;
		}
	}
	if (flag == 0)
		printf("All passed\n");
	return 0;
}