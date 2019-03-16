#include<iostream>
using namespace std;


void ShellSort(int* a, int n)
{
	int grap = 5;
	while (grap > 1)
	{
		grap = (grap / 3) + 1;
		for (int i = 0; i < n - grap; i++)
		{
			int j = i;
			while (j >= 0)
			{
				if (a[j] > a[j + grap])
				{
					swap(a[j], a[j + grap]);
					j -= grap;
				}
				else
					break;
			}
		}
		
	}
}

void MpSort(int* a1, int n)
{
	for (int i = n - 1 ; i >= 0; i--)//注意
	{
		for (int j = 0; j < i; j++)
		{
			if (a1[j] > a1[j + 1])
			{
				swap(a1[j], a1[j + 1]);
			}
		}
	}
}
//1.建堆
void HeapBuild(int* a2, int i, int n)
{
	int parent = i;
	int child = (parent * 2) + 1;
	while (child < n)
	{
		if (child + 1 < n && a2[child] < a2[child + 1])
		{
			child++;
		}
		if (child < n && a2[parent] < a2[child])
		{
			swap(a2[parent], a2[child]);
			parent = child;
			child = (parent * 2) + 1;
		}
		else
			break;
		
	}
}

//2.排数
void HeapSort(int* a2, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		HeapBuild(a2, i, n);
	}

	int end = n - 1;
	while (end > 0)
	{
		swap(a2[end], a2[0]);
		HeapBuild(a2, 0, end);
		end--;
	}
}


void CountSort(int* a3, int n)
{
	int min = 0;
	int max = 0;
	int i = 0;
	while (i < n)
	{
		if (min > a3[i])
		{
			min = a3[i];
		}
		if (max < a3[i])
		{
			max = a3[i];
		}
		i++;
	}

	int count = max - min + 1;
	int* a = new int[count];
	memset(a, 0 ,sizeof(int) * count); //注意要开空间

	for (int i = 0; i < n; i++)
	{
		a[a3[i] - min]++;
	}

	int j = 0;
	int q = 0;
	while (q < count)
	{
		
		while (a[q]-- > 0)
		{
			a3[j++] = q + min;
		}
		q++;
	}
}

void ChoseSort(int* a4, int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a4[min] > a4[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(a4[min], a4[i]);
		}
	}
}
//for (int i = 0; i < n - 1; i++)
//{
//	int j = i + 1;
//	int k = j + 1;
//	if (j < n)
//	{
//		while (k < n)
//		{
//			if (a4[j] > a4[k])
//			{
//				k++;
//			}
//			else
//			{
//				j = k;
//				k++;
//			}
//		}
//	}
//	swap(a4[i], a4[j]);

int main()
{
	//int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	//int a1[] = { 6, 25, 24, 12, 55, 56 };
	//int a2[] = { 20, 17, 4, 16, 5, 3 };
	//int a3[] = { 2, 5, 3, 0, 2, 3, 0, 3 };
	//int a4[] = { 7, 4, 5, 9, 8, 2, 1 };
	int a5[] = { 10, 6, 7, 1, 3, 9, 4, 2 };
	int n = sizeof(a5)/ sizeof(a5[0]);
	//ShellSort(a, n);
	//MpSort(a1, n);
	//HeapSort(a2, n);
	//CountSort(a3, n);
	ChoseSort(a5, n);
	for (auto e : a5)
	{
		cout << e << " ";
	}
	system("pause");
	return 0;
}