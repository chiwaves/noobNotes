#include <cstdio>
int main()
{
	int n;
	bool flag;
	long long A, B, C, f;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld%lld%lld", &A, &B, &C);
		f = A + B;
		if (A > 0 && B > 0 && f < 0)	//若A、B同正，正溢出时，f为负
			flag = true;
		else if (A < 0 && B < 0 && f >= 0)	//若A、B同负，负溢出时，f为正
			flag = false;
		else if (f > C)
			flag = true;
		else
			flag = false;
		if (flag)
			printf("Case #%d: true\n", i);
		else
			printf("Case #%d: false\n", i);
	}
	return 0;
}
