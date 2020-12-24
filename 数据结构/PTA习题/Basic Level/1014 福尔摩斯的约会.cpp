#include <cstdio>
const int MAX = 61;
char week[30] = {"MONTUEWEDTHUFRISATSUN"};

bool Istrue(char c, char l, char r)
{
	if (l <= c && c <= r)
		return true;
	else
		return false;
}

int main()
{
	char A1[MAX], A2[MAX], B1[MAX], B2[MAX];
	int i = 0, day, hh, mm;
	scanf("%s%s%s%s", A1, A2, B1, B2);
	while (i < MAX)
	{
		if (A1[i] == A2[i] && Istrue(A1[i], 'A', 'G'))
			break;
		else
			i++;
	}
	day = A1[i] - 'A' + 1;
	i++;
	while (i < MAX)
	{
		if (A1[i] == A2[i] && Istrue(A1[i], '0', '9'))
		{
			hh = A1[i] - '0';
			break;
		}
		else if (A1[i] == A2[i] && Istrue(A1[i], 'A', 'N'))
		{
			hh = A1[i] - 'A' + 10;
			break;
		}
		else
			i++;
	}
	i = 0;
	while (i < MAX)
	{
		if (B1[i] == B2[i] && (Istrue(B1[i], 'A', 'Z') || Istrue(B1[i], 'a', 'z')))
		{
			mm = i;
			break;
		}
		else
			i++;
	}
	day = (day - 1)*3;
	i = 3;
	while (i--)
		printf("%c", week[day++]);
	printf(" %02d:%02d\n", hh, mm);
	return 0;
}