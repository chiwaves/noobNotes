#include <stdio.h>
int Change(char c)	//B,C,J正好按字母序从小到大，而且又形成了布锤子剪刀大小循环链。相当于已经完成一趟桶排序。同时满足这两点很关键
{
	if (c == 'B')
		return 0;
	if (c == 'C')
		return 1;
	if (c == 'J')
		return 2;
}

int main()
{
	int n, i, k1, k2, win1 = 0, win2 = 0, ping = 0;
	int count1[] = {0, 0, 0};
	int count2[] = {0, 0, 0};
	char x, y;
	int max1 = 0, max2 = 0;
	char mp[] = {'B', 'C', 'J'};
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		getchar();
		scanf("%c %c", &x, &y);
		k1 = Change(x);
		k2 = Change(y);
		if ((k1+1)%3 == k2)	//由上所述，才有了这样的判胜负条件
		{
			win1++;
			count1[k1]++;
		}
		else if ((k2+1)%3 == k1)
		{
			win2++;
			count2[k2]++;
		}
		else
			ping++;
	}
	printf("%d %d %d\n", win1, ping, win2);
	printf("%d %d %d\n", win2, ping, win1);
	for (i = 1; i < 3; i++)
	{
		if (count1[max1] < count1[i])
			max1 = i;
		if (count2[max2] < count2[i])
			max2 = i;
	}
	printf("%c %c", mp[max1], mp[max2]);
	return 0;
}