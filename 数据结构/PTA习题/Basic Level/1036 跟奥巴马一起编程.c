#include <stdio.h> 
int main ()
{
	int i, j, n, k;	//n是列编号，k是行编号，建议和范例一样使用row和col避免搞错
	char c;
	scanf("%d %c", &n, &c);
	//四舍五入的老实做法，本题中都是正整数，除以2不可能得出.4的
	if (n%2 != 0 && n*10/2%10 >= 5)
		k = n/2+1;
	else
		k = n/2;
	//打印第1行
	for (j = 0; j < n; j++)
		printf("%c", c);
	printf("\n");
	//打印第2到第k-1行
	for (i = 1; i < k-1; i++)
	{
		printf("%c", c);
		for (j = 1; j < n-1; j++)
			printf(" ");
		printf("%c\n", c);
	}
	//打印最后一行
	for (j = 0; j < n; j++)
		printf("%c", c);
	return 0;
}
