#include <stdio.h>
int main ()
{
	const int maxn = 100001;
	int N, schID, score;
	int school[maxn];
	scanf("%d", &N);
//初始化school数组
	for (int i = 0; i <= N; i++)
		school[i] = 0;
//登记每个学校的分数
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &schID, &score);
		school[schID] += score;
	}
//找出得分最多的那个学校
	int fin, maxscore = -1;
	for (int i = 1; i <= N; i++)
	{
		if (school[i] > maxscore)
		{
			fin = i;
			maxscore = school[fin];
		}
	}
	printf("%d %d\n", fin, school[fin]);
	return 0;
}