#include <cstdio>
int main()
{
	char A[3] = {'W', 'T', 'L'};
	double max, odd, pro = 1.0;
	int index;
	for (int i = 0; i < 3; i++)
	{
		max = 0.0;	//这里max归为最小必须放在每次内循环之前
		for (int j = 0; j < 3; j++)
		{
			scanf("%lf", &odd);
			if (odd > max)
			{
				max = odd;
				index = j;
			}
		}
		pro = pro * max;
		printf("%c ", A[index]);
	}
	pro = (pro*0.65 - 1)*2;
	printf("%.2f", pro);
	return 0;
}