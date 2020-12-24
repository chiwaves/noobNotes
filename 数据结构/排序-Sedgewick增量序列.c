#include<stdio.h>
#include<math.h>

int main ()
{
	int i; 
	double r1, r2;
	
	for ( i = 0; i < 10; i++)
	{
		r1 = 9 * pow ( 4, i ) - 9 * pow ( 2, i ) + 1;
		r2 = pow ( 4, i+2 ) - 3 * pow ( 2, i+2 ) + 1;
		printf("%7.0lf\n%7.0lf\n", r1, r2);
	}
	return 0;
} 
