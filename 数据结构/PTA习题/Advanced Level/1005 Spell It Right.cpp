#include <cstdio>
#include <cstring>
const int MAX = 110;
char str[10][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main()
{
	char num[MAX];
	int tmp[MAX];
	int sum = 0;
	scanf("%s", num);
	for (int i = 0; i < strlen(num); i++)
		sum = sum + (num[i] - '0');		
	int i = 0;
	if (sum == 0)
		tmp[i++] = 0;
	while (sum)
	{
		tmp[i++] = sum % 10;
		sum /= 10;
	}
	for (int k = i - 1; k >= 0; k--)
	{
		printf("%s", str[tmp[k]]);
		if (k)
			printf(" ");
	}
	return 0;
}
//注意点：1.数字的拼写是否正确是否有遗漏。  2.特殊点0