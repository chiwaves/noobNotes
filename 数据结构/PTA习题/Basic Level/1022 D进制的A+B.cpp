#include <cstdio>
int main()
{
	int a, b, d, sum, c[32], num = 0;
	scanf("%d%d%d", &a, &b, &d);
	sum = a + b;
	do
	{
		c[num++] = sum % d;
		sum = sum / d;
	}
	while (sum);
	for (int i = num-1; i >= 0; i--)
		printf("%d", c[i]);
	return 0;
}

/*	该做法的盲点在于最后打印十进制的数(%d或%lld)，而机器中是二进制，机器内的long long也是64位的二进制数。
	要打印的32位十进制数的真值范围大于机器内64位二进制数能表达的真值范围。
	例如要求1073741823 + 1073741823的2进制结果，结果在10进制下是32位。
	long long的数值只有63位，2的63次转成10进制只有18位，不够用。
	只能用上述的32个元素的数组来表达最终结果。

#include <cstdio>
int main()
{
	int a, b, d;
	long long c = 0, tmp, t = 1；
	scanf("%d%d%d", &a, &b, &d);
	tmp = a + b;
	while (tmp)
	{
		c = c + (tmp % d) * t;
		tmp = tmp / d;
		t = t * 10;
	}
	printf("%lld", c);
	return 0;
}
*/