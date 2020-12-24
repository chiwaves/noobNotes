int Partition (int A[], int n)  //快速排序P295.6
{
	int pivot, left, right;
	int low = 0, high = n;
	int final = n/2-1;
	int i, sum1 = sum2 = 0;
	while (1)
	{
		left = low;
		right = high;
		pivot = A[low];  //选择枢纽
		while (low < high)  //基于枢纽对集合进行划分
		{
			while (low < high && A[high] >= pivot)
				high--;
			A[low] = A[high];
			while (low < high && A[low] <= pivot)
				low--;
			A[high] = A[low];
		}
		A[low] = pivot;
		if (low > final)  //如果枢纽的位置在n/2之后，则继续对枢纽后部分进行划分
		{
			low = left;
			high--;
		}
		else if (low < final) //如果枢纽在n/2之前，则继续对枢纽前部分进行划分
		{
			low++;
			high = right;
		}
		else break;  //如果枢纽是第n/2个元素，则划分成功
	}
	for (i = 0; i < final+1; i++)
		sum1 = sum1 + A[i];
	for (i = final+1; i < n; i++)
		sum2 = sum2 + A[i];
	return sum2 - sum1;
}