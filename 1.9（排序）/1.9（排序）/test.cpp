#include<stdio.h>
#include<stdlib.h>
//插入排序
//void InsetSort(int* a, int n)
//{
//	int end = 0;
//	int tmp = end + 1;
//	while (end < n - 1)
//	{
//		int x = end;
//		int y = tmp;
//		while (a[x] >a[y])
//		{
//			int tme = a[x];
//			a[x] = a[y];
//			a[y] = tme;
//			x--;
//			y--;
//		}
//		end++;
//		tmp++;
//	}
//}
//
//int main()
//{
//	int a[6] = { 6, 5, 4, 3, 2, 1 };
//	int i = 0;
//	InsetSort(a, 6);
//	for (i = 0; i < 6; i++)
//	{
//		printf("%d", a[i]);
//	}
//	system("pause");
//
//	return 0;
//}

//希尔排序

//void ShellNode(int* a, int x)
//{
//	
//	int gap = 3;
//	while (gap > 0)
//	{
//		int end = 0;
//
//		while (end < x - gap - 1)
//		{
//
//			int tmp = end + gap;
//			int prev = end;
//			int cur = tmp;
//			while (cur < x)
//			{
//				if (a[prev] > a[cur])
//				{
//					int tme = a[prev];
//					a[prev] = a[cur];
//					a[cur] = tme;
//				}
//				else
//				{
//					break;
//				}
//			}
//
//			end++;
//
//		}
//		gap = (gap - 1) / 3;
//	}
//	
//	
//}
//
////for (int i = 0; i< x - gap - 1; ++i)
////{
//
////	int end = i;
////	int tmp = a[end + gap];
////	while (end >= 0)
////	{
////		if (a[end] > tmp)
////		{
////			a[end + gap] = a[end];
////			end -= gap;
////		}
////		else
////		{
////			break;
////		}
////	}
////	a[end + gap] = tmp;
////}
//
//int main()
//{
//	int a[] = {9,1,2,5,7,4,8,6,3,5};
//	int n = sizeof(a) / sizeof(a[0]);
//	int i = 0;
//	ShellNode(a, n);
//	for (i = 0; i < n; i++)
//	{
//		printf("%d", a[i]);
//	}
//	system("pause");
//	return 0;
//}

//直接选择排序

//void easychoose(int* a,int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		int min = i;
//		
//		for (int j = i + 1; j < n; j++)
//		{
//			if (a[j] < a[min])
//			{
//				min = j;
//			}
//		}
//		if (i != min)//只改变数组中的数，不改变下标
//		{
//			int let = a[i];
//			a[i] = a[min];
//			a[min] = let;
//
//		}
//	}
//
//}


//堆排序
void HeapBuilt(int* a, int n, int i)
{
	int parent = i ;
	int child = parent * 2 + 1;
	while (child < n)
	{

		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			int tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;
			
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	//建大堆
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		HeapBuilt(a, n, i);
	}
	//选数
	int end = n - 1 ;
	while (end > 0)
	{
		int cur = a[end];
		a[end] = a[0];
		a[0] = cur;

		HeapBuilt(a, end, 0);

		end--;
	}
}

int main()
{
	int a[] = {20,17,4,16,5,3};
	int n = sizeof(a) / sizeof(a[0]);
	int k = 0;
	//easychoose(a, n);
	HeapSort(a, n);
	for (k = 0; k < n; k++)
	{
		printf("%d", a[k]);
	}
	system("pause");
	return 0;
}



