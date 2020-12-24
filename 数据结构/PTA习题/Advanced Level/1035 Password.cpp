#include <cstdio>
#include <cstring>
struct node
{
	char name[15];
	char pwd[15];
	bool ischange;	
}T[1005];

void change(node &T, int &count)	//cpp的语法里node XX 可以，在c的语法里，必须是struct node XX
{									//而且c语言中函数声明里似乎不可用 & 变量名 来表示引用，必须在main函数中传入指针才能达到相同功能
	int len = strlen(T.pwd);
	for (int j = 0; j < len; j++)
	{
		if (T.pwd[j] == '1')
		{
			T.pwd[j] = '@';
			T.ischange = true;
		}
		if (T.pwd[j] == '0')
		{
			T.pwd[j] = '%';
			T.ischange = true;
		}
		if (T.pwd[j] == 'l')
		{
			T.pwd[j] = 'L';
			T.ischange = true;
		}
		if (T.pwd[j] == 'O')
		{
			T.pwd[j] = 'o';
			T.ischange = true;
		}
	}
	if (T.ischange == true)
		count++;
}

int main()
{
	int N, count = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s%s", T[i].name, T[i].pwd);
		T[i].ischange = false;
		change(T[i], count);
	}
	if (count == 0 && N == 1)
		printf("There is %d account and no account is modified", N);
	else if (count == 0 && N > 1)
		printf("There are %d accounts and no account is modified", N);
	else
	{
		printf("%d\n", count);
		for (int i = 0; i < N; i++)
			if (T[i].ischange == true)
				printf("%s %s\n", T[i].name, T[i].pwd);
	}
	return 0;
}
