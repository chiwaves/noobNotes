#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct pNode
{
	char id[20];
	int hh, mm, ss;
}tmp, ans1, ans2;

void initial()
{
	ans1.hh = 24, ans1.mm = 60, ans1.ss = 60;
	ans2.hh = 0, ans2.mm = 0, ans2.ss = 0;
}

bool great(pNode node1, pNode node2)	//精髓所在，判断时分秒、年月日这类大小的函数
{
	if (node1.hh != node2.hh)
		return node1.hh > node2.hh;
	else if (node1.mm != node2.mm)
		return node1.mm > node2.mm;
	else
		return node1.ss > node2.ss;
}

int main()
{
	int n;
	scanf("%d", &n);
	initial();
	for (int i = 0; i < n; i++)
	{
		scanf("%s%d:%d:%d", tmp.id, &tmp.hh, &tmp.mm, &tmp.ss);
		if (great(tmp, ans1) == false)
			ans1 = tmp;
		scanf("%d:%d:%d", &tmp.hh, &tmp.mm, &tmp.ss);
		if (great(tmp, ans2))
			ans2 = tmp;
	}
	printf("%s %s\n", ans1.id, ans2.id);
	return 0;
}

/*
#include <cstdio>
const int MAX = 20;

int main()
{
	int m, hi, mi, si, ho, mo, so, max = 0, min = 86400, tmpi, tmpo;
	char id[MAX], earliest[MAX], latest[MAX];
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%s %d:%d:%d %d:%d:%d", id, &hi, &mi, &si, &ho, &mo, &so);
		tmpi = hi*3600 + mi*60 + si;
		tmpo = ho*3600 + mo*60 + so;
		if (tmpi < min)
		{
			min = tmpi;
			for (int j = 0; j < MAX; j++)
				earliest[j] = id[j];
		}
		if (tmpo > max)
		{
			max = tmpo;
			for (int j = 0; j < MAX; j++)
				latest[j] = id[j];
		}
	}
	printf("%s %s", earliest, latest);
	return 0;
}
*/