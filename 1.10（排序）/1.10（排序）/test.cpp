
#include"game.h"

//冒泡排序
void BullSort(int* a, int n)
{
	int i = n - 1;
	while (i >= 0)
	{
		int cur = 0;
		
		while (cur < i)
		{
			if (a[cur] > a[cur + 1])//选出最小的数放在数组的最后一位
			{
				int tmp = a[cur];
				a[cur] = a[cur + 1];
				a[cur + 1] = tmp;
			}
			cur++;//向下一位移动
		}
		i--;//将最后一个最小的数挪出循环。
	}
}

//快速排序



int Realkey(int* a, int begin, int end)//三点取中
{
	int mid = begin + ((end - begin) >> 1);
	if (a[mid] > a[begin])
	{
		if (a[begin] > a[end])
			return begin;
		if (a[end] > a[mid])
			return mid;
	}
	if (a[mid] > a[end])
	{
		if (a[end] > a[begin])
			return end;
		if (a[begin] > a[mid])
			return mid;
	}
	return begin;
}

int QuickBuilt1(int*a, int begin, int end)//最简单的快速排序
{
	int key = Realkey(a,begin,end);
	int tme = a[begin];
	a[begin] = a[key];
	a[key] = tme;
	while (begin < end)
	{
		while (begin < end && a[end] > a[key])
		{
			end--;
		}

		while (begin < end && a[begin] <= a[key])
		{
			begin++;
		}

		int tmp = a[begin];
		a[begin] = a[end];
		a[end] = tmp;
	}
	int tmp = a[key];
	a[key] = a[end];
	a[end] = tmp;
	return begin;
}

int QuickBuilt2(int*a, int begin, int end)//挖洞快排
{
	int key = Realkey(a, begin, end);
	int newkey = a[key];
	int tme = a[begin];
	a[begin] = a[key]; 
	a[key] = tme;
	
	while (begin < end)
	{
		while (begin < end && a[end] > newkey)
		{
			end--;
		}
		a[begin] = a[end];
		while (begin < end && a[begin] <= newkey)
		{
			begin++;
		}
		a[end] = a[begin];
	}
	a[begin] = newkey;
	return begin;
}

int QuickBuilt3(int*a, int begin, int end)//两个指针排序
{
	int key = begin;
	int cur = begin + 1;
	int prev = begin;
	return 0;
}
	


void QuickSort1(int*a, int begin, int end)
{
	if (begin >= end)
		return;
	int div = QuickBuilt1(a, begin, end);
	QuickSort1(a, begin, div-1);
	QuickSort1(a, div + 1, end);
}

void QuickSort2(int*a, int begin, int end)//非递归写法
{
	Stack ps;
	StackInit(&ps);
	StackPush(&ps, begin);
	StackPush(&ps, end);
	while (StackEmpty(&ps) != 0)
	{
		int right = StackTop(&ps);
		StackPop(&ps);	
		int left =StackTop(&ps);
		StackPop(&ps);

		int div = QuickBuilt1(a, left, right);

		if (div - 1 > left)
		{
			StackPush(&ps, left);
			StackPush(&ps, div-1);
			

		}

		if (div + 1 < right)
		{
			StackPush(&ps, div + 1);
			StackPush(&ps, right);
			

		}

	}

}


int main()
{
	int a[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	int n = sizeof(a) / sizeof(a[0]);
	//BullSort(a, n);
	int begin = 0;
	int end = n - 1;
	QuickSort2(a, begin, end);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}
