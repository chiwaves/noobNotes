#include <stdio.h>
int main()
{
	const int CLK_TCK = 100;
	int C1, C2, TMP;
	int hh, mm, ss;
	scanf("%d%d", &C1, &C2);
	if ((C2 - C1) % CLK_TCK >= 50)
		TMP = (C2 - C1) / CLK_TCK + 1;
	else
		TMP = (C2 - C1) / CLK_TCK;
	ss = TMP % 60;
	mm = TMP / 60 % 60;
	hh = TMP / 3600;
	printf("%02d:%02d:%02d\n", hh, mm, ss);	
	/*答案错误的一种可能是输出不符合规范，此题中规定输出的都是两位。如果不注意，遇到00:07:09这种就会有问题*/
	return 0;
}
