#include<stdio.h>

bool Merge( sqList A, sqList B, sqList &C )  // 函数返回C表的地址
{
	int i = j = k = 0;
	if ( A.length + B.length > C.length )
		return false;
	while ( i < A.length && j < B.length )
	{
		if ( A.data[i] <= B.data[j] )
			C.data[k++] = A.data[i++];
		else
			C.data[k++] = B.data[j++];
	}
	while ( i < A.length )
			C.data[k++] = A.data[i++];
	while ( j < B.length )
			C.data[k++] = B.data[j++];
	C.length = k;
	return true;
}




void Reverse( sqList &L, int left, int right ) //先将数组逆置，然后对前n个元素，和后m个元素，分块逆置
{
	ElementType temp;
	if ( left > right || L.length == 0 )
		return;
	while ( left < right )
	{
		temp = L[left];
		L[left++] = L[right];
		L[right--] = temp;
	}
}
void Exchange( sqList &L, int m, int n )
{
	Reverse( L, 0, m+n-1 );
	Reverse( L, 0, n-1 );
	Reverse( L, n, m+n-1 );
}




void SBD( ElementType A[], ElementType X )
{
	int low = 0, high = n-1;
	int mid = (high-low)/2;
	while( low <= high )
	{
		if ( A[mid] == X )
			break;
		else if ( A[mid] < X )
			low = mid+1;
		else
			high = mid-1;
		mid = (high-low)/2;
	}
	if ( A[mid] == X && mid != n-1 )
	{
		A[mid] = A[mid+1];
		A[mid] = X;
	}
	else
	{
		for( i = n; i > high; i-- )
			A[i] = A[i-1];
		A[i] = X;
	}
}




//先将X0到Xn-1逆置，再将Xn-1到Xp逆置，最后将Xp-1到X0逆置
void Reverse( int R[], int left, int right )
{
	int temp;
	while ( left++ < right--)
	{
		temp = R[left];
		R[left] = R[right];
		R[right] = temp;
	}
}
void Right_shift( int R[] )
{
	Reverse( R, 0, n-1 );
	Reverse( R, 0, n-p-1 );
	Reverse( R, n-p, n-1 );
}



/*	看到中位数这种的，肯定要把时间复杂度往O(logn)上靠
	算法思想：分别求A和B的中位数a和b，1.若a=b，a或b即为所求。2.若a<b，则舍弃A中前一半，B中后一半。3.若a>b，则舍弃A中后一半，B中前一半
	每次两个序列舍弃的数必须一样多。剩下的数组部分重复执行上述过程直至序列中只剩一个元素 */
int Median( int A[], int B[], int num )
{
	int la = 0, ra = num-1, ma;
	int lb = 0, rb = num-1, mb;
	while ( la != ra )
	{
		ma = (ra-la)/2;
		mb = (rb-lb)/2;
		if ( A[ma] == B[mb] )  	//满足情况1，如果A序列的中位数与B序列的相同
			return A[ma];
		if ( A[ma] < B[mb] )	//满足情况2，如果A序列的中位数小于B序列的
		{
			if ( (ra-la+1)%2 == 0 )	//如果元素个数是偶数，A,B序列中删除的元素不同
				ma++;              	//就将A序列中前一半连同中位数一起删除
			la = ma;
			rb = mb;
		}
		else					//满足情况3，如果A序列的中位数大于B序列的
		{
			if ( (ra-la+1)%2 == 0 )	//如果元素个数是偶数
				mb++;				//将B序列中前一半连同中位数一起删除
			lb = mb;
			ra = ma;
		}
	}
	if ( A[la] < B[lb] )
		return A[la];
	else
		return B[lb];
}



int Majority (int A[], int n)
{
	int i, c, count = 1;
	c = A[0];
	for (i = 1; i < n; i++)
	{
		if (A[i] == c)
			count++;
		else if (A[i] != c && count == 1)
			c = A[i+1];
		else
			count--;
	}
	if (count > 0)
	{
		count = 0;
		for (i = 1; i < n; i++)
			if (A[i] == c)
				count++;
	}
	if (count > n/2)
		return c;
	else
		return -1;
}