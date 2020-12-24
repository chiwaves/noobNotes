#include <cstdio>
#include <algorithm>
using namespace std;	//C++的标准库用法，有待深入了解

const int MAX = 100005;
int dis[MAX];
dis[0] = 0;	//如果不是0，输出答案错误。可能多余，如果编译器默认一个新定义的数组初始都是0，(参考答案里没有)

int main()
{
	int n, sum = 0, A, query, left, right, tmp;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &A);
		sum += A;
		dis[i] = sum;	//dis[i]存放结点1到结点i+1的距离
	}
	scanf("%d", &query);
	for (int i = 0; i < query; i++)
	{
		scanf("%d%d", &left, &right);
		if (right < left)
			swap(right, left);
		tmp = dis[right-1] - dis[left-1];	
/*精髓所在，不用每次求距离都遍历一遍原图导致超时，dis[right-1]-dis[left-1]就是结点left到结点right的距离*/
		printf("%d\n", min(tmp, sum - tmp));
	}
	return 0;
}

/*运行超时
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, i, j, pair, a, b, left, right, cut, sum = 0;
	scanf("%d", &n);
	int *Dist = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", Dist+i);
		sum = sum + *(Dist+i);
	}
	scanf("%d", &pair);
	for (i = 0; i < pair; i++)
	{
		scanf("%d%d", &a, &b);
		right = left = 0;
		for (j = a-1; j != b-1; j = (j+1)%n) //循环内套循环，超时之处
			right = right + Dist[j];
		left = sum - right;
		if (right < left)
			cut = right;
		else
			cut = left;
		printf("%d\n", cut);
	}
	return 0;
}
*/