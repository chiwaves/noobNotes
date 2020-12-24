#include<stdio.h>
#define NUM 2
void Scan (int [][NUM]);
int Compare (int, int);
void Attach(int, int, Polynomial * );
void PolyAdd (int [][NUM], int [][NUM]);
void PolyMul (int [][NUM], int [][NUM]);
void Show (int [][NUM])

int main (void)
{
	Scan (P1);
	Scan (P2);
	PolyAdd (P1, P2);
	PolyMul (P1, P2);
	return 0;
}



void Scan (int P[][NUM])
{
	int row, cow, num;
	while ( scanf("%d", &num) == 1);
	for (row = 0; row < num; row++)
	    for (col = 0; col < NUM; col++)
	        scanf ("%d", &P1[row][num]);
}


void PolyAdd (int [][NUM], int [][NUM])
{
	for ()
}




void PolyMul (int [][NUM], int [][NUM])
{
	
}

























