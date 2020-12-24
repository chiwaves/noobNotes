#include <cstdio>
struct info
{
	char name[11], gender, id[11];
	int grade;
}tmp, boy, girl;

int main()
{
	int n;
	boy.grade = 101;
	girl.grade = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s %c %s %d", tmp.name, &tmp.gender, tmp.id, &tmp.grade);
		if (tmp.gender == 'M' && tmp.grade < boy.grade)
			boy = tmp;
		if (tmp.gender == 'F' && tmp.grade > girl.grade)
			girl = tmp;
	}
	if (girl.grade == -1)
		printf("Absent\n");
	else
		printf("%s %s\n", girl.name, girl.id);
	if (boy.grade == 101)
		printf("Absent\n");
	else
		printf("%s %s\n", boy.name, boy.id);
	if (girl.grade != -1 && boy.grade != 101)
		printf("%d\n", girl.grade - boy.grade);
	else
		printf("NA\n");
	return 0;
}