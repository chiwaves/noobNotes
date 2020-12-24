#include <cstdio>
const int MAX = 1001;
struct Student
{
	long long id;
	int eSeat;
}st[MAX];

int main()
{
	int n, tSeat, eSeat, m, later;
	long long id;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld%d%d", &id, &tSeat, &eSeat);
		st[tSeat].id = id;
		st[tSeat].eSeat = eSeat;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &later);
		printf("%lld %d\n", st[later].id, st[later].eSeat);
	}
	return 0;
}