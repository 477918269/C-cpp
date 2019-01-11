#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void CountSort(int*a, int n)
{
	//先计算最大最小数，
	int min = a[0];
	int max = a[0];
	int i = 0;
	while (i < n)
	{
		if (min > a[i])
		{
			min = a[i];
		}
		if (max < a[i])
		{
			max = a[i];
		}
		i++;
	}
	//开辟空间

	int count = max - min + 1;
	int* cur = (int*)malloc(sizeof(int)*count);

	//记得要将新开辟的数组初始化
	memset(cur, 0, sizeof(int)*count);

	//建立存数的表

	for (int i = 0; i < n; i++)
	{
		cur[a[i] + min]++;
	}

	//将cur的数取出，依次放回a[]中

	int index = 0;
	for (i = 0; i < count; i++)//记住是从cur数组中取数，因此范围应该是0~count
	{
		while (cur[i]-- != 0)
		{
			a[index++] = i + min; //放入的不是cur[i],而是cur的下标，如果cur[i]的数减为0，就走向下一个数。
		}
	}

}

void _MergeSort(int*a, int begin, int end, int* cur)
{
	if (begin >= end )
	{
		return;
	}

	int mid = begin + ((end - begin) >> 1);

	_MergeSort(a, begin, mid-1, cur);
	_MergeSort(a, mid, end, cur);
	int begin1 = begin;
	int end1 = mid - 1;
	int begin2 = mid;
	int end2 = end;
	int index = begin;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			cur[index++] = a[begin1++];
		}
		else
			cur[index++] = a[begin2++];

	}
	while (begin1 <= end1)
	{
		cur[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		cur[index++] = a[begin2++];
	}
	//归并结果
	index = begin;
	while (begin <= end)
		a[index++] = cur[begin++];


}

void MergeSort(int*a, int n)
{
	int* cur = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, cur);
	free(cur);
}

int main()
{
	int a[] = { 10,6,7,1,3,9,4,2};
	int n = sizeof(a) / sizeof(a[0]);
	int i = 0;
	MergeSort(a, n);
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}