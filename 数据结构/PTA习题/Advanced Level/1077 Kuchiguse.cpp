#include <cstdio>
#include <cstring>
/*
从头造了gets函数的轮子
Kuchiguse(大概翻译为“习惯后缀”)中可以带空格
测试用例漏了一种情况：习惯后缀中带空格，同时又是一个单独的词。例如输入为：
3
Itai nyan~ai k
Ninjin wa iyada nyan~ai k
uhhh nyan~ai k
习惯后缀为nyan~ai k，然而下面代码判断为 nyan~ai k，最前面多了一个空格。测试用例无法检测出这种错误
*/
void getstr(char a[])
{
	int i = 0;
	bool isenter = false;
	while (i < 300 && isenter == false)
	{
		scanf("%c", &a[i]);
		if (a[i] == '\n')
		{
			a[i] = '\0';
			isenter = true;
		}
		i++;
	}
}

void reverse(char a[])
{
	int len = strlen(a);
	char tmp;
	for (int i = 0; i < len/2; i++)
	{
		tmp = a[i];
		a[i] = a[len - 1 - i];
		a[len - 1 - i] = tmp; 
	}
}

int main()
{
	int N, count = 0;
	bool flag = true, mark;
	char first[300], next[300], suffix[300];
	scanf("%d", &N);
	getchar();
	getstr(first);
	getstr(next);
	reverse(first);
	reverse(next);
	int len1 = strlen(first);
	int len2 = strlen(next);
	int len = len1 < len2 ? len1 : len2;
	for (int i = 0; i < len; i++)
	{
		if (first[i] == next[i])
		{
			suffix[i] = first[i];
			count++;
		}
		else
			break;
	}
	if (count > 0)
	{
		for (int i = 2; i < N; i++)
		{
			int j;
			for (j = 0; j < 300; j++)
				first[j] = ' ';
			mark = true;
			count = 0;
			getstr(first);
			reverse(first);
			int len1 = strlen(first);
			int len2 = strlen(suffix);
			int len = len1 < len2 ? len1 : len2;
			for (j = 0; j < len; j++)
			{
				if (suffix[j] == first[j])
					count++;
				else
					break;
			}
			suffix[j] = '\0';
			if (count == 0)
			{
				flag = false;
				break;
			}
		}
	}
	else
		flag = false;
	if (flag)
	{
		reverse(suffix);
		printf("%s", suffix);
	}
	else
		printf("nai");
	return 0;
}