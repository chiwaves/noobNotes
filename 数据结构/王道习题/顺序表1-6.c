  #include<stdio.h>

// 返回true和false分别表示查找并删除的成功和失败。传入min的地址，这样可以直接将最小值赋给min，从而传出。
bool DelMin( sqList &L, ElementType &min )  //传入的两个参数分别是L和min的地址，所以后面直接使用L和min。
{
	if ( L.length == 0 )
		return false;
	else
	{
		min = L.data[0];
		for( i = 1; i <= L.length; i++ )
			if ( L.data[i] < min )
			{
				min = L.data[i];
				position = i;
			}
		L.data[position] = L.data[length-1];
		L.length--;
		return true;
	}
}




void reverse( sqList &L )
{
	int i;
	ElementType temp;
	for( i = 0, i < L.length-i-1; i++ )
	{
		temp = L.data[i];
		L.data[i] = L.data[L.length-i-1];
		L.data[L.length-i-1] = temp;
	}
}



//算法思想：一边扫描顺序表L，一边用k统计不等于x的元素个数，并将不等于x的元素放到顺序表的位置k上。
//思路2：一边扫描顺序表L，一边用k统计等于x的元素的个数，当遇到一个非x元素，将其前移k位。
void Del_x1( sqList &L, ElementType x )
{
	int i, k = 0;
	for( i = 0; i < L.length; i++ )
		if L.data[i] != x
		{
			L.data[k] = L.data[i];
			k++;
		}
	L.length = k;
}



//算法思想：有序顺序表，掐头去尾就行
bool Del_st( sqList &L, ElementType s, ElementType t )
{
	int i = 0;
	int j;
	if ( L.length == 0 || s >= t )
		return false;
	while ( i < L.length && L.data[i] < s )
		i++;
	if ( i >= L.length )
		return false;
	j = i;
	while ( j < L.length && L.data[j] <= t )
		j++;
	while ( j < L.length )
		L.data[i++] = L.data[j++];
	L.length = i+1;
	return true;
}



bool Del_st2( sqList &L, ElementType s, ElementType t )
{
	int i, k = 0;
	if ( L.length <=0 || s >= t )
		return false;
	for ( i = 0; i < L.length; i++ )
		if ( L.data[i] < s || L.data[i] > t )
		{
			L.data[k] = L.data[i];
			k++;
		}
	L.length = k;
	return true;
}




bool Del_same( sqList &L )
{
	int i, k = 1;             //k用于记录不重复的元素个数
	if ( L.length == 0 )
		return false;
	for ( i = 1; i < L.length; i++ )
		if ( L.data[i] != L.data[i-1] )
			{
				L.data[k] = L.data[i];
				k++; 
			}
	L.length = k;
	return true;
}