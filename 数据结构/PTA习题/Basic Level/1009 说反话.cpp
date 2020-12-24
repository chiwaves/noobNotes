#include <cstdio>
#include <cstring>
const int MAX = 82;

int main()
{
	char words[MAX];
	int left, right;
	gets(words);
	int last = strlen(words) - 1;
	for (int i = last; i >= 0; i--)
	{
		right = i;
		while (words[i] != ' ' && i >= 0)
			i--;
		left = i + 1;
		for (int j = left; j <= right; j++)
			printf("%c", words[j]);
		if (left != 0)
			printf(" ");
	}
	return 0;
}

/*
#include <cstdio>
#include <cstring>
int main()
{
	char str[90];
	gets(str);
	int len = strlen(str);
	int r = 0, h = 0;
	char ans[90][90];
	for (int i = 0; i < len; i++)
	{
		if(str[i] != ' ')
			ans[r][h++] = str[i];
		else
		{						//'\0'这句应该加在这里
			r++;
			h = 0;
			ans[r][h] = '\0';	//这里'\0'添加的位置有问题啊，但不加'\0'，运行也正确，所以没法验证对错
		}
	}
	for (int i = r; i >= 0; i--)
	{
		printf("%s", ans[i]);
		if (i > 0)
			printf(" ");
	}
	return 0;
}
*/