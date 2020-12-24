#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student
{
	char id[15];
	int score;
	int location_num;
	int local_rank;
	int rank;
}stu[30010];

bool cmp(Student a, Student b)
{
	if (a.score != b.score)
		return a.score > b.score;
	else
		return strcmp(a.id, b.id) < 0;
}

int main()
{
	int n, k, p = 0, left, right;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		left = p;
		for (int j = 0; j < k; j++)
		{
			scanf("%s %d", stu[p].id, &stu[p].score);
			stu[p].location_num = i + 1;
			p++;
		}
		right = p;
		sort(&stu[left], &stu[right], cmp);
		stu[left].local_rank = 1;
		for (int j = 1; j < k; j++)
		{
			if (stu[left + j].score != stu[left + j - 1].score)
				stu[left + j].local_rank = j + 1;
			else
				stu[left + j].local_rank = stu[left + j - 1].local_rank;
		}
	}
	printf("%d\n", p);
	sort(stu, stu + p, cmp);
	stu[0].rank = 1;
	for (int i = 1; i < p; i++)
	{
		if (stu[i].score != stu[i - 1].score)
			stu[i].rank = i + 1;
		else
			stu[i].rank = stu[i - 1].rank;
	}
	for (int i = 0; i < p; i++)
		printf("%s %d %d %d\n", stu[i].id, stu[i].rank, stu[i].location_num, stu[i].local_rank);
	return 0;
}