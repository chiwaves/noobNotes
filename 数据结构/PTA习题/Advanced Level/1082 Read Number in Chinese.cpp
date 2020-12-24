/* 
多位数读法原则：

1、四位以内的数，按照数位顺序，从高位读起。

2、四位以上的数，先从右向左四位分级，然后从最高级起，依次读亿级、万级、个级。读出各级里的数和它们的级名。

亿级里的数，按照个级的数的读法来读，再在后面加上一个“亿”字；万级里的数，按照个级的数的读法来读，再在后面加上一个“万”字；

3、每级末尾不管有几个“0”，都不读；其他数位上有一个“0”或几个“0”，都只读一个零。
*/
#include <cstdio>
#include <cstring>
char num[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
char wei[5][5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};

int main()
{
	char dig[15];	
	scanf("%s", dig);
	int len = strlen(dig);
	int left = 0;
	int right = len - 1;
	int count = 0;
	int tmp;
	bool zero = false, none = true;
	if (dig[0] == '-')
	{
		printf("Fu");
		left++;
	}
	if (len == 1 && dig[0] == '0')
		printf("ling");
	while (right - 4 >= left)
	{
		right = right - 4;
		count++;
	}
	while (right < len)
	{
		while (left <= right)
		{
			tmp = dig[left] - '0';
			if (tmp == 0)
				zero = true;
			else
			{
				if (zero)
					printf(" %s", num[0]);
				zero = false;
				none = false;
				if (left > 0)
					printf(" ");
				printf("%s", num[tmp]);
				tmp = right - left - 1;
				if (tmp >= 0)
					printf(" %s", wei[tmp]);
			}
			left++;
		}
		if (count && !none)
		{
			printf(" %s", wei[count + 2]);
			count--;
		}
		if (count && none)
			count--;
		right = left + 3;
		zero = false;
		none = true;
	}
	return 0;
}