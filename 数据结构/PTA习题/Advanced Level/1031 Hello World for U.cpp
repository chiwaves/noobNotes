#include <cstdio>	//PTA系统编译器的一个BUG:cstdio头文件里没有gets函数
#include <cstring>
const int MAX = 90;

int main()
{
	int left, right;
	char st[MAX];
	gets(st);
	int len = strlen(st);
	left = 0, right = len - 1;
	int n1 = (len + 2) / 3;
	int n2 = len + 2 - n1 * 2;
	for (int i = 1; i <= n1; i++)
	{
		if (i != n1)
		{
			printf("%c", st[left++]);
			for (int j = 0; j < n2 - 2; j++)
				printf(" ");
			printf("%c\n", st[right--]);
		}
		else
			for (int j = 0; j < n2; j++)
				printf("%c", st[left++]);
	}
	return 0;
}