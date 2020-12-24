#include <cstdio>
#include <cstring>
const int MAX = 110;
char shu[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main()
{
	char num[MAX];
	int sum = 0, ans[MAX];
	scanf("%s", num);
	for (int i = 0; i < strlen(num); i++)
		sum = sum + (num[i] - '0');
	int j = 0;
	do 
	{	
		ans[j++] = sum % 10;	//暂时不会赋值字符串数组，则巧妙避开使用字符串数组赋值
		sum /= 10;
	}
	while (sum);
	for (int i = j - 1; i >= 0; i--)
	{
		printf("%s", shu[ans[i]]);
		if (i != 0)
			printf(" ");
	}
	return 0;
}