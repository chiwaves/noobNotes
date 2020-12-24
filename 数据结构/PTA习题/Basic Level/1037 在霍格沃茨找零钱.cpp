#include <cstdio>
const int gs = 17;
const int sk = 29;

int main()
{
	int a1, b1, c1;
	int a2, b2, c2;
	int a3, b3, c3;
	scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
	int price = a1*gs*sk + b1*sk + c1;
	int money = a2*gs*sk + b2*sk + c2;
	a3 = (money - price) / (gs*sk);
	if (money > price)
	{
		b3 = (money - price) % (gs*sk) / sk;
		c3 = (money - price) % sk;
	}
	else
	{
		b3 = (price - money) % (gs*sk) / sk;
		c3 = (price - money) % sk;
	}
	printf("%d.%d.%d\n", a3, b3, c3);
	return 0;
}