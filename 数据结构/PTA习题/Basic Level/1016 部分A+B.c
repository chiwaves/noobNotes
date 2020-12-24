#include <stdio.h>
int main()
{
	int DA, DB;
	long A, B, PA = 0, PB = 0;	//声明时就用PA = PB = 0语法上是错误的
	scanf("%ld%d%ld%d", &A, &DA, &B, &DB);
	while (A != 0)
	{
		if (A%10 == DA)
			PA = PA * 10 + DA; //右移的思想
		A = A/10;
	}
	while (B != 0)
	{
		if (B%10 == DB)
			PB = PB * 10 + DB;
		B = B/10;
	}
	printf("%ld\n", PA + PB);
	return 0;
}
