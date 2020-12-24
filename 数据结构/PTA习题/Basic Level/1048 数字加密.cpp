#include <cstdio>
#include <cstring>
const int MAX = 110;
char ten[3] = {'J', 'Q', 'K'};

/*	题目有没交代清楚的地方。当正整数A和B位数不同时，较短的那个在缺少的高位处补0。
	比如 A = 10012315，B = 98，此时就在B的高位补0变为00000098，再做加密运算。
	除开下面这种做法外，可以先将数组倒置再加密运算。更加简单。
*/
int main()
{
	char a[MAX], b[MAX], ans[MAX];
	scanf("%s%s", a, b);
	int lenA = strlen(a) - 1;
	int lenB = strlen(b) - 1;
	int count = 1;
	int tmp;
	int len = lenA > lenB ? lenA : lenB;
	int fin = len;
	while (lenA >= 0 && lenB >= 0)
	{
		if (count++ % 2 != 0)
		{
			tmp = (a[lenA--] - '0' + b[lenB--] - '0') % 13;
			if (tmp > 9)
				ans[len--] = ten[tmp - 10];
			else
				ans[len--] = tmp + '0';
		}
		else
		{
			tmp = (b[lenB--] - '0') - (a[lenA--] - '0');
			if (tmp < 0)
				ans[len--] = tmp + 1 + '9';
			else
				ans[len--] = tmp + '0';
		}
	}
	if (lenA >= 0)
		while (lenA >= 0)
		{
			if (count++ % 2 != 0)
				ans[len--] = a[lenA--];
			else
			{
				tmp = a[lenA--] - '0';
				if (tmp == 0)
					ans[len--] = '0';
				else
				{
					tmp = 0 - tmp + 10;
					ans[len--] = tmp + '0';
				}
			}
		}
	if (lenB >= 0)
		while (lenB >= 0)
			ans[len--] = b[lenB--];
	for (int i = 0; i <= fin; i++)
		printf("%c", ans[i]);
	return 0;
}